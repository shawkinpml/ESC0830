/**********************************************************************
* $Id$		hm_clkpwr.h			2021-09-29
*//**
* @file		hm_clkpwr.h
* @brief	Contains all functions support for CLKPWR firmware library on
*			HM3C1788,HM4C123,HM3S9B96
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
/** @defgroup CLKPWR	CLKPWR (Clock Power)
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_CLKPWR_H_
#define __HM_CLKPWR_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"

#ifdef CHIP_SELECT_HM3C1788
#include "system_HM3C1788.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/* Public Macros -------------------------------------------------------------- */
/** @defgroup CLKPWR_Public_Macros CLKPWR Public Macros
 * @{
 */

/********************************************************************
* Clock Source Selection Definitions
**********************************************************************/
#define CLKPWR_CLKSRCSEL_IRCOSC		((uint32_t)(0))
#define CLKPWR_CLKSRCSEL_MAINOSC	((uint32_t)(1))

/********************************************************************
* Clock type/domain Definitions (calculated from input and pre-configuration
* parameter(s)
**********************************************************************/
#define CLKPWR_CLKTYPE_CPU			((uint32_t)(0))
#define CLKPWR_CLKTYPE_PER			((uint32_t)(1))
#define CLKPWR_CLKTYPE_EMC			((uint32_t)(2))
#define CLKPWR_CLKTYPE_USB			((uint32_t)(3))

/********************************************************************
* Power Control for Peripherals Definitions
**********************************************************************/
/** LCD controller power/clock control bit */
#define CLKPWR_PCONP_PCLCD		((uint32_t)(1<<0))

/** Timer/Counter 0 power/clock control bit */
#define	CLKPWR_PCONP_PCTIM0		((uint32_t)(1<<1))

/* Timer/Counter 1 power/clock control bit */
#define	CLKPWR_PCONP_PCTIM1		((uint32_t)(1<<2))

/** UART0 power/clock control bit */
#define	CLKPWR_PCONP_PCUART0  	((uint32_t)(1<<3))

/** UART1 power/clock control bit */
#define	CLKPWR_PCONP_PCUART1  	((uint32_t)(1<<4))

/** PWM0 power/clock control bit */
#define CLKPWR_PCONP_PCPWM0		((uint32_t)(1<<5))

/** PWM1 power/clock control bit */
#define	CLKPWR_PCONP_PCPWM1		((uint32_t)(1<<6))

/** The I2C0 interface power/clock control bit */
#define	CLKPWR_PCONP_PCI2C0		((uint32_t)(1<<7))

/** UART4 power/clock control bit */
#define CLKPWR_PCONP_PCUART4	((uint32_t)(1<<8))

/** The RTC power/clock control bit */
#define	CLKPWR_PCONP_PCRTC  	((uint32_t)(1<<9))

/** The SSP1 interface power/clock control bit */
#define	CLKPWR_PCONP_PCSSP1	 	((uint32_t)(1<<10))

/** External Memory controller power/clock control bit */
#define CLKPWR_PCONP_PCEMC		((uint32_t)(1<<11))

/** A/D converter 0 (ADC0) power/clock control bit */
#define	CLKPWR_PCONP_PCADC  	((uint32_t)(1<<12))

/** CAN Controller 1 power/clock control bit */
#define	CLKPWR_PCONP_PCAN1  	((uint32_t)(1<<13))

/** CAN Controller 2 power/clock control bit */
#define	CLKPWR_PCONP_PCAN2 	((uint32_t)(1<<14))

/** GPIO power/clock control bit */
#define	CLKPWR_PCONP_PCGPIO 	((uint32_t)(1<<15))

/** D/A converter 0 (DAC) power/clock control bit */
#define	CLKPWR_PCONP_PCDAC  	((uint32_t)(1<<16))

/** Motor Control PWM */
#define CLKPWR_PCONP_PCMCPWM 	((uint32_t)(1<<17))

/** Quadrature Encoder Interface power/clock control bit */
#define CLKPWR_PCONP_PCQEI 		((uint32_t)(1<<18))

/** The I2C1 interface power/clock control bit */
#define	CLKPWR_PCONP_PCI2C1  	((uint32_t)(1<<19))

/** The SSP2 interface power/clock control bit */
#define CLKPWR_PCONP_PCSSP2		((uint32_t)(1<<20))

/** The SSP0 interface power/clock control bit */
#define	CLKPWR_PCONP_PCSSP0		((uint32_t)(1<<21))

/** Timer 2 power/clock control bit */
#define	CLKPWR_PCONP_PCTIM2	((uint32_t)(1<<22))

/** Timer 3 power/clock control bit */
#define	CLKPWR_PCONP_PCTIM3	((uint32_t)(1<<23))

/** UART 2 power/clock control bit */
#define	CLKPWR_PCONP_PCUART2  	((uint32_t)(1<<24))

/** UART 3 power/clock control bit */
#define	CLKPWR_PCONP_PCUART3  	((uint32_t)(1<<25))

/** I2C interface 2 power/clock control bit */
#define	CLKPWR_PCONP_PCI2C2	((uint32_t)(1<<26))

/** I2S interface power/clock control bit*/
#define	CLKPWR_PCONP_PCI2S  	((uint32_t)(1<<27))

/** SD card interface power/clock control bit */
#define CLKPWR_PCONP_PCSDC		((uint32_t)(1<<28))

/** GP DMA function power/clock control bit*/
#define	 CLKPWR_PCONP_PCGPDMA  	((uint32_t)(1<<29))

/** Ethernet block power/clock control bit*/
#define	 CLKPWR_PCONP_PCENET	((uint32_t)(1<<30))

/** USB interface power/clock control bit*/
#define	 CLKPWR_PCONP_PCUSB  	((uint32_t)(1<<31))

/********************************************************************
* Power Control for Peripherals Definitions
**********************************************************************/
#define CLKPWR_RSTCON0_LCD		((uint32_t)(0))
#define CLKPWR_RSTCON0_TIM0		((uint32_t)(1))
#define CLKPWR_RSTCON0_TIM1		((uint32_t)(2))
#define CLKPWR_RSTCON0_UART0	((uint32_t)(3))
#define CLKPWR_RSTCON0_UART1	((uint32_t)(4))
#define CLKPWR_RSTCON0_PWM0		((uint32_t)(5))
#define CLKPWR_RSTCON0_PWM1		((uint32_t)(6))
#define CLKPWR_RSTCON0_I2C0		((uint32_t)(7))
#define CLKPWR_RSTCON0_UART4	((uint32_t)(8))
#define CLKPWR_RSTCON0_RTC		((uint32_t)(9))
#define CLKPWR_RSTCON0_SSP1		((uint32_t)(10))
#define CLKPWR_RSTCON0_EMC		((uint32_t)(11))
#define CLKPWR_RSTCON0_ADC		((uint32_t)(12))
#define CLKPWR_RSTCON0_CAN1		((uint32_t)(13))
#define CLKPWR_RSTCON0_CAN2		((uint32_t)(14))
#define CLKPWR_RSTCON0_GPIO		((uint32_t)(15))
#define CLKPWR_RSTCON0_MCPWM	((uint32_t)(17))
#define CLKPWR_RSTCON0_QEI		((uint32_t)(18))
#define CLKPWR_RSTCON0_I2C1		((uint32_t)(19))
#define CLKPWR_RSTCON0_SSP2		((uint32_t)(20))
#define CLKPWR_RSTCON0_SSP0		((uint32_t)(21))
#define CLKPWR_RSTCON0_TIM2		((uint32_t)(22))
#define CLKPWR_RSTCON0_TIM3		((uint32_t)(23))
#define CLKPWR_RSTCON0_UART2	((uint32_t)(24))
#define CLKPWR_RSTCON0_UART3	((uint32_t)(25))
#define CLKPWR_RSTCON0_I2C2		((uint32_t)(26))
#define CLKPWR_RSTCON0_I2S		((uint32_t)(27))
#define CLKPWR_RSTCON0_SDC		((uint32_t)(28))
#define CLKPWR_RSTCON0_GPDMA	((uint32_t)(29))
#define CLKPWR_RSTCON0_ENET		((uint32_t)(30))
#define CLKPWR_RSTCON0_USB		((uint32_t)(31))

#define CLKPWR_RSTCON1_IOCON	((uint32_t)(32))
#define CLKPWR_RSTCON1_DAC		((uint32_t)(33))
#define CLKPWR_RSTCON1_CANACC	((uint32_t)(34))
#define CLKPWR_RSTCON1_MACPHY	((uint32_t)(35))
#define CLKPWR_RSTCON1_CRC		((uint32_t)(36))
#define CLKPWR_RSTCON_NUM		((uint32_t)(37))

/**
 * @}
 */
 
/* External clock variable from system_hm_libcfg_default.h */
extern uint32_t SystemCoreClock;     /*!< System Clock Frequency (Core Clock)  	*/
extern uint32_t PeripheralClock;	 /*!< Peripheral Clock Frequency (Pclk) 	*/
extern uint32_t EMCClock;		 /*!< EMC Clock Frequency                   	*/

/* External clock variable from hm_clkpwr.h */
extern uint32_t USBClock;		/*!< USB Frequency 								*/

/* Public Functions ----------------------------------------------------------- */
/** @defgroup CLKPWR_Public_Functions CLKPWR Public Functions
 * @{
 */

void CLKPWR_SetCLKDiv(uint8_t ClkType, uint8_t DivVal);
uint32_t CLKPWR_GetCLK(uint8_t ClkType);
void CLKPWR_ConfigPPWR(uint32_t PPType, FunctionalState NewState);
void CLKPWR_ConfigReset(uint8_t PType, FunctionalState NewState);
void CLKPWR_Sleep(void);
void CLKPWR_DeepSleep(void);

/**
 * @}
 */


#ifdef __cplusplus
}
#endif

#endif /* __HM_CLKPWR_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
