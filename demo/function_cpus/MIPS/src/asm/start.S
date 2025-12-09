/*
Copyright (c) 2007-2018, MIPS Tech, LLC and/or its affiliated group companies or licensors

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are
permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of
conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list
of conditions and the following disclaimer in the documentation and/or other materials
provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be
used to endorse or promote products derived from this software without specific prior
written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <mips/asm.h>
#include <mips/regdef.h>
#include <boot.h>
#include <mips/m32c0.h>

	# The first function, __reset_vector, just loads the address of the __cpu_init function
	# and jumps to it. This does 2 things; First it will jump to a KSEG1 address which is a
	# mirror of the KSEG0 BEV address but cacheable. Second it will do a mode switch to
	# enable micromips mode.

LEAF(__reset_vector)
	la a2,__cpu_init
	mtc0	$0, C0_COUNT  	    # Clear cp0 Count (Used to measure boot time.)
	jr a2

	# Note: Address 0x1FC0.0010 is special, in the sense that it is overridden
	# and does not decode to an address in the SW-EPROM, but rather to memory
	# mapped register which holds the board REVISION number. This makes the
	# following nops necessary to insure the next code segment does not fall
	# into the Revision address range

	nop
	nop
	nop
	nop

END(__reset_vector)

	.org 0x180
	.set push
	.set nomicromips                        # This code assumes exceptions are handled in MIPS32 mode
.weak _mips_general_exception
__general_exception_loop:
	LA	k1, _mips_general_exception
	beqz    k1, __general_exception_loop
	jr	k1
	.set    pop
/*
.org 0x200								# TLB refill, 32 bit task.
.set push
.set nomicromips                        # This code assumes exceptions are handled in MIPS32 mode
tlb_refill_excpt:                       # This label helps the disassembler figure out this is MIPS32 code
    sdbbp								# This has the effect of starting the debugger
.set pop

.org 0x280								# XTLB refill, 64 bit task. start + 0x280
.set push
.set nomicromips                        # This code assumes exceptions are handled in MIPS32 mode.
xtlb_refill_excpt:						# This label helps the disassembler figure out this is MIPS32 code
    sdbbp								# This has the effect of starting the debugger
.set pop

.org 0x300								# Cache error exception. start + 0x300
.set push
.set nomicromips                        # This code assumes exceptions are handled in MIPS32 mode.
cache_error_excpt:						# This label helps the disassembler figure out this is MIPS32 code
    sdbbp								# This has the effect of starting the debugger
.set pop

#include <init_tlb.S>

.org 0x380								# General exception. start + 0x380
.set push
.set nomicromips                        # This code assumes exceptions are handled in MIPS32 mode.
.set at
general_excpt:							# This label helps the disassembler figure out this is MIPS32 code
	nop
wait_here:
	b		wait_here
.set pop

# If you want the above code to fit into 1k flash you will need to leave out the
# code below. This is the code that covers the debug exception which you normally will not get.
.org 0x480 								# EJTAG Debug (with ProbEn = 0 in the EJTAG Control Register)
.set push
.set nomicromips                        # This code assumes exceptions are handled in MIPS32 mode.
debug_excpt:
    b         debug_excpt  # Stay here 
.set pop

#include <init_caches.S>
*/

//.set micromips							# This causes the code below to be compiled as micromips
										# This will reduce the code size and help the code fit into 1K of memory
LEAF(__cpu_init)

	# Verify the code is here due to a reset and not NMI. If this is an NMI then trigger
	# a debugger breakpoint using a sdbp instruction.

    mfc0    s1, C0_STATUS              	# Read CP0 Status
    ext	    s1, s1, 19, 1				# extract NMI
    beqz    s1, init_resources 		 	# Branch if this is NOT an NMI exception.
    sdbbp                              	# Failed assertion: NMI.

init_resources:  						# initializes resources for "cpu".

	# Set the global pointer register address to _gp and the stack pointer register to
	# STACK_BASE_ADDR these values are assigned in the linker file

    la      gp, _gp						# All share globals.
	#li      sp, STACK_BASE_ADDR		# LI RD, IMM32  <--> RD = IMM32
	la      sp, __stack                 # LA RD, LABEL  <--> RD = ADDRESS(LABEL)

    # Initialize CP0 registers

    la a2,     init_cp0    				# Init CP0 Status, Count, Compare, Watch*, and Cause.
    jalr a2

	# Copy "C" code (main.c) and data to RAM and zero bss

    la 		a2, copy_c2_ram
    jalr 	a2

    # Prepare for eret to main (sp and gp set in set_gpr_boot_values).
    la      ra, all_done				# If main returns then go to all_done:.
    la      v0, main					# load the address of the main function
    mtc0    v0, C0_ERRPC				# Write ErrorEPC with the address of main
    ehb									# clear hazards (makes sure write to ErrorEPC has completed)

    # Return from exception will now execute code in main
    eret   								# Exit reset exception handler and start execution of main().

/**************************************************************************************
**************************************************************************************/
all_done:
    # If main returns it will return to this point.  Just spin here.
    b       all_done

END(__cpu_init)

# Inline the code fill the rest of
# space between here and the next exception vector address.

#include <copy_c2_ram.S>

/**************************************************************************************
    B O O T   E X C E P T I O N   H A N D L E R S (CP0 Status[BEV] = 1)
**************************************************************************************/
/* NOTE: the linker script must insure that this code starts at  */
/* BEV (boot exception vector) + 0x200 so the exception */
/* vectors will be addressed properly. All .org assume this! */

/* TLB refill, 32 bit task. */
#include <init_cp0.S>

.set nomicromips
