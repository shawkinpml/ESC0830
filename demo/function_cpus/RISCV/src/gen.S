.section .labels, "aw", @progbits
    .align  2
    .globl  __Labels
    .type   __Labels, @object
__Labels:
    .long	10
    .long	0x100c9c
    .long	11
    .long	0x100d42

	.size	__Labels, . - __Labels

	.end
