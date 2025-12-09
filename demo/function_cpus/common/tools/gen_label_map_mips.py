from gen_label_map_common import genfile
from gen_label_map_common import DEST_TAIL
import os

## MIPS
CPU0_PATH = os.path.join(os.getcwd(), "MIPS/app/build/mips_app.lst")
DES0_PATH = os.path.join(os.getcwd(), "MIPS/src/gen.S")
DES0_HEAD = [
"#include <mips/asm.h>\n",
"#include <mips/regdef.h>\n",
"#include <mips/cpu.h>\n",
"\n",
"LEAF(pml_stack_restore)\n",
"    addiu	sp,sp,-32\n",
"	sw	ra,28(sp)\n",
"	sw	s8,24(sp)\n",
"	move	s8,sp\n",
"	sw	zero,16(s8)\n",
"	addiu s7, s8, 24\n",
"	lw  s6, 0(s7)\n",
"	sw	s6,16(s8)\n",
"	lw	a0,16(s8)\n",
"	la  t0, stack_restore_helper\n",
"	jalr t0\n",
"	nop\n",
"	nop\n",
"    move	sp,s8\n",
"    lw	ra,28(sp)\n",
"    lw	s8,24(sp)\n",
"    addiu	sp,sp,32\n",
"    jr	ra\n",
"    nop\n",
"END(pml_stack_restore)\n",
"\n",
"    .section .labels, \"aw\", @progbits\n",
"    .align  2\n",
"    .globl  __Labels\n",
"    .type   __Labels, @object\n",
"__Labels:\n"
]

genfile(CPU0_PATH, DES0_PATH, DES0_HEAD, DEST_TAIL)
