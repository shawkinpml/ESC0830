/**************************************************************************/ /**
                                                                              * @file     HM3S9B96.h
                                                                              * @brief    CMSIS Cortex-M3 Core Peripheral Access Layer Header File for
                                                                              *           Device HM3S9B96
                                                                              * @version  V0.01
                                                                              * @date     28. Sept 2021
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

#ifndef HM3S9B96_H
#define HM3S9B96_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup CM3DS_MPS2_Definitions HM3S9B96 Definitions
  This file defines all structures and symbols for HM3S9B96:
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

typedef enum IRQn {
  /******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn = -14,   /*!<  2 Cortex-M3 Non Maskable Interrupt                 */
  HardFault_IRQn = -13,        /*!<  3 Cortex-M3 Hard Fault Interrupt                   */
  MemoryManagement_IRQn = -12, /*!<  4 Cortex-M3 Memory Management Interrupt            */
  BusFault_IRQn = -11,         /*!<  5 Cortex-M3 Bus Fault Interrupt                    */
  UsageFault_IRQn = -10,       /*!<  6 Cortex-M3 Usage Fault Interrupt                  */
  SVCall_IRQn = -5,            /*!< 11 Cortex-M3 SV Call Interrupt                      */
  DebugMonitor_IRQn = -4,      /*!< 12 Cortex-M3 Debug Monitor Interrupt                */
  PendSV_IRQn = -2,            /*!< 14 Cortex-M3 Pend SV Interrupt                      */
  SysTick_IRQn = -1,           /*!< 15 Cortex-M3 System Tick Interrupt                  */

  /******  HM3S9B96 Specific Interrupt Numbers *******************************************************/
  // GPIOA_IRQn = 0,      /*!< GPIOA Interrupt                                  	*/
  // GPIOB_IRQn = 1,      /*!< GPIOB Interrupt									*/
  SAVE_CONTEXT_IRQ0             =   0,
	PLIC_IRQ1                     =   1,
  GPIOC_IRQn = 2,      /*!< GPIOC Interrupt 					 				*/
  GPIOD_IRQn = 3,      /*!< GPIOD Interrupt								  	*/
  GPIOE_IRQn = 4,      /*!< GPIOE Interrupt 								  	*/
  UART0_IRQn = 5,      /*!< UART0 Rx and Tx Interrupt							*/
  UART1_IRQn = 6,      /*!< UART1 Rx and Tx Interrupt							*/
  SSI0_IRQn = 7,       /*!< SSI0 Rx and Tx Interrupt							*/
  I2C0_IRQn = 8,       /*!< I2C0 Master and Slave Interrupt					*/
  PWMFault_IRQn = 9,   /*!< PWM Fault Interrupt								*/
  PWM0_IRQn = 10,      /*!< PWM Generator 0 Interrupt							*/
  PWM1_IRQn = 11,      /*!< PWM Generator 1 Interrupt	  					    */
  PWM2_IRQn = 12,      /*!< PWM Generator 2 Interrupt							*/
  QEI_IRQn = 13,       /*!< Quadrature Encoder Interface Interrupt				*/
  ADC0SS0_IRQn = 14,   /*!< ADC Sequence 0 Interrupt							*/
  ADC0SS1_IRQn = 15,   /*!< ADC Sequence 1 Interrupt							*/
  ADC0SS2_IRQn = 16,   /*!< ADC Sequence 2 Interrupt							*/
  ADC0SS3_IRQn = 17,   /*!< ADC Sequence 3 Interrupt							*/
  WDT_IRQn = 18,       /*!< Watchdog Timer Interrupt                         	*/
  TIMER0A_IRQn = 19,   /*!< Timer 0 subtimer A Interrupt                       */
  TIMER0B_IRQn = 20,   /*!< Timer 0 subtimer B Interrupt                       */
  TIMER1A_IRQn = 21,   /*!< Timer 1 subtimer A Interrupt                       */
  TIMER1B_IRQn = 22,   /*!< Timer 1 subtimer B Interrupt                       */
  TIMER2A_IRQn = 23,   /*!< Timer 2 subtimer A Interrupt 						*/
  TIMER2B_IRQn = 24,   /*!< Timer 2 subtimer B Interrupt 						*/
  AC0_IRQn = 25,       /*!< Analog Comparator 0 Interrupt                      */
  AC1_IRQn = 26,       /*!< Analog Comparator 1 Interrupt                      */
  AC2_IRQn = 27,       /*!< Analog Comparator 2 Interrupt						*/
  SC_IRQn = 28,        /*!< System Control (PLL, OSC, BO)						*/
  FLASH_IRQn = 29,     /*!< FLASH Control Interrupt                            */
  GPIOF_IRQn = 30,     /*!< GPIO Port F Interrupt                              */
  GPIOG_IRQn = 31,     /*!< GPIO Port G Interrupt                              */
  GPIOH_IRQn = 32,     /*!< GPIO Port H  Interrupt                             */
  UART2_IRQn = 33,     /*!< UART2 Rx and Tx Interrupt                          */
  SSI1_IRQn = 34,      /*!< SSI1 Rx and Tx Interrupt                           */
  TIMER3A_IRQn = 35,   /*!< Timer 3 subtimer A Interrupt                   	*/
  TIMER3B_IRQn = 36,   /*!< Timer 3 subtimer B Interrupt                       */
  I2C1_IRQn = 37,      /*!< I2C1 Master and Slave Interrupt                   	*/
  QEI1_IRQn = 38,      /*!< Quadrature Encoder 1 Interrupt                   	*/
  CAN0_IRQn = 39,      /*!< CAN0 Interrupt										*/
  CAN1_IRQn = 40,      /*!< CAN1 Interrupt                                    	*/
  Reserved0_IRQn = 41, /*!< Reserved 											*/
  ENET_IRQn = 42,      /*!< Ethernet Interrupt                               	*/
  Reserved1_IRQn = 43, /*!< Reserved 											*/
  USB_IRQn = 44,       /*!< USB0 Interrupt										*/
  PWM3_IRQn = 45,      /*!< PWM Generator 3 Interrupt							*/
  UDMA_IRQn = 46,      /*!< uDMA Software Transfer Interrupt					*/
  UDMAERR_IRQn = 47,   /*!< uDMA Error Interrupt								*/
  ADC1SS0_IRQn = 48,   /*!< ADC1 Sequence 0 Interrupt							*/
  ADC1SS1_IRQn = 49,   /*!< ADC1 Sequence 1 Interrupt							*/
  ADC1SS2_IRQn = 50,   /*!< ADC1 Sequence 2 Interrupt							*/
  ADC1SS3_IRQn = 51,   /*!< ADC1 Sequence 3 Interrupt							*/
  I2S0_IRQn = 52,      /*!< I2S0 Interrupt                   					*/
  EPI_IRQn = 53,       /*!< External Bus Interface 0 Interrupt                 */
  GPIOJ_IRQn = 54,     /*!< GPIO Port J Interrupt  							*/
} IRQn_Type;

/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M3 Processor and Core Peripherals */
#define __CM3_REV 0x0201         /*!< Core Revision r2p1                             */
#define __NVIC_PRIO_BITS 3       /*!< Number of Bits used for Priority Levels        */
#define __Vendor_SysTickConfig 0 /*!< Set to 1 if different SysTick Config is used   */
#define __MPU_PRESENT 1          /*!< MPU present or not                             */

/*@}*/ /* end of group CM3DS_MPS2_CMSIS */

#include "core_cm3.h"        /* Cortex-M3 processor and core peripherals           */
#include "system_HM3S9B96.h" /* CM3DS System include file                      */

/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/
/** @addtogroup CM3DS_MPS2_Peripherals CM3DS_MPS2 Peripherals
  CM3DS_MPS2 Device Specific Peripheral registers structures
  @{
*/

#if defined(__CC_ARM)
#pragma anon_unions
#endif

/*------------- System Control (SC) ------------------------------------------*/
/** @brief System Control (SC) register structure definition */
typedef struct {
  __I uint32_t DEVICE_ID; /*!< Offset: 0x00 (R/W)	 */
  uint32_t RESERVED1[11];
  __IO uint32_t PBORCTL; /*!< Offset: 0x30 (R/W)	 */
  uint32_t RESERVED2[3];
  __IO uint32_t SRCR0; /*!< Offset: 0x40 (R/W)	 */
  __IO uint32_t SRCR1; /*!< Offset: 0x44 (R/W)	 */
  __IO uint32_t SRCR2; /*!< Offset: 0x48 (R/W)	 */
  uint32_t RESERVED3;
  __IO uint32_t RIS;  /*!< Offset: 0x50 (R/W)	 */
  __IO uint32_t IMC;  /*!< Offset: 0x54 (R/W)	 */
  __IO uint32_t MISC; /*!< Offset: 0x58 (R/W)	 */
  __IO uint32_t RESC; /*!< Offset: 0x5C (R/W)	 */
  uint32_t RESERVED4[7];
  __IO uint32_t MOSCCTL; /*!< Offset: 0x7C (R/W)	 */
  uint32_t RESERVED5[32];
  __IO uint32_t RCGC0; /*!< Offset: 0x100 (R/W)	 */
  __IO uint32_t RCGC1; /*!< Offset: 0x104 (R/W)	 */
  __IO uint32_t RCGC2; /*!< Offset: 0x108 (R/W)	 */
  uint32_t RESERVED6;
  __IO uint32_t SCGC0; /*!< Offset: 0x110 (R/W)	 */
  __IO uint32_t SCGC1; /*!< Offset: 0x114 (R/W)	 */
  __IO uint32_t SCGC2; /*!< Offset: 0x118 (R/W)	 */
  uint32_t RESERVED7;
  __IO uint32_t DCGC0; /*!< Offset: 0x120 (R/W)	 */
  __IO uint32_t DCGC1; /*!< Offset: 0x124 (R/W)	 */
  __IO uint32_t DCGC2; /*!< Offset: 0x128 (R/W)	 */
  uint32_t RESERVED8[53];
  __IO uint32_t CPU_MODE;          /*!< Offset: 0x200 (R/W)	 */
  __IO uint32_t cfg_deep_sleep_en; /*!< Offset: 0x204 (R/W)	 */
  __IO uint32_t PVD_PU;            /*!< Offset: 0x208 (R/W)	 */
  __IO uint32_t LDO_SEL;           /*!< Offset: 0x20C (R/W)	 */
  __IO uint32_t PVD12_LV_O;        /*!< Offset: 0x210 (R/W)	 */
  __IO uint32_t PVD33_LV_O;        /*!< Offset: 0x214 (R/W)	 */
  __IO uint32_t MOSC_CFG;          /*!< Offset: 0x218 (R/W)	 */
  __IO uint32_t MOSC_DETECT_0;     /*!< Offset: 0x21C (R/W)	 */
  __IO uint32_t MOSC_DETECT_1;     /*!< Offset: 0x220 (R/W)	 */
  __IO uint32_t MOSC_DETECT_2;     /*!< Offset: 0x224 (R/W)	 */
  __IO uint32_t MOSC_ETH_CFG;      /*!< Offset: 0x228 (R/W)	 */
  __IO uint32_t PIOSC_CFG;         /*!< Offset: 0x22C (R/W)	 */
  __IO uint32_t OSC_CLK_MUX;       /*!< Offset: 0x230 (R/W)	 */
  __IO uint32_t CFG_REG_PLL0_0;    /*!< Offset: 0x234 (R/W)	 */
  __IO uint32_t CFG_REG_PLL0_1;    /*!< Offset: 0x238 (R/W)	 */
  __IO uint32_t CFG_REG_PLL0_2;    /*!< Offset: 0x23C (R/W)	 */
  __IO uint32_t PLL0_PRE_DIV;      /*!< Offset: 0x240 (R/W)	 */
  __IO uint32_t PLL0_ADC_CFG;      /*!< Offset: 0x244 (R/W)	 */
  uint32_t RESERVED9;
  __IO uint32_t PLL0_PHY_CFG;   /*!< Offset: 0x24C (R/W)	 */
  __IO uint32_t PLL0_SYS_CFG;   /*!< Offset: 0x250 (R/W)	 */
  __IO uint32_t CFG_REG_PLL1_0; /*!< Offset: 0x254 (R/W)	 */
  __IO uint32_t CFG_REG_PLL1_1; /*!< Offset: 0x258 (R/W)	 */
  __IO uint32_t CFG_REG_PLL1_2; /*!< Offset: 0x25C (R/W)	 */
  __IO uint32_t PLL1_PRE_DIV;   /*!< Offset: 0x260 (R/W)	 */
  __IO uint32_t PLL1_USB_CFG;   /*!< Offset: 0x264 (R/W)	 */
  uint32_t RESERVED10;
  __IO uint32_t SYS_CLK_DIV_TIMER_0_3;  /*!< Offset: 0x26C (R/W)	 */
  __IO uint32_t SYS_CLK_DIV_TIMER_4_7;  /*!< Offset: 0x270 (R/W)	 */
  __IO uint32_t SYS_CLK_DIV_TRACECLKIN; /*!< Offset: 0x274 (R/W)	 */
  __IO uint32_t SYS_CLK_DIV_PWM;        /*!< Offset: 0x278 (R/W)	 */
  __IO uint32_t SYS_CLK_DIV_CAN;        /*!< Offset: 0x27C (R/W)	 */
  uint32_t RESERVED11[32];
  __IO uint32_t SYSRESETn_M3_CTRL; /*!< Offset: 0x300 (R/W)	 */
  __IO uint32_t M3_CFG;            /*!< Offset: 0x304 (R/W)	 */
  uint32_t RESERVED12[6];
  __IO uint32_t M3_DEBUG;   /*!< Offset: 0x320 (R/W)	 */
  __IO uint32_t PMU_ENABLE; /*!< Offset: 0x324 (R/W)	 */
  uint32_t RESERVED13[23];
  __IO uint32_t MST_SLV_SEL_I2S; /*!< Offset: 0x384 (R/W)	 */
  __IO uint32_t I2S_RATE_CFG;    /*!< Offset: 0x388 (R/W)	 */
  __IO uint32_t I2S_MODE_CFG;    /*!< Offset: 0x38C (R/W)	 */
  __IO uint32_t MST_SLV_SEL_SSI; /*!< Offset: 0x390 (R/W)	 */
  uint32_t RESERVED14[3];
  __IO uint32_t IR_SEL_UART; /*!< Offset: 0x3A0 (R/W)	 */
  uint32_t RESERVED15[23];
  __IO uint32_t IO_SEL_UART1;     /*!< Offset: 0x400 (R/W)	 */
  __IO uint32_t CFG_RTC_SEL;      /*!< Offset: 0x404 (R/W)	 */
  __IO uint32_t CFG_SEL_C_OUT;    /*!< Offset: 0x408 (R/W)	 */
  __IO uint32_t CFG_SEL_PWM0_3;   /*!< Offset: 0x40C (R/W)	 */
  __IO uint32_t CFG_SEL_PWM4_7;   /*!< Offset: 0x410 (R/W)	 */
  __IO uint32_t CFG_SEL_FAULT0_3; /*!< Offset: 0x414 (R/W)	 */
  __IO uint32_t CFG_SEL_I2S;      /*!< Offset: 0x418 (R/W)	 */
  __IO uint32_t CFG_SEL_IDX0_1;   /*!< Offset: 0x41C (R/W)	 */
  __IO uint32_t CFG_SEL_PHAB0_1;  /*!< Offset: 0x420 (R/W)	 */
  __IO uint32_t CFG_SEL_UART2;    /*!< Offset: 0x424 (R/W)	 */
  __IO uint32_t CFG_SEL_SSI1;     /*!< Offset: 0x428 (R/W)	 */
  __IO uint32_t CFG_SEL_CAN0;     /*!< Offset: 0x42C (R/W)	 */
  __IO uint32_t CFG_SEL_I2C1;     /*!< Offset: 0x430 (R/W)	 */
  __IO uint32_t CFG_SEL_USB0;     /*!< Offset: 0x434 (R/W)	 */
  __IO uint32_t CFG_SEL_CCP0_1;   /*!< Offset: 0x438 (R/W)	 */
  __IO uint32_t CFG_SEL_CCP2_3;   /*!< Offset: 0x43C (R/W)	 */
  __IO uint32_t CFG_SEL_CCP4_5;   /*!< Offset: 0x440 (R/W)	 */
  __IO uint32_t CFG_SEL_CCP6_7;   /*!< Offset: 0x444 (R/W)	 */
  __IO uint32_t CFG_SEL_EPI;      /*!< Offset: 0x448 (R/W)	 */
  __IO uint32_t CFG_SEL_DC;       /*!< Offset: 0x44C (R/W)	 */
  __IO uint32_t SW_RST_N;         /*!< Offset: 0x500 (R/W)	 */
  uint32_t RESERVED16[2];         /*!< Offset: 0x504 (R/W)	 */
  __IO uint32_t USB_S_ADDR_UPPER; /*!< Offset: 0x50C (R/W)	 */
} HM_SC_TypeDef;

/*------------- General Purpose Input/Output (GPIO) --------------------------*/
/** @brief General Purpose Input/Output (GPIO) register structure definition */
typedef struct {
  __IO uint32_t DATA[256]; /*!< GPIO Data															 */
  __IO uint32_t DIR;       /*!< GPIO Direction														 */
  __IO uint32_t IS;        /*!< GPIO Interrupt Sense 												 */
  __IO uint32_t IBE;       /*!< GPIO Interrupt Both Edges											 */
  __IO uint32_t IEV;       /*!< GPIO Interrupt Event 												 */
  __IO uint32_t IM;        /*!< GPIO Interrupt Mask													 */
  __IO uint32_t RIS;       /*!< GPIO Raw Interrupt Status											 */
  __IO uint32_t MIS;       /*!< GPIO Masked Interrupt Status 										 */
  __O uint32_t ICR;        /*!< GPIO Interrupt Clear 												 */
  __IO uint32_t AFSEL;     /*!< GPIO Alternate Function Select										 */
  __I uint32_t RESERVED1[55];
  __IO uint32_t DR2R;      /*!< GPIO 2-mA Drive Select												 */
  __IO uint32_t DR4R;      /*!< GPIO 4-mA Drive Select												 */
  __IO uint32_t DR8R;      /*!< GPIO 8-mA Drive Select												 */
  __IO uint32_t ODR;       /*!< GPIO Open Drain Select												 */
  __IO uint32_t PUR;       /*!< GPIO Pull-Up Select													 */
  __IO uint32_t PDR;       /*!< GPIO Pull-Down Select												 */
  __IO uint32_t RESERVED2; /*!< GPIO Pull-Down Select												 */
  __IO uint32_t DEN;       /*!< GPIO Digital Enable	  											 */
  __IO uint32_t LOCK;      /*!< GPIO Pull-Down Select												 */
  __IO uint32_t CR;        /*!< GPIO Ctrl	  											 */
  __IO uint32_t AMSEL;     /*!< GPIO Pull-Down Select												 */
  __IO uint32_t PORTCTRL;
} HM_GPIO_TypeDef;
/** @brief General Purpose Input/Output interrupt (GPIOINT) register structure definition */
typedef struct {
  __I uint32_t IntStatus;   /*!< Offset: 0x080 (R/W)	*/
  __I uint32_t IO0IntStatR; /*!< Offset: 0x084 (R/W)	*/
  __I uint32_t IO0IntStatF; /*!< Offset: 0x088 (R/W)	*/
  __O uint32_t IO0IntClr;   /*!< Offset: 0x08c (R/W)	*/
  __IO uint32_t IO0IntEnR;  /*!< Offset: 0x090 (R/W)	*/
  __IO uint32_t IO0IntEnF;  /*!< Offset: 0x094 (R/W)	*/
  uint32_t RESERVED0[3];    /*!< Offset: 0x098 (R/W)	*/
  __I uint32_t IO2IntStatR; /*!< Offset: 0x0a4 (R/W)	*/
  __I uint32_t IO2IntStatF; /*!< Offset: 0x0a8 (R/W)	*/
  __O uint32_t IO2IntClr;   /*!< Offset: 0x0ac (R/W)	*/
  __IO uint32_t IO2IntEnR;  /*!< Offset: 0x0b0 (R/W)	*/
  __IO uint32_t IO2IntEnF;  /*!< Offset: 0x0b4 (R/W)	*/
} HM_GPIOINT_TypeDef;
/*------------- Timer (TIM) --------------------------------------------------*/
/** @brief Timer (TIM) register structure definition */
typedef struct {
  __IO uint32_t CFG;       /*!< Offset: 0x000 (R/W)	*/
  __IO uint32_t TAMR;      /*!< Offset: 0x004 (R/W)	*/
  __IO uint32_t TBMR;      /*!< Offset: 0x008 (R/W)	*/
  __IO uint32_t CTL;       /*!< Offset: 0x00C (R/W)	*/
  __IO uint32_t SYNC;      /*!< Offset: 0x010 (R/W)	*/
  uint32_t RESERVED1;      /*!< Offset: 0x00C (R/W)	*/
  __IO uint32_t IMR;       /*!< Offset: 0x018 (R/W)	*/
  __IO uint32_t RIS;       /*!< Offset: 0x01C (R/W)	*/
  __IO uint32_t MIS;       /*!< Offset: 0x020 (R/W)	*/
  __IO uint32_t ICR;       /*!< Offset: 0x024 (R/W)	*/
  __IO uint32_t TAILR;     /*!< Offset: 0x028 (R/W)	*/
  __IO uint32_t TBILR;     /*!< Offset: 0x02C (R/W)	*/
  __IO uint32_t TAMATCHR;  /*!< Offset: 0x030 (R/W)	*/
  __IO uint32_t TBMATCHR;  /*!< Offset: 0x034 (R/W)	*/
  __IO uint32_t TAPR;      /*!< Offset: 0x038 (R/W)	*/
  __IO uint32_t TBPR;      /*!< Offset: 0x03C (R/W)	*/
  __IO uint32_t TAPMR;     /*!< Offset: 0x040 (R/W)	*/
  __IO uint32_t TBPMR;     /*!< Offset: 0x044 (R/W)	*/
  __IO uint32_t TAR;       /*!< Offset: 0x048 (R/W)	*/
  __IO uint32_t TBR;       /*!< Offset: 0x04C (R/W)	*/
  __IO uint32_t TAV;       /*!< Offset: 0x050 (R/W)	*/
  __IO uint32_t TBV;       /*!< Offset: 0x054 (R/W)	*/
  __IO uint32_t RTCPD;     /*!< Offset: 0x058 (R/W)	*/
  __IO uint32_t TAPS;      /*!< Offset: 0x05C (R/W)	*/
  __IO uint32_t TBPS;      /*!< Offset: 0x060 (R/W)	*/
  __IO uint32_t TAPV;      /*!< Offset: 0x064 (R/W)	*/
  __IO uint32_t TBPV;      /*!< Offset: 0x068 (R/W)	*/
  uint32_t RESERVED2[981]; /*!< Offset: 0x00C (R/W)	*/
  __IO uint32_t PP;        /*!< Offset: 0xFC0 (R/W)	*/
} HM_TIM_TypeDef;

/*------------- Pulse-Width Modulation (PWM) ---------------------------------*/
/** @brief Pulse-Width Modulation (PWM) register structure definition */
typedef struct {              /*!< 0x040	0x080	0x0C0	0x100	*/
  __IO uint32_t PWMCTL;       /*!< Offset: 0x000 (R/W)	*/
  __IO uint32_t PWMINTEN;     /*!< Offset: 0x004 (R/W)	*/
  __IO uint32_t PWMRIS;       /*!< Offset: 0x008 (R/W)	*/
  __IO uint32_t PWMISC;       /*!< Offset: 0x00C (R/W)	*/
  __IO uint32_t PWMLOAD;      /*!< Offset: 0x010 (R/W)	*/
  __IO uint32_t PWMCOUNT;     /*!< Offset: 0x014 (R/W)	*/
  __IO uint32_t PWMCMPA;      /*!< Offset: 0x018 (R/W)	*/
  __IO uint32_t PWMCMPB;      /*!< Offset: 0x01C (R/W)	*/
  __IO uint32_t PWMGENA;      /*!< Offset: 0x020 (R/W)	*/
  __IO uint32_t PWMGENB;      /*!< Offset: 0x024 (R/W)	*/
  __IO uint32_t PWMDBCTL;     /*!< Offset: 0x028 (R/W)	*/
  __IO uint32_t PWMDBRISE;    /*!< Offset: 0x02C (R/W)	*/
  __IO uint32_t PWMDBFALL;    /*!< Offset: 0x030 (R/W)	*/
  __IO uint32_t PWMFLTSRC0;   /*!< Offset: 0x034 (R/W)	*/
  __IO uint32_t PWMFLTSRC1;   /*!< Offset: 0x038 (R/W)	*/
  __IO uint32_t PWMMINFLTPER; /*!< Offset: 0x03C (R/W)	*/
} HM_PWMCH_TypeDef;

typedef struct {               /*!< 0x800	0x880	0x900	0x980	*/
  __IO uint32_t PWMFLTSEN;     /*!< Offset: 0x000 (R/W)	*/
  __IO uint32_t PWMFLTSTAT0;   /*!< Offset: 0x004 (R/W)	*/
  __IO uint32_t PWMFLTSTAT1;   /*!< Offset: 0x008 (R/W)	*/
  __IO uint32_t RESERVED1[29]; /*!< Offset: 0x00C (R/W)	*/
} HM_PWMCHEXT_TypeDef;

typedef struct {
  __IO uint32_t PWMCTL;            /*!< Offset: 0x000 (R/W)	*/
  __IO uint32_t PWMSYNC;           /*!< Offset: 0x004 (R/W)	*/
  __IO uint32_t PWMENABLE;         /*!< Offset: 0x008 (R/W)	*/
  __IO uint32_t PWMINVERT;         /*!< Offset: 0x00C (R/W)	*/
  __IO uint32_t PWMFAULT;          /*!< Offset: 0x010 (R/W)	*/
  __IO uint32_t PWMINTEN;          /*!< Offset: 0x014 (R/W)	*/
  __IO uint32_t PWMRIS;            /*!< Offset: 0x018 (R/W)	*/
  __IO uint32_t PWMISC;            /*!< Offset: 0x01C (R/W)	*/
  __IO uint32_t PWMSTATUS;         /*!< Offset: 0x020 (R/W)	*/
  __IO uint32_t PWMFAULTVAL;       /*!< Offset: 0x024 (R/W)	*/
  __IO uint32_t PWMENUPD;          /*!< Offset: 0x028 (R/W)	*/
  uint32_t RESERVED1[5];           /*!< Offset: 0x030 (R/W)	*/
  HM_PWMCH_TypeDef PWMCH[4];       /*!< Offset: 0x040 (R/W)	*/
  __IO uint32_t PWM_CAP_CTRL;      /*!< Offset: 0x140 (R/W)	*/
  __IO uint32_t PWM_CAP_RT_CLR;    /*!< Offset: 0x144 (R/W)	*/
  __IO uint32_t PWM0CAP_I0;        /*!< Offset: 0x148 (R/W)	*/
  __IO uint32_t PWM1CAP_I0;        /*!< Offset: 0x14C (R/W)	*/
  __IO uint32_t PWM2CAP_I0;        /*!< Offset: 0x150 (R/W)	*/
  __IO uint32_t PWM3CAP_I0;        /*!< Offset: 0x154 (R/W)	*/
  __IO uint32_t PWM0CAP_I1;        /*!< Offset: 0x158 (R/W)	*/
  __IO uint32_t PWM1CAP_I1;        /*!< Offset: 0x15C (R/W)	*/
  __IO uint32_t PWM2CAP_I1;        /*!< Offset: 0x160 (R/W)	*/
  __IO uint32_t PWM3CAP_I1;        /*!< Offset: 0x164 (R/W)	*/
  uint32_t RESERVED2[2];           /*!< Offset: 0x168 (R/W)	*/
  __IO uint32_t PWMPR;             /*!< Offset: 0x170 (R/W)	*/
  __IO uint32_t PWMPC;             /*!< Offset: 0x174 (R/W)	*/
  uint32_t RESERVED3[418];         /*!< Offset: 0x178 (R/W)	*/
  HM_PWMCHEXT_TypeDef PWMCHEXT[4]; /*!< Offset: 0x800 (R/W)	*/
} HM_PWM_TypeDef;

/** @brief  Universal Asynchronous Receiver Transmitter 0 (UART0) register structure definition */
typedef struct {
  __IO uint32_t CTRL; /*!< Offset: 0x000 (R/W)	*/
  __IO uint32_t MODE; /*!< Offset: 0x004 (R/W)	*/
  __IO uint32_t IER;  /*!< Offset: 0x008 (W)	*/
  __IO uint32_t IDR;  /*!< Offset: 0x00c (W)	*/
  __IO uint32_t IMR;  /*!< Offset: 0x010 (R)	*/
  __IO uint32_t CISR; /*!< Offset: 0x014 (R/W)	*/
  __IO uint32_t BRGR; /*!< Offset: 0x018 (R/W)	*/
  __IO uint32_t RTOR; /*!< Offset: 0x01c (R/W)	*/
  __IO uint32_t RTR;  /*!< Offset: 0x020 (R/W)	*/
  __IO uint32_t MCR;  /*!< Offset: 0x024 (R/W)	*/
  __IO uint32_t MSR;  /*!< Offset: 0x028 (R)	    */
  __IO uint32_t CSR;  /*!< Offset: 0x02c (R)	    */
  union {
    __IO uint32_t RFIFO; /*!< Offset: 0x030 (R/W)	*/
    __IO uint32_t TFIFO;
  };

  __IO uint32_t BDIVR;                      /*!< Offset: 0x034 (R/W)	*/
  __IO uint32_t FCDR;                       /*!< Offset: 0x038 (R/W)	*/
  __IO uint32_t RPWR;                       /*!< Offset: 0x03c (R/W)	*/
  __IO uint32_t TPWR;                       /*!< Offset: 0x040 (R/W)	*/
  __IO uint32_t TTR;                        /*!< Offset: 0x044 (R/W)	*/
  __IO uint32_t RBSR;                       /*!< Offset: 0x048 (R)	*/
  uint32_t Reserved[13];                    /*!< Offset: 0x04C+13*4 (R)	*/
  __IO uint32_t RS485CTRL;                  /*!< Offset: 0x080 (R/W)	*/
  __IO uint32_t RS485ADDR_MATCH;            /*!< Offset: 0x084 (R/W)	*/
  __IO uint32_t RS485OE_DELAY;              /*!< Offset: 0x088 (R/W)	*/
  __IO uint32_t RS485_RECEIVE_EN;           /*!< Offset: 0x08c (R/W)	*/
  __IO uint32_t RS485_RXFIFO_STORE_FLAG;    /*!< Offset: 0x090 (R)	*/
  __IO uint32_t RS485_RXDATA_STORE_RDY_INT; /*!< Offset: 0x094 (R)	*/
  __IO uint32_t RS485_NMM_RXDIS_ADDR;       /*!< Offset: 0x098 (R)	*/
  __IO uint32_t UART_OR_IRMODE_CTRL;        /*!< Offset: 0x09c (R/W)	*/
  __IO uint32_t UA_DMAMODE_CTRL;            /*!< Offset: 0x0a0 (R/W)	*/

} HM_UART_TypeDef;

/*------------- Synchronous Serial Communication (SSP) -----------------------*/
/** @brief  Synchronous Serial Communication (SSP) register structure definition */
typedef struct {
  __IO uint32_t CTRLR0;         /*!< Offset: 0x000 (R/W)     Control 	*/
  __IO uint32_t CTRLR1;         /*!< Offset: 0x004 (R/W)     Control 	*/
  __IO uint32_t SSIENR;         /*!< Offset: 0x008 (R/W)     SSI Enable	*/
  __IO uint32_t MWCR;           /*!< Offset: 0x00c (R/W)	 Microwire Control*/
  __IO uint32_t SER;            /*!< Offset: 0x010 (R/W)	 Slave Enable */
  __IO uint32_t BAUDR;          /*!< Offset: 0x014 (R/W)	 Slave Baud Rate Select*/
  __IO uint32_t TXFTLR;         /*!< Offset: 0x018 (R/W)	 Transmit FIFO Threshold Level*/
  __IO uint32_t RXFTLR;         /*!< Offset: 0x01c (R/W)	 Receive FIFO Threshold Level*/
  __IO uint32_t TXFLR;          /*!< Offset: 0x020 (R/W)	 Transmit FIFO Level */
  __IO uint32_t RXFLR;          /*!< Offset: 0x024 (R/W)	 Receive FIFO Level */
  __IO uint32_t SR;             /*!< Offset: 0x028 (R/W)	 Status */
  __IO uint32_t IMR;            /*!< Offset: 0x02c (R/W)	 Interrupt Mask*/
  __IO uint32_t ISR;            /*!< Offset: 0x030 (R/W)	 Interrupt Status*/
  __IO uint32_t RISR;           /*!< Offset: 0x034 (R/W)	 Raw Interrupt Status*/
  __IO uint32_t TXOICR;         /*!< Offset: 0x038 (R/W)	 Transmit FIFO Overflow Interrupt Clear*/
  __IO uint32_t RXOICR;         /*!< Offset: 0x03c (R/W)	 Receive FIFO Overflow Interrupt Clear*/
  __IO uint32_t RXUICR;         /*!< Offset: 0x040 (R/W)	 Receive FIFO Underflow Interrupt Clear */
  __IO uint32_t MSTICR;         /*!< Offset: 0x044 (R/W)	 Multi-Master Interrupt Clear*/
  __IO uint32_t ICR;            /*!< Offset: 0x048 (R/W)	 Slave Enable*/
  __IO uint32_t DMACR;          /*!< Offset: 0x04c (R/W)	 DMA Control*/
  __IO uint32_t DMATDLR;        /*!< Offset: 0x050 (R/W)	 DMA Transmit Data Level*/
  __IO uint32_t DMARDLR;        /*!< Offset: 0x054 (R/W)	 DMA Receive Data Level*/
  __IO uint32_t IDR;            /*!< Offset: 0x058 (R/W)	 Identification */
  __IO uint32_t SSI_VERSION_ID; /*!< Offset: 0x05c (R/W)	 coreKit version ID */
  __IO uint32_t DRX;            /*!< Offset: 0x060 (R/W)	 DataX */
  uint32_t Reserved0[35];
  __IO uint32_t RX_SAMPLE_DLY;  /*!< Offset: 0x0f0 (R/W)	 RX Sample Delay*/
  __IO uint32_t SPI_CTRLR0;     /*!< Offset: 0x0f4 (R/W)	 SPI Control*/
  __IO uint32_t TXD_DRIVE_EDGE; /*!< Offset: 0x0f8 (R/W)	 Transmit Drive Edge*/
  __IO uint32_t RSVD;           /*!< Offset: 0x0fc (R/W)	 RSVD - Reserved address location*/
} HM_SSP_CFG_TypeDef;
typedef struct {
  HM_SSP_CFG_TypeDef SSP_M;   /*!< Offset: 0x000 (R/W)	*/
  HM_SSP_CFG_TypeDef SSP_S;   /*!< Offset: 0x100 (R/W)	*/
  __IO uint32_t SSI_MSCTRL;   /*!< Offset: 0x200 (R/W)	*/
  __I uint32_t SSI_SLEEP;     /*!< Offset: 0x204 (R/W)	*/
  __I uint32_t SSI_BUSY;      /*!< Offset: 0x208 (R/W)	*/
  __I uint32_t SSI_IN_N_CTRL; /*!< Offset: 0x20c (R/W)	*/
  __IO uint32_t SSI_DMA_CTRL; /*!< Offset: 0x210 (R/W)	*/

} HM_SSP_TypeDef;

/*------------- Inter-Integrated Circuit (I2C) -------------------------------*/
/** @brief  Inter-Integrated Circuit (I2C) register structure definition */
typedef struct {
  __IO uint32_t CON;      /*!< Offset: 0x000 (R/W)	*/
  __IO uint32_t TAR;      /*!< Offset: 0x004 (R/W)	*/
  __IO uint32_t SAR;      /*!< Offset: 0x008 (R/W)	*/
  __IO uint32_t HS_MADDR; /*!< Offset: 0x00c (R/W)	*/
  __IO uint32_t DATA_CMD; /*!< Offset: 0x010 (R/W)	*/
  union {
    __IO uint32_t SS_SCL_HCNT; /*!< Offset: 0x014 (R/W)	*/
    __IO uint32_t UFM_SCL_HCNT;
  };
  union {
    __IO uint32_t SS_SCL_LCNT; /*!< Offset: 0x018 (R/W)	*/
    __IO uint32_t UFM_SCL_LCNT;
  };
  union {
    __IO uint32_t FS_SCL_HCNT; /*!< Offset: 0x01c (R/W)	*/
    __IO uint32_t UFM_TBUF_CNT;
  };
  __IO uint32_t FS_SCL_LCNT;        /*!< Offset: 0x020 (R/W)	*/
  __IO uint32_t HS_SCL_HCNT;        /*!< Offset: 0x024 (R/W)	*/
  __IO uint32_t HS_SCL_LCNT;        /*!< Offset: 0x028 (R/W)	*/
  __IO uint32_t INTR_STAT;          /*!< Offset: 0x02C (R/W)	*/
  __IO uint32_t INTR_MASK;          /*!< Offset: 0x030 (R/W)	*/
  __IO uint32_t RAW_INTR_STAT;      /*!< Offset: 0x034 (R/W)	*/
  __IO uint32_t RX_TL;              /*!< Offset: 0x038 (R/W)	*/
  __IO uint32_t TX_TL;              /*!< Offset: 0x03c (R/W)	*/
  __IO uint32_t CLR_INTR;           /*!< Offset: 0x040 (R/W)	*/
  __IO uint32_t CLR_RX_UNDER;       /*!< Offset: 0x044 (R/W)	*/
  __IO uint32_t CLR_RX_OVER;        /*!< Offset: 0x048 (R/W)	*/
  __IO uint32_t CLR_TX_OVER;        /*!< Offset: 0x04c (R/W)	*/
  __IO uint32_t CLR_RD_REQ;         /*!< Offset: 0x050 (R/W)	*/
  __IO uint32_t CLR_TX_ABRT;        /*!< Offset: 0x054 (R/W)	*/
  __IO uint32_t CLR_RX_DONE;        /*!< Offset: 0x058 (R/W)	*/
  __IO uint32_t CLR_ACTIVITY;       /*!< Offset: 0x05c (R/W)	*/
  __IO uint32_t CLR_STOP_DET;       /*!< Offset: 0x060 (R/W)	*/
  __IO uint32_t CLR_START_DET;      /*!< Offset: 0x064 (R/W)	*/
  __IO uint32_t CLR_GEN_CALL;       /*!< Offset: 0x068 (R/W)	*/
  __IO uint32_t ENABLE;             /*!< Offset: 0x06c (R/W)	*/
  __IO uint32_t STATUS;             /*!< Offset: 0x070 (R/W)	*/
  __IO uint32_t TXFLR;              /*!< Offset: 0x074 (R/W)	*/
  __IO uint32_t RXFLR;              /*!< Offset: 0x078 (R/W)	*/
  __IO uint32_t SDA_HOLD;           /*!< Offset: 0x07c (R/W)	*/
  __IO uint32_t TX_ABRT_SOURCE;     /*!< Offset: 0x080 (R/W)	*/
  __IO uint32_t SLV_DATA_NACK_ONLY; /*!< Offset: 0x084 (R/W)	*/
  __IO uint32_t DMA_CR;             /*!< Offset: 0x088 (R/W)	*/
  __IO uint32_t DMA_TDLR;           /*!< Offset: 0x08c (R/W)	*/
  __IO uint32_t DMA_RDLR;           /*!< Offset: 0x090 (R/W)	*/
  __IO uint32_t SDA_SETUP;          /*!< Offset: 0x094 (R/W)	*/
  __IO uint32_t ACK_GENERAL_CALL;   /*!< Offset: 0x098 (R/W)	*/
  __IO uint32_t ENABLE_STATUS;      /*!< Offset: 0x09c (R/W)	*/
  union {
    __IO uint32_t FS_SPKLEN; /*!< Offset: 0x0a0 (R/W)	*/
    __IO uint32_t UFM_SPKLEN;
  };
  __IO uint32_t HS_SPKLEN;                  /*!< Offset: 0x0a4 (R/W)	*/
  __IO uint32_t CLR_RESTART_DET;            /*!< Offset: 0x0a8 (R/W)	*/
  __IO uint32_t SCL_STUCK_AT_LOW_TIMEOUT;   /*!< Offset: 0x0ac (R/W)	*/
  __IO uint32_t SDA_STUCK_AT_LOW_TIMEOUT;   /*!< Offset: 0x0b0 (R/W)	*/
  __IO uint32_t CLR_SCL_STUCK_DET;          /*!< Offset: 0x0b4 (R/W)	*/
  __IO uint32_t DEVICE_ID;                  /*!< Offset: 0x0b8 (R/W)	*/
  __IO uint32_t SMBUS_CLK_LOW_SEXT;         /*!< Offset: 0x0bc (R/W)	*/
  __IO uint32_t SMBUS_CLK_LOW_MEXT;         /*!< Offset: 0x0c0 (R/W)	*/
  __IO uint32_t SMBUS_THIGH_MAX_IDLE_COUNT; /*!< Offset: 0x0c4 (R/W)	*/
  __IO uint32_t SMBUS_INTR_STAT;            /*!< Offset: 0x0c8 (R/W)	*/
  __IO uint32_t SMBUS_INTR_MASK;            /*!< Offset: 0x0cc (R/W)	*/
  __IO uint32_t SMBUS_RAW_INTR_STAT;        /*!< Offset: 0x0d0 (R/W)	*/
  __IO uint32_t CLR_SMBUS_INTR;             /*!< Offset: 0x0d4 (R/W)	*/
  __IO uint32_t OPTIONAL_SAR;               /*!< Offset: 0x0d8 (R/W)	*/
  __IO uint32_t SMBUS_UDID_LSB_OR_WORD0;    /*!< Offset: 0x0dc (R/W)	*/
  __IO uint32_t SMBUS_UDID_WORD1;           /*!< Offset: 0x0e0 (R/W)	*/
  __IO uint32_t SMBUS_UDID_WORD2;           /*!< Offset: 0x0e4 (R/W)	*/
  __IO uint32_t SMBUS_UDID_WORD3;           /*!< Offset: 0x0e8 (R/W)	*/
  uint32_t Reserved0;
  __IO uint32_t TIMEOUT_RST;  /*!< Offset: 0x0f0 (R/W)	*/
  __IO uint32_t COMP_PARAM_1; /*!< Offset: 0x0f4 (R/W)	*/
  __IO uint32_t COMP_VERSION; /*!< Offset: 0x0f8 (R/W)	*/
  __IO uint32_t COMP_TYPE;    /*!< Offset: 0x0fc (R/W)	*/
  __IO uint32_t SAR2;         /*!< Offset: 0x100 (R/W)	*/
  __IO uint32_t SAR3;         /*!< Offset: 0x104 (R/W)	*/
  __IO uint32_t SAR4;         /*!< Offset: 0x108 (R/W)	*/
  uint32_t Reserved1[4];
  __IO uint32_t CLR_WR_REQ;            /*!< Offset: 0x11c (R/W)	*/
  __IO uint32_t CLR_SLV_ADDR_TAG;      /*!< Offset: 0x120 (R/W)	*/
  __IO uint32_t SAR2_SMBUS_UDID_WORD0; /*!< Offset: 0x124 (R/W)	*/
  __IO uint32_t SAR2_SMBUS_UDID_WORD1; /*!< Offset: 0x128 (R/W)	*/
  __IO uint32_t SAR2_SMBUS_UDID_WORD2; /*!< Offset: 0x12c (R/W)	*/
  __IO uint32_t SAR2_SMBUS_UDID_WORD3; /*!< Offset: 0x130 (R/W)	*/
  __IO uint32_t SAR3_SMBUS_UDID_WORD0; /*!< Offset: 0x134 (R/W)	*/
  __IO uint32_t SAR3_SMBUS_UDID_WORD1; /*!< Offset: 0x138 (R/W)	*/
  __IO uint32_t SAR3_SMBUS_UDID_WORD2; /*!< Offset: 0x13c (R/W)	*/
  __IO uint32_t SAR3_SMBUS_UDID_WORD3; /*!< Offset: 0x140 (R/W)	*/
  __IO uint32_t SAR4_SMBUS_UDID_WORD0; /*!< Offset: 0x144 (R/W)	*/
  __IO uint32_t SAR4_SMBUS_UDID_WORD1; /*!< Offset: 0x148 (R/W)	*/
  __IO uint32_t SAR4_SMBUS_UDID_WORD2; /*!< Offset: 0x14c (R/W)	*/
  __IO uint32_t SAR4_SMBUS_UDID_WORD3; /*!< Offset: 0x150 (R/W)	*/
} HM_I2C_TypeDef;

/*------------- Inter IC Sound (I2S) -----------------------------------------*/
/** @brief  Inter IC Sound (I2S) register structure definition */
typedef struct {
  __IO uint32_t IER;   /*!< Offset: 0x000 (R/W)	*/
  __IO uint32_t IRER;  /*!< Offset: 0x004 (R/W)	*/
  __IO uint32_t ITER;  /*!< Offset: 0x008 (R/W)	*/
  __IO uint32_t CER;   /*!< Offset: 0x00c (R/W)	*/
  __IO uint32_t CCR;   /*!< Offset: 0x010 (R/W)	*/
  __IO uint32_t RXFFR; /*!< Offset: 0x014 (R/W)	*/
  __IO uint32_t TXFFR; /*!< Offset: 0x018 (R/W)	*/
  __IO uint32_t SR;    /*!< Offset: 0x01C (R/W)	*/
  union {
    __IO uint32_t LRBRx; /*!< Offset: 0x020 (R/W)	*/
    __IO uint32_t LTHRx;
  };
  union {
    __IO uint32_t RRBRx; /*!< Offset: 0x024 (R/W)	*/
    __IO uint32_t RTHRx;
  };

  __IO uint32_t RERx;             /*!< Offset: 0x028 (R/W)	*/
  __IO uint32_t TERx;             /*!< Offset: 0x02C (R/W)	*/
  __IO uint32_t RCRx;             /*!< Offset: 0x030 (R/W)	*/
  __IO uint32_t TCRx;             /*!< Offset: 0x034 (R/W)	*/
  __IO uint32_t ISRx;             /*!< Offset: 0x038 (R/W)	*/
  __IO uint32_t IMRx;             /*!< Offset: 0x03C (R/W)	*/
  __IO uint32_t RORx;             /*!< Offset: 0x040 (R/W)	*/
  __IO uint32_t TORx;             /*!< Offset: 0x044 (R/W)	*/
  __IO uint32_t RFCRx;            /*!< Offset: 0x048 (R/W)	*/
  __IO uint32_t TFCRx;            /*!< Offset: 0x04C (R/W)	*/
  __IO uint32_t RFFx;             /*!< Offset: 0x050 (R/W)	*/
  __IO uint32_t TFFx;             /*!< Offset: 0x054 (R/W)	*/
  uint32_t Reserved1[2];          /*!< Offset: 0x058 (R/W)	*/
  uint32_t Reserved2[88];         /*!< Offset: 0x060 (R/W)	*/
  __IO uint32_t RXDMA;            /*!< Offset: 0x1C0 (R/W)	*/
  __IO uint32_t RRXDMA;           /*!< Offset: 0x1C4 (R/W)	*/
  __IO uint32_t TXDMA;            /*!< Offset: 0x1C8 (R/W)	*/
  __IO uint32_t RTXDMA;           /*!< Offset: 0x1CC (R/W)	*/
  uint32_t Reserved3[8];          /*!< Offset: 0x1D0 (R/W)	*/
  __IO uint32_t I2S_COMP_PARAM_2; /*!< Offset: 0x1F0 (R/W)	*/
  __IO uint32_t I2S_COMP_PARAM_1; /*!< Offset: 0x1F4 (R/W)	*/
  __IO uint32_t I2S_COMP_VERSION; /*!< Offset: 0x1F8 (R/W)	*/
  __IO uint32_t I2S_COMP_TYPE;    /*!< Offset: 0x1FC (R/W)	*/
  __IO uint32_t DMACR;            /*!< Offset: 0x200 (R/W)	*/

  __IO uint32_t RXDMA_CH0; /*!< Offset: 0x204 (R/W)	*/
  __IO uint32_t RXDMA_CH1; /*!< Offset: 0x208 (R/W)	*/
  uint32_t Reserved4[2];
  __IO uint32_t TXDMA_CH0; /*!< Offset: 0x214 (R/W)	*/
  __IO uint32_t TXDMA_CH1; /*!< Offset: 0x218 (R/W)	*/
  uint32_t Reserved5[2];
  union {
    __IO uint32_t RSLOTx; /*!< Offset: 0x224 (R/W)	*/
    __IO uint32_t TSLOTx;
  };
  uint32_t Reserved6[886]; /*!< Offset: 0x228 (R/W)	*/
} HM_I2S_CFG_TypeDef;

typedef struct {
  HM_I2S_CFG_TypeDef I2S_M;     /*!< Offset: 0x0000 (R/W)	*/
  HM_I2S_CFG_TypeDef I2S_S;     /*!< Offset: 0x1000 (R/W)	*/
  __IO uint32_t I2SMSCTRL;      /*!< Offset: 0x2000 (R/W)	*/
  __IO uint32_t I2STX_RATE;     /*!< Offset: 0x2004 (R/W)	*/
  __IO uint32_t I2SRX_RATE;     /*!< Offset: 0x2008 (R/W)	*/
  __IO uint32_t I2STXMODE;      /*!< Offset: 0x200C (R/W)	*/
  __IO uint32_t I2SRXMODE;      /*!< Offset: 0x2010 (R/W)	*/
  __IO uint32_t I2STXBITRATE;   /*!< Offset: 0x2014 (R/W)	*/
  __IO uint32_t I2SRXBITRATE;   /*!< Offset: 0x2018 (R/W)	*/
  __IO uint32_t I2SDMACHANNEL0; /*!< Offset: 0x201C (R/W)	*/
  __IO uint32_t I2SDMACHANNEL1; /*!< Offset: 0x2020 (R/W)	*/
} HM_I2S_TypeDef;

/*------------- Real-Time Clock (RTC) ----------------------------------------*/
/** @brief  Real-Time Clock (RTC) register structure definition */
typedef struct {
  __IO uint32_t CONTROL;          /*!< Offset: 0x000 (R/W)	*/
  __IO uint32_t HOURMODE;         /*!< Offset: 0x004 (R/W)	*/
  __IO uint32_t TIME;             /*!< Offset: 0x008 (R/W)	*/
  __IO uint32_t CALENDAR;         /*!< Offset: 0x00C (R/W)	*/
  __IO uint32_t TIME_ALARM;       /*!< Offset: 0x010 (R/W)	*/
  __IO uint32_t CALENDAR_ALARM;   /*!< Offset: 0x014 (R/W)	*/
  __IO uint32_t ALARM_ENABLE;     /*!< Offset: 0x018 (R/W)	*/
  __IO uint32_t EVENT_FLAGS;      /*!< Offset: 0x01C (R/W)	*/
  __O uint32_t INTERRUPT_ENABLE;  /*!< Offset: 0x020 (R/W)	*/
  __O uint32_t INTERRUPT_DISABLE; /*!< Offset: 0x024 (R/W)	*/
  __IO uint32_t INTERRUPT_MASK;   /*!< Offset: 0x028 (R/W)	*/
  __IO uint32_t STATUS;           /*!< Offset: 0x02C (R/W)	*/
  __IO uint32_t KEEP_RTC;         /*!< Offset: 0x030 (R/W)	*/
  __IO uint32_t RTC_PRL;          /*!< Offset: 0x034 (R/W)	*/
  uint32_t Reserved1[18];
  __IO uint32_t ERSTATUS;  /*!< Offset: 0x080 (R/W)	 */
  __IO uint32_t ERCONTROL; /*!< Offset: 0x084 (R/W)	*/
  __I uint32_t ERCOUNTERS; /*!< Offset: 0x088 (R)	 */
  uint32_t Reserved2;
  __I uint32_t ERFIRSTSTAMP0; /*!< Offset: 0x090 (R)*/
  __I uint32_t ERFIRSTSTAMP1; /*!< Offset: 0x094 (R) */
  __I uint32_t ERFIRSTSTAMP2; /*!< Offset: 0x098 (R)*/
  uint32_t Reserved3;
  __I uint32_t ERLASTSTAMP0; /*!< Offset: 0x0A0 (R)	*/
  __I uint32_t ERLASTSTAMP1; /*!< Offset: 0x0A4 (R)	*/
  __I uint32_t ERLASTSTAMP2; /*!< Offset: 0x0A8 (R)	*/

} HM_RTC_TypeDef;

/*------------- Watchdog Timer (WDT) -----------------------------------------*/
/** @brief  Watchdog Timer (WDT) register structure definition */
typedef struct {
  __IO uint32_t WDTLOAD; /*!< Offset: 0x000	   */
  __I uint32_t WDTVALUE; /*!< Offset: 0x004   */
  __IO uint32_t WDTCTL;  /*!< Offset: 0x008   */
  __I uint32_t WDTICR;   /*!< Offset: 0x00C   */
  __I uint32_t WDTRIS;   /*!< Offset: 0x010	   */
  __I uint32_t WDTMIS;   /*!< Offset: 0x014  */
  uint32_t Reserved[256];
  __IO uint32_t WDTTEST; /*!< Offset: 0x418   */
  uint32_t Reserved1[505];
  __IO uint32_t WDTLOCK; /*!< Offset: 0xC00	   */
  uint32_t Reserved2[243];
  __I uint32_t WDTPeriphID4; /*!< Offset: 0xFD0   */
  __I uint32_t WDTPeriphID5; /*!< Offset: 0xFD4  */
  __I uint32_t WDTPeriphID6; /*!< Offset: 0xFD8  */
  __I uint32_t WDTPeriphID7; /*!< Offset: 0xFDC  */
  __I uint32_t WDTPeriphID0; /*!< Offset: 0xFE0  */
  __I uint32_t WDTPeriphID1; /*!< Offset: 0xFE4  */
  __I uint32_t WDTPeriphID2; /*!< Offset: 0xFE8  */
  __I uint32_t WDTPeriphID3; /*!< Offset: 0xFEC  */
  __I uint32_t WDTPCellID0;  /*!< Offset: 0xFF0  */
  __I uint32_t WDTPCellID1;  /*!< Offset: 0xFF4  */
  __I uint32_t WDTPCellID2;  /*!< Offset: 0xFF8  */
  __I uint32_t WDTPCellID3;  /*!< Offset: 0xFFC  */

} HM_WDT_TypeDef;

/*------------- Analog-to-Digital Converter (ADC) ----------------------------*/
/** @brief  Analog-to-Digital Converter (ADC) register structure definition */
typedef struct {
  __IO uint32_t CR;  /*!< Offset: 0x000	   A/D Control Register (R/W) */
  __IO uint32_t GDR; /*!< Offset: 0x004	   A/D Global Data Register (R/W) */
  __IO uint32_t CHSEL;
  __IO uint32_t INTEN; /*!< Offset: 0x00C	   A/D Interrupt Enable Register (R/W) */
  __IO uint32_t DR[8]; /*!< Offset: 0x010-0x02C A/D Channel 0..7 Data Register (R/W) */
  __I uint32_t STAT;   /*!< Offset: 0x030	   A/D Status Register (R/ ) */
  __IO uint32_t HILMT;
  __IO uint32_t LOLMT;
  __IO uint32_t SSCR;
  __IO uint32_t PWMFAULT;

} HM_ADC_TypeDef;

/*------------- Digital-to-Analog Converter (DAC) ----------------------------*/
/** @brief  Digital-to-Analog Converter (DAC) register structure definition */
typedef struct {
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
typedef struct {
  __IO uint32_t CR;
} HM_AC_TypeDef;

/*------------- Quadrature Encoder Interface (QEI) ---------------------------*/
/** @brief  Quadrature Encoder Interface (QEI) register structure definition */
typedef struct {
  __IO uint32_t CTL;    /*!< Offset: 0x000	   */
  __IO uint32_t STAT;   /*!< Offset: 0x004	   */
  __IO uint32_t POS;    /*!< Offset: 0x008	   */
  __IO uint32_t MAXPOS; /*!< Offset: 0x00C	   */
  __IO uint32_t LOAD;   /*!< Offset: 0x010	   */
  __IO uint32_t TIME;   /*!< Offset: 0x014	   */
  __IO uint32_t COUNT;  /*!< Offset: 0x018	   */
  __IO uint32_t SPEED;  /*!< Offset: 0x01C	   */
  __IO uint32_t INTEN;  /*!< Offset: 0x020	   */
  __IO uint32_t RIS;    /*!< Offset: 0x024	   */
  __IO uint32_t ISC;    /*!< Offset: 0x028	   */
  uint32_t RESERVED1[5];
  __IO uint32_t CNTCLR; /*!< Offset: 0x040	   */
  uint32_t RESERVED2[3];
  __IO uint32_t VELCOMP; /*!< Offset: 0x050	   */
  __IO uint32_t CMPOS0;  /*!< Offset: 0x054	   */
  __IO uint32_t CMPOS1;  /*!< Offset: 0x058	   */
  __IO uint32_t CMPOS2;  /*!< Offset: 0x05C	   */
  __IO uint32_t INXCNT;  /*!< Offset: 0x060	   */
  __IO uint32_t INXCMP0; /*!< Offset: 0x064	   */
  __IO uint32_t INXCMP1; /*!< Offset: 0x068	   */
  __IO uint32_t INXCMP2; /*!< Offset: 0x06C	   */

} HM_QEI_TypeDef;

/*------------- Controller Area Network (CAN) --------------------------------*/

/** @brief  Controller Area Network Controller (CAN) register structure definition */
typedef struct /* Controller Registers               */
{
  __IO uint32_t Rbuf[20];             /*!< Offset: 0x000	  (R/W) */
  __IO uint32_t Tbuf[20];             /*!< Offset: 0x050	  (R/W) */
  __IO uint32_t Control;              /*!< Offset: 0x0A0	  (R/W) */
  __IO uint32_t Interrupt;            /*!< Offset: 0x0A4	  (R/W) */
  __IO uint32_t BitTimingS;           /*!< Offset: 0x0A8	  (R/W) */
  __IO uint32_t BitTimingF;           /*!< Offset: 0x0AC	  (R/W) */
  __IO uint32_t ErrorCounter;         /*!< Offset: 0x0B0	  (R/W) */
  __IO uint32_t AcceptanceFilterCtrl; /*!< Offset: 0x0B4	  (R/W) */
  __IO uint32_t AcceptanceCODE;       /*!< Offset: 0x0B8	  (R/W) */
  __IO uint32_t Version;              /*!< Offset: 0x0BC	  (R/W) */
  __IO uint32_t ReferenceMessage;     /*!< Offset: 0x0C0	  (R/W) */
  __IO uint32_t TriggerTime;          /*!< Offset: 0x0C4	  (R/W) */
  __IO uint32_t WatchTriggerTime;     /*!< Offset: 0x0C8	  (R/W) */
  uint32_t Reserved;
  __O uint32_t FDEnable; /*!< Offset: 0x0D0	  (R/W) */
  __O uint32_t DivNum;   /*!< Offset: 0x0D4	  (R/W) */
} HM_CAN_TypeDef;

/*------------- Direct Memory Access (UDMA) -----------------*/
/** @brief  Direct Memory Access (UDMA) register structure definition */
typedef struct /* Common Registers                   */
{
  __I uint32_t STAT;        /*!< Offset: 0x000	  (R/W) */
  __I uint32_t CFG;         /*!< Offset: 0x004	  (R/W) */
  __O uint32_t CTLBASE;     /*!< Offset: 0x008	  (R/W) */
  __I uint32_t ALTBASE;     /*!< Offset: 0x00C	  (R/W) */
  __O uint32_t WAITSTAT;    /*!< Offset: 0x010	  (R/W) */
  __I uint32_t SWREQ;       /*!< Offset: 0x014	  (R/W) */
  __I uint32_t USEBURSTSET; /*!< Offset: 0x018	  (R/W) */
  __I uint32_t USEBURSTCLR; /*!< Offset: 0x01C	  (R/W) */
  __IO uint32_t REQMASKSET; /*!< Offset: 0x020	  (R/W) */
  __IO uint32_t REQMASKCLR; /*!< Offset: 0x024	  (R/W) */
  __IO uint32_t ENASET;     /*!< Offset: 0x028	  (R/W) */
  __IO uint32_t ENACLR;     /*!< Offset: 0x02C	  (R/W) */
  __IO uint32_t ALTSET;     /*!< Offset: 0x030	  (R/W) */
  __IO uint32_t ALTCLR;     /*!< Offset: 0x034	  (R/W) */
  __IO uint32_t PRIOSET;    /*!< Offset: 0x038	  (R/W) */
  __IO uint32_t PRIOCLR;    /*!< Offset: 0x03C	  (R/W) */
  uint32_t RESERVED1[3];    /*!< Offset: 0x040	  (R/W) */
  __IO uint32_t ERRCLR;     /*!< Offset: 0x04C	  (R/W) */
  uint32_t RESERVED2[1004]; /*!< Offset: 0x050	  (R/W) */
  __IO uint32_t ASSMODE[4]; /*!< Offset: 0x1000	  (R/W) */
  __IO uint32_t ASSMODEEN;  /*!< Offset: 0x1010   (R/W) */
  uint32_t RESERVED3[3];    /*!< Offset: 0x1014	  (R/W) */
  __IO uint32_t SWCHREQ;    /*!< Offset: 0x1020   (R/W) */
  __IO uint32_t SWSTACLR;   /*!< Offset: 0x1024   (R/W) */

} HM_UDMA_TypeDef;

/** @brief  General Purpose Direct Memory Access Channel (GPDMACH) register structure definition */
typedef struct /* Channel Registers                  */
{
  __IO uint32_t CSrcAddr;
  __IO uint32_t CDestAddr;
  __IO uint32_t CLLI;
  __IO uint32_t CControl;
  __IO uint32_t CConfig;
} HM_GPDMACH_TypeDef;

/*------------- Universal Serial Bus (USB) -----------------------------------*/
/** @brief  Universal Serial Bus (USB) register structure definition */
typedef struct {
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

/*------------- External Peripheral Interface (EPI) -----------------------------*/
/** @brief  External Peripheral Interface (EPI) register structure definition */
typedef struct {
  __IO uint32_t Control; /*!< Offset: 0x000	 (R/W) */

} HM_EPI_TypeDef;
/*------------- FLASH_ Engine (FLASH_) -----------------------------------------*/
/** @brief  FLASH_ Engine (FLASH_)  register structure definition */
typedef struct {
  __IO uint32_t AcceleratorCtrl1; /*!< Offset: 0x000	 (R/W) */
  __IO uint32_t BootloaderCtrl;   /*!< Offset: 0x004	 (R/W) */
  __IO uint32_t ProgramCmd;       /*!< Offset: 0x008	 (R/W) */
  __IO uint32_t PageLatchsData;   /*!< Offset: 0x00C	 (R/W) */
  __IO uint32_t SYSFlashCtrl;     /*!< Offset: 0x010	 (R/W) */
  __IO uint32_t SYSFlashAddr;     /*!< Offset: 0x014	 (R/W) */
  __IO uint32_t AcceleratorCtrl2; /*!< Offset: 0x018	 (R/W) */
  __IO uint32_t FlashInfo;        /*!< Offset: 0x01C	 (R/W) */
  __IO uint32_t FlashStatus;      /*!< Offset: 0x020	 (R/W) */
  __IO uint32_t SYSFlashData;     /*!< Offset: 0x024	 (R/W) */
  __IO uint32_t Unlock;           /*!< Offset: 0x028	 (R/W) */
  __IO uint32_t BootromBufferEn;  /*!< Offset: 0x02C	 (R/W) */
  uint32_t RESERVED11[52];
  __IO uint32_t BootloaderRemap; /*!< Offset: 0x100	 (R/W) */
} HM_FLASH_TypeDef;

/*------------- CRC Engine (CRC) -----------------------------------------*/
/** @brief  CRC Engine (CRC)  register structure definition */
typedef struct {
  __IO uint32_t MODE; /*!< Offset: 0x000	 (R/W) */
  __IO uint32_t SEED; /*!< Offset: 0x004	 (R/W) */
  __I uint32_t SUM;   /*!< Offset: 0x008	 (R/W) */
  union {
    struct {
      __O uint32_t DATA; /*!< Offset: 0x00C	 (R/W) */
    } WR_DATA_DWORD;

    struct {
      __O uint16_t DATA;
      uint16_t RESERVED;
    } WR_DATA_WORD;

    struct {
      __O uint8_t DATA;
      uint8_t RESERVED[3];
    } WR_DATA_BYTE;
  };
  __IO uint32_t LEN;    /*!< Offset: 0x010	 (R/W) */
  __O uint32_t INT_CLR; /*!< Offset: 0x014	 (R/W) */
  __I uint32_t STATUS;  /*!< Offset: 0x018	 (R/W) */

} HM_CRC_TypeDef;

/******************************************************************************/
/*                         Peripheral memory map                              */
/******************************************************************************/
/* Base addresses                                                             */
#define HM_FLASH_BASE (0x00000000UL)
#define HM_ROMRAM_BASE (0x01000000UL)
#define HM_RAM_BASE (0x20000000UL)
#define HM_APB0_BASE (0x40000000UL)
#define HM_APB1_BASE (0x40020000UL)
#define HM_BITBAND1_BASE (0x22000000UL)
#define HM_BITBAND2_BASE (0x42000000UL)
#define HM_CM3_BASE (0xE0000000UL)

/* APB0 peripherals                                                           */
#define HM_WDT0_BASE (HM_APB0_BASE + 0x00000)
#define HM_WDT1_BASE (HM_APB0_BASE + 0x01000)
#define HM_GPIOA_BASE (HM_APB0_BASE + 0x04000)
#define HM_GPIOB_BASE (HM_APB0_BASE + 0x05000)
#define HM_GPIOC_BASE (HM_APB0_BASE + 0x06000)
#define HM_GPIOD_BASE (HM_APB0_BASE + 0x07000)
#define HM_SSI0_BASE (HM_APB0_BASE + 0x08000)
#define HM_SSI1_BASE (HM_APB0_BASE + 0x09000)
#define HM_UART0_BASE (HM_APB0_BASE + 0x0C000)
#define HM_UART1_BASE (HM_APB0_BASE + 0x0D000)
#define HM_UART2_BASE (HM_APB0_BASE + 0x0E000)

/* APB1 peripherals                                                           */
#define HM_I2C0_BASE (HM_APB1_BASE + 0x00000)
#define HM_I2C1_BASE (HM_APB1_BASE + 0x01000)
#define HM_GPIOE_BASE (HM_APB1_BASE + 0x04000)
#define HM_GPIOF_BASE (HM_APB1_BASE + 0x05000)
#define HM_GPIOG_BASE (HM_APB1_BASE + 0x06000)
#define HM_GPIOH_BASE (HM_APB1_BASE + 0x07000)
#define HM_PWM_BASE (HM_APB1_BASE + 0x08000)
#define HM_QEI0_BASE (HM_APB1_BASE + 0x0C000)
#define HM_QEI1_BASE (HM_APB1_BASE + 0x0D000)
#define HM_TIM0_BASE (HM_APB1_BASE + 0x10000)
#define HM_TIM1_BASE (HM_APB1_BASE + 0x11000)
#define HM_TIM2_BASE (HM_APB1_BASE + 0x12000)
#define HM_TIM3_BASE (HM_APB1_BASE + 0x13000)
#define HM_ADC0_BASE (HM_APB1_BASE + 0x18000)
#define HM_ADC1_BASE (HM_APB1_BASE + 0x19000)
#define HM_AC_BASE (HM_APB1_BASE + 0x1C000)
#define HM_GPIOJ_BASE (HM_APB1_BASE + 0x1D000)
#define HM_CAN0_BASE (HM_APB1_BASE + 0x20000)
#define HM_CAN1_BASE (HM_APB1_BASE + 0x21000)
#define HM_EMAC_BASE (HM_APB1_BASE + 0x28000)
#define HM_USB_BASE (HM_APB1_BASE + 0x30000)
#define HM_I2S0_BASE (HM_APB1_BASE + 0x34000)
#define HM_EPI0_BASE (HM_APB1_BASE + 0xB0000)
#define HM_FLASHCTRL_BASE (HM_APB1_BASE + 0xDD000)
#define HM_SC_BASE (HM_APB1_BASE + 0xDE000)
#define HM_GPDMA_BASE (HM_APB1_BASE + 0xDF000)

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/
#define HM_SC ((HM_SC_TypeDef *)HM_SC_BASE)
#define HM_WDT0 ((HM_WDT_TypeDef *)HM_WDT0_BASE)
#define HM_WDT1 ((HM_WDT_TypeDef *)HM_WDT1_BASE)
#define HM_GPIOA ((HM_GPIO_TypeDef *)HM_GPIOA_BASE)
#define HM_GPIOB ((HM_GPIO_TypeDef *)HM_GPIOB_BASE)
#define HM_GPIOC ((HM_GPIO_TypeDef *)HM_GPIOC_BASE)
#define HM_GPIOD ((HM_GPIO_TypeDef *)HM_GPIOD_BASE)
#define HM_GPIOE ((HM_GPIO_TypeDef *)HM_GPIOE_BASE)
#define HM_GPIOF ((HM_GPIO_TypeDef *)HM_GPIOF_BASE)
#define HM_GPIOG ((HM_GPIO_TypeDef *)HM_GPIOG_BASE)
#define HM_GPIOH ((HM_GPIO_TypeDef *)HM_GPIOH_BASE)
#define HM_GPIOJ ((HM_GPIO_TypeDef *)HM_GPIOJ_BASE)
#define HM_SSP0 ((HM_SSP_TypeDef *)HM_SSI0_BASE)
#define HM_SSP1 ((HM_SSP_TypeDef *)HM_SSI1_BASE)
#define HM_UART0 ((HM_UART_TypeDef *)HM_UART0_BASE)
#define HM_UART1 ((HM_UART_TypeDef *)HM_UART1_BASE)
#define HM_UART2 ((HM_UART_TypeDef *)HM_UART2_BASE)
#define HM_I2C0 ((HM_I2C_TypeDef *)HM_I2C0_BASE)
#define HM_I2C1 ((HM_I2C_TypeDef *)HM_I2C1_BASE)
#define HM_PWM ((HM_PWM_TypeDef *)HM_PWM_BASE)
#define HM_QEI0 ((HM_QEI_TypeDef *)HM_QEI0_BASE)
#define HM_QEI1 ((HM_QEI_TypeDef *)HM_QEI1_BASE)
#define HM_TIM0 ((HM_TIM_TypeDef *)HM_TIM0_BASE)
#define HM_TIM1 ((HM_TIM_TypeDef *)HM_TIM1_BASE)
#define HM_TIM2 ((HM_TIM_TypeDef *)HM_TIM2_BASE)
#define HM_TIM3 ((HM_TIM_TypeDef *)HM_TIM3_BASE)
#define HM_ADC0 ((HM_ADC_TypeDef *)HM_ADC0_BASE)
#define HM_ADC1 ((HM_ADC_TypeDef *)HM_ADC1_BASE)
#define HM_CMP ((HM_AC_TypeDef *)HM_AC_BASE)
#define HM_CAN0 ((HM_CAN_TypeDef *)HM_CAN0_BASE)
#define HM_CAN1 ((HM_CAN_TypeDef *)HM_CAN1_BASE)
#define HM_USB ((HM_USB_TypeDef *)HM_USB_BASE)
#define HM_I2S ((HM_I2S_TypeDef *)HM_I2S0_BASE)
#define HM_EPI ((HM_EPI_TypeDef *)HM_EPI0_BASE)
#define HM_FLASH ((HM_FLASH_TypeDef *)HM_FLASHCTRL_BASE)
#define HM_GPDMA ((HM_UDMA_TypeDef *)HM_GPDMA_BASE)

#ifdef __cplusplus
}
#endif

#endif /* CM3DS_MPS2_H */
