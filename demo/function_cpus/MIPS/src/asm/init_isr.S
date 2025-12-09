#include <mips/asm.h>
#include <mips/regdef.h>
#include <boot.h>
#include <mips/m32c0.h>
	.set noreorder		# Linker don't change instruction order
	.set noat
	
.macro save_regs
	/* save values into the GPRs */
	sw	AT, 20(k1)
	sw	v0, 24(k1)
	sw	v1, 28(k1)
	sw	a0, 32(k1)
	sw	a1, 36(k1)
	sw	a2, 40(k1)
	sw	a3, 44(k1)
	sw	t0, 48(k1)
	sw	t1, 52(k1)
	sw	t2, 56(k1)
	sw	t3, 60(k1)
	sw	t4, 64(k1)
	sw	t5, 68(k1)
	sw	t6, 72(k1)
	sw	t7, 76(k1)
	sw	t8, 80(k1)
	sw	t9, 84(k1)
	sw	s0, 88(k1)
	sw	s1, 92(k1)
	sw	s2, 96(k1)
	sw	s3, 100(k1)
	sw	s4, 104(k1)
	sw	s5, 108(k1)
	sw	s6, 112(k1)
	sw	s7, 116(k1)
	sw	fp, 120(k1)
	sw	gp, 124(k1)
    sw	sp, 128(k1)
	sw	ra, 132(k1)
	
    mfc0	t1, C0_STATUS		# Get status register
	sw	t1, 136(k1)		# Save status register value to stack
	mfc0	t2, C0_EPC		# Get EPC register`
	sw	t2, 140(k1)		# Save EPC register value to stack	
.endm

.macro load_regs
	lw	t2, 140(k1)		# retrieve the value of C0_EPC
    mtc0	t2, C0_EPC		# Restore EPC register
	ehb				# Wait for change to take effect
	lw	k0, 136(k1)		# retrieve the value of C0_STATUS
	mtc0	k0, C0_STATUS		# Copy new status back to C0_STATUS
	ehb				# Wait for change to take effect

	/* load saved values into the GPRs */
	lw	ra, 132(k1)
	lw	sp, 128(k1)
	lw	gp, 124(k1)
	lw	fp, 120(k1)
	lw	s7, 116(k1)
	lw	s6, 112(k1)
	lw	s5, 108(k1)
	lw	s4, 104(k1)
	lw	s3, 100(k1)
	lw	s2, 96(k1)
	lw	s1, 92(k1)
	lw	s0, 88(k1)
	lw	t9, 84(k1)
	lw	t8, 80(k1)
	lw	t7, 76(k1)
	lw	t6, 72(k1)
	lw	t5, 68(k1)
	lw	t4, 64(k1)
	lw	t3, 60(k1)
	lw	t2, 56(k1)
	lw	t1, 52(k1)
	lw	t0, 48(k1)
	lw	a3, 44(k1)
	lw	a2, 40(k1)
	lw	a1, 36(k1)
	lw	a0, 32(k1)
	lw	v1, 28(k1)
	lw	v0, 24(k1)
	lw	AT, 20(k1)
.endm


LEAF(init_isr)
	/* Mask all interrupts, it seems timer IRQ is default enabled */
	mfc0	t1, C0_STATUS
	/* bit8-16 and bit18 */
	ins	t1, zero, 8, 8
	ins	t1, zero, 18, 1
	mtc0	t1, C0_STATUS
    /* set CAUSE.iv bit to enable VI mode */
    mfc0    t1, C0_CAUSE
    li      t0, 1 << 23
    or      t1, t1, t0
    mtc0    t1, C0_CAUSE
	j	ra
    nop
END(init_isr)

.set reorder
