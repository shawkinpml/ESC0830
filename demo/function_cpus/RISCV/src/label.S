.section .labels, "aw", @progbits
    .align  2
    .globl  __Labels
    .type   __Labels, @object
__Labels:

	.size	__Labels, . - __Labels

	.end
