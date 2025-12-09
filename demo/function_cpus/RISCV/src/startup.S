#include "encoding.h"
#if __riscv_xlen == 64
# define LREG ld
# define SREG sd
# define REGBYTES 8
#else
# define LREG lw
# define SREG sw
# define REGBYTES 4
#endif
// <<< Use Configuration Wizard in Context Menu >>>

	.section .stack,"aw",@nobits
	.align	3
#ifdef __STACK_SIZE
#define	Stack_Size __STACK_SIZE
#else
#define	Stack_Size 0x00000800        // 2KB; not 0x00000400 1KB
#endif
	.globl	__StackTop
	.globl	__StackLimit
__StackLimit:
	.space	Stack_Size
	.size	__StackLimit, . - __StackLimit
__StackTop:
	.size	__StackTop, . - __StackTop

	.section .heap,"aw",@nobits
	.align	3
#ifdef __HEAP_SIZE
#define	Heap_Size __HEAP_SIZE
#else
#define	Heap_Size 0x00002000        // 8KB; not 0x00000C00 3KB
#endif
	.globl	__HeapBase
	.globl	__HeapLimit
__HeapBase:
	.if	Heap_Size
	.space	Heap_Size
	.endif
	.size	__HeapBase, . - __HeapBase
__HeapLimit:
	.size	__HeapLimit, . - __HeapLimit

.section .vectors, "aw", @progbits
    .align  6
    .globl  __Vectors
    .type   __Vectors, @object
__Vectors:
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler

    /* External interrupts */
    .long   SAVE_CONTEXT_Handler
    .long   PLIC_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    .long   Default_Handler
    
/*
 * For importing variable or functions from other c or assemble files.
 */
.global __main
.global SystemInit
.global general_handle_trap
.global save_context_handler
.global plic_handler

  .section ".text.init"
  .globl Reset_Handler
  .type Reset_Handler, %function
  .global __dirver_test_service__
  .weak __driver_test_service__
  .type __driver_test_service__, %function
Reset_Handler:
	# enable FPU and accelerator if present, enable global irq
	li t0, MSTATUS_FS | MSTATUS_XS | MSTATUS_MIE
	csrs mstatus, t0

  li t0, 0x888 # enable mie
  csrs mie, t0

  #icache enable
  li t1, 1
  csrrs t3, mhcr, t1
  #csrrc t3, mhcr, t1

  #dcache enable
  li t1, 2
  #csrrs t3, mhcr, t1
  csrrc t3, mhcr, t1
  
	# enable MXSTATUS.THEADISAEE bit[22]
	li t0,  0x400000
	csrs mxstatus, t0

    la      a0, Default_Handler
    ori     a0, a0, 3
    csrw    mtvec, a0

    la      a0, __Vectors
    csrw    mtvt, a0

    la      sp, __stack
    csrw    mscratch, sp

    jal     SystemInit

    la      a0, __driver_test_service__
    beq     zero, a0, 1f
    jalr    a0
    j       __exit

1:
    jal     __main

    .size   Reset_Handler, . - Reset_Handler

__exit:
    j      __exit

.macro SAVE_CONTEXT
  addi sp, sp, -40*REGBYTES

  SREG x1, 1*REGBYTES(sp)
  SREG x2, 2*REGBYTES(sp)
  SREG x3, 3*REGBYTES(sp)
  SREG x4, 4*REGBYTES(sp)
  SREG x5, 5*REGBYTES(sp)
  SREG x6, 6*REGBYTES(sp)
  SREG x7, 7*REGBYTES(sp)
  SREG x8, 8*REGBYTES(sp)
  SREG x9, 9*REGBYTES(sp)
  SREG x10, 10*REGBYTES(sp)
  SREG x11, 11*REGBYTES(sp)
  SREG x12, 12*REGBYTES(sp)
  SREG x13, 13*REGBYTES(sp)
  SREG x14, 14*REGBYTES(sp)
  SREG x15, 15*REGBYTES(sp)
  SREG x16, 16*REGBYTES(sp)
  SREG x17, 17*REGBYTES(sp)
  SREG x18, 18*REGBYTES(sp)
  SREG x19, 19*REGBYTES(sp)
  SREG x20, 20*REGBYTES(sp)
  SREG x21, 21*REGBYTES(sp)
  SREG x22, 22*REGBYTES(sp)
  SREG x23, 23*REGBYTES(sp)
  SREG x24, 24*REGBYTES(sp)
  SREG x25, 25*REGBYTES(sp)
  SREG x26, 26*REGBYTES(sp)
  SREG x27, 27*REGBYTES(sp)
  SREG x28, 28*REGBYTES(sp)
  SREG x29, 29*REGBYTES(sp)
  SREG x30, 30*REGBYTES(sp)
  SREG x31, 31*REGBYTES(sp)

  csrr x5, mepc
  SREG x5, 32*REGBYTES(sp)
  csrr x5, mcause
  SREG x5, 33*REGBYTES(sp)
.endm

.macro RESTORE_CONTEXT
  LREG x5,  32*REGBYTES(sp)
  csrw mepc, x5
  LREG x5,  33*REGBYTES(sp)
  csrw mcause, x5
  # csrw mepc, a0

  # Remain in M-mode after eret, enable interrupt TODO
  li t0, MSTATUS_MPP | MSTATUS_MPIE
  csrs mstatus, t0

  LREG x1, 1*REGBYTES(sp)
  LREG x2, 2*REGBYTES(sp)
  LREG x3, 3*REGBYTES(sp)
  LREG x4, 4*REGBYTES(sp)
  LREG x5, 5*REGBYTES(sp)
  LREG x6, 6*REGBYTES(sp)
  LREG x7, 7*REGBYTES(sp)
  LREG x8, 8*REGBYTES(sp)
  LREG x9, 9*REGBYTES(sp)
  LREG x10, 10*REGBYTES(sp)
  LREG x11, 11*REGBYTES(sp)
  LREG x12, 12*REGBYTES(sp)
  LREG x13, 13*REGBYTES(sp)
  LREG x14, 14*REGBYTES(sp)
  LREG x15, 15*REGBYTES(sp)
  LREG x16, 16*REGBYTES(sp)
  LREG x17, 17*REGBYTES(sp)
  LREG x18, 18*REGBYTES(sp)
  LREG x19, 19*REGBYTES(sp)
  LREG x20, 20*REGBYTES(sp)
  LREG x21, 21*REGBYTES(sp)
  LREG x22, 22*REGBYTES(sp)
  LREG x23, 23*REGBYTES(sp)
  LREG x24, 24*REGBYTES(sp)
  LREG x25, 25*REGBYTES(sp)
  LREG x26, 26*REGBYTES(sp)
  LREG x27, 27*REGBYTES(sp)
  LREG x28, 28*REGBYTES(sp)
  LREG x29, 29*REGBYTES(sp)
  LREG x30, 30*REGBYTES(sp)
  LREG x31, 31*REGBYTES(sp)

  addi sp, sp, 40*REGBYTES
.endm

  .align 6
Default_Handler:
  SAVE_CONTEXT

  csrr a0, mcause
  csrr a1, mepc
  mv a2, sp
  jal general_handle_trap

  RESTORE_CONTEXT
  mret

  .align 2
SAVE_CONTEXT_Handler:
  SAVE_CONTEXT

  csrr a0, mcause
  csrr a1, mepc
  mv a2, sp
  jal save_context_handler
  
  RESTORE_CONTEXT
  mret

  .align 2
PLIC_Handler:
  SAVE_CONTEXT

  csrr a0, mcause
  csrr a1, mepc
  mv a2, sp
  jal plic_handler
  
  RESTORE_CONTEXT
  mret

.global pml_get_sp
  .align 2
pml_get_sp:
  addi	sp,sp,-32
  sw	ra,28(sp)
  sw  s0,24(sp)
  addi	s0,sp,32
  sw	a0,-20(s0) // input parameter: unsigned int *pr

  mv	a4,s0
  lw	a5,-20(s0)
  sw	a4,0(a5)   // *pr = old sp

  nop
  lw  ra,28(sp)
  lw	s0,24(sp)
  addi	sp,sp,32
  ret

.global pml_stack_restore
  .align 2
pml_stack_restore: 
  addi	sp,sp,-32
  sw	ra,28(sp)
  sw	s0,24(sp)
  addi	s0,sp,32

  sw	zero,-20(s0) // unsigned int result = 0
  mv	a5,s0        // __asm volatile("mv %0, s0" : "=r"(result))
  sw	a5,-20(s0)   // result = old sp
  
  lw	a0,-20(s0)   // stack_restore_helper(result)
  jal	stack_restore_helper

  nop
  lw	ra,28(sp)
  lw	s0,24(sp)
  addi	sp,sp,32
  ret

.global SAVE_REGISTER
.global RESTORE_REGISTER

  .align 2
SAVE_REGISTER:
  la t6, 0x4400FC00 # define STACK_SAVE_SRAM_ADDR  (LOC_SRAM_BASEADDR + LOC_SRAM_SIZE - __REGS_SIZE - __STACK_SIZE)
  sw x1, 1*4(t6)
  sw x2, 2*4(t6)
  sw x3, 3*4(t6)
  sw x4, 4*4(t6)
  sw x5, 5*4(t6)
  sw x6, 6*4(t6)
  sw x7, 7*4(t6)
  sw x8, 8*4(t6)
  sw x9, 9*4(t6)
  sw x10, 10*4(t6)
  sw x11, 11*4(t6)
  sw x12, 12*4(t6)
  sw x13, 13*4(t6)
  sw x14, 14*4(t6)
  sw x15, 15*4(t6)
  sw x16, 16*4(t6)
  sw x17, 17*4(t6)
  sw x18, 18*4(t6)
  sw x19, 19*4(t6)
  sw x20, 20*4(t6)
  sw x21, 21*4(t6)
  sw x22, 22*4(t6)
  sw x23, 23*4(t6)
  sw x24, 24*4(t6)
  sw x25, 25*4(t6)
  sw x26, 26*4(t6)
  sw x27, 27*4(t6)
  sw x28, 28*4(t6)
  sw x29, 29*4(t6)
  sw x30, 30*4(t6)
  ret

  .align 2
RESTORE_REGISTER:
  la t6, 0x4400FC00 # define STACK_SAVE_SRAM_ADDR  (LOC_SRAM_BASEADDR + LOC_SRAM_SIZE - __REGS_SIZE - __STACK_SIZE)
  lw x1, 1*4(t6)
  lw x2, 2*4(t6)
  lw x3, 3*4(t6)
  lw x4, 4*4(t6)
  lw x5, 5*4(t6)
  lw x6, 6*4(t6)
  lw x7, 7*4(t6)
  lw x8, 8*4(t6)
  lw x9, 9*4(t6)
  lw x10, 10*4(t6)
  lw x11, 11*4(t6)
  lw x12, 12*4(t6)
  lw x13, 13*4(t6)
  lw x14, 14*4(t6)
  lw x15, 15*4(t6)
  lw x16, 16*4(t6)
  lw x17, 17*4(t6)
  lw x18, 18*4(t6)
  lw x19, 19*4(t6)
  lw x20, 20*4(t6)
  lw x21, 21*4(t6)
  lw x22, 22*4(t6)
  lw x23, 23*4(t6)
  lw x24, 24*4(t6)
  lw x25, 25*4(t6)
  lw x26, 26*4(t6)
  lw x27, 27*4(t6)
  lw x28, 28*4(t6)
  lw x29, 29*4(t6)
  lw x30, 30*4(t6)
  ret