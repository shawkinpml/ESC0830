/**********************************************************************
* $Id$		system_HM3C1788.h			2021-09-17
*//**
* @file		system_HM3C1788.h
* @brief	CMSIS Cortex-M3 Device Peripheral Access Layer Source File
*			for the HM3C HM3C1788 Device Series
* @version	1.0
* @date		17. Sept. 2021
* @author	PML MCU SW Application Team
* 
* Copyright(C) 2021, PML 
* All rights reserved.
*
***********************************************************************
*
**********************************************************************/

#ifndef __SYSTEM_HM3C1788_H
#define __SYSTEM_HM3C1788_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/** @addtogroup HM3C1788_System
 * @{
 */
extern uint32_t SystemCoreClock;      /*!< System Clock Frequency (Core Clock)  	*/
extern uint32_t PeripheralClock;	    /*!< Peripheral Clock Frequency (Pclk) 	    */
extern uint32_t EMCClock;			        /*!< EMC Clock                              */
extern uint32_t USBClock;			        /*!< USB Frequency 						              */


/**
 * Initialize the system
 *
 * @param  none
 * @return none
 *
 * @brief  Setup the microcontroller system.
 *         Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);

/**
 * Update SystemCoreClock variable
 *
 * @param  none
 * @return none
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define XTAL        (12000000UL)        /* Oscillator frequency               */
#define OSC_CLK     (      XTAL)        /* Main oscillator frequency          */
#define RTC_CLK     (   32768UL)        /* RTC oscillator frequency           */
#define IRC_OSC     (12000000UL)        /* Internal RC oscillator frequency   */
#define WDT_OSC		  (  500000UL)		/* Internal WDT oscillator frequency  */



/*
//-------- <<< end of configuration section >>> ------------------------------
*/

#ifdef __cplusplus
}
#endif

/**
 * @}
 */
#endif /* __SYSTEM_HM3C1788_H */
