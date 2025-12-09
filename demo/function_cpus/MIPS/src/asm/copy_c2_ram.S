/*
 * copy_c2_ram.S
 *
 *  Copy code and data to ram then clear BSS
*/
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
#include <core_config.h>

#define all_ones				$17   /* at Will hold 0xffffffff to simplify bit insertion of 1's. */
#define data					$4   /* data to be moved */
#define source_addr				$5   /* from address */
#define destination_addr		$6   /* to address */
#define end_addr				$7   /* ending address */

	.set	noat                # Don't allow the assembler to use r1(at) for synthetic instr.

/**************************************************************************************
**************************************************************************************/
LEAF(copy_c2_ram)

	li      all_ones, 0xffffffff

/*
    # Copy code and read-only/initialized data from FLASH to (uncached) RAM.
    LA      source_addr, _ftext_rom
    LA      destination_addr, _ftext_rom # _ftext_ram
    LA      end_addr, _ftext_rom # _etext_ram
    #if !defined(EVA) && !defined(MPU)  // NOTE EVA mode assumed to be uncached
    	// Switch address to uncached (kseg1) so copy will go directly
    	// to memory
    	ins     destination_addr, all_ones, 29, 1
    	ins     end_addr, all_ones, 29, 1
    #endif
    beq     destination_addr, end_addr, copy_data
next_ram_word:
    lw      data, 0(source_addr)
    sw      data, 0(destination_addr)
    addiu   destination_addr, 4
    addiu   source_addr, 4
    bne     end_addr, destination_addr, next_ram_word
*/

copy_data:
// now copy the data
    LA      source_addr, _fdata_rom
    LA      destination_addr,  _fdata_ram
    LA      end_addr, _edata_ram
    #if !defined(EVA) && !defined(MPU)  // NOTE EVA mode assumed to be uncached
    	// Switch address to uncached (kseg1) so copy will go directly
    	// to memory
    	ins     destination_addr, all_ones, 29, 1
    	ins     end_addr, all_ones, 29, 1
    #endif
    beq     destination_addr, end_addr, zero_bss  // if no data skip ahead
next_ram_dword:
    lw      data, 0(source_addr)
    sw      data, 0(destination_addr)
    addiu   destination_addr, 4
    addiu   source_addr, 4
    bne     end_addr, destination_addr, next_ram_dword

zero_bss:
    LA      destination_addr, _fbss
    LA      end_addr, _end
    #ifndef EVA  // NOTE EVA mode assumed to be uncached
    	// Switch address to uncached (kseg1) so copy will go directly
    	// to memory
	    ins     destination_addr, all_ones, 29, 1
	    ins     end_addr, all_ones, 29, 1
    #endif
    beq     destination_addr, end_addr, copy_c2_ram_done
next_bss_word:
    sw      zero, 0(destination_addr)
    addiu   destination_addr, 4
    bne     destination_addr, end_addr, next_bss_word

copy_c2_ram_done:
    jalr	zero,      ra

.set at
END(copy_c2_ram)
