/**************************************************************************//**
 * @file     HM4C123.h
 * @brief    CMSIS Cortex-M4 Core Peripheral Access Layer Header File for
 *           Device HM4C123
 * @version  V0.01
 * @date     11. Sept 2022
 *
 * @note
 * Copyright (C) 2021-2031 PML Limited. All rights reserved.
 *
 * @par
 * PML Limited (PML) is supplying this software for use with Cortex-M
 * processor based microcontrollers.  This file can be freely distributed
 * within development tools that are supporting such ARM based processors.
 *
 * @par
 *
 ******************************************************************************/


#ifndef __HM4C123_H
#define __HM4C123_H

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup CM3DS_MPS2_Definitions HM4C123 Definitions
  This file defines all structures and symbols for HM4C123:
    - registers and bitfields
    - peripheral base address
    - peripheral ID
    - Peripheral definitions
  @{
*/


/******************************************************************************/
/*                Processor and Core Peripherals                              */
/******************************************************************************/
/** @addtogroup CM3DS_MPS2_CMSIS Device CMSIS Definitions
  Configuration of the Cortex-M3 Processor and Core Peripherals
  @{
*/

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */

typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
	NonMaskableInt_IRQn           = -14,    /*!<  2 Cortex-M3 Non Maskable Interrupt                        */
	HardFault_IRQn                = -13,    /*!<  3 Cortex-M3 Hard Fault Interrupt                          */
	MemoryManagement_IRQn         = -12,    /*!<  4 Cortex-M3 Memory Management Interrupt            */
	BusFault_IRQn                 = -11,    /*!<  5 Cortex-M3 Bus Fault Interrupt                    */
	UsageFault_IRQn               = -10,    /*!<  6 Cortex-M3 Usage Fault Interrupt                  */
	SVCall_IRQn                   = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                      */
	DebugMonitor_IRQn             = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                */
	PendSV_IRQn                   = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                      */
	SysTick_IRQn                  = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                  */

	/******  HM4C123 Specific Interrupt Numbers *******************************************************/
	// GPIOA_IRQn                    =   0,              /*!<   0  GPIOA                                                            */
	// GPIOB_IRQn                    =   1,              /*!<   1  GPIOB                                                            */
	SAVE_CONTEXT_IRQ0             =   0,
	PLIC_IRQ1                     =   1,
	GPIOC_IRQn                    =   2,              /*!<   2  GPIOC                                                            */
	GPIOD_IRQn                    =   3,              /*!<   3  GPIOD                                                            */
	GPIOE_IRQn                    =   4,              /*!<   4  GPIOE                                                            */
	UART0_IRQn                    =   5,              /*!<   5  UART0                                                            */
	UART1_IRQn                    =   6,              /*!<   6  UART1                                                            */
	SSI0_IRQn                     =   7,              /*!<   7  SSI0                                                             */
	I2C0_IRQn                     =   8,              /*!<   8  I2C0                                                             */
	PWM0_IRQn               		  =   9,              /*!<   9  PWM0_FAULT                                                       */
	QEI0_IRQn                     =  13,              /*!<  13  QEI0                                                             */
	ADC0SS0_IRQn                  =  14,              /*!<  14  ADC0SS0                                                          */
	ADC0SS1_IRQn                  =  15,              /*!<  15  ADC0SS1                                                          */
	ADC0SS2_IRQn                  =  16,              /*!<  16  ADC0SS2                                                          */
	ADC0SS3_IRQn                  =  17,              /*!<  17  ADC0SS3                                                          */
	WATCHDOG0_IRQn                =  18,              /*!<  18  WATCHDOG0                                                        */
	TIMER0A_IRQn                  =  19,              /*!<  19  TIMER0A                                                          */
	TIMER0B_IRQn                  =  20,              /*!<  20  TIMER0B                                                          */
	TIMER1A_IRQn                  =  21,              /*!<  21  TIMER1A                                                          */
	TIMER1B_IRQn                  =  22,              /*!<  22  TIMER1B                                                          */
	TIMER2A_IRQn                  =  23,              /*!<  23  TIMER2A                                                          */
	TIMER2B_IRQn                  =  24,              /*!<  24  TIMER2B                                                          */
	COMP0_IRQn                    =  25,              /*!<  25  COMP0                                                            */
	COMP1_IRQn                    =  26,              /*!<  26  COMP1                                                            */
	COMP2_IRQn                    =  27,              /*!<  27  COMP2                                                            */	
	GPIOF_IRQn                    =  30,              /*!<  30  GPIOF                                                            */
	GPIOG_IRQn                    =  31,              /*!<  30  GPIOG                                                            */
	GPIOH_IRQn                    =  32,              /*!<  30  GPIOH                                                            */
	UART2_IRQn                    =  33,              /*!<  33  UART2                                                            */
	SSI1_IRQn                     =  34,              /*!<  34  SSI1                                                             */
	TIMER3A_IRQn                  =  35,              /*!<  35  TIMER3A                                                          */
	TIMER3B_IRQn                  =  36,              /*!<  36  TIMER3B                                                          */
	I2C1_IRQn                     =  37,              /*!<  37  I2C1                                                             */
	QEI1_IRQn                     =  38,              /*!<  38  QEI1                                                             */
	CAN0_IRQn                     =  39,              /*!<  39  CAN0                                                             */
	CAN1_IRQn                     =  40,              /*!<  40  CAN1                                                             */
	HIB_LOWV_IRQn                 =  43,              /*!<  43  HIB_LOWV                                                              */
	USB0_IRQn                     =  44,              /*!<  44  USB0                                                             */
	UDMA_IRQn                     =  46,              /*!<  46  UDMA                                                             */

	ADC1SS0_IRQn                  =  48,              /*!<  48  ADC1SS0                                                          */
	ADC1SS1_IRQn                  =  49,              /*!<  49  ADC1SS1                                                          */
	ADC1SS2_IRQn                  =  50,              /*!<  50  ADC1SS2                                                          */
	ADC1SS3_IRQn                  =  51,              /*!<  51  ADC1SS3                                                          */
	GPIOJ_IRQn                    =  54,              /*!<  54  GPIOJ                                                            */
	GPIOK_IRQn                    =  55,              /*!<  55  GPIOK                                                            */
	GPIOL_IRQn                    =  56,              /*!<  56  GPIOL                                                            */

	SSI2_IRQn                     =  57,              /*!<  57  SSI2                                                             */
	SSI3_IRQn                     =  58,              /*!<  58  SSI3                                                             */
	UART3_IRQn                    =  59,              /*!<  59  UART3                                                            */
	UART4_IRQn                    =  60,              /*!<  60  UART4                                                            */
	UART5_IRQn                    =  61,              /*!<  61  UART5                                                            */
	UART6_IRQn                    =  62,              /*!<  62  UART6                                                            */
	UART7_IRQn                    =  63,              /*!<  63  UART7                                                            */

	WATCHDOG1_IRQn                =  66,              /*!<  66   WATCHDOG1                                                        */
	I2C2_IRQn                     =  68,              /*!<  68  I2C2                                                             */
	I2C3_IRQn                     =  69,              /*!<  69  I2C3                                                             */
	TIMER4A_IRQn                  =  70,              /*!<  70  TIMER4A                                                          */
	TIMER4B_IRQn                  =  71,              /*!<  71  TIMER4B                                                          */
	
	ADC0_0_IRQn                   =  72,              /*!<  72  ADC0_0                                                          */
	ADC0_1_IRQn                   =  73,              /*!<  73  ADC0_1                                                          */
	ADC0_2_IRQn                   =  74,              /*!<  74  ADC0_2                                                          */
	ADC0_3_IRQn                   =  75,              /*!<  75  ADC0_3                                                          */
	ADC1_0_IRQn                   =  76,              /*!<  76  ADC1_0                                                          */
	ADC1_1_IRQn                   =  77,              /*!<  77  ADC1_1                                                          */
	ADC1_2_IRQn                   =  78,              /*!<  78  ADC1_2                                                          */
	ADC1_3_IRQn                   =  79,              /*!<  79  ADC1_3                                                          */

	PLL0LOCK_IRQn                 =  80,              /*!<  80  PLL0LOCK                                                         */
	PLL1LOCK_IRQn                 =  81,              /*!<  81  PLL1LOCK                                                         */
	USBPHY_IRQn                   =  82,              /*!<  82  USBPHY                                                         */
	BORIOR_IRQn                   =  83,              /*!<  83  BORIOR                                                         */
	MOSC_IRQn                     =  84,              /*!<  84  MOSC                                                         */
	HIB_WEAK_IRQn                 =  85,              /*!<  85  HIB_WAKE                                                         */
	HIB_RTC_IRQn                  =  86,              /*!<  86  HIB_RTC                                                         */

	
	TIMER5A_IRQn                  =  92,              /*!<  92  TIMER5A                                                          */
	TIMER5B_IRQn                  =  93,              /*!<  93  TIMER5B                                                          */
	WTIMER0A_IRQn                 =  94,              /*!<  94  WTIMER0A                                                         */
	WTIMER0B_IRQn                 =  95,              /*!<  95  WTIMER0B                                                         */
	WTIMER1A_IRQn                 =  96,              /*!<  96  WTIMER1A                                                         */
	WTIMER1B_IRQn                 =  97,              /*!<  97  WTIMER1B                                                         */
	WTIMER2A_IRQn                 =  98,              /*!<  98  WTIMER2A                                                         */
	WTIMER2B_IRQn                 =  99,              /*!<  99  WTIMER2B                                                         */
	WTIMER3A_IRQn                 = 100,              /*!< 100  WTIMER3A                                                         */
	WTIMER3B_IRQn                 = 101,              /*!< 101  WTIMER3B                                                         */
	WTIMER4A_IRQn                 = 102,              /*!< 102  WTIMER4A                                                         */
	WTIMER4B_IRQn                 = 103,              /*!< 103  WTIMER4B                                                         */
	WTIMER5A_IRQn                 = 104,              /*!< 104  WTIMER5A                                                         */
	WTIMER5B_IRQn                 = 105,              /*!< 105  WTIMER5B                                                         */
	FPU_IRQn                      = 106,              /*!< 106  FPU                                                          */

	I2C4_IRQn                     = 109,              /*!<    I2C4                                                             */
	I2C5_IRQn                     = 110,              /*!<    I2C5                                                             */
	GPIOM_IRQn                    = 111,              /*!< 111  GPIOM                                                            */
	GPION_IRQn                    = 112,              /*!< 112  GPION                                                            */
	GPIOP_IRQn                    = 116,              /*!< 116  GPIOP                                                            */
	PWM1_IRQn               	  = 117               /*!< 117  PWM1_                                                       */

} IRQn_Type;


/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M3 Processor and Core Peripherals */
#define __CM3_REV                 0x0201    /*!< Core Revision r2p1                             */
#define __NVIC_PRIO_BITS          3         /*!< Number of Bits used for Priority Levels        */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used   */
#define __MPU_PRESENT             1         /*!< MPU present or not                             */

/*@}*/ /* end of group CM3DS_MPS2_CMSIS */


#include "core_cm4.h"                     /* Cortex-M4 processor and core peripherals           */
#include "system_HM4C123.h"             /* CM3DS System include file                      */


/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/
/** @addtogroup CM3DS_MPS2_Peripherals CM3DS_MPS2 Peripherals
  CM3DS_MPS2 Device Specific Peripheral registers structures
  @{
*/

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif


/*------------- System Control (SC) ------------------------------------------*/
/** @brief System Control (SC) register structure definition */
typedef struct
{
	__IO uint32_t  DEVICEID;							  /*!< Offset: 0x000 (R/W)   Device Identification 0												 */
			 uint32_t  RESERVED0[11];
	__IO uint32_t  PTEMP1;
			 uint32_t  RESERVED1[7];
	__IO uint32_t  PTEMP2;
	__IO uint32_t  PTEMP3;
	__IO uint32_t  PTEMP4;
	__IO uint32_t  RESC;							  /*!< Offset: 0x05C (R/W) Reset Cause															 */
			 uint32_t  RESERVED2[7];
	__IO uint32_t  MOSCCTL; 						  /*!< Offset: 0x07C (R/W)  Main Oscillator Control												 */
			 uint32_t  RESERVED3[288];
	__IO uint32_t  SRWD;							  /*!< Offset: 0x500 (R/W)  Offset: 0x500 (R/W)  Watchdog Timer Software Reset										 */
	__IO uint32_t  SRTIMER; 						  /*!< Offset: 0x000 (R/W)  16/32-Bit General-Purpose Timer Software Reset						 */
	__IO uint32_t  SRGPIO;							  /*!< Offset: 0x000 (R/W)  General-Purpose Input/Output Software Reset							 */
	__IO uint32_t  SRDMA;							  /*!< Offset: 0x50C (R/W)  Micro Direct Memory Access Software Reset							 */
			 uint32_t  RESERVED31;
	__IO uint32_t  SRHIB;							  /*!< Offset: 0x514 (R/W)  Hibernation Software Reset											 */
	__IO uint32_t  SRUART;							  /*!< Offset: 0x000 (R/W)  Universal Asynchronous Receiver/Transmitter Software Reset			 */
	__IO uint32_t  SRSSI;							  /*!< Offset: 0x000 (R/W)  Synchronous Serial Interface Software Reset							 */
	__IO uint32_t  SRI2C;							  /*!< Offset: 0x520 (R/W)  Inter-Integrated Circuit Software Reset								 */
			 uint32_t  RESERVED4;
	__IO uint32_t  SRUSB;							  /*!< Offset: 0x528 (R/W)  Universal Serial Bus Software Reset									 */
			 uint32_t  RESERVED5[2];
	__IO uint32_t  SRCAN;							  /*!< Offset: 0x534 (R/W)  Controller Area Network Software Reset								 */
	__IO uint32_t  SRADC;							  /*!< Offset: 0x000 (R/W)  Analog-to-Digital Converter Software Reset							 */
	__IO uint32_t  SRACMP;							  /*!< Offset: 0x000 (R/W)  Analog Comparator Software Reset 									 */
	__IO uint32_t  SRPWM;							  /*!< Offset: 0x000 (R/W)  Pulse Width Modulator Software Reset 								 */
	__IO uint32_t  SRQEI;							  /*!< Offset: 0x544 (R/W)  Quadrature Encoder Interface Software Reset							 */
			 uint32_t  RESERVED6[5];
	__IO uint32_t  SRWTIMER;							  /*!< Offset: 0x55C (R/W)  						 */
			 uint32_t  RESERVED7[40];
	__IO uint32_t  RCGCWD;							  /*!< Offset: 0x600 (R/W)  Watchdog Timer Run Mode Clock Gating Control 						 */
	__IO uint32_t  RCGCTIMER;						  /*!< Offset: 0x000 (R/W)  16/32-Bit General-Purpose Timer Run Mode Clock Gating Control		 */
	__IO uint32_t  RCGCGPIO;						  /*!< Offset: 0x000 (R/W)  General-Purpose Input/Output Run Mode Clock Gating Control			 */
	__IO uint32_t  RCGCDMA; 						  /*!< Offset: 0x000 (R/W)  Micro Direct Memory Access Run Mode Clock Gating Control 			 */
			 uint32_t  RESERVED71;
	__IO uint32_t  RCGCHIB; 						  /*!< Offset: 0x000 (R/W)  Hibernation Run Mode Clock Gating Control							 */
	__IO uint32_t  RCGCUART;						  /*!< Offset: 0x000 (R/W)  Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating Control																 */
	__IO uint32_t  RCGCSSI; 						  /*!< Offset: 0x000 (R/W)  Synchronous Serial Interface Run Mode Clock Gating Control			 */
	__IO uint32_t  RCGCI2C; 						  /*!< Offset: 0x620 (R/W)  Inter-Integrated Circuit Run Mode Clock Gating Control				 */
			 uint32_t  RESERVED8;
	__IO uint32_t  RCGCUSB; 						  /*!< Offset: 0x628 (R/W)  Universal Serial Bus Run Mode Clock Gating Control					 */
			 uint32_t  RESERVED9[2];
	__IO uint32_t  RCGCCAN; 						  /*!< Offset: 0x634 (R/W)  Controller Area Network Run Mode Clock Gating Control				 */
	__IO uint32_t  RCGCADC; 						  /*!< Offset: 0x000 (R/W)  Analog-to-Digital Converter Run Mode Clock Gating Control			 */
	__IO uint32_t  RCGCACMP;						  /*!< Offset: 0x000 (R/W)  Analog Comparator Run Mode Clock Gating Control						 */
	__IO uint32_t  RCGCPWM; 						  /*!< Offset: 0x000 (R/W)  Pulse Width Modulator Run Mode Clock Gating Control					 */
	__IO uint32_t  RCGCQEI; 						  /*!< Offset: 0x644 (R/W)  Quadrature Encoder Interface Run Mode Clock Gating Control			 */
			 uint32_t  RESERVED10[5];
	__IO uint32_t  RCGCWTIMER;						/*!< Offset: 0x65C (R/W)  						 */	
			 uint32_t  RESERVED11[40];
	__IO uint32_t  SCGCWD;							  /*!< Offset: 0x700 (R/W)  Watchdog Timer Sleep Mode Clock Gating Control						 */
	__IO uint32_t  SCGCTIMER;						  /*!< Offset: 0x000 (R/W)  16/32-Bit General-Purpose Timer Sleep Mode Clock Gating Control		 */
	__IO uint32_t  SCGCGPIO;						  /*!< Offset: 0x000 (R/W)  General-Purpose Input/Output Sleep Mode Clock Gating Control 		 */
	__IO uint32_t  SCGCDMA; 						  /*!< Offset: 0x70C (R/W)  Micro Direct Memory Access Sleep Mode Clock Gating Control			 */
			 uint32_t  RESERVED111;
	__IO uint32_t  SCGCHIB; 						  /*!< Offset: 0x000 (R/W)  Hibernation Sleep Mode Clock Gating Control							 */
	__IO uint32_t  SCGCUART;						  /*!< Offset: 0x000 (R/W)  Universal Asynchronous Receiver/Transmitter Sleep Mode Clock Gating Control														 */
	__IO uint32_t  SCGCSSI; 						  /*!< Offset: 0x000 (R/W)  Synchronous Serial Interface Sleep Mode Clock Gating Control 		 */
	__IO uint32_t  SCGCI2C; 						  /*!< Offset: 0x720 (R/W)  Inter-Integrated Circuit Sleep Mode Clock Gating Control 			 */
			 uint32_t  RESERVED12;
	__IO uint32_t  SCGCUSB; 						  /*!< Offset: 0x728 (R/W)  Universal Serial Bus Sleep Mode Clock Gating Control 				 */
			 uint32_t  RESERVED13[2];
	__IO uint32_t  SCGCCAN; 						  /*!< Offset: 0x734 (R/W)  Controller Area Network Sleep Mode Clock Gating Control				 */
	__IO uint32_t  SCGCADC; 						  /*!< Offset: 0x000 (R/W)  Analog-to-Digital Converter Sleep Mode Clock Gating Control			 */
	__IO uint32_t  SCGCACMP;						  /*!< Offset: 0x000 (R/W)  Analog Comparator Sleep Mode Clock Gating Control					 */
	__IO uint32_t  SCGCPWM; 						  /*!< Offset: 0x000 (R/W)  Pulse Width Modulator Sleep Mode Clock Gating Control				 */
	__IO uint32_t  SCGCQEI; 						  /*!< Offset: 0x744 (R/W)  Quadrature Encoder Interface Sleep Mode Clock Gating Control 		 */
			 uint32_t  RESERVED14[5];
	__IO uint32_t  SCGCWTIMER;						/*!< Offset: 0x75C (R/W)  						 */	
			 uint32_t  RESERVED15[40];
	__IO uint32_t  DCGCWD;							  /*!< Offset: 0x800 (R/W)  Watchdog Timer Deep-Sleep Mode Clock Gating Control					 */
	__IO uint32_t  DCGCTIMER;						  /*!< Offset: 0x000 (R/W)  16/32-Bit General-Purpose Timer Deep-Sleep Mode Clock Gating Control																 */
	__IO uint32_t  DCGCGPIO;						  /*!< Offset: 0x000 (R/W)  General-Purpose Input/Output Deep-Sleep Mode Clock Gating Control	 */
	__IO uint32_t  DCGCDMA; 						  /*!< Offset: 0x000 (R/W)  Micro Direct Memory Access Deep-Sleep Mode Clock Gating Control		 */
			 uint32_t  RESERVED151;
	__IO uint32_t  DCGCHIB; 						  /*!< Offset: 0x000 (R/W)  Hibernation Deep-Sleep Mode Clock Gating Control 					 */
	__IO uint32_t  DCGCUART;						  /*!< Offset: 0x000 (R/W)  Universal Asynchronous Receiver/Transmitter Deep-Sleep Mode Clock Gating Control 												 */
	__IO uint32_t  DCGCSSI; 						  /*!< Offset: 0x000 (R/W)  Synchronous Serial Interface Deep-Sleep Mode Clock Gating Control	 */
	__IO uint32_t  DCGCI2C; 						  /*!< Offset: 0x820 (R/W)  Inter-Integrated Circuit Deep-Sleep Mode Clock Gating Control		 */
			 uint32_t  RESERVED16;
	__IO uint32_t  DCGCUSB; 						  /*!< Offset: 0x828 (R/W)  Universal Serial Bus Deep-Sleep Mode Clock Gating Control			 */
			 uint32_t  RESERVED17[2];
	__IO uint32_t  DCGCCAN; 						  /*!< Offset: 0x834 (R/W)  Controller Area Network Deep-Sleep Mode Clock Gating Control 		 */
	__IO uint32_t  DCGCADC; 						  /*!< Offset: 0x000 (R/W)  Analog-to-Digital Converter Deep-Sleep Mode Clock Gating Control 	 */
	__IO uint32_t  DCGCACMP;						  /*!< Offset: 0x000 (R/W)  Analog Comparator Deep-Sleep Mode Clock Gating Control				 */
	__IO uint32_t  DCGCPWM; 						  /*!< Offset: 0x000 (R/W)  Pulse Width Modulator Deep-Sleep Mode Clock Gating Control			 */
	__IO uint32_t  DCGCQEI; 						  /*!< Offset: 0x844 (R/W)  Quadrature Encoder Interface Deep-Sleep Mode Clock Gating Control	 */
			 uint32_t  RESERVED18[5];
	__IO uint32_t  DCGCWTIMER;						/*!< Offset: 0x85C (R/W)  						 */	
			 uint32_t  RESERVED19[168];						
	__IO uint32_t  CPU_MODE;								/*!< Offset: 0xB00 (R/W)  						 */	
	__IO uint32_t  CFG_DEEPSLEEP_EN;				/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  PVD_PU;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  LDO12_SEL;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  PVD12_LVO;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  PVD33_LVO;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  MOSG_CFG;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  MOSG_DETECT0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  MOSG_DETECT1;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  MOSG_DETECT2;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  PIOSC_CFG;						/*!< Offset: 0xB28 (R/W)  						 */	
			 uint32_t  RESERVED20;					
	__IO uint32_t  OSC_CLK_MUX;						/*!< Offset: 0xB30 (R/W)  						 */	
	__IO uint32_t  CFG_REG_PLL0_0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_REG_PLL0_1;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_REG_PLL0_2;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  PLL0_PRE_DIV;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  PLL0_ADC_CFG;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  PLL0_LCD_CFG;						/*!< Offset: 0xB48 (R/W)  						 */	
			 uint32_t  RESERVED21;					
	__IO uint32_t  PLL0_SYS_CFG;						/*!< Offset: 0xB50 (R/W)  						 */	
	__IO uint32_t  CFG_REG_PLL1_0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_REG_PLL1_1;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_REG_PLL1_2;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  PLL1_PRE_DIV;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  PLL1_USB_CFG;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  SYS_CLK_DIV_TIMER_0_3;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  SYS_CLK_DIV_TIMER_4_7;						/*!< Offset: 0x000 (R/W) 						 */	
	__IO uint32_t  SYS_CLK_DIV_TIMER_8_11;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  SYS_CLK_DIV_WTIMER_0_3;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  SYS_CLK_DIV_WTIMER_4_7;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  SYS_CLK_DIV_WTIMER_8_11;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  SYS_CLK_DIV_TRACECLKIN;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  SYS_CLK_DIV_PWM;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  SYS_CLK_DIV_CAN;						/*!< Offset: 0xB88 (R/W)  						 */	
			 uint32_t  RESERVED22[29];						
	__IO uint32_t  SYSRESETn_M4_CTRL;						/*!< Offset: 0xC00 (R/W)  						 */	
	__IO uint32_t  M4_CFG;						/*!< Offset: 0xC04 (R/W)  						 */	
			 uint32_t  RESERVED23[7];					
	__IO uint32_t  PMU_ENABLE;						/*!< Offset: 0xC24 (R/W)  						 */	
			 uint32_t  RESERVED24;						
	__IO uint32_t  USB_CTRL_CFG;						/*!< Offset: 0xC2C (R/W)  						 */	
			 uint32_t  RESERVED24_1;
	__IO uint32_t  USB_PHY_REG0;						/*!< Offset: 0xC34 (R/W)  						 */	
	__IO uint32_t  REG_USB2_OTG;						/*!< Offset: 0xC38 (R/W)  						 */	
	__IO uint32_t  SYS_DMA_DONE_USB;						/*!< Offset: 0xC3C (R/W)  						 */	
	__IO uint32_t  USB_OVR;						/*!< Offset: 0xC40 (R/W)  						 */	
			 uint32_t  RESERVED25[16];						
	__IO uint32_t  MST_SLV_SEL_SSI;						/*!< Offset: 0xC84 (R/W)  						 */	
			 uint32_t  RESERVED26[7];						
	__IO uint32_t  IR_SEL_UART;						/*!< Offset: 0xCA4 (R/W)  						 */	
			 uint32_t  RESERVED27[22];						
	__IO uint32_t  IO_SEL_UART1;						/*!< Offset: 0xD00 (R/W)  						 */	
	__IO uint32_t  CFG_RTC_SEL;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_C_OUT;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_M0_PWM;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_M1_PWM;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_M0_FAULT;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_M1_FAULT;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_IDX0_1;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_PHAB0_1;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_UART;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_SSI;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_CAN;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_I2C1;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_USB0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_T0_CCP0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_T1_CCP0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_T2_CCP0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_T3_CCP0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_T4_CCP0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_T5_CCP0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_WT0_CCP0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_WT1_CCP0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_WT2_CCP0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_WT3_CCP0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_WT4_CCP0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_WT5_CCP0;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_PWM_DC;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_SEL_NMI;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CALENDAR_RTC;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  TIME_RTC;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  BATCHK;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  CFG_EEPROM_EN;						/*!< Offset: 0xD7C (R/W)  						 */	
			 uint32_t  RESERVED28[32];					
	__IO uint32_t  SW_RST_N;						/*!< Offset: 0xE00 (R/W)  						 */	
	__IO uint32_t  RECSERVE0_REG;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  RECSERVE1_REG;						/*!< Offset: 0x000 (R/W)  						 */	
	__IO uint32_t  USB_S_ADDR_UPPER;						/*!< Offset: 0xE04 (R/W)  						 */	

 } HM_SC_TypeDef;
 
/*------------- General Purpose Input/Output (GPIO) --------------------------*/
/** @brief General Purpose Input/Output (GPIO) register structure definition */
typedef struct
{
	__IO uint32_t  DATA[256];						  /*!< GPIO Data															 */
	__IO uint32_t  DIR; 							  /*!< GPIO Direction														 */
	__IO uint32_t  IS;								  /*!< GPIO Interrupt Sense 												 */
	__IO uint32_t  IBE; 							  /*!< GPIO Interrupt Both Edges											 */
	__IO uint32_t  IEV; 							  /*!< GPIO Interrupt Event 												 */
	__IO uint32_t  IM;								  /*!< GPIO Interrupt Mask													 */
	__IO uint32_t  RIS; 							  /*!< GPIO Raw Interrupt Status											 */
	__IO uint32_t  MIS; 							  /*!< GPIO Masked Interrupt Status 										 */
	__O  uint32_t  ICR; 							  /*!< GPIO Interrupt Clear 												 */
	__IO uint32_t  AFSEL;							  /*!< GPIO Alternate Function Select										 */
	__I  uint32_t  RESERVED1[55];
	__IO uint32_t  DR2R;							  /*!< GPIO 2-mA Drive Select												 */
	__IO uint32_t  DR4R;							  /*!< GPIO 4-mA Drive Select												 */
	__IO uint32_t  DR8R;							  /*!< GPIO 8-mA Drive Select												 */
	__IO uint32_t  ODR; 							  /*!< GPIO Open Drain Select												 */
	__IO uint32_t  PUR; 							  /*!< GPIO Pull-Up Select													 */
	__IO uint32_t  PDR; 							  /*!< GPIO Pull-Down Select												 */
	__IO uint32_t  RESERVED2; 							  /*!< GPIO Pull-Down Select												 */
	__IO uint32_t  DEN; 							  /*!< GPIO Digital Enable	  											 */	
	__IO uint32_t  LOCK; 							  /*!< GPIO Pull-Down Select												 */
	__IO uint32_t  CR; 							  /*!< GPIO Ctrl	  											 */	
	__IO uint32_t  AMSEL; 							  /*!< GPIO Pull-Down Select												 */
	__IO uint32_t  PORTCTRL;
} HM_GPIO_TypeDef;
/** @brief General Purpose Input/Output interrupt (GPIOINT) register structure definition */
typedef struct
{
	__I  uint32_t IntStatus;							/*!< Offset: 0x080 (R/W)	*/
	__I  uint32_t IO0IntStatR;							/*!< Offset: 0x084 (R/W)	*/
	__I  uint32_t IO0IntStatF;							/*!< Offset: 0x088 (R/W)	*/
	__O  uint32_t IO0IntClr;							/*!< Offset: 0x08c (R/W)	*/
	__IO uint32_t IO0IntEnR;							/*!< Offset: 0x090 (R/W)	*/
	__IO uint32_t IO0IntEnF;							/*!< Offset: 0x094 (R/W)	*/
		 uint32_t RESERVED0[3];							/*!< Offset: 0x098 (R/W)	*/
	__I  uint32_t IO2IntStatR;							/*!< Offset: 0x0a4 (R/W)	*/
	__I  uint32_t IO2IntStatF;							/*!< Offset: 0x0a8 (R/W)	*/
	__O  uint32_t IO2IntClr;							/*!< Offset: 0x0ac (R/W)	*/
	__IO uint32_t IO2IntEnR;							/*!< Offset: 0x0b0 (R/W)	*/
	__IO uint32_t IO2IntEnF;							/*!< Offset: 0x0b4 (R/W)	*/
} HM_GPIOINT_TypeDef;
/*------------- Timer (TIM) --------------------------------------------------*/
/** @brief Timer (TIM) register structure definition */
typedef struct
{
	__IO uint32_t CFG;							/*!< Offset: 0x000 (R/W)	*/
	__IO uint32_t TAMR;							/*!< Offset: 0x004 (R/W)	*/
	__IO uint32_t TBMR;							/*!< Offset: 0x008 (R/W)	*/
	__IO uint32_t CTL;							/*!< Offset: 0x00C (R/W)	*/
	__IO uint32_t SYNC;							/*!< Offset: 0x010 (R/W)	*/
	     uint32_t RESERVED1;					/*!< Offset: 0x00C (R/W)	*/
	__IO uint32_t IMR;							/*!< Offset: 0x018 (R/W)	*/
	__IO uint32_t RIS;							/*!< Offset: 0x01C (R/W)	*/
	__IO uint32_t MIS;							/*!< Offset: 0x020 (R/W)	*/
	__IO uint32_t ICR;							/*!< Offset: 0x024 (R/W)	*/
	__IO uint32_t TAILR;							/*!< Offset: 0x028 (R/W)	*/
	__IO uint32_t TBILR;							/*!< Offset: 0x02C (R/W)	*/
	__IO uint32_t TAMATCHR;							/*!< Offset: 0x030 (R/W)	*/
	__IO uint32_t TBMATCHR;							/*!< Offset: 0x034 (R/W)	*/
	__IO uint32_t TAPR;							/*!< Offset: 0x038 (R/W)	*/
	__IO uint32_t TBPR;							/*!< Offset: 0x03C (R/W)	*/
	__IO uint32_t TAPMR;							/*!< Offset: 0x040 (R/W)	*/
	__IO uint32_t TBPMR;							/*!< Offset: 0x044 (R/W)	*/
	__IO uint32_t TAR;							/*!< Offset: 0x048 (R/W)	*/
	__IO uint32_t TBR;							/*!< Offset: 0x04C (R/W)	*/
	__IO uint32_t TAV;							/*!< Offset: 0x050 (R/W)	*/
	__IO uint32_t TBV;							/*!< Offset: 0x054 (R/W)	*/
	__IO uint32_t RTCPD;							/*!< Offset: 0x058 (R/W)	*/
	__IO uint32_t TAPS;							/*!< Offset: 0x05C (R/W)	*/
	__IO uint32_t TBPS;							/*!< Offset: 0x060 (R/W)	*/
	__IO uint32_t TAPV;							/*!< Offset: 0x064 (R/W)	*/
	__IO uint32_t TBPV;							/*!< Offset: 0x068 (R/W)	*/
		 uint32_t RESERVED2[981];				/*!< Offset: 0x00C (R/W)	*/
	__IO uint32_t PP;							/*!< Offset: 0xFC0 (R/W)	*/
} HM_TIM_TypeDef;

/*------------- Pulse-Width Modulation (PWM) ---------------------------------*/
/** @brief Pulse-Width Modulation (PWM) register structure definition */
typedef struct
{													/*!< 0x040	0x080	0x0C0	0x100	*/	
	__IO uint32_t PWMCTL;							/*!< Offset: 0x000 (R/W)	*/
	__IO uint32_t PWMINTEN;							/*!< Offset: 0x004 (R/W)	*/
	__IO uint32_t PWMRIS;							/*!< Offset: 0x008 (R/W)	*/
	__IO uint32_t PWMISC;							/*!< Offset: 0x00C (R/W)	*/
	__IO uint32_t PWMLOAD;							/*!< Offset: 0x010 (R/W)	*/
	__IO uint32_t PWMCOUNT;							/*!< Offset: 0x014 (R/W)	*/
	__IO uint32_t PWMCMPA;							/*!< Offset: 0x018 (R/W)	*/
	__IO uint32_t PWMCMPB;							/*!< Offset: 0x01C (R/W)	*/
	__IO uint32_t PWMGENA;							/*!< Offset: 0x020 (R/W)	*/
	__IO uint32_t PWMGENB;							/*!< Offset: 0x024 (R/W)	*/
	__IO uint32_t PWMDBCTL;							/*!< Offset: 0x028 (R/W)	*/
	__IO uint32_t PWMDBRISE;						/*!< Offset: 0x02C (R/W)	*/
	__IO uint32_t PWMDBFALL;						/*!< Offset: 0x030 (R/W)	*/
	__IO uint32_t PWMFLTSRC0;						/*!< Offset: 0x034 (R/W)	*/
	__IO uint32_t PWMFLTSRC1;						/*!< Offset: 0x038 (R/W)	*/
	__IO uint32_t PWMMINFLTPER;						/*!< Offset: 0x03C (R/W)	*/
} HM_PWMCH_TypeDef;

typedef struct
{													/*!< 0x800	0x880	0x900	0x980	*/	
	__IO uint32_t PWMFLTSEN;						/*!< Offset: 0x000 (R/W)	*/
	__IO uint32_t PWMFLTSTAT0;						/*!< Offset: 0x004 (R/W)	*/
	__IO uint32_t PWMFLTSTAT1;						/*!< Offset: 0x008 (R/W)	*/
	__IO uint32_t RESERVED1[29];					/*!< Offset: 0x00C (R/W)	*/
}HM_PWMCHEXT_TypeDef;

typedef struct
{
	__IO uint32_t PWMCTL;							/*!< Offset: 0x000 (R/W)	*/
	__IO uint32_t PWMSYNC;							/*!< Offset: 0x004 (R/W)	*/
	__IO uint32_t PWMENABLE;						/*!< Offset: 0x008 (R/W)	*/
	__IO uint32_t PWMINVERT;						/*!< Offset: 0x00C (R/W)	*/
	__IO uint32_t PWMFAULT;							/*!< Offset: 0x010 (R/W)	*/
	__IO uint32_t PWMINTEN;							/*!< Offset: 0x014 (R/W)	*/
	__IO uint32_t PWMRIS;							/*!< Offset: 0x018 (R/W)	*/
	__IO uint32_t PWMISC;							/*!< Offset: 0x01C (R/W)	*/
	__IO uint32_t PWMSTATUS;						/*!< Offset: 0x020 (R/W)	*/
	__IO uint32_t PWMFAULTVAL;						/*!< Offset: 0x024 (R/W)	*/
	__IO uint32_t PWMENUPD;							/*!< Offset: 0x028 (R/W)	*/
		 uint32_t RESERVED1[5];						/*!< Offset: 0x030 (R/W)	*/
	HM_PWMCH_TypeDef PWMCH[4];					/*!< Offset: 0x040 (R/W)	*/
	__IO uint32_t PWM_CAP_CTRL;						/*!< Offset: 0x140 (R/W)	*/
	__IO uint32_t PWM_CAP_RT_CLR;					/*!< Offset: 0x144 (R/W)	*/
	__IO uint32_t PWM0CAP_I0;						/*!< Offset: 0x148 (R/W)	*/
	__IO uint32_t PWM1CAP_I0;						/*!< Offset: 0x14C (R/W)	*/
	__IO uint32_t PWM2CAP_I0;						/*!< Offset: 0x150 (R/W)	*/
	__IO uint32_t PWM3CAP_I0;						/*!< Offset: 0x154 (R/W)	*/
	__IO uint32_t PWM0CAP_I1;						/*!< Offset: 0x158 (R/W)	*/
	__IO uint32_t PWM1CAP_I1;						/*!< Offset: 0x15C (R/W)	*/
	__IO uint32_t PWM2CAP_I1;						/*!< Offset: 0x160 (R/W)	*/
	__IO uint32_t PWM3CAP_I1;						/*!< Offset: 0x164 (R/W)	*/
		 uint32_t RESERVED2[2];						/*!< Offset: 0x168 (R/W)	*/
	__IO uint32_t PWMPR;							/*!< Offset: 0x170 (R/W)	*/
	__IO uint32_t PWMPC;							/*!< Offset: 0x174 (R/W)	*/
		 uint32_t RESERVED3[418];					/*!< Offset: 0x178 (R/W)	*/
	HM_PWMCHEXT_TypeDef PWMCHEXT[4];				/*!< Offset: 0x800 (R/W)	*/
} HM_PWM_TypeDef;

/** @brief  Universal Asynchronous Receiver Transmitter 0 (UART0) register structure definition */
typedef struct
{
	__IO uint32_t CTRL;							/*!< Offset: 0x000 (R/W)	*/
	__IO uint32_t MODE;							/*!< Offset: 0x004 (R/W)	*/
	__IO uint32_t IER;							/*!< Offset: 0x008 (W)	*/
	__IO uint32_t IDR;							/*!< Offset: 0x00c (W)	*/
	__IO uint32_t IMR;							/*!< Offset: 0x010 (R)	*/
	__IO uint32_t CISR;							/*!< Offset: 0x014 (R/W)	*/
	__IO uint32_t BRGR;							/*!< Offset: 0x018 (R/W)	*/
	__IO uint32_t RTOR;							/*!< Offset: 0x01c (R/W)	*/
	__IO uint32_t RTR;							/*!< Offset: 0x020 (R/W)	*/
	__IO uint32_t MCR;							/*!< Offset: 0x024 (R/W)	*/
	__IO uint32_t MSR;							/*!< Offset: 0x028 (R)	*/
	__IO uint32_t CSR;							/*!< Offset: 0x02c (R)	*/
	union{
	__IO uint32_t TFIFO;							/*!< Offset: 0x030 (R)	*/
	__IO uint32_t RFIFO;							/*!< Offset: 0x030 (R)	*/		
	};
	__IO uint32_t BDIVR;						/*!< Offset: 0x034 (R/W)	*/
	__IO uint32_t FCDR;							/*!< Offset: 0x038 (R/W)	*/
	__IO uint32_t RPWR;							/*!< Offset: 0x03c (R/W)	*/
	__IO uint32_t TPWR;							/*!< Offset: 0x040 (R/W)	*/
	__IO uint32_t TTR;							/*!< Offset: 0x044 (R/W)	*/
	__IO uint32_t RBSR;							/*!< Offset: 0x048 (R)	*/
		 uint32_t Reserved[13];					/*!< Offset: 0x04C+13*4 (R)	*/
	__IO uint32_t RS485CTRL;					/*!< Offset: 0x080 (R/W)	*/	 
	__IO uint32_t RS485ADDR_MATCH;				/*!< Offset: 0x084 (R/W)	*/	 
	__IO uint32_t RS485OE_DELAY;				/*!< Offset: 0x088 (R/W)	*/	 
	__IO uint32_t RS485_RECEIVE_EN;				/*!< Offset: 0x08c (R/W)	*/	 
	__IO uint32_t RS485_RXFIFO_STORE_FLAG;		/*!< Offset: 0x090 (R)	*/	 
	__IO uint32_t RS485_RXDATA_STORE_RDY_INT;	/*!< Offset: 0x094 (R)	*/	 
	__IO uint32_t RS485_NMM_RXDIS_ADDR;			/*!< Offset: 0x098 (R)	*/	 
	__IO uint32_t UART_OR_IRMODE_CTRL;			/*!< Offset: 0x09c (R/W)	*/
	__IO uint32_t UA_DMAMODE_CTRL;				/*!< Offset: 0x0a0 (R/W)	*/

}HM_UART_TypeDef;


/*------------- Synchronous Serial Communication (SSP) -----------------------*/
/** @brief  Synchronous Serial Communication (SSP) register structure definition */
typedef struct
{
	__IO uint32_t CTRLR0;						/*!< Offset: 0x000 (R/W)	*/	 
	__IO uint32_t CTRLR1;						/*!< Offset: 0x004 (R/W)	*/	 
	__IO uint32_t SSIENR;						/*!< Offset: 0x008 (R/W)	*/	 
	__IO uint32_t MWCR;						/*!< Offset: 0x00c (R/W)	*/	 
	__IO uint32_t SER;						/*!< Offset: 0x010 (R/W)	*/	 
	__IO uint32_t BAUDR;						/*!< Offset: 0x014 (R/W)	*/	 
	__IO uint32_t TXFTLR;						/*!< Offset: 0x018 (R/W)	*/	 
	__IO uint32_t RXFTLR;						/*!< Offset: 0x01c (R/W)	*/	 
	__IO uint32_t TXFLR;						/*!< Offset: 0x020 (R/W)	*/	 
	__IO uint32_t RXFLR;						/*!< Offset: 0x024 (R/W)	*/	 
	__IO uint32_t SR;							/*!< Offset: 0x028 (R/W)	*/	 
	__IO uint32_t IMR;						/*!< Offset: 0x02c (R/W)	*/	 
	__IO uint32_t ISR;						/*!< Offset: 0x030 (R/W)	*/	 
	__IO uint32_t RISR;						/*!< Offset: 0x034 (R/W)	*/	 
	__IO uint32_t TXOICR;						/*!< Offset: 0x038 (R/W)	*/	 
	__IO uint32_t RXOICR;						/*!< Offset: 0x03c (R/W)	*/	 
	__IO uint32_t RXUICR;						/*!< Offset: 0x040 (R/W)	*/	 
	__IO uint32_t MSTICR;						/*!< Offset: 0x044 (R/W)	*/	 
	__IO uint32_t ICR;						/*!< Offset: 0x048 (R/W)	*/	 
	__IO uint32_t DMACR;						/*!< Offset: 0x04c (R/W)	*/	 
	__IO uint32_t DMATDLR;					/*!< Offset: 0x050 (R/W)	*/	 
	__IO uint32_t DMARDLR;					/*!< Offset: 0x054 (R/W)	*/	 
	__IO uint32_t IDR;						/*!< Offset: 0x058 (R/W)	*/	 
	__IO uint32_t SSI_VERSION_ID;				/*!< Offset: 0x05c (R/W)	*/	 
	__IO uint32_t DR;						/*!< Offset: 0x060 (R/W)	*/
		 uint32_t Reserved0[35];
	__IO uint32_t RX_SAMPLE_DLY;				/*!< Offset: 0x0f0 (R/W)	*/	 
	__IO uint32_t SPI_CTRLR0;					/*!< Offset: 0x0f4 (R/W)	*/	 
	__IO uint32_t TXD_DRIVE_EDGE;				/*!< Offset: 0x0f8 (R/W)	*/	 
	__IO uint32_t RSVD;						/*!< Offset: 0x0fc (R/W)	*/	 

} HM_SSPx_TypeDef;

typedef struct
{
	HM_SSPx_TypeDef SSP_M;					/*!< Offset: 0x000 (R/W)	*/	
	HM_SSPx_TypeDef SSP_S;					/*!< Offset: 0x100 (R/W)	*/	
	__IO uint32_t SSI_MSCTRL;					/*!< Offset: 0x200 (R/W)	*/	
	__I  uint32_t SSI_SLEEP;					/*!< Offset: 0x204 (R/W)	*/	
	__I  uint32_t SSI_BUSY;						/*!< Offset: 0x208 (R/W)	*/	
	__I  uint32_t SSI_IN_N_CTRL;				/*!< Offset: 0x20c (R/W)	*/	
	__IO uint32_t SSI_DMA_CTRL;				    /*!< Offset: 0x210 (R/W)	*/	

} HM_SSP_TypeDef;

/*------------- Inter-Integrated Circuit (I2C) -------------------------------*/
/** @brief  Inter-Integrated Circuit (I2C) register structure definition */
typedef struct
{
	__IO uint32_t CON;						    /*!< Offset: 0x000 (R/W)	*/	
	__IO uint32_t TAR;						    /*!< Offset: 0x004 (R/W)	*/	
	__IO uint32_t SAR;						    /*!< Offset: 0x008 (R/W)	*/	
	__IO uint32_t HS_MADDR;					    /*!< Offset: 0x00c (R/W)	*/	
	__IO uint32_t DATA_CMD;					    /*!< Offset: 0x010 (R/W)	*/	
    union{
		__IO uint32_t SS_SCL_HCNT;				/*!< Offset: 0x014 (R/W)	*/	
		__IO uint32_t UFM_SCL_HCNT;
	};
	union{
		__IO uint32_t SS_SCL_LCNT;				/*!< Offset: 0x018 (R/W)	*/	
		__IO uint32_t UFM_SCL_LCNT;
	};
	union{
		__IO uint32_t FS_SCL_HCNT;				/*!< Offset: 0x01c (R/W)	*/	
		__IO uint32_t UFM_TBUF_CNT;
	};	
	__IO uint32_t FS_SCL_LCNT;				    /*!< Offset: 0x020 (R/W)	*/	
	__IO uint32_t HS_SCL_HCNT;				    /*!< Offset: 0x024 (R/W)	*/	
	__IO uint32_t HS_SCL_LCNT;				    /*!< Offset: 0x028 (R/W)	*/	
	__IO uint32_t INTR_STAT;				    /*!< Offset: 0x02C (R/W)	*/	
	__IO uint32_t INTR_MASK;				    /*!< Offset: 0x030 (R/W)	*/	
	__IO uint32_t RAW_INTR_STAT;				/*!< Offset: 0x034 (R/W)	*/	
	__IO uint32_t RX_TL;				        /*!< Offset: 0x038 (R/W)	*/	
	__IO uint32_t TX_TL;						/*!< Offset: 0x03c (R/W)	*/
	__IO uint32_t CLR_INTR;						/*!< Offset: 0x040 (R/W)	*/
	__IO uint32_t CLR_RX_UNDER;					/*!< Offset: 0x044 (R/W)	*/
	__IO uint32_t CLR_RX_OVER;					/*!< Offset: 0x048 (R/W)	*/
	__IO uint32_t CLR_TX_OVER;					/*!< Offset: 0x04c (R/W)	*/
	__IO uint32_t CLR_RD_REQ;					/*!< Offset: 0x050 (R/W)	*/
	__IO uint32_t CLR_TX_ABRT;					/*!< Offset: 0x054 (R/W)	*/
	__IO uint32_t CLR_RX_DONE;					/*!< Offset: 0x058 (R/W)	*/
	__IO uint32_t CLR_ACTIVITY;					/*!< Offset: 0x05c (R/W)	*/
	__IO uint32_t CLR_STOP_DET;					/*!< Offset: 0x060 (R/W)	*/
	__IO uint32_t CLR_START_DET;				/*!< Offset: 0x064 (R/W)	*/
	__IO uint32_t CLR_GEN_CALL;					/*!< Offset: 0x068 (R/W)	*/
	__IO uint32_t ENABLE;						/*!< Offset: 0x06c (R/W)	*/
	__IO uint32_t STATUS;						/*!< Offset: 0x070 (R/W)	*/
	__IO uint32_t TXFLR;						/*!< Offset: 0x074 (R/W)	*/
	__IO uint32_t RXFLR;						/*!< Offset: 0x078 (R/W)	*/
	__IO uint32_t SDA_HOLD;						/*!< Offset: 0x07c (R/W)	*/
	__IO uint32_t TX_ABRT_SOURCE;				/*!< Offset: 0x080 (R/W)	*/
	__IO uint32_t SLV_DATA_NACK_ONLY;			/*!< Offset: 0x084 (R/W)	*/
	__IO uint32_t DMA_CR;						/*!< Offset: 0x088 (R/W)	*/
	__IO uint32_t DMA_TDLR;						/*!< Offset: 0x08c (R/W)	*/
	__IO uint32_t DMA_RDLR;						/*!< Offset: 0x090 (R/W)	*/
	__IO uint32_t SDA_SETUP;					/*!< Offset: 0x094 (R/W)	*/
	__IO uint32_t ACK_GENERAL_CALL;				/*!< Offset: 0x098 (R/W)	*/
	__IO uint32_t ENABLE_STATUS;				/*!< Offset: 0x09c (R/W)	*/
	union{
		__IO uint32_t FS_SPKLEN;				/*!< Offset: 0x0a0 (R/W)	*/	
		__IO uint32_t UFM_SPKLEN;
	};	
	__IO uint32_t HS_SPKLEN;					/*!< Offset: 0x0a4 (R/W)	*/
	__IO uint32_t CLR_RESTART_DET;				/*!< Offset: 0x0a8 (R/W)	*/
	__IO uint32_t SCL_STUCK_AT_LOW_TIMEOUT ;	/*!< Offset: 0x0ac (R/W)	*/
	__IO uint32_t SDA_STUCK_AT_LOW_TIMEOUT ;	/*!< Offset: 0x0b0 (R/W)	*/
	__IO uint32_t CLR_SCL_STUCK_DET ;			/*!< Offset: 0x0b4 (R/W)	*/
	__IO uint32_t DEVICE_ID ;					/*!< Offset: 0x0b8 (R/W)	*/
	__IO uint32_t SMBUS_CLK_LOW_SEXT;			/*!< Offset: 0x0bc (R/W)	*/
	__IO uint32_t SMBUS_CLK_LOW_MEXT ;			/*!< Offset: 0x0c0 (R/W)	*/
	__IO uint32_t SMBUS_THIGH_MAX_IDLE_COUNT;	/*!< Offset: 0x0c4 (R/W)	*/
	__IO uint32_t SMBUS_INTR_STAT;				/*!< Offset: 0x0c8 (R/W)	*/
	__IO uint32_t SMBUS_INTR_MASK;				/*!< Offset: 0x0cc (R/W)	*/
	__IO uint32_t SMBUS_RAW_INTR_STAT;			/*!< Offset: 0x0d0 (R/W)	*/
	__IO uint32_t CLR_SMBUS_INTR;				/*!< Offset: 0x0d4 (R/W)	*/
	__IO uint32_t OPTIONAL_SAR;					/*!< Offset: 0x0d8 (R/W)	*/
	__IO uint32_t SMBUS_UDID_LSB_OR_WORD0;		/*!< Offset: 0x0dc (R/W)	*/
	__IO uint32_t SMBUS_UDID_WORD1;				/*!< Offset: 0x0e0 (R/W)	*/
	__IO uint32_t SMBUS_UDID_WORD2;				/*!< Offset: 0x0e4 (R/W)	*/
	__IO uint32_t SMBUS_UDID_WORD3;				/*!< Offset: 0x0e8 (R/W)	*/
         uint32_t Reserved0;
	__IO uint32_t TIMEOUT_RST;					/*!< Offset: 0x0f0 (R/W)	*/
	__IO uint32_t COMP_PARAM_1;					/*!< Offset: 0x0f4 (R/W)	*/
	__IO uint32_t COMP_VERSION;					/*!< Offset: 0x0f8 (R/W)	*/
	__IO uint32_t COMP_TYPE;					/*!< Offset: 0x0fc (R/W)	*/
	__IO uint32_t SAR2 ;						/*!< Offset: 0x100 (R/W)	*/
	__IO uint32_t SAR3;							/*!< Offset: 0x104 (R/W)	*/
	__IO uint32_t SAR4 ;						/*!< Offset: 0x108 (R/W)	*/
         uint32_t Reserved1[4];
	__IO uint32_t CLR_WR_REQ;					/*!< Offset: 0x11c (R/W)	*/
	__IO uint32_t CLR_SLV_ADDR_TAG;				/*!< Offset: 0x120 (R/W)	*/
	__IO uint32_t SAR2_SMBUS_UDID_WORD0;		/*!< Offset: 0x124 (R/W)	*/
	__IO uint32_t SAR2_SMBUS_UDID_WORD1;		/*!< Offset: 0x128 (R/W)	*/
	__IO uint32_t SAR2_SMBUS_UDID_WORD2;		/*!< Offset: 0x12c (R/W)	*/
	__IO uint32_t SAR2_SMBUS_UDID_WORD3;		/*!< Offset: 0x130 (R/W)	*/
	__IO uint32_t SAR3_SMBUS_UDID_WORD0;		/*!< Offset: 0x134 (R/W)	*/
	__IO uint32_t SAR3_SMBUS_UDID_WORD1;		/*!< Offset: 0x138 (R/W)	*/
	__IO uint32_t SAR3_SMBUS_UDID_WORD2;		/*!< Offset: 0x13c (R/W)	*/
	__IO uint32_t SAR3_SMBUS_UDID_WORD3;		/*!< Offset: 0x140 (R/W)	*/
	__IO uint32_t SAR4_SMBUS_UDID_WORD0;		/*!< Offset: 0x144 (R/W)	*/
	__IO uint32_t SAR4_SMBUS_UDID_WORD1;		/*!< Offset: 0x148 (R/W)	*/
	__IO uint32_t SAR4_SMBUS_UDID_WORD2;		/*!< Offset: 0x14c (R/W)	*/
	__IO uint32_t SAR4_SMBUS_UDID_WORD3;		/*!< Offset: 0x150 (R/W)	*/
} HM_I2C_TypeDef;

/*------------- Inter IC Sound (I2S) -----------------------------------------*/
/** @brief  Inter IC Sound (I2S) register structure definition */
typedef struct
{
	__IO uint32_t IER;					/*!< Offset: 0x000 (R/W)	*/	
	__IO uint32_t IRER;					/*!< Offset: 0x004 (R/W)	*/	
	__IO uint32_t ITER;					/*!< Offset: 0x008 (R/W)	*/	
	__IO uint32_t CER;					/*!< Offset: 0x00c (R/W)	*/	
	__IO uint32_t CCR;					/*!< Offset: 0x010 (R/W)	*/	
	__IO uint32_t RXFFR;					/*!< Offset: 0x014 (R/W)	*/	
	__IO uint32_t TXFFR;					/*!< Offset: 0x018 (R/W)	*/	
	__IO uint32_t SR;					/*!< Offset: 0x01C (R/W)	*/	
	union{
		__IO uint32_t LRBRx;					/*!< Offset: 0x020 (R/W)	*/	
		__IO uint32_t LTHRx;

	};
	union{
		__IO uint32_t RRBRx;					/*!< Offset: 0x024 (R/W)	*/	
		__IO uint32_t RTHRx;

	};

	__IO uint32_t RERx;					/*!< Offset: 0x028 (R/W)	*/	
	__IO uint32_t TERx;					/*!< Offset: 0x02C (R/W)	*/	
	__IO uint32_t RCRx;					/*!< Offset: 0x030 (R/W)	*/	
	__IO uint32_t TCRx;					/*!< Offset: 0x034 (R/W)	*/	
	__IO uint32_t ISRx;					/*!< Offset: 0x038 (R/W)	*/	
	__IO uint32_t IMRx;					/*!< Offset: 0x03C (R/W)	*/	
	__IO uint32_t RORx;					/*!< Offset: 0x040 (R/W)	*/	
	__IO uint32_t TORx;					/*!< Offset: 0x044 (R/W)	*/	
	__IO uint32_t RFCRx;					/*!< Offset: 0x048 (R/W)	*/	
	__IO uint32_t TFCRx;					/*!< Offset: 0x04C (R/W)	*/	
	__IO uint32_t RFFx;					/*!< Offset: 0x050 (R/W)	*/	
	__IO uint32_t TFFx;					/*!< Offset: 0x054 (R/W)	*/	
		 uint32_t Reserved1[2];					/*!< Offset: 0x058 (R/W)	*/	
		 uint32_t Reserved2[88];					/*!< Offset: 0x060 (R/W)	*/	
	__IO uint32_t RXDMA;					/*!< Offset: 0x1C0 (R/W)	*/	
	__IO uint32_t RRXDMA;					/*!< Offset: 0x1C4 (R/W)	*/	
	__IO uint32_t TXDMA;					/*!< Offset: 0x1C8 (R/W)	*/	
	__IO uint32_t RTXDMA;					/*!< Offset: 0x1CC (R/W)	*/	
		 uint32_t Reserved3[8];					/*!< Offset: 0x1D0 (R/W)	*/	
	__IO uint32_t I2S_COMP_PARAM_2;					/*!< Offset: 0x1F0 (R/W)	*/	
	__IO uint32_t I2S_COMP_PARAM_1;					/*!< Offset: 0x1F4 (R/W)	*/	
	__IO uint32_t I2S_COMP_VERSION;					/*!< Offset: 0x1F8 (R/W)	*/	
	__IO uint32_t I2S_COMP_TYPE;					/*!< Offset: 0x1FC (R/W)	*/	
	__IO uint32_t DMACR;					/*!< Offset: 0x200 (R/W)	*/	
	
	__IO uint32_t RXDMA_CH0;					/*!< Offset: 0x204 (R/W)	*/	
	__IO uint32_t RXDMA_CH1;					/*!< Offset: 0x208 (R/W)	*/	
		 uint32_t Reserved4[2];
	__IO uint32_t TXDMA_CH0;					/*!< Offset: 0x214 (R/W)	*/
	__IO uint32_t TXDMA_CH1;					/*!< Offset: 0x218 (R/W)	*/
		 uint32_t Reserved5[2];
	union{
	__IO uint32_t RSLOTx;					/*!< Offset: 0x224 (R/W)	*/	
	__IO uint32_t TSLOTx;
	};
		 uint32_t Reserved6[886];					/*!< Offset: 0x228 (R/W)	*/	
} HM_I2S_CFG_TypeDef;

typedef struct
{
	HM_I2S_CFG_TypeDef I2S_M;					/*!< Offset: 0x0000 (R/W)	*/	
	HM_I2S_CFG_TypeDef I2S_S;					/*!< Offset: 0x1000 (R/W)	*/	
	__IO uint32_t I2SMSCTRL;					/*!< Offset: 0x2000 (R/W)	*/	
	__IO uint32_t I2STX_RATE;					/*!< Offset: 0x2004 (R/W)	*/	
	__IO uint32_t I2SRX_RATE;					/*!< Offset: 0x2008 (R/W)	*/	
	__IO uint32_t I2STXMODE;					/*!< Offset: 0x200C (R/W)	*/	
	__IO uint32_t I2SRXMODE;					/*!< Offset: 0x2010 (R/W)	*/	
	__IO uint32_t I2STXBITRATE;					/*!< Offset: 0x2014 (R/W)	*/	
	__IO uint32_t I2SRXBITRATE;					/*!< Offset: 0x2018 (R/W)	*/	
	__IO uint32_t I2SDMACHANNEL0;					/*!< Offset: 0x201C (R/W)	*/	
	__IO uint32_t I2SDMACHANNEL1;					/*!< Offset: 0x2020 (R/W)	*/	
} HM_I2S_TypeDef;

/*------------- Real-Time Clock (RTC) ----------------------------------------*/
/** @brief  Real-Time Clock (RTC) register structure definition */
typedef struct
{
	__IO uint32_t CONTROL;						/*!< Offset: 0x000 (R/W)	*/	
	__IO uint32_t HOURMODE;						/*!< Offset: 0x004 (R/W)	*/	
	__IO uint32_t TIME;						/*!< Offset: 0x008 (R/W)	*/	
	__IO uint32_t CALENDAR;						/*!< Offset: 0x00C (R/W)	*/	
	__IO uint32_t TIME_ALARM;						/*!< Offset: 0x010 (R/W)	*/	
	__IO uint32_t CALENDAR_ALARM;						/*!< Offset: 0x014 (R/W)	*/	
	__IO uint32_t ALARM_ENABLE;						/*!< Offset: 0x018 (R/W)	*/	
	__IO uint32_t EVENT_FLAGS;						/*!< Offset: 0x01C (R/W)	*/	
	__O  uint32_t INTERRUPT_ENABLE;						/*!< Offset: 0x020 (R/W)	*/	
	__O  uint32_t INTERRUPT_DISABLE;						/*!< Offset: 0x024 (R/W)	*/	
	__IO uint32_t INTERRUPT_MASK;						/*!< Offset: 0x028 (R/W)	*/	
	__IO uint32_t STATUS;						/*!< Offset: 0x02C (R/W)	*/	
	__IO uint32_t KEEP_RTC;						/*!< Offset: 0x030 (R/W)	*/	
	__IO uint32_t RTC_PRL;						/*!< Offset: 0x034 (R/W)	*/	
	uint32_t Reserved1[18];
	__IO uint32_t ERSTATUS;							/*!< Offset: 0x080 (R/W)	 */	
	__IO uint32_t ERCONTROL;						/*!< Offset: 0x084 (R/W)	*/	
	__I	 uint32_t ERCOUNTERS;						/*!< Offset: 0x088 (R)	 */	
	uint32_t Reserved2;
	__I  uint32_t ERFIRSTSTAMP0;					/*!< Offset: 0x090 (R)*/	
	__I  uint32_t ERFIRSTSTAMP1;					/*!< Offset: 0x094 (R) */	
	__I  uint32_t ERFIRSTSTAMP2;						/*!< Offset: 0x098 (R)*/	
	uint32_t Reserved3;
	__I  uint32_t ERLASTSTAMP0;						/*!< Offset: 0x0A0 (R)	*/	
	__I  uint32_t ERLASTSTAMP1;						/*!< Offset: 0x0A4 (R)	*/	
	__I  uint32_t ERLASTSTAMP2;					/*!< Offset: 0x0A8 (R)	*/	

} HM_RTC_TypeDef;

/*------------- Watchdog Timer (WDT) -----------------------------------------*/
/** @brief  Watchdog Timer (WDT) register structure definition */
typedef struct
{
	__IO uint32_t LOAD;					/*!< Offset: 0x000 (R/W)*/	
	__IO uint32_t VALUE;					/*!< Offset: 0x004 (R)	*/	
	__IO uint32_t CTL;						/*!< Offset: 0x008 (R)	*/	
	__IO uint32_t ICR;						/*!< Offset: 0x00C (W)	*/	
	__IO uint32_t RIS;						/*!< Offset: 0x010 (R)	*/	
	__IO uint32_t MIS;							/*!< Offset: 0x014 (R)	*/	
			uint32_t Reserved0[256];
	__IO uint32_t TEST;					/*!< Offset: 0x418 (R/W)*/	
			uint32_t Reserved1[505];
	__IO uint32_t LOCK;					/*!< Offset: 0xC00 (R/W)*/
} HM_WDT_TypeDef;

/*------------- Analog-to-Digital Converter (ADC sampling) ----------------------------*/
/** @brief  Analog-to-Digital Converter (ADC sampling) register structure definition */
typedef struct{
	__IO uint32_t ADCSSMUX;				  /*!< Offset: 0x040	60  80  A0   A/D Interrupt Enable Register (R/W) */
	__IO uint32_t ADCSSCTL;				  /*!< Offset: 0x044  64  84  A4  A/D Channel 0..7 Data Register (R/W) */
	__IO uint32_t ADCSSFIFO; 				/*!< Offset: 0x048	68  88  A8   A/D Status Register (R/ ) */
	__IO uint32_t ADCSSFSTAT;				/*!< Offset: 0x04C	6C  8C  AC   A/D Global Data Register (R/W) */
	__IO uint32_t ADCSSOP;					/*!< Offset: 0x050	70  90  B0   A/D Global Data Register (R/W) */
	__IO uint32_t ADCSSDC;					/*!< Offset: 0x054	74  94  B4   A/D Global Data Register (R/W) */
			uint32_t Reserved0[2];
//	__IO uint32_t ADCSSEMUX;				/*!< Offset: 0x058	78  98  B8   A/D Global Data Register (R/W) */
//	__IO uint32_t ADCSSTSH;					/*!< Offset: 0x05C	7C  9C  BC   A/D Global Data Register (R/W) */
}HM_ADC_SAMPLING_TypeDef;

/*------------- Analog-to-Digital Converter (ADC) ----------------------------*/
/** @brief  Analog-to-Digital Converter (ADC) register structure definition */
typedef struct
{
	__IO uint32_t ADCACTSS;					 /*!< Offset: 0x000	   A/D Control Register (R/W) */
	__IO uint32_t ADCRIS;					   /*!< Offset: 0x004	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCIM;						 /*!< Offset: 0x008	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCISC;				     /*!< Offset: 0x00C	   A/D Interrupt Enable Register (R/W) */
	__IO uint32_t ADCOSTAT;				   /*!< Offset: 0x010 A/D Channel 0..7 Data Register (R/W) */
	__IO uint32_t ADCEMUX; 				   /*!< Offset: 0x014	   A/D Status Register (R/ ) */
	__IO uint32_t ADCUSTAT;					 /*!< Offset: 0x018	   A/D Global Data Register (R/W) */
				uint32_t Reserved1;
	__IO uint32_t ADCSSPRI;					 /*!< Offset: 0x020	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCSPC;						 /*!< Offset: 0x024	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCPSSI;					 /*!< Offset: 0x028	   A/D Global Data Register (R/W) */
				uint32_t Reserved2;
	__IO uint32_t ADCSAC;					   /*!< Offset: 0x030	   A/D Control Register (R/W) */
	__IO uint32_t ADCDCISC;					 /*!< Offset: 0x034	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCCTL;						 /*!< Offset: 0x038	   A/D Global Data Register (R/W) */
				uint32_t Reserved3;
	HM_ADC_SAMPLING_TypeDef ADCChannel[4];
				uint32_t Reserved7[784];
	__IO uint32_t ADCDCRIC;					 /*!< Offset: 0xD00	   A/D Global Data Register (R/W) */
				uint32_t Reserved8[63];		
	__IO uint32_t ADCDCCTL0;				 /*!< Offset: 0xE00	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCDCCTL1;				 /*!< Offset: 0xE04	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCDCCTL2;				 /*!< Offset: 0xE08	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCDCCTL3;				 /*!< Offset: 0xE0C	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCDCCTL4;				 /*!< Offset: 0xE10	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCDCCTL5;				 /*!< Offset: 0xE14	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCDCCTL6;				 /*!< Offset: 0xE18	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCDCCTL7;				 /*!< Offset: 0xE1C	   A/D Global Data Register (R/W) */
				uint32_t Reserved9[8];
	__IO uint32_t ADCDCCMP0;				 /*!< Offset: 0xE40	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCDCCMP1;				 /*!< Offset: 0xE44	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCDCCMP2;				 /*!< Offset: 0xE48	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCDCCMP3;				 /*!< Offset: 0xE4C	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCDCCMP4;				 /*!< Offset: 0xE50	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCDCCMP5;				 /*!< Offset: 0xE54	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCDCCMP6;				 /*!< Offset: 0xE58	   A/D Global Data Register (R/W) */
	__IO uint32_t ADCDCCMP7;				 /*!< Offset: 0xE5C	   A/D Global Data Register (R/W) */

} HM_ADC_TypeDef;

/*------------- Digital-to-Analog Converter (DAC) ----------------------------*/
/** @brief  Digital-to-Analog Converter (DAC) register structure definition */
typedef struct
{
	__IO uint32_t CR;
	__IO uint32_t DATA;
	__IO uint32_t STEP_CAL;
	__IO uint32_t MIN_VAL;
	__IO uint32_t MAX_VAL;
	__I uint32_t FIFO_STA;
	__IO uint32_t FILT_CNT;
	__IO uint32_t COMPARE;
	__IO uint32_t TIME_CNT_VAL;
} HM_DAC_TypeDef;
/*------------- Analog Comparators (AC) ----------------------------*/
/** @brief  Analog Comparators (AC) register structure definition */
typedef struct
{
	__IO uint32_t ACMIS;				/*!< Offset: 0x000	   A/D Global Data Register (R/W) */
	__IO uint32_t ACRIS;        /*!< Offset: 0x004	   A/D Global Data Register (R/W) */
	__IO uint32_t ACINTEN;      /*!< Offset: 0x008	   A/D Global Data Register (R/W) */
				uint32_t Reserved0;
	__IO uint32_t ACREFCTL;     /*!< Offset: 0x010	   A/D Global Data Register (R/W) */
				uint32_t Reserved1[3];
	__IO uint32_t ACSTAT0;      /*!< Offset: 0x020	   A/D Global Data Register (R/W) */
	__IO uint32_t ACCTL0;       /*!< Offset: 0x024	   A/D Global Data Register (R/W) */
				uint32_t Reserved3[6];
	__IO uint32_t ACSTAT1;      /*!< Offset: 0x040	   A/D Global Data Register (R/W) */
	__IO uint32_t ACCTL1;       /*!< Offset: 0x044	   A/D Global Data Register (R/W) */
				uint32_t Reserved4[6];
	__IO uint32_t ACSTAT2;      /*!< Offset: 0x060	   A/D Global Data Register (R/W) */
	__IO uint32_t ACCTL2;       /*!< Offset: 0x064	   A/D Global Data Register (R/W) */
				uint32_t Reserved5[6];
	__IO uint32_t AMP0;      /*!< Offset: 0x080	   A/D Global Data Register (R/W) */
	__IO uint32_t AMP1;       /*!< Offset: 0x084	   A/D Global Data Register (R/W) */
} HM_AC_TypeDef;


/*------------- Quadrature Encoder Interface (QEI) ---------------------------*/
/** @brief  Quadrature Encoder Interface (QEI) register structure definition */
typedef struct
{
	__IO uint32_t  CTL;							/*!< Offset: 0x000	  (R/W) */
	__IO uint32_t  STAT;							/*!< Offset: 0x004	  (R/W) */
	__IO uint32_t  POS;							/*!< Offset: 0x008	  (R/W) */
	__IO uint32_t  MAXPOS;							/*!< Offset: 0x00C	  (R/W) */
	__IO uint32_t  LOAD;							/*!< Offset: 0x010	  (R/W) */
	__IO uint32_t  TIME;							/*!< Offset: 0x014	  (R/W) */
	__IO uint32_t  COUNT;							/*!< Offset: 0x018	  (R/W) */
	__IO uint32_t  SPEED;							/*!< Offset: 0x01C	  (R/W) */
	__IO uint32_t  INTEN;							/*!< Offset: 0x020	  (R/W) */
	__IO uint32_t  RIS;							/*!< Offset: 0x024	  (R/W) */
	__IO uint32_t  ISC;								/*!< Offset: 0x028	  (R/W) */
	__IO uint32_t  PHA_FILCNT;
	__IO uint32_t  PHB_FILCNT;
	__IO uint32_t  IDX_FILCNT;
	__IO uint32_t  CNTCLR;
	__IO uint32_t  INXWINDOW;
	__IO uint32_t  VELCOMP;
	__IO uint32_t  CMPOS0;
	__IO uint32_t  CMPOS1;
	__IO uint32_t  CMPOS2;
	__IO uint32_t  INXCNT;
	__IO uint32_t  INXCMP0;
	__IO uint32_t  INXCMP1;
	__IO uint32_t  INXCMP2;
} HM_QEI_TypeDef;

/*------------- SD/MMC card Interface (MCI)-----------------------------------*/
/** @brief  SD/MMC card Interface (MCI) register structure definition */
typedef struct
{
	__IO uint32_t HRS[64];							/*!< Offset: 0x000	  (R/W) */
	__IO uint32_t CRS[64];							/*!< Offset: 0x000	  (R/W) */
	__IO uint32_t SRS[64];							/*!< Offset: 0x000	  (R/W) */
	__IO uint32_t CQRS[24];							/*!< Offset: 0x000	  (R/W) */
	
} HM_MCI_TypeDef;

/*------------- Controller Area Network (CAN) --------------------------------*/

/** @brief  Controller Area Network Controller (CAN) register structure definition */
typedef struct                          /* Controller Registers               */
{
	__IO uint32_t Rbuf[20];							/*!< Offset: 0x000	  (R/W) */
	__IO uint32_t Tbuf[20];							/*!< Offset: 0x050	  (R/W) */
	__IO uint32_t Control;							/*!< Offset: 0x0A0	  (R/W) */
	__IO uint32_t Interrupt;						/*!< Offset: 0x0A4	  (R/W) */
	__IO uint32_t BitTimingS;						/*!< Offset: 0x0A8	  (R/W) */
	__IO uint32_t BitTimingF;						/*!< Offset: 0x0AC	  (R/W) */
	__IO uint32_t ErrorCounter;						/*!< Offset: 0x0B0	  (R/W) */
	__IO uint32_t AcceptanceFilterCtrl;				/*!< Offset: 0x0B4	  (R/W) */
	__IO uint32_t AcceptanceCODE;					/*!< Offset: 0x0B8	  (R/W) */
	__IO uint32_t Version;							/*!< Offset: 0x0BC	  (R/W) */
	__IO uint32_t ReferenceMessage;					/*!< Offset: 0x0C0	  (R/W) */
	__IO uint32_t TriggerTime;						/*!< Offset: 0x0C4	  (R/W) */
	__IO uint32_t WatchTriggerTime;					/*!< Offset: 0x0C8	  (R/W) */
		 uint32_t Reserved;
	__O  uint32_t FDEnable;							/*!< Offset: 0x0D0	  (R/W) */
	__O  uint32_t DivNum;							/*!< Offset: 0x0D4	  (R/W) */
} HM_CAN_TypeDef;

/*------------- Direct Memory Access (UDMA) -----------------*/
/** @brief  Direct Memory Access (UDMA) register structure definition */
typedef struct                          /* Common Registers                   */
{
	__IO  uint32_t STAT;		    /*!< Offset: 0x000	  (R/W) */	
	__IO  uint32_t CFG;			/*!< Offset: 0x004	  (R/W) */
	__IO  uint32_t CTLBASE;		  /*!< Offset: 0x008	  (R/W) */	
	__IO  uint32_t ALTBASE;		  /*!< Offset: 0x00C	  (R/W) */	
	__IO  uint32_t WAITSTAT;		  /*!< Offset: 0x010	  (R/W) */	
	__IO  uint32_t SWREQ;		/*!< Offset: 0x014	  (R/W) */	
	__IO  uint32_t USEBURSTSET;	/*!< Offset: 0x018	  (R/W) */	
	__IO  uint32_t USEBURSTCLR;			/*!< Offset: 0x01C	  (R/W) */		
	__IO  uint32_t REQMASKSET;				/*!< Offset: 0x020	  (R/W) */	
	__IO  uint32_t REQMASKCLR;				/*!< Offset: 0x024	  (R/W) */
	__IO  uint32_t ENASET;			/*!< Offset: 0x028	  (R/W) */
	__IO  uint32_t ENACLR;			/*!< Offset: 0x02C	  (R/W) */	
	__IO  uint32_t ALTSET;					/*!< Offset: 0x030	  (R/W) */	
	__IO  uint32_t ALTCLR;						/*!< Offset: 0x034	  (R/W) */
	__IO  uint32_t PRIOSET;			/*!< Offset: 0x038	  (R/W) */
	__IO  uint32_t PRIOCLR;			/*!< Offset: 0x03C	  (R/W) */
	 	 uint32_t RESERVED1[3];		/*!< Offset: 0x040	  (R/W) */
	__IO  uint32_t ERRCLR ;			/*!< Offset: 0x04C	  (R/W) */
		 uint32_t RESERVED2[1004];	/*!< Offset: 0x050	  (R/W) */
	__IO  uint32_t ASSMODE[4];			/*!< Offset: 0x1000	  (R/W) */
	__IO  uint32_t ASSMODEEN; 		/*!< Offset: 0x1010   (R/W) */
		 uint32_t RESERVED3[3];		/*!< Offset: 0x1014	  (R/W) */
	__IO  uint32_t SWCHREQ; 			/*!< Offset: 0x1020   (R/W) */
	__IO  uint32_t SWSTACLR; 		/*!< Offset: 0x1024   (R/W) */

} HM_UDMA_TypeDef;

/*------------- Universal Serial Bus (USB) -----------------------------------*/
/** @brief  Universal Serial Bus (USB) register structure definition */
typedef struct
{
	uint32_t Reserved;
} HM_USB_TypeDef;
#if 0
/*------------- Ethernet Media Access Controller (EMAC) ----------------------*/
/** @brief  Ethernet Media Access Controller (EMAC) register structure definition */
typedef struct
{
	__IO uint32_t MAC_CTRL; 						/*	   		0x2000	   		*/
	__I  uint32_t MAC_STATUS_0; 					/*	   		0x2004	   		*/
	__I  uint32_t MAC_STATUS_1; 					/*	   		0x2008	   		*/
	__I  uint32_t MAC_STATUS_2; 					/*	   		0x200C	   		*/
	__I  uint32_t MAC_STATUS_3; 					/*	   		0x2010	   		*/
	__IO uint32_t REG_ETHPHY_0; 					/*	   		0x2014	   		*/
	__IO uint32_t REG_ETHPHY_1; 					/*	   		0x2018	   		*/
	__IO uint32_t REG_ETHPHY_2; 					/*	   		0x201C	   		*/
	__IO uint32_t REG_ETHPHY_3; 					/*	   		0x2020	   		*/
	__IO uint32_t REG_ETHPHY_4; 					/*	   		0x2024	   		*/
	__IO uint32_t REG_ETHPHY_5; 					/*	   		0x2028	   		*/
	__IO uint32_t REG_ETHPHY_6; 					/*	   		0x202C	   		*/
	__IO uint32_t REG_ETHPHY_7; 					/*	   		0x2030	   		*/
	__IO uint32_t REGOUT_ETHPHY_0; 					/*	   		0x2034	   		*/
	__IO uint32_t REGOUT_ETHPHY_1; 					/*	   		0x2038	   		*/
	__IO uint32_t REGOUT_ETHPHY_2; 					/*	   		0x203C	   		*/
	__IO uint32_t REGOUT_ETHPHY_3; 					/*	   		0x2040	   		*/
	__IO uint32_t POR12; 							/*	   		0x2044	   		*/
	__IO uint32_t POR33; 							/*	   		0x2048	   		*/

} HM_EMAC_TypeDef;
#endif
/*------------- LCD controller (LCD) -----------------------------------------*/
/** @brief  LCD controller (LCD) register structure definition */
typedef struct
{
	__IO uint32_t TIMH; 					  /*!< Offset: 0x000	 (R/W) */
	__IO uint32_t TIMV;					  /*!< Offset: 0x0004 (R/W) */
	__IO uint32_t POL;					  /*!< Offset: 0x008	 (R/W) */
	__IO uint32_t LE;					  /*!< Offset: 0x00C	 (R/W) */
	__IO uint32_t UPBASE;					  /*!< Offset: 0x010	 (R/W) */
	__IO uint32_t LPBASE;					  /*!< Offset: 0x014	 (R/W) */
	__IO uint32_t CTRL;					  /*!< Offset: 0x018	 (R/W) */
	__IO uint32_t INTMSK;					  /*!< Offset: 0x01C	 (R/W) */
	__I  uint32_t INTRAW;					  /*!< Offset: 0x020	 (R/W) */
	__I  uint32_t INTSTAT;					  /*!< Offset: 0x024	 (R/W) */
	__O  uint32_t INTCLR;					  /*!< Offset: 0x028	 (R/W) */
	__I  uint32_t UPCURR;					  /*!< Offset: 0x02C	 (R/W) */
	__I  uint32_t LPCURR;					  /*!< Offset: 0x030	 (R/W) */
		 uint32_t RESERVED0[115];					  /*!< Offset: 0x034	 (R/W) */
	__IO uint32_t PAL[128];					  /*!< Offset: 0x200	 (R/W) */
		 uint32_t RESERVED1[256];					  /*!< Offset: 0x400	 (R/W) */
	__IO uint32_t CRSR_IMG[256];					  /*!< Offset: 0x800	 (R/W) */
	__IO uint32_t CRSR_CTRL;					  /*!< Offset: 0xC00	 (R/W) */
	__IO uint32_t CRSR_CFG;					  /*!< Offset: 0xC04	 (R/W) */
	__IO uint32_t CRSR_PAL0;					  /*!< Offset: 0xC08	 (R/W) */
	__IO uint32_t CRSR_PAL1;					  /*!< Offset: 0xC0C	 (R/W) */
	__IO uint32_t CRSR_XY;					  /*!< Offset: 0xC10	 (R/W) */
	__IO uint32_t CRSR_CLIP;					  /*!< Offset: 0xC14	 (R/W) */
		 uint32_t RESERVED2[2];					  /*!< Offset: 0xC18	 (R/W) */
	__IO uint32_t CRSR_INTMSK;					  /*!< Offset: 0xC20	 (R/W) */
	__O  uint32_t CRSR_INTCLR;					  /*!< Offset: 0xC24	 (R/W) */
	__I  uint32_t CRSR_INTRAW;					  /*!< Offset: 0xC28	 (R/W) */
	__I  uint32_t CRSR_INTSTAT;					  /*!< Offset: 0xC30	 (R/W) */

} HM_LCD_TypeDef;

/*------------- External Peripheral Interface (EPI) -----------------------------*/
/** @brief  External Peripheral Interface (EPI) register structure definition */
typedef struct
{
	__IO uint32_t Control;					  /*!< Offset: 0x000	 (R/W) */

} HM_EPI_TypeDef;
/*------------- FLASH_ Engine (FLASH_) -----------------------------------------*/
/** @brief  FLASH_ Engine (FLASH_)  register structure definition */
typedef struct
{
	__IO uint32_t AcceleratorCtrl1;					  /*!< Offset: 0x000	 (R/W) */
	__IO uint32_t BootloaderCtrl;					  /*!< Offset: 0x004	 (R/W) */
	__IO uint32_t ProgramCmd;					  	  /*!< Offset: 0x008	 (R/W) */
	__IO uint32_t PageLatchsData;					  /*!< Offset: 0x00C	 (R/W) */
	__IO uint32_t SYSFlashCtrl;					  	  /*!< Offset: 0x010	 (R/W) */
	__IO uint32_t SYSFlashAddr;					  	  /*!< Offset: 0x014	 (R/W) */
	__IO uint32_t AcceleratorCtrl2;					  /*!< Offset: 0x018	 (R/W) */
	__IO uint32_t FlashInfo;					  	  /*!< Offset: 0x01C	 (R/W) */
	__IO uint32_t FlashStatus;					  	  /*!< Offset: 0x020	 (R/W) */
	__IO uint32_t SYSFlashData;					  	  /*!< Offset: 0x024	 (R/W) */
	__IO uint32_t Unlock;					  	  	  /*!< Offset: 0x028	 (R/W) */
	__IO uint32_t AHBReadRomBufferEn;				/*!< Offset: 0x028	 (R/W) */	
		 uint32_t RESERVED11[52];
	__IO uint32_t BootloaderRemap;					  /*!< Offset: 0x100	 (R/W) */
} HM_FLASH_TypeDef;

/*------------- CRC Engine (CRC) -----------------------------------------*/
/** @brief  CRC Engine (CRC)  register structure definition */
typedef struct
{
	__IO uint32_t MODE;								/*!< Offset: 0x000	 (R/W) */
	__IO uint32_t SEED;								/*!< Offset: 0x004	 (R/W) */
	__I  uint32_t SUM;								/*!< Offset: 0x008	 (R/W) */
	union {
	struct {
	__O  uint32_t DATA;								/*!< Offset: 0x00C	 (R/W) */
	} WR_DATA_DWORD;
	
	struct {
	__O  uint16_t DATA;
		 uint16_t RESERVED;
	}WR_DATA_WORD;
	
	struct {
	__O  uint8_t  DATA;
		 uint8_t  RESERVED[3];
	  }WR_DATA_BYTE;
	};
	__IO uint32_t LEN;								/*!< Offset: 0x010	 (R/W) */
	__O  uint32_t INT_CLR;						/*!< Offset: 0x014	 (R/W) */
	__I  uint32_t STATUS;							/*!< Offset: 0x018	 (R/W) */

} HM_CRC_TypeDef;

/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* Base addresses                                                             */
#define HM_FLASH_BASE        (0x00000000UL)
#define HM_ROMRAM_BASE       (0x01000000UL)
#define HM_RAM_BASE     	 (0x20000000UL)
#define HM_APB0_BASE         (0x40000000UL)
#define HM_APB1_BASE         (0x40020000UL)
#define HM_BITBAND1_BASE     (0x22000000UL)
#define HM_BITBAND2_BASE     (0x42000000UL)
#define HM_CM3_BASE          (0xE0000000UL)

/* APB0 peripherals                                                           */
// #define HM_WDT0_BASE         (HM_APB0_BASE + 0x00000)
// #define HM_WDT1_BASE         (HM_APB0_BASE + 0x01000)
#ifdef TARGET_MIPS
#define HM_WDT0_BASE         (0x80130000)
#define HM_WDT1_BASE         (0x80131000)
#endif
#ifdef TARGET_ARM
#define HM_WDT0_BASE         (0x00130000)
#define HM_WDT1_BASE         (0x00131000)
#endif
#ifdef TARGET_RISCV
#define HM_WDT0_BASE         (0x20130000)
#define HM_WDT1_BASE         (0x20131000)
#endif

//#define HM_GPIOA_BASE        (HM_APB0_BASE + 0x04000)
//#define HM_GPIOB_BASE        (HM_APB0_BASE + 0x05000)
//#define HM_GPIOC_BASE        (HM_APB0_BASE + 0x06000)
//#define HM_GPIOD_BASE        (HM_APB0_BASE + 0x07000)
#define HM_SSI0_BASE         (HM_APB0_BASE + 0x08000)
#define HM_SSI1_BASE         (HM_APB0_BASE + 0x09000)
#define HM_SSI2_BASE         (HM_APB0_BASE + 0x0A000)
#define HM_SSI3_BASE         (HM_APB0_BASE + 0x0B000)
#define HM_UART0_BASE        (HM_APB0_BASE + 0x0C000)
#define HM_UART1_BASE        (HM_APB0_BASE + 0x0D000)
#define HM_UART2_BASE        (HM_APB0_BASE + 0x0E000)
#define HM_UART3_BASE        (HM_APB0_BASE + 0x0F000)
#define HM_UART4_BASE        (HM_APB0_BASE + 0x10000)
#define HM_UART5_BASE        (HM_APB0_BASE + 0x11000)
#define HM_UART6_BASE        (HM_APB0_BASE + 0x12000)
#define HM_UART7_BASE        (HM_APB0_BASE + 0x13000)

/* APB1 peripherals                                                           */
#define HM_I2C0_BASE         (HM_APB1_BASE + 0x00000)
#define HM_I2C1_BASE         (HM_APB1_BASE + 0x01000)
#define HM_I2C2_BASE         (HM_APB1_BASE + 0x02000)
#define HM_I2C3_BASE         (HM_APB1_BASE + 0x03000)
#define HM_I2C4_BASE         (0x400C0000 + 0x0000)
#define HM_I2C5_BASE         (0x400C0000 + 0x1000)

//#define HM_GPIOE_BASE        (HM_APB1_BASE + 0x04000)
//#define HM_GPIOF_BASE        (HM_APB1_BASE + 0x05000)
//#define HM_GPIOG_BASE        (HM_APB1_BASE + 0x06000)
//#define HM_GPIOH_BASE        (HM_APB1_BASE + 0x07000)
#define HM_PWM0_BASE          (HM_APB1_BASE + 0x08000)
#define HM_PWM1_BASE          (HM_APB1_BASE + 0x09000)
#define HM_QEI0_BASE   	     (HM_APB1_BASE + 0x0C000)
#define HM_QEI1_BASE         (HM_APB1_BASE + 0x0D000)
#define HM_TIM0_BASE         (HM_APB1_BASE + 0x10000)
#define HM_TIM1_BASE         (HM_APB1_BASE + 0x11000)
#define HM_TIM2_BASE         (HM_APB1_BASE + 0x12000)
#define HM_TIM3_BASE         (HM_APB1_BASE + 0x13000)
#define HM_TIM4_BASE         (HM_APB1_BASE + 0x14000)

#define HM_ADC0_BASE         (HM_APB1_BASE + 0x18000)
#define HM_ADC1_BASE         (HM_APB1_BASE + 0x19000)
#define HM_AC_BASE           (HM_APB1_BASE + 0x1C000)
//#define HM_GPIOJ_BASE        (HM_APB1_BASE + 0x1D000)
#define HM_CAN0_BASE         (HM_APB1_BASE + 0x20000)
#define HM_CAN1_BASE         (HM_APB1_BASE + 0x21000)
#define HM_EMAC_BASE         (HM_APB1_BASE + 0x28000)
#define HM_USB_BASE          (HM_APB1_BASE + 0x30000)
#define HM_I2S0_BASE         (HM_APB1_BASE + 0x34000)
#define HM_EPI0_BASE         (HM_APB1_BASE + 0xB0000)
#define HM_FLASHCTRL_BASE    (HM_APB1_BASE + 0xDD000)
#define HM_SC_BASE    		 (HM_APB1_BASE + 0xDE000)
#define HM_UDMA_BASE         (HM_APB1_BASE + 0xDF000)

#define HM_GPIOA_BASE        (HM_APB1_BASE + 0x38000)
#define HM_GPIOB_BASE        (HM_APB1_BASE + 0x39000)
#define HM_GPIOC_BASE        (HM_APB1_BASE + 0x3A000)
#define HM_GPIOD_BASE        (HM_APB1_BASE + 0x3B000)
#define HM_GPIOE_BASE        (HM_APB1_BASE + 0x3C000)
#define HM_GPIOF_BASE        (HM_APB1_BASE + 0x3D000)
#define HM_GPIOG_BASE        (HM_APB1_BASE + 0x3E000)
#define HM_GPIOH_BASE        (HM_APB1_BASE + 0x3F000)
#define HM_GPIOJ_BASE        (HM_APB1_BASE + 0x40000)
#define HM_GPIOK_BASE        (HM_APB1_BASE + 0x41000)
#define HM_GPIOL_BASE        (HM_APB1_BASE + 0x42000)
#define HM_GPIOM_BASE        (HM_APB1_BASE + 0x43000)
#define HM_GPION_BASE        (HM_APB1_BASE + 0x44000)
#define HM_GPIOP_BASE        (HM_APB1_BASE + 0x45000)

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define HM_SC                ((HM_SC_TypeDef        *) HM_SC_BASE       )
#define HM_WDT0              ((HM_WDT_TypeDef       *) HM_WDT0_BASE     )
#define HM_WDT1              ((HM_WDT_TypeDef       *) HM_WDT1_BASE     )
#define HM_GPIOA             ((HM_GPIO_TypeDef      *) HM_GPIOA_BASE    )
#define HM_GPIOB             ((HM_GPIO_TypeDef      *) HM_GPIOB_BASE    )
#define HM_GPIOC             ((HM_GPIO_TypeDef      *) HM_GPIOC_BASE    )
#define HM_GPIOD             ((HM_GPIO_TypeDef      *) HM_GPIOD_BASE    )
#define HM_GPIOE             ((HM_GPIO_TypeDef      *) HM_GPIOE_BASE    )
#define HM_GPIOF             ((HM_GPIO_TypeDef      *) HM_GPIOF_BASE    )
#define HM_GPIOG             ((HM_GPIO_TypeDef      *) HM_GPIOG_BASE    )
#define HM_GPIOH             ((HM_GPIO_TypeDef      *) HM_GPIOH_BASE    )
#define HM_GPIOJ             ((HM_GPIO_TypeDef      *) HM_GPIOJ_BASE    )
#define HM_GPIOK             ((HM_GPIO_TypeDef      *) HM_GPIOK_BASE    )
#define HM_GPIOL             ((HM_GPIO_TypeDef      *) HM_GPIOL_BASE    )
#define HM_GPIOM             ((HM_GPIO_TypeDef      *) HM_GPIOM_BASE    )
#define HM_GPION             ((HM_GPIO_TypeDef      *) HM_GPION_BASE    )
#define HM_GPIOP             ((HM_GPIO_TypeDef      *) HM_GPIOP_BASE    )
#define HM_SSP0              ((HM_SSP_TypeDef       *) HM_SSI0_BASE     )
#define HM_SSP1              ((HM_SSP_TypeDef       *) HM_SSI1_BASE     )
#define HM_SSP2              ((HM_SSP_TypeDef       *) HM_SSI2_BASE     )
#define HM_SSP3              ((HM_SSP_TypeDef       *) HM_SSI3_BASE     )
#define HM_UART0             ((HM_UART_TypeDef      *) HM_UART0_BASE    )
#define HM_UART1             ((HM_UART_TypeDef      *) HM_UART1_BASE    )
#define HM_UART2             ((HM_UART_TypeDef      *) HM_UART2_BASE    )
#define HM_UART3             ((HM_UART_TypeDef      *) HM_UART3_BASE    )
#define HM_UART4             ((HM_UART_TypeDef      *) HM_UART4_BASE    )
#define HM_UART5             ((HM_UART_TypeDef      *) HM_UART5_BASE    )
#define HM_UART6             ((HM_UART_TypeDef      *) HM_UART6_BASE    )
#define HM_UART7             ((HM_UART_TypeDef      *) HM_UART7_BASE    )

#define HM_I2C0              ((HM_I2C_TypeDef       *) HM_I2C0_BASE     )
#define HM_I2C1              ((HM_I2C_TypeDef       *) HM_I2C1_BASE     )
#define HM_I2C2              ((HM_I2C_TypeDef       *) HM_I2C2_BASE     )
#define HM_I2C3              ((HM_I2C_TypeDef       *) HM_I2C3_BASE     )
#define HM_I2C4              ((HM_I2C_TypeDef       *) HM_I2C4_BASE     )
#define HM_I2C5              ((HM_I2C_TypeDef       *) HM_I2C5_BASE     )

#define HM_PWM0              ((HM_PWM_TypeDef       *) HM_PWM0_BASE      )
#define HM_PWM1              ((HM_PWM_TypeDef       *) HM_PWM1_BASE      )
#define HM_QEI0              ((HM_QEI_TypeDef       *) HM_QEI0_BASE     )
#define HM_QEI1              ((HM_QEI_TypeDef       *) HM_QEI1_BASE     )
#define HM_TIM0              ((HM_TIM_TypeDef       *) HM_TIM0_BASE     )
#define HM_TIM1              ((HM_TIM_TypeDef       *) HM_TIM1_BASE     )
#define HM_TIM2              ((HM_TIM_TypeDef       *) HM_TIM2_BASE     )
#define HM_TIM3              ((HM_TIM_TypeDef       *) HM_TIM3_BASE     )
#define HM_TIM4              ((HM_TIM_TypeDef       *) HM_TIM4_BASE     )

#define HM_ADC0              ((HM_ADC_TypeDef       *) HM_ADC0_BASE     )
#define HM_ADC1              ((HM_ADC_TypeDef       *) HM_ADC1_BASE     )
#define HM_COMP               ((HM_AC_TypeDef        *) HM_AC_BASE       )
#define HM_CAN0              ((HM_CAN_TypeDef       *) HM_CAN0_BASE     )
#define HM_CAN1              ((HM_CAN_TypeDef       *) HM_CAN1_BASE     )
#define HM_EMAC              ((HM_EMAC_TypeDef      *) HM_EMAC_BASE     )
#define HM_USB               ((HM_USB_TypeDef       *) HM_USB_BASE      )
#define HM_I2S               ((HM_I2S_TypeDef       *) HM_I2S0_BASE     )
#define HM_EPI               ((HM_EPI_TypeDef       *) HM_EPI0_BASE     )
#define HM_FLASH			 ((HM_FLASH_TypeDef     *) HM_FLASHCTRL_BASE)
#define HM_UDMA              ((HM_UDMA_TypeDef      *) HM_UDMA_BASE    )
 
#ifdef __cplusplus
}
#endif

#endif  /* __HM4C123_H */
