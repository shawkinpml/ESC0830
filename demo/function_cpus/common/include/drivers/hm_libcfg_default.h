/**********************************************************************
* $Id$		hm_libcfg.h			2021-09-29
***
* @file		hm_libcfg.h
* @brief	Library configuration file
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

#ifndef _HM_LIBCFG_H_
#define _HM_LIBCFG_H_

#include "hm_types.h"

#define CHIP_SEL_ESC0830
// #define CHIP_SEL_ESC0820

// #define PLL_120M
// #define PLL_80M
// typedef enum {
//   PLL_NONE = 0,
//   PLL_NONE = 1,
//   PLL_80M = 1,
//   PLL_120M = 2
// } unsigned;

#ifdef CHIP_SEL_ESC0830
#include "HM4C123.h"
#include "_HM4C123_EMAC.h"
#include "core_cm4.h"
#endif

#ifdef CHIP_SEL_ESC0820
#include "HM3S9B96.h"
#include "_HM3S9B96_EMAC.h"
#include "core_cm3.h"
#endif

/************************** DEBUG MODE DEFINITIONS *********************************/
/* Un-comment the line below to compile the library in DEBUG mode, this will expanse
   the "CHECK_PARAM" macro in the FW library code */

#define DEBUG

/* BOOT Config -------------------- */
#define BOOT_FROM_SRAM					(0)
// #define USER_FLASH_START				(0x00000000)
// #define FUNCBOOT_START					(0x000FC800)
// #define USER_SRAM_START					(0x00100000)
#define USER_SRAM_START					(0x10000000) // boot from flash, so this addr isn't used

/******************* PERIPHERAL FW LIBRARY CONFIGURATION DEFINITIONS ***********************/

/* Comment the line below to disable the specific peripheral inclusion */

/* DEBUG_FRAMWORK -------------------- */
#define _DBGFWK

/* Clock & Power -------------------- */
#define _CLKPWR


/* GPIO ------------------------------- */
#define _GPIO

/* NVIC ------------------------------- */
#define _NVIC


/* EXTI ------------------------------- */
//#define _EXTI

/* EMC ------------------------------- */
//#define _EMC

/* UART ------------------------------- */
#define _UART

/* SPI ------------------------------- */
#define _SPI

/* SYSTICK --------------------------- */
#define _SYSTICK

/* SSP ------------------------------- */
#define _SSP


/* I2C ------------------------------- */
#define _I2C

/* TIMER ------------------------------- */
#define _TIM

/* WDT ------------------------------- */
#define _WDT


/* UDMA ------------------------------- */
#define _UDMA

/* ADC ------------------------------- */
#define _ADC


/* PWM ------------------------------- */
#define _PWM

/* RTC ------------------------------- */
#define _RTC

/* I2S ------------------------------- */
#define _I2S

/* USB device ------------------------------- */
#define _USBDEV
#ifdef _USBDEV
#define _USB_DEV_AUDIO
#define _USB_DEV_MASS_STORAGE
#define _USB_DEV_HID
#define _USB_DEV_VIRTUAL_COM
#endif /*_USBDEV*/

/* USB Host ------------------------------- */
#define _USBHost

/* QEI ------------------------------- */
#define _QEI

/* MCPWM ------------------------------- */
//#define _MCPWM

/* CAN--------------------------------*/
#define _CAN

/* EMAC ------------------------------ */
#define _EMAC

/* LCD ------------------------------ */
//#define _LCD

/* MCI ------------------------------ */
//#define _MCI

/* IAP------------------------------ */
#define _IAP

/* BOD------------------------------ */
//#define _BOD

/* FLASH------------------------------ */
#define _FLASH

/* COMP------------------------------ */
#define _COMP

/* EEPROM------------------------------ */
#define _EEPROM

/************************** GLOBAL/PUBLIC MACRO DEFINITIONS *********************************/


#endif /* _HM3C1788,HM4C123,HM3S9B96_LIBCFG_H_ */
