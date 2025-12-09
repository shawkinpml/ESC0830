/**********************************************************************
* $Id$		hm_nvic.h			2021-09-29
*//**
* @file		hm_nvic.h
* @brief	Contains all expansion functions support for Nesting 
*			Vectored Interrupt Controller (NVIC) firmware library 
*			on HM3C1788,HM4C123,HM3S9B96. The main NVIC functions are defined 
*			in core_cm3.h
* @version	0.01
* @date		29. Sept. 2021
* @author	PML MCU SW Application Team
* 
* Copyright(C) 2024, Purple Moutain Laboratories
* All rights reserved.
*
***********************************************************************
*
**********************************************************************/


/* Peripheral group ----------------------------------------------------------- */
/** @defgroup NVIC NVIC (Nested Vectored Interrupt Controller)
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_NVIC_H_
#define __HM_NVIC_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"

#ifdef __cplusplus
extern "C"
{
#endif


/* Public Functions ----------------------------------------------------------- */
/** @defgroup NVIC_Public_Functions NVIC Public Functions
 * @{
 */

void NVIC_DeInit(void);
void NVIC_SCBDeInit(void);
void NVIC_SetVTOR(uint32_t offset);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __HM_NVIC_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
