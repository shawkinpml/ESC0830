#include <mips/asm.h>
#include <mips/regdef.h>
#include <mips/cpu.h>

LEAF(pml_stack_restore)
    addiu	sp,sp,-32
	sw	ra,28(sp)
	sw	s8,24(sp)
	move	s8,sp
	sw	zero,16(s8)  /* unsigned int result = 0; */
	addiu s7, s8, 24   /* result <- [s8 + 24] */
	lw s6, 0(s7)
	sw	s6,16(s8)
	lw	a0,16(s8)
	la  t0, stack_restore_helper
	jalr t0
	nop
	nop
    move	sp,s8
    lw	ra,28(sp)
    lw	s8,24(sp)
    addiu	sp,sp,32
    jr	ra
    nop
END(pml_stack_restore)

    .section .labels, "aw", @progbits
    .align  2
    .globl  __Labels
    .type   __Labels, @object
__Labels:

	.size	__Labels, . - __Labels

    .end