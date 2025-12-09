/**********************************************************************
* $Id$		hm_bitband.h			2021-09-28
*//**
* @file		hm_bitband.h
* @brief	Contains all functions support for BITBAND
*			firmware library on HM3C1788,HM4C123,HM3S9B96
* @version	0.01
* @date		28. Sept. 2021
* @author	PML MCU SW Application Team
* 
* Copyright(C) 2024, Purple Moutain Laboratories
* All rights reserved.
*
***********************************************************************
*
**********************************************************************/


/* Peripheral group ----------------------------------------------------------- */
/** @defgroup BITBAND	BITBAND
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_BITBAND_H_
#define __HM_BITBAND_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"


#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup BITBAND_Private_Macros BITBAND Private Macros
 * @{
 */


/* Bit band SRAM definitions */
#define BITBAND_SRAM_REF   0x20000000
#define BITBAND_SRAM_BASE  0x22000000

#define BITBAND_SRAM(a,b) ((BITBAND_SRAM_BASE + ((a-BITBAND_SRAM_REF)<<5) + (b<<2)))  // Convert SRAM address

/* Bit band PERIPHERAL definitions */
#define BITBAND_PERI_REF   0x40000000
#define BITBAND_PERI_BASE  0x42000000

#define BITBAND_PERI(a,b) ((BITBAND_PERI_BASE + ((a-BITBAND_PERI_REF)<<5) + (b<<2)))  // Convert PERI address

/* Basic bit band function definitions */
#define BITBAND_SRAM_ClearBit(a,b)	(*(volatile uint32_t *) (BITBAND_SRAM(a,b)) = 0)
#define BITBAND_SRAM_SetBit(a,b)	(*(volatile uint32_t *) (BITBAND_SRAM(a,b)) = 1)
#define BITBAND_SRAM_GetBit(a,b)	(*(volatile uint32_t *) (BITBAND_SRAM(a,b)))

#define BITBAND_PERI_ClearBit(a,b)	(*(volatile uint32_t *) (BITBAND_PERI(a,b)) = 0)
#define BITBAND_PERI_SetBit(a,b)	(*(volatile uint32_t *) (BITBAND_PERI(a,b)) = 1)
#define BITBAND_PERI_GetBit(a,b)	(*(volatile uint32_t *) (BITBAND_PERI(a,b)))

/**
 * @}
 */


#ifdef __cplusplus
}
#endif

#endif /* __HM_BITBAND_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
