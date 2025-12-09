	.syntax	unified
	.arch	armv7-m

	.section .labels
	.align	2
	.globl	__Labels
__Labels:
    .long	10
    .long	0x100754
    .long	11
    .long	0x1007be

	.size	__Labels, . - __Labels

	.end
