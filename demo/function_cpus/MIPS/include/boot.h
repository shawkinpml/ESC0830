/*
 * Copyright (C) 2020-2021 CIP United Co. Ltd.  All Rights Reserved.
 *
 */

/*
 * boot.h
 *
*/
/*
Copyright (c) 2007-2020, MIPS Tech, LLC and/or its affiliated group companies or licensors

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are
permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of
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
#include <mips/m32c0.h>


//#define GCR_CONFIG_ADDR     0xbfbf8000  //!< KSEG0 address of the GCR registers
//#define GIC_P_BASE_ADDR		0x1bdc0000  //!< physical address of the GIC
//#define GIC_BASE_ADDR		0xbbdc0000  //!< KSEG0 address address of the GIC
//#define CPC_P_BASE_ADDR 	0x1bde0001  //!< physical address of the CPC
//#define CPC_BASE_ADDR		0xbbde0000  //!< KSEG0 address address of the CPC
//#define STACK_BASE_ADDR     0xbfc88000  /* According to Ming 20201108. */
//#define STACK_BASE_ADDR     0x82a10000
#define STACK_BASE_ADDR     0x80111400
#define STACK_SIZE_LOG2     16          /* 64Kbytes each */


/**************************************************************************************
 Register use while executing in this file: ("GLOBAL" denotes a common value.)
**************************************************************************************/

// o32 $2 - $7 (v0, v1, a0 - a3) reserved for program use
// p32 $2 - $7 (t4, t5, a0 - a3) reserved for program use

/* o32 t0 Core number. Only core 0 is active after reset. */
/* p32 a4 Core number. Only core 0 is active after reset. */
#define r8_core_num    $8
/* o32 t1 MT ASE VPE number that this TC is bound to (0 if non-MT.) */
/* p32 a5 MT ASE VPE number that this TC is bound to (0 if non-MT.) */
#define r9_vpe_num     $9
/* o32 t2 Core implements the MT ASE. */
/* p32 a6 Core implements the MT ASE. */
#define r10_has_mt_ase  $10
/* o32 t3 Core is part of a Coherent Processing System. */
/* p32 a7 Core is part of a Coherent Processing System. */
#define r11_is_cps      $11

// $12 - $15 (t4 - t7 o32 or t0 - t3 n32/64/p32)  are free to use
// $16, $17 (s0 and s1) are free to use

#define r18_tc_num      $18  /* s2 MT ASE TC number (0 if non-MT.) */
#define r19_more_cores  $19  /* s3 Number of cores in CPS in addition to core 0. GLOBAL! */
#define r20_more_vpes   $20  /* s4 Number of vpes in this core in addition to vpe 0. */
#define r21_more_tcs    $21  /* s5 Number of tcs in vpe in addition to the first. */
#define r22_gcr_addr    $22  /* s6 Uncached (kseg1) base address of the Global Config Registers. */
#define r23_cpu_num     $23  /* s7 Unique per vpe "cpu" identifier (CP0 EBase[CPUNUM]). */
//#define r24_boston_byte $24  /* t8 flash address of boston_lcd_display_byte function */
#define r25_coreid      $25  /* t9 Copy of cp0 PRiD GLOBAL! */
// 						$26  /* k0 Interrupt handler scratch */
// 					    $27  /* k1 Interrupt handler scratch */
// $28 gp and $29 sp
#define r30_cpc_addr    $30  /* s8 Address of CPC register block after cpc_init. 0 indicates no CPC. */
// $31 ra

#ifndef __ASSEMBLER__

typedef struct pt_regs
{
    unsigned long reserved[5];
    unsigned long at;
    unsigned long v0;
    unsigned long v1;
    unsigned long a0;
    unsigned long a1;
    unsigned long a2;
    unsigned long a3;
    unsigned long t0;
    unsigned long t1;
    unsigned long t2;
    unsigned long t3;
    unsigned long t4;
    unsigned long t5;
    unsigned long t6;
    unsigned long t7;
    unsigned long t8;
    unsigned long t9;
    unsigned long s0;
    unsigned long s1;
    unsigned long s2;
    unsigned long s3;
    unsigned long s4;
    unsigned long s5;
    unsigned long s6;
    unsigned long s7;
    unsigned long fp;
    unsigned long gp;
    unsigned long sp;
    unsigned long ra;
    unsigned long status;
    unsigned long epc;
} pt_regs;

#endif