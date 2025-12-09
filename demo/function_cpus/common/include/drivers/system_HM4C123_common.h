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
#ifndef SYSTEM_C123_COMMON_H
#define SYSTEM_C123_COMMON_H

#include <stdint.h>
#include "hm_libcfg_default.h"
#include "system_HM4C123.h"

/** @addtogroup HM4C123_System
 * @{
 */
 
#define __CLK_DIV(x,y) (((y) == 0) ? 0: (x)/(y))

/*

*/

/** @addtogroup HM4C123_System_Defines  HM4C123 System Defines
  @{
 */
#ifdef BOOTMODE
#define CLOCK_SETUP           0
#else
#define CLOCK_SETUP           1
#endif

#define SCS_Val               0x00000020
#define CLKSRCSEL_Val         0x00000001
#define PLL0_SETUP            1
#define PLL0CFG_Val           0x00000009
#define PLL1_SETUP            1
#define PLL1CFG_Val           0x00000023
#define CCLKSEL_Val           0x00000101
#define USBCLKSEL_Val         0x00000072
#define EMCCLKSEL_Val         0x00000001
#define LCDCLKSEL_Val         0x00000001
#define PCLKSEL_Val           0x00000002
#define PCONP_Val             0x042887DE
#define CLKOUTCFG_Val         0x00000100

/*--------------------- Flash Accelerator Configuration ----------------------
//
//	<e>	Flash Accelerator Configuration register (FLASHCFG - address 0x400F C000)
//		<o1.12..15>	FLASHTIM: Flash Access Time
//					<0=>	1 CPU clock (for CPU clock up to 20 MHz)
//					<1=>	2 CPU clocks (for CPU clock up to 40 MHz)
//					<2=>	3 CPU clocks (for CPU clock up to 60 MHz)
//					<3=>	4 CPU clocks (for CPU clock up to 80 MHz)
//					<4=>	5 CPU clocks (for CPU clock up to 100 MHz)
//					<5=>	6 CPU clocks (for CPU clock up to 120 MHz)
//	</e>
*/

#define FLASH_SETUP           1
#define FLASHCFG_Val          0x00000015

/*
//-------- <<< end of configuration section >>> ------------------------------
*/


/*----------------------------------------------------------------------------
  Check the register settings
 *----------------------------------------------------------------------------*/
#define CHECK_RANGE(val, min, max)                ((val < min) || (val > max))
#define CHECK_RSVD(val, mask)                     (val & mask)

/* Clock Configuration -------------------------------------------------------*/
#if (CHECK_RSVD((SCS_Val),       ~0x0000003F))
   #error "SCS: Invalid values of reserved bits!"
#endif

#if (CHECK_RANGE((CLKSRCSEL_Val), 0, 1))
   #error "CLKSRCSEL: Value out of range!"
#endif

#if (CHECK_RSVD((PLL0CFG_Val),   ~0x0000007F))
   #error "PLL0CFG: Invalid values of reserved bits!"
#endif

#if (CHECK_RSVD((PLL1CFG_Val),   ~0x0000007F))
   #error "PLL1CFG: Invalid values of reserved bits!"
#endif

#if (CHECK_RSVD((CCLKSEL_Val),   ~0x0000011F))
   #error "CCLKSEL: Invalid values of reserved bits!"
#endif

#if (CHECK_RSVD((USBCLKSEL_Val), ~0x000000FF))
   #error "USBCLKSEL: Invalid values of reserved bits!"
#endif

#if (CHECK_RSVD((EMCCLKSEL_Val), ~0x00000001))
   #error "EMCCLKSEL: Invalid values of reserved bits!"
#endif

#if (CHECK_RSVD((PCLKSEL_Val), ~0x0000001F))
   #error "PCLKSEL: Invalid values of reserved bits!"
#endif

#if (CHECK_RSVD((PCONP_Val), ~0xFFFEFFFF))
   #error "PCONP: Invalid values of reserved bits!"
#endif

#if (CHECK_RSVD((CLKOUTCFG_Val), ~0x000001FF))
   #error "CLKOUTCFG: Invalid values of reserved bits!"
#endif

/* Flash Accelerator Configuration -------------------------------------------*/
#if (CHECK_RSVD((FLASHCFG_Val), ~0x000000FF))
   #warning "FLASHCFG: Invalid values of reserved bits!"
#endif


/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/
/* pll_out_clk = F_cco / (2 × P)
   F_cco = pll_in_clk × M × 2 × P */
#define __M                   ((PLL0CFG_Val & 0x1F) + 1)
#define __PLL0_CLK(__F_IN)    (__F_IN * __M)
#define __CCLK_DIV            (CCLKSEL_Val & 0x1F)
#define __PCLK_DIV			  (PCLKSEL_Val & 0x1F)
#define __ECLK_DIV			  ((EMCCLKSEL_Val & 0x01) + 1)

/* Determine core clock frequency according to settings */
#if (CLOCK_SETUP)                       /* Clock Setup                        */

  #if ((CLKSRCSEL_Val & 0x01) == 1) && ((SCS_Val & 0x20)== 0)
   #error "Main Oscillator is selected as clock source but is not enabled!"
  #endif

  #if ((CCLKSEL_Val & 0x100) == 0x100) && (PLL0_SETUP == 0)
   #error "Main PLL is selected as clock source but is not enabled!"
  #endif

  #if ((CCLKSEL_Val & 0x100) == 0)      /* cclk = sysclk */
    #if ((CLKSRCSEL_Val & 0x01) == 0)   /* sysclk = irc_clk */
        #define __CORE_CLK (IRC_OSC / __CCLK_DIV)
		#define __PER_CLK  (IRC_OSC/  __PCLK_DIV)
        #define __EMC_CLK  (__CORE_CLK/  __ECLK_DIV)
    #else                               /* sysclk = osc_clk */
        #define __CORE_CLK (OSC_CLK / __CCLK_DIV)
        #define __PER_CLK  (OSC_CLK/  __PCLK_DIV)
        #define __EMC_CLK  (__CORE_CLK/  __ECLK_DIV)
    #endif
  #else                                 /* cclk = pll_clk */
    #if ((CLKSRCSEL_Val & 0x01) == 0)   /* sysclk = irc_clk */
        #define __CORE_CLK (__PLL0_CLK(IRC_OSC) / __CCLK_DIV)
        #define __PER_CLK  (__PLL0_CLK(IRC_OSC) / __PCLK_DIV)
        #define __EMC_CLK  (__CORE_CLK / __ECLK_DIV)
    #else                               /* sysclk = osc_clk */
        #define __CORE_CLK (__PLL0_CLK(OSC_CLK) / __CCLK_DIV)
        #define __PER_CLK  (__PLL0_CLK(OSC_CLK) / __PCLK_DIV)
		#define __EMC_CLK  (__CORE_CLK / __ECLK_DIV)
    #endif
  #endif

 /**
  * @}
  */
#else
        #define __CORE_CLK (IRC_OSC)
        #define __PER_CLK  (IRC_OSC)
        #define __EMC_CLK  (__CORE_CLK)
#endif
/** @addtogroup HM4C123_System_Public_Variables  HM4C123 System Public Variables
  @{
 */
/*----------------------------------------------------------------------------
  Clock Variable definitions
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock = 80000000UL;/*!< System Clock Frequency (Core Clock)*/
uint32_t PeripheralClock = 40000000UL; /*!< Peripheral Clock Frequency (Pclk)  */
uint32_t EMCClock		 = __EMC_CLK; /*!< EMC Clock Frequency 				  */
uint32_t USBClock 		 = (48000000UL);		  /*!< USB Clock Frequency - this value will
									be updated after call SystemCoreClockUpdate, should be 48MHz*/
/**
 * @}
 */

/** @addtogroup HM4C123_System_Public_Functions  HM4C123 System Public Functions
  @{
 */

void SystemCoreClockUpdate (void);

#endif