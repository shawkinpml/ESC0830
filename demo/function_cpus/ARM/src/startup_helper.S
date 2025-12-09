/**************************************************************************//**
 * @file     startup_ARMCM3.s
 * @brief    CMSIS Core Device Startup File for
 *           ARMCM3 Device Series
 * @version  V5.00
 * @date     02. March 2016
 ******************************************************************************/
/*
 * Copyright (c) 2009-2016 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

	.syntax	unified
	.arch	armv7-m

	.text
	.thumb

	.align	2
	.thumb_func
	.globl	pml_stack_restore
	.type	pml_stack_restore, %function
pml_stack_restore:
	push	{r7, lr}
	sub	sp, #8
	add	r7, sp, #0
	movs	r3, #0   /* unsigned int result = 0; */
	str	r3, [r7, #4]
	add r3, r7, #8   /* result <- [sp + 8] */
	ldr r4, [r3]
	str	r4, [r7, #4]
	ldr	r0, [r7, #4] /* stack_restore_helper(result); */
	bl  stack_restore_helper
	nop
	adds	r7, #8
	mov	sp, r7
	pop	{r7, pc}
	.size	pml_stack_restore, . - pml_stack_restore

	.end
