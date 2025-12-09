/*
 * init_gpr.S
 *
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
#include <core_config.h>
#include <mips/regdef.h>
#include <mips/m32c0.h>

	.set	noat                // Don't allow the assembler to use r1(at) for synthetic instr.
/**************************************************************************************
**************************************************************************************/
LEAF(init_gpr)

	// Initialize the general purpose registers and any shadow register sets.
	// Although not necessary, register initialization may be useful during debugging
	// to see if a register has ever been written


	// Initialize register sets
    li      $1, 0xdeadbeef      // (0xdeadbeef stands out, kseg2 mapped, odd.)

	move	$2, $1
	move	$3, $1
	move	$4, $1
	move	$5, $1
	move	$6, $1
	move	$7, $1
	move	$8, $1
	move	$9, $1
	move	$10, $1
	move	$11, $1
	move	$12, $1
	move	$13, $1
	move	$14, $1
	move	$15, $1
	move	$16, $1
	move	$17, $1
	move	$18, $1
	move	$19, $1
	move	$20, $1
	move	$21, $1
	move	$22, $1
	move	$23, $1
	move	$24, $1
	move	$25, $1
	move	$26, $1
	move	$27, $1
	move	$28, $1
	move	$29, $1
	move	$30, $1
	// move	$31, $1  // Don't clobber RA return pointer to be use to return to start.S (if inlining you can uncomment this line


done_init_gpr:
    jr      ra
END(init_gpr)

