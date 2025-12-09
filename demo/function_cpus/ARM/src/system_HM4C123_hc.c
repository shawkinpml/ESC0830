/**********************************************************************
* $Id$		system_HM4C123.c			2021-09-17
*//**
* @file		system_HM4C123.c
* @brief	CMSIS Cortex-M3 Device Peripheral Access Layer Source File
*          	for the PML Device Series
*
*
* @version	1.0
* @date		06. Nov. 2021
* @author	PML MCU SW Application Team
* 
* Copyright(C) 2024, Purple Moutain Laboratories
* All rights reserved.
*
***********************************************************************
**********************************************************************/

#include <stdint.h>
#include "hm_libcfg_default.h"
#include "system_HM4C123.h"
#include "io_arm.h"
#include "driver_common.h"
 
void SystemInit (void)
{
#ifdef BOOTMODE
	__enable_irq();
	return;
#endif
  //  extern void Resource_Init(void);
   Resource_Init();
}


/**
 * @}
 */

/**
 * @}
 */
