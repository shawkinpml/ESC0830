/*
 * Copyright (c) 2019 Nuclei Limited. All rights reserved.
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
#ifndef PML_PLIC_CORE_H
#define PML_PLIC_CORE_H
/*!
 * @file     plic_core.h
 * @brief    PLIC feature API header file for RISC-V Core
 */
/*
 * PLIC Feature Configuration Macro:
 * 1. __PLIC_PRESENT:  Define whether Platform Level Interrupt Controller (PLIC) Unit is present or not
 *   * 0: Not present
 *   * 1: Present
 * 2. __PLIC_BASEADDR:  Base address of the PLIC unit.
 * 3. __PLIC_INTNUM  : Define the external interrupt number of PLIC Unit
 *
 */
#ifdef __cplusplus
 extern "C" {
#endif

// #include "plic_base.h"
#ifndef   __STATIC_FORCEINLINE
  #define __STATIC_FORCEINLINE                   __attribute__((always_inline)) static inline
#endif

#define __PLIC_PRESENT            1                   /*!< Set to 1 if PLIC is present */
#define __CORE_INT_NUM            2                   /* the first interrupt for save_context, the second interrpt for plic output */

#define __PLIC_BASEADDR           0x41100000          /*!< Set to PLIC baseaddr of your device */
#define __PLIC_INTNUM             64                  /*!< Set to 1 - 64, total interrupt sources of PLIC Unit */

/**
 * \defgroup NMSIS_Core_PLIC_Registers     Register Define and Type Definitions Of PLIC
 * \ingroup NMSIS_Core_Registers
 * \brief   Type definitions and defines for plic registers.
 *
 * @{
 */
/* 32 bits per source */
#define PLIC_PRIORITY_OFFSET                0x0           /*!< PLIC Priority register offset */
#define PLIC_PRIORITY_SHIFT_PER_SOURCE      2             /*!< PLIC Priority register offset shift per source */
/* 1 bit per source (1 address) */
#define PLIC_PENDING_OFFSET                 0x200         /*!< PLIC Pending register offset */
#define PLIC_PENDING_SHIFT_PER_SOURCE       0             /*!< PLIC Pending register offset shift per source */

/* 0x80 per target */
#define PLIC_ENABLE_OFFSET                  0x400         /*!< PLIC Enable register offset */
#define PLIC_ENABLE_SHIFT_PER_TARGET        7             /*!< PLIC Enable register offset shift per target */

#define PLIC_THRESHOLD_OFFSET               0x600         /*!< PLIC Threshold register offset */
#define PLIC_CLAIM_OFFSET                   0x604         /*!< PLIC Claim register offset */
#define PLIC_THRESHOLD_SHIFT_PER_TARGET     12            /*!< PLIC Threshold register offset shift per target */
#define PLIC_CLAIM_SHIFT_PER_TARGET         12            /*!< PLIC Claim register offset shift per target */
/* PLIC Memory mapping of Device */
#define PLIC_BASE                           __PLIC_BASEADDR                            /*!< PLIC Base Address */

/** @} */ /* end of group NMSIS_Core_PLIC_Registers */

/* ##########################   PLIC functions  #################################### */
/**
 * \defgroup   NMSIS_Core_IntExc        Interrupts and Exceptions
 * \brief Functions that manage interrupts and exceptions via the PLIC.
 *
 * @{
 */

/**
 * \brief  Set priority threshold value of plic
 * \details
 * This function set priority threshold value of plic for current hart.
 * \param [in]    thresh    threshold value
 * \remarks
 * \sa
 * - \ref PLIC_GetThreshold
 */
__STATIC_FORCEINLINE void PLIC_SetThreshold(uint32_t thresh)
{
    uint32_t hartid = 0; // __RV_CSR_READ(CSR_MHARTID);
    volatile uint32_t *thresh_reg = (uint32_t *)((PLIC_BASE) + \
                    PLIC_THRESHOLD_OFFSET + (hartid << PLIC_THRESHOLD_SHIFT_PER_TARGET));

    *thresh_reg = thresh;
}

/**
 * \brief  Get priority threshold value of plic
 * \details
 * This function get priority threshold value of plic.
 * \return priority threshold value for current hart
 * \remarks
 * \sa
 * - \ref PLIC_SetThreshold
 */
__STATIC_FORCEINLINE uint32_t PLIC_GetThreshold(void)
{
    uint32_t hartid = 0; // __RV_CSR_READ(CSR_MHARTID);
    volatile uint32_t *thresh_reg = (uint32_t *)((PLIC_BASE) + \
                    PLIC_THRESHOLD_OFFSET + (hartid << PLIC_THRESHOLD_SHIFT_PER_TARGET));

    return (*thresh_reg);
}

/**
 * \brief  Enable interrupt for selected source plic
 * \details
 * This function enable interrupt for selected source plic of current hart.
 * \param [in]    source    interrupt source
 * \remarks
 * \sa
 * - \ref PLIC_DisableInterrupt
 */
__STATIC_FORCEINLINE void PLIC_EnableInterrupt(uint32_t source)
{
    uint32_t hartid = 0; // __RV_CSR_READ(CSR_MHARTID);
    volatile uint32_t *enable_reg = (uint32_t *)((PLIC_BASE) + PLIC_ENABLE_OFFSET + \
                    (hartid << PLIC_ENABLE_SHIFT_PER_TARGET) + (source >> 5) * 4);

    uint32_t current = *enable_reg;
    current = current | (1<<(source&0x1F));
    *enable_reg = current;
}

/**
 * \brief  Disable interrupt for selected source plic
 * \details
 * This function disable interrupt for selected source plic of current hart.
 * \param [in]    source    interrupt source
 * \remarks
 * \sa
 * - \ref PLIC_EnableInterrupt
 */
__STATIC_FORCEINLINE void PLIC_DisableInterrupt(uint32_t source)
{
    uint32_t hartid = 0; // __RV_CSR_READ(CSR_MHARTID);
    volatile uint32_t *enable_reg = (uint32_t *)((PLIC_BASE) + PLIC_ENABLE_OFFSET + \
                    (hartid << PLIC_ENABLE_SHIFT_PER_TARGET) + (source >> 5) * 4);

    uint32_t current = *enable_reg;
    current = current & (~(1<<(source&0x1F)));
    *enable_reg = current;
}

/**
 * \brief  Get interrupt enable status for selected source plic
 * \details
 * This function get interrupt enable for selected source plic of current hart.
 * \param [in]    source    interrupt source
 * \return enable status for selected interrupt source for current hart
 * \remarks
 * \sa
 * - \ref PLIC_EnableInterrupt
 * - \ref PLIC_DisableInterrupt
 */
__STATIC_FORCEINLINE uint32_t PLIC_GetInterruptEnable(uint32_t source)
{
    uint32_t hartid = 0; // __RV_CSR_READ(CSR_MHARTID);
    volatile uint32_t *enable_reg = (uint32_t *)((PLIC_BASE) + PLIC_ENABLE_OFFSET + \
                    (hartid << PLIC_ENABLE_SHIFT_PER_TARGET) + (source >> 5) * 4);

    uint32_t current = *enable_reg;
    current = current >> (source&0x1F);
    return current;
}

/**
 * \brief  Set interrupt priority for selected source plic
 * \details
 * This function set interrupt priority for selected source plic of current hart.
 * \param [in]    source    interrupt source
 * \param [in]    priority  interrupt priority
 * \remarks
 * \sa
 * - \ref PLIC_GetPriority
 */
__STATIC_FORCEINLINE void PLIC_SetPriority(uint32_t source, uint32_t priority)
{
    volatile uint32_t *priority_reg = (uint32_t *)((PLIC_BASE) + PLIC_PRIORITY_OFFSET + \
                    + (source << PLIC_PRIORITY_SHIFT_PER_SOURCE));

    *priority_reg = priority;
}

/**
 * \brief  Get interrupt priority for selected source plic
 * \details
 * This function get interrupt priority for selected source plic of current hart.
 * \param [in]    source    interrupt source
 * \param [in]    priority  interrupt priority
 * \remarks
 * \sa
 * - \ref PLIC_SetPriority
 */
__STATIC_FORCEINLINE uint32_t PLIC_GetPriority(uint32_t source)
{
    volatile uint32_t *priority_reg = (uint32_t *)((PLIC_BASE) + PLIC_PRIORITY_OFFSET + \
                    + (source << PLIC_PRIORITY_SHIFT_PER_SOURCE));

    return (*priority_reg);
}

/**
 * \brief  Claim interrupt for plic of current hart
 * \details
 * This function claim interrupt for plic of current hart.
 * \return  the ID of the highest priority pending interrupt or
 *      zero if there is no pending interrupt
 * \remarks
 * A successful claim will also atomically clear the corresponding pending bit
 * on the interrupt source. The PLIC can perform a claim at any time and the
 * claim operation is not affected by the setting of the priority threshold register.
 * \sa
 * - \ref PLIC_CompleteInterrupt
 */
__STATIC_FORCEINLINE uint32_t PLIC_ClaimInterrupt(void)
{
    uint32_t hartid = 0; // __RV_CSR_READ(CSR_MHARTID);
    volatile uint32_t *claim_reg = (volatile uint32_t *)((PLIC_BASE) + PLIC_CLAIM_OFFSET + \
                    + (hartid << PLIC_CLAIM_SHIFT_PER_TARGET));

    return (*claim_reg);
}

/**
 * \brief  Complete interrupt for plic of current hart
 * \details
 * This function complete interrupt for plic of current hart.
 * \return  the ID of the highest priority pending interrupt or
 *      zero if there is no pending interrupt
 * \remarks
 * The PLIC signals it has completed executing an interrupt handler by writing
 * the interrupt ID it received from the claim to the claim/complete register.
 * The PLIC does not check whether the completion ID is the same as the last
 * claim ID for that target.
 * If the completion ID does not match an interrupt source that is currently
 * enabled for the target, the completion is silently ignored.
 * \sa
 * - \ref PLIC_ClaimInterrupt
 */
__STATIC_FORCEINLINE void PLIC_CompleteInterrupt(uint32_t source)
{
    uint32_t hartid = 0; // __RV_CSR_READ(CSR_MHARTID);
    volatile uint32_t *complete_reg = (uint32_t *)((PLIC_BASE) + PLIC_CLAIM_OFFSET + \
                    + (hartid << PLIC_CLAIM_SHIFT_PER_TARGET));

    *complete_reg = source;
}

#ifdef __cplusplus
}
#endif
#endif /** __CORE_FEATURE_PLIC__ */
