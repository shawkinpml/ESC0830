/**********************************************************************
* $Id$		hm_gpio.c			2021-09-29
*//**
* @file		hm_gpio.c
* @brief	Contains all functions support for GPIO firmware library
*			on HM4C123,HM3S9B96
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
/** @defgroup GPIO	GPIO (General Purpose Input/Output)
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_GPIO_H_
#define __HM_GPIO_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"


#ifdef __cplusplus
extern "C"
{
#endif

/* Public Macros -------------------------------------------------------------- */
/** @defgroup GPIO_Public_Macros GPIO Public Macros
 * @{
 */

//*****************************************************************************
//
// HM4C123 Port/Pin Mapping Definitions
//
//*****************************************************************************
//                    0x    X     XX    XXX   XX
//                        INDEX   POS   MASK  REG

#ifdef CHIP_SEL_ESC0830

/*alt 1*/
#define GPIO_AIN0_PE3           0x0000FFFF
#define GPIO_AIN1_PE2         	0x0000FFFF
#define GPIO_AIN10_PB4         	0x0000FFFF
#define GPIO_AIN11_PB5         	0x0000FFFF
#define GPIO_AIN12_PD3         	0x0000FFFF
#define GPIO_AIN13_PD2         	0x0000FFFF
#define GPIO_AIN14_PD1         	0x0000FFFF
#define GPIO_AIN15_PD0         	0x0000FFFF
#define GPIO_AIN16_PK0         	0x0000FFFF
#define GPIO_AIN17_PK1         	0x0000FFFF
#define GPIO_AIN18_PK2         	0x0000FFFF
#define GPIO_AIN19_PK3         	0x0000FFFF
#define GPIO_AIN2_PE1         	0x0000FFFF
#define GPIO_AIN20_PE7         	0x0000FFFF
#define GPIO_AIN21_PE6         	0x0000FFFF
#define GPIO_AIN22_PP1         	0x0000FFFF
#define GPIO_AIN23_PP0         	0x0000FFFF
#define GPIO_AIN3_PE0         	0x0000FFFF
#define GPIO_AIN4_PD7         	0x0000FFFF
#define GPIO_AIN5_PD6         	0x0000FFFF
#define GPIO_AIN6_PD5         	0x0000FFFF
#define GPIO_AIN7_PD4         	0x0000FFFF
#define GPIO_AIN8_PE5         	0x0000FFFF
#define GPIO_AIN9_PE4         	0x0000FFFF

#define GPIO_C0P_PC6         	0x0000FFFF
#define GPIO_C0N_PC7         	0x0000FFFF
#define GPIO_C1P_PC5         	0x0000FFFF
#define GPIO_C1N_PC4         	0x0000FFFF
#define GPIO_C2P_PJ4         	0x0000FFFF
#define GPIO_C2N_PJ5         	0x0000FFFF

#define GPIO_I2C0SCL_PB2       	0x0000FFFF
#define GPIO_I2C0SDA_PB3       	0x0000FFFF
#define GPIO_I2C4SCL_PG2       	0x0000FFFF
#define GPIO_I2C4SDA_PG3       	0x0000FFFF
#define GPIO_I2C5SCL_PG6       	0x0000FFFF
#define GPIO_I2C5SDA_PG7       	0x0000FFFF

#define GPIO_M1FAULT3_PK3        	0x0000FFFF

#define GPIO_RTCCLK_PK4       	0x0000FFFF

#define GPIO_SSI0CLK_PA2       	0x0000FFFF
#define GPIO_SSI0FSS_PA3       	0x0000FFFF
#define GPIO_SSI0RX_PA4       	0x0000FFFF
#define GPIO_SSI0TX_PA5       	0x0000FFFF
#define GPIO_SSI2RX_PH6       	0x0000FFFF
#define GPIO_SSI2TX_PH7       	0x0000FFFF

#define GPIO_SWCLK_PC0       	0x0000FFFF
#define GPIO_SWDIO_PC1       	0x0000FFFF
#define GPIO_SWO_PC3      		0x0000FFFF

#define GPIO_TCK_PC0       		0x0000FFFF
#define GPIO_TDI_PC2       		0x0000FFFF
#define GPIO_TDO_PC3       		0x0000FFFF
#define GPIO_TMS_PC1       		0x0000FFFF

#define GPIO_TRCLK_PF3       	0x0000FFFF
#define GPIO_TRD0_PF2       	0x0000FFFF
#define GPIO_TRD1_PF1       	0x0000FFFF
#define GPIO_TRD2_PF0       	0x0000FFFF
#define GPIO_TRD3_PF4         0x0000FFFF

#define GPIO_U0RX_PA0       	0x0000FFFF
#define GPIO_U0TX_PA1       	0x0000FFFF
#define GPIO_U1DCD_PF2       	0x0000FFFF
#define GPIO_U1DSR_PF3       	0x0000FFFF
#define GPIO_U1DTR_PF4       	0x0000FFFF
#define GPIO_U1RI_PE7       	0x0000FFFF
#define GPIO_U3RX_PC6       	0x0000FFFF
#define GPIO_U3TX_PC7       	0x0000FFFF
#define GPIO_USB0DM_PL7       	0x0000FFFF
#define GPIO_USB0DP_PL6       	0x0000FFFF
#define GPIO_USB0ID_PB0       	0x0000FFFF
#define GPIO_USB0VBUS_PB1      	0x0000FFFF
/*alt 2*/
#define GPIO_C0O_PF0          0x00000308
#define GPIO_C0O_PK4					0x10000308
#define GPIO_C1O_PF1          0x00200308
#define GPIO_C1O_PK5					0x10200308
#define GPIO_C2O_PF2       		0x00400308
#define GPIO_C2O_PK6       		0x10400308

#define GPIO_CAN1RX_PA0			0x0080032C
#define GPIO_CAN1RX_PE6			0x1080032C
#define GPIO_CAN1TX_PA1			0x00A0032C
#define GPIO_CAN1TX_PE7			0x10A0032C

#define GPIO_I2C1SCL_PA6			0x00200330
#define GPIO_I2C1SCL_PG4			0x10200330
#define GPIO_I2C1SDA_PA7			0x00000330
#define GPIO_I2C1SDA_PG5			0x10000330
#define GPIO_I2C2SCL_PE4			0x00600330
#define GPIO_I2C2SCL_PF6			0x10600330
#define GPIO_I2C2SDA_PE5			0x00400330
#define GPIO_I2C2SDA_PF7			0x10400330
#define GPIO_I2C3SCL_PD0			0x00A00330
#define GPIO_I2C3SCL_PG0			0x10A00330
#define GPIO_I2C3SDA_PD1			0x00800330
#define GPIO_I2C3SDA_PG1			0x10800330

#define GPIO_M0PWM0_PH0			0x0000030C
#define GPIO_M0PWM0_PP0			0x1000030C
#define GPIO_M0PWM1_PH1			0x0020030C
#define GPIO_M0PWM1_PP1			0x1020030C
#define GPIO_M0PWM3_PB5			0x0040030C
#define GPIO_M0PWM3_PH3			0x1040030C

#define GPIO_M1FAULT1_PG0			0x00300318
#define GPIO_M1FAULT1_PK1			0x10300318
#define GPIO_M1FAULT2_PG1			0x00500318
#define GPIO_M1FAULT2_PK2			0x10500318

#define GPIO_M1PWM0_PD0			0x00000310
#define GPIO_M1PWM0_PG2			0x10000310
#define GPIO_M1PWM1_PD1			0x00200310
#define GPIO_M1PWM1_PG3			0x10200310
#define GPIO_M1PWM4_PF0			0x00A00310
#define GPIO_M1PWM4_PN4			0x10A00310
#define GPIO_M1PWM5_PF1			0x00C00310
#define GPIO_M1PWM5_PN5			0x10C00310
#define GPIO_M1PWM6_PF2			0x00E00310
#define GPIO_M1PWM6_PN6			0x10E00310
#define GPIO_M1PWM7_PF3			0x01000310
#define GPIO_M1PWM7_PN7			0x11000310

#define GPIO_NMI_PD7			0x0000036C
#define GPIO_NMI_PF0			0x0000036C

#define GPIO_SSI1CLK_PD0			0x00600328
#define GPIO_SSI1CLK_PF2			0x10600328
#define GPIO_SSI1FSS_PD1			0x00400328
#define GPIO_SSI1FSS_PF3			0x10400328
#define GPIO_SSI1RX_PD2			0x00200328
#define GPIO_SSI1RX_PF0			0x10200328
#define GPIO_SSI1TX_PD3			0x00000328
#define GPIO_SSI1TX_PF1			0x10000328
#define GPIO_SSI2CLK_PB4			0x00A00328
#define GPIO_SSI2CLK_PH4			0x10A00328
#define GPIO_SSI2FSS_PB5			0x00800328
#define GPIO_SSI2FSS_PH5			0x10800328

#define GPIO_T0CCP0_PF0			0x00000338
#define GPIO_T0CCP0_PL0			0x10000338
#define GPIO_T0CCP1_PF1			0x00200338
#define GPIO_T0CCP1_PL1			0x10200338

#define GPIO_U1CTS_PC5			0x00000300
#define GPIO_U1CTS_PF1			0x10000300
#define GPIO_U1RTS_PC4			0x00200300
#define GPIO_U1RTS_PF0			0x10200300

#define GPIO_U1RX_PB0			0x00200324
#define GPIO_U1RX_PC4			0x10200324
#define GPIO_U1TX_PB1			0x00000324
#define GPIO_U1TX_PC5			0x10000324
#define GPIO_U2RX_PD6			0x00600324
#define GPIO_U2RX_PG4			0x10600324
#define GPIO_U2TX_PD7			0x00400324
#define GPIO_U2TX_PG5			0x10400324
#define GPIO_U4RX_PC4			0x00A00324
#define GPIO_U4RX_PJ0			0x10A00324
#define GPIO_U4TX_PC5			0x00800324
#define GPIO_U4TX_PJ1			0x10800324
#define GPIO_U5RX_PE4			0x00E00324
#define GPIO_U5RX_PJ2			0X10E00324
#define GPIO_U5TX_PE5			0x00C00324
#define GPIO_U5TX_PJ3			0x10C00324
#define GPIO_U6RX_PD4			0x01200324
#define GPIO_U6RX_PJ4			0x11200324
#define GPIO_U6TX_PD5			0x01000324
#define GPIO_U6TX_PJ5			0x11000324
#define GPIO_U7RX_PE0			0x01400324
#define GPIO_U7RX_PK4			0x11400324
#define GPIO_U7TX_PE1			0x01600324
#define GPIO_U7TX_PK5			0x11600324
/*alt 3*/
#define GPIO_IDX1_PC4			0x0040071C
#define GPIO_IDX1_PG5     0x1040071C
#define GPIO_IDX1_PG7     0x2040071C

#define GPIO_M0FAULT3_PF5			0x00E00714
#define GPIO_M0FAULT3_PH3   	0x10E00714
#define GPIO_M0FAULT3_PK7   	0x20E00714
#define GPIO_M0PWM2_PB4    	0x0040070C
#define GPIO_M0PWM2_PH2    	0x1040070C
#define GPIO_M0PWM2_PP2    	0x2040070C
#define GPIO_M1FAULT0_PF4   	0x00000718
#define GPIO_M1FAULT0_PF7   	0x10000718
#define GPIO_M1FAULT0_PK0   	0x20000718
#define GPIO_M1PWM2_PA6     0x00400710
#define GPIO_M1PWM2_PE4     0x10400710
#define GPIO_M1PWM2_PG4     0x20400710
#define GPIO_M1PWM3_PA7     0x00700710
#define GPIO_M1PWM3_PE5     0x10700710
#define GPIO_M1PWM3_PG5     0x20700710

#define GPIO_PHA0_PD6			0x00000720
#define GPIO_PHA0_PF0     0x10000720
#define GPIO_PHA0_PH4     0x20000720
#define GPIO_PHA1_PC5     0x00300720
#define GPIO_PHA1_PG0     0x10300720
#define GPIO_PHA1_PG3     0x20300720
#define GPIO_PHB0_PD7     0x00600720
#define GPIO_PHB0_PF1     0x10600720
#define GPIO_PHB0_PH5     0x20600720
#define GPIO_PHB1_PC6     0x00900720
#define GPIO_PHB1_PG1     0x10900720
#define GPIO_PHB1_PG4			0x20900720

#define GPIO_SSI3CLK_PD0			0x01500728
#define GPIO_SSI3CLK_PH0    	0x11500728
#define GPIO_SSI3CLK_PK0			0x21500728
#define GPIO_SSI3FSS_PD1    	0x01200728
#define GPIO_SSI3FSS_PH1    	0x11200728
#define GPIO_SSI3FSS_PK1			0x21200728
#define GPIO_SSI3RX_PD2			0x00F00728
#define GPIO_SSI3RX_PH2     0x10F00728
#define GPIO_SSI3RX_PK2			0x20F00728
#define GPIO_SSI3TX_PD3     0x00C00728
#define GPIO_SSI3TX_PH3     0x10C00728
#define GPIO_SSI3TX_PK3			0x20C00728

#define GPIO_T5CCP1_PC3			0x0040074C
#define GPIO_T5CCP1_PG3     	0x1040074C
#define GPIO_T5CCP1_PM3			0x2040074C
#define GPIO_WT5CCP0_PD6    	0x00000764
#define GPIO_WT5CCP0_PH2    	0x10000764
#define GPIO_WT5CCP0_PM2			0x20000764
#define GPIO_WT5CCP1_PD7    	0x00300764
#define GPIO_WT5CCP1_PH3    	0x10300764
#define GPIO_WT5CCP1_PM3		0x20300764
/*alt 4*/
#define GPIO_CAN0RX_PB4			0x00400F2C
#define GPIO_CAN0RX_PE4     	0x10400F2C
#define GPIO_CAN0RX_PF0    		0x20400F2C
#define GPIO_CAN0RX_PN0     	0x30400F2C
#define GPIO_CAN0TX_PB5     	0x00000F2C
#define GPIO_CAN0TX_PE5     	0x10000F2C
#define GPIO_CAN0TX_PF3     	0x20000F2C
#define GPIO_CAN0TX_PN1     	0x30000F2C

#define GPIO_IDX0_PD3			0x00000F1C
#define GPIO_IDX0_PF4			0x10000F1C
#define GPIO_IDX0_PH1			0x20000F1C
#define GPIO_IDX0_PJ2			0x30000F1C

#define GPIO_M0FAULT2_PF4		0x00A00F14
#define GPIO_M0FAULT2_PG3		0x10A00F14
#define GPIO_M0FAULT2_PH2		0x20A00F14
#define GPIO_M0FAULT2_PK6		0x30A00F14

#define GPIO_M0PWM4_PE4			0x00900F0C
#define GPIO_M0PWM4_PG4			0x10900F0C
#define GPIO_M0PWM4_PH4			0x20900F0C
#define GPIO_M0PWM4_PM6			0x30900F0C

#define GPIO_M0PWM5_PE5			0x00D00F0C
#define GPIO_M0PWM5_PG5			0x10D00F0C
#define GPIO_M0PWM5_PH5     	0x20D00F0C
#define GPIO_M0PWM5_PM7     	0x30D00F0C
														
#define GPIO_T1CCP0_PB4     	0x00000F3C
#define GPIO_T1CCP0_PF2     	0x10000F3C
#define GPIO_T1CCP0_PJ0     	0x20000F3C
#define GPIO_T1CCP0_PL2     	0x30000F3C
#define GPIO_T1CCP1_PB5     	0x00400F3C
#define GPIO_T1CCP1_PF3     	0x10400F3C
#define GPIO_T1CCP1_PJ1     	0x20400F3C
#define GPIO_T1CCP1_PL3     	0x30400F3C
														
#define GPIO_T2CCP0_PB0     	0x00000F40
#define GPIO_T2CCP0_PF4     	0x10000F40
#define GPIO_T2CCP0_PJ2     	0x20000F40
#define GPIO_T2CCP0_PL4     	0x30000F40
#define GPIO_T2CCP1_PB1     	0x00400F40
#define GPIO_T2CCP1_PF5     	0x10400F40
#define GPIO_T2CCP1_PJ3     	0x20400F40
#define GPIO_T2CCP1_PL5    	 	0x30400F40
													
#define GPIO_T3CCP0_PB2     	0x00000F44
#define GPIO_T3CCP0_PF6     	0x10000F44
#define GPIO_T3CCP0_PJ4     	0x20000F44
#define GPIO_T3CCP0_PL6     	0x30000F44
#define GPIO_T3CCP1_PB3     	0x00400F44
#define GPIO_T3CCP1_PF7     	0x10400F44
#define GPIO_T3CCP1_PJ5    		0x20400F44
#define GPIO_T3CCP1_PL7     	0x30400F44
														
#define GPIO_T4CCP0_PC0     	0x00000F48
#define GPIO_T4CCP0_PG0     	0x10000F48
#define GPIO_T4CCP0_PM0     	0x20000F48
#define GPIO_T4CCP0_PP0     	0x30000F48
#define GPIO_T4CCP1_PC1     	0x00400F48
#define GPIO_T4CCP1_PG1     	0x10400F48
#define GPIO_T4CCP1_PM1     	0x20400F48
#define GPIO_T4CCP1_PP1     	0x30400F48

#define GPIO_T5CCP0_PC2			0x00000F4C
#define GPIO_T5CCP0_PG2			0x10000F4C
#define GPIO_T5CCP0_PM2			0x20000F4C
#define GPIO_T5CCP0_PP2			0x30000F4C

#define GPIO_USB0EPEN_PC6		0x00400F34
#define GPIO_USB0EPEN_PD2   	0x10400F34
#define GPIO_USB0EPEN_PF4   	0x20400F34
#define GPIO_USB0EPEN_PG4   	0x30400F34
#define GPIO_USB0PFLT_PC7   	0x00000F34
#define GPIO_USB0PFLT_PD3   	0x10000F34
#define GPIO_USB0PFLT_PF5   	0x20000F34
#define GPIO_USB0PFLT_PG5   	0x30000F34

#define GPIO_WT0CCP0_PC4		0x00000F50
#define GPIO_WT0CCP0_PG4    	0x10000F50
#define GPIO_WT0CCP0_PL0    	0x20000F50
#define GPIO_WT0CCP0_PM6    	0x30000F50
#define GPIO_WT0CCP1_PC5    	0x00400F50
#define GPIO_WT0CCP1_PG5    	0x10400F50
#define GPIO_WT0CCP1_PL1    	0x20400F50
#define GPIO_WT0CCP1_PM7    	0x30400F50
#define GPIO_WT1CCP0_PC6    	0x00000F54
#define GPIO_WT1CCP0_PG6      	0x10000F54
#define GPIO_WT1CCP0_PK6      	0x20000F54
#define GPIO_WT1CCP0_PL2      	0x30000F54
#define GPIO_WT1CCP1_PC7      	0x00400F54
#define GPIO_WT1CCP1_PG7      	0x10400F54
#define GPIO_WT1CCP1_PK7     	0x20400F54
#define GPIO_WT1CCP1_PL3      	0x30400F54
#define GPIO_WT2CCP0_PD0    	0x00000F58
#define GPIO_WT2CCP0_PH0      	0x10000F58
#define GPIO_WT2CCP0_PL4      	0x20000F58
#define GPIO_WT2CCP0_PN2      	0x30000F58
#define GPIO_WT2CCP1_PD1      	0x00400F58
#define GPIO_WT2CCP1_PH1      	0x10400F58
#define GPIO_WT2CCP1_PL5      	0x20400F58
#define GPIO_WT2CCP1_PN3      	0x30400F58
#define GPIO_WT3CCP0_PD2      	0x00000F5C
#define GPIO_WT3CCP0_PH4      	0x10000F5C
#define GPIO_WT3CCP0_PL6      	0x20000F5C
#define GPIO_WT3CCP0_PN4      	0x30000F5C
#define GPIO_WT3CCP1_PD3      	0x00400F5C
#define GPIO_WT3CCP1_PH5      	0x10400F5C
#define GPIO_WT3CCP1_PL7      	0x20400F5C
#define GPIO_WT3CCP1_PN5      	0x30400F5C
#define GPIO_WT4CCP0_PD4    	0x00000F60
#define GPIO_WT4CCP0_PH6      	0x10000F60
#define GPIO_WT4CCP0_PM0      	0x20000F60
#define GPIO_WT4CCP0_PN6      	0x30000F60
#define GPIO_WT4CCP1_PD5      	0x00400F60
#define GPIO_WT4CCP1_PH7      	0x10400F60
#define GPIO_WT4CCP1_PM1      	0x20400F60
#define GPIO_WT4CCP1_PN7      	0x30400F60
/*alt 5*/
#define GPIO_M0FAULT0_PD2		0x00001F14
#define GPIO_M0FAULT0_PD6   	0x10001F14
#define GPIO_M0FAULT0_PF2		0x20001F14
#define GPIO_M0FAULT0_PH0   	0x30001F14
#define GPIO_M0FAULT0_PK4   	0x40001F14
#define GPIO_M0FAULT1_PD7   	0x00501F14
#define GPIO_M0FAULT1_PF3     	0x10501F14
#define GPIO_M0FAULT1_PG2     	0x20501F14
#define GPIO_M0FAULT1_PH1     	0x30501F14
#define GPIO_M0FAULT1_PK5     	0x40501F14

#define GPIO_M0PWM6_PC4			0x01101F0C
#define GPIO_M0PWM6_PD0    		0x11101F0C
#define GPIO_M0PWM6_PG6    		0x21101F0C
#define GPIO_M0PWM6_PH6    		0x31101F0C
#define GPIO_M0PWM6_PN2    		0x41101F0C
#define GPIO_M0PWM7_PC5    		0x01601F0C
#define GPIO_M0PWM7_PD1    		0x11601F0C
#define GPIO_M0PWM7_PG7    		0x21601F0C
#define GPIO_M0PWM7_PH7    		0x31601F0C
#define GPIO_M0PWM7_PN3    		0x41601F0C





#endif





//*****************************************************************************
//
// The following values define the bit field for the ui8Pins argument to
// several of the APIs.
//
//*****************************************************************************
#define GPIO_PIN_0              0x00000001  // GPIO pin 0
#define GPIO_PIN_1              0x00000002  // GPIO pin 1
#define GPIO_PIN_2              0x00000004  // GPIO pin 2
#define GPIO_PIN_3              0x00000008  // GPIO pin 3
#define GPIO_PIN_4              0x00000010  // GPIO pin 4
#define GPIO_PIN_5              0x00000020  // GPIO pin 5
#define GPIO_PIN_6              0x00000040  // GPIO pin 6
#define GPIO_PIN_7              0x00000080  // GPIO pin 7

//*****************************************************************************
//
// Values that can be passed to GPIODirModeSet as the ui32PinIO parameter, and
// returned from GPIODirModeGet.
//
//*****************************************************************************
#define GPIO_DIR_MODE_IN        0x00000000  // Pin is a GPIO input
#define GPIO_DIR_MODE_OUT       0x00000001  // Pin is a GPIO output
#define GPIO_DIR_MODE_HW        0x00000002  // Pin is a peripheral function

//*****************************************************************************
//
// Values that can be passed to GPIOIntTypeSet as the ui32IntType parameter,
// and returned from GPIOIntTypeGet.
//
//*****************************************************************************
#define GPIO_FALLING_EDGE       0x00000000  // Interrupt on falling edge
#define GPIO_RISING_EDGE        0x00000004  // Interrupt on rising edge
#define GPIO_BOTH_EDGES         0x00000001  // Interrupt on both edges
#define GPIO_LOW_LEVEL          0x00000002  // Interrupt on low level
#define GPIO_HIGH_LEVEL         0x00000006  // Interrupt on high level
#define GPIO_DISCRETE_INT       0x00010000  // Interrupt for individual pins

//*****************************************************************************
//
// Values that can be passed to GPIOPadConfigSet as the ui32Strength parameter,
// and returned by GPIOPadConfigGet in the *pui32Strength parameter.
//
//*****************************************************************************
#define GPIO_STRENGTH_2MA       0x00000001  // 2mA drive strength
#define GPIO_STRENGTH_4MA       0x00000002  // 4mA drive strength
#define GPIO_STRENGTH_8MA       0x00000004  // 8mA drive strength

//*****************************************************************************
//
// Values that can be passed to GPIOPadConfigSet as the ui32PadType parameter,
// and returned by GPIOPadConfigGet in the *pui32PadType parameter.
//
//*****************************************************************************
#define GPIO_PIN_TYPE_IPU       0x00000002
#define GPIO_PIN_TYPE_IPD       0x00000004
#define GPIO_PIN_TYPE_STD       0x00000008  // Push-pull
#define GPIO_PIN_TYPE_STD_WPU   0x0000000A  // Push-pull with weak pull-up
#define GPIO_PIN_TYPE_STD_WPD   0x0000000C  // Push-pull with weak pull-down
#define GPIO_PIN_TYPE_OD        0x00000009  // Open-drain
#define GPIO_PIN_TYPE_ANALOG    0x00000000  // Analog comparator

//*****************************************************************************
//
// Values that can be passed to GPIOIntEnable() and GPIOIntDisable() functions
// in the ui32IntFlags parameter.
//
//*****************************************************************************
#define GPIO_INT_PIN_0          0x00000001
#define GPIO_INT_PIN_1          0x00000002
#define GPIO_INT_PIN_2          0x00000004
#define GPIO_INT_PIN_3          0x00000008
#define GPIO_INT_PIN_4          0x00000010
#define GPIO_INT_PIN_5          0x00000020
#define GPIO_INT_PIN_6          0x00000040
#define GPIO_INT_PIN_7          0x00000080
#define GPIO_INT_DMA            0x00000100

typedef enum 
{
	GPIOA=0,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG,
	GPIOH,
	GPIOJ,
	GPIOK,
	GPIOL,
	GPIOM,
	GPION,
	GPIOP
}GPIO_Type;

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
int32_t GPIO_PortRead(uint32_t port);
// extern void GPIO_DirModeSet(uint32_t ui32Port, uint8_t ui8Pins,
//                            uint32_t ui32PinIO);
extern void GPIO_DirModeSet(uint32_t port, uint32_t pins, uint32_t pinIO);
extern uint32_t GPIO_DirModeGet(uint32_t ui32Port, uint8_t ui8Pin);
extern void GPIO_IntTypeSet(uint32_t ui32Port, uint8_t ui8Pins,
                           uint32_t ui32IntType);
extern uint32_t GPIO_IntTypeGet(uint32_t ui32Port, uint8_t ui8Pin);
// extern void GPIO_PadConfigSet(uint32_t ui32Port, uint8_t ui8Pins,
//                              uint32_t ui32Strength, uint32_t ui32PadType);
extern void GPIO_PadConfigSet(uint32_t port, uint32_t pins,uint32_t strength, uint32_t pinType);
extern void GPIO_PadConfigGet(uint32_t ui32Port, uint8_t ui8Pin,
                             uint32_t *pui32Strength, uint32_t *pui32PadType);
extern void GPIO_IntEnable(uint32_t ui32Port, uint32_t ui32IntFlags);
extern void GPIO_IntDisable(uint32_t ui32Port, uint32_t ui32IntFlags);
extern uint32_t GPIO_IntStatus(uint32_t ui32Port, Bool bMasked);
extern void GPIO_IntClear(uint32_t ui32Port, uint32_t ui32IntFlags);
extern void GPIO_IntRegister(uint32_t ui32Port, void (*pfnIntHandler)(void));
extern void GPIO_IntUnregister(uint32_t ui32Port);
extern void GPIO_IntRegisterPin(uint32_t ui32Port, uint32_t ui32Pin,
                               void (*pfnIntHandler)(void));
extern void GPIO_IntUnregisterPin(uint32_t ui32Port, uint32_t ui32Pin);
extern int32_t GPIO_PinRead(uint32_t ui32Port, uint8_t ui8Pins);
// extern void GPIO_PinWrite(uint32_t ui32Port, uint8_t ui8Pins, uint8_t ui8Val);
extern void GPIO_PinWrite(uint32_t port, uint32_t pins, uint32_t val);
extern void GPIO_PinConfigure(uint32_t ui32PinConfig);

extern void GPIO_PinTypeADC(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeCAN(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeComparator(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeComparatorOutput(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeDIVSCLK(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeEPI(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeEthernetLED(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeEthernetMII(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeGPIOInput(uint32_t ui32Port, uint8_t ui8Pins);
// extern void GPIO_PinTypeGPIOOutput(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeGPIOOutput(uint32_t port, uint32_t pins);
extern void GPIO_PinTypeGPIOOutputOD(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeHibernateRTCCLK(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeI2C(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeI2CSCL(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeLCD(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeOneWire(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypePWM(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeQEI(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeSSI(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeTimer(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeTrace(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeUART(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeUSBAnalog(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeUSBDigital(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeWakeHigh(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_PinTypeWakeLow(uint32_t ui32Port, uint8_t ui8Pins);
extern uint32_t GPIO_PinWakeStatus(uint32_t ui32Port);
extern void GPIO_DMATriggerEnable(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_DMATriggerDisable(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_ADCTriggerEnable(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_ADCTriggerDisable(uint32_t ui32Port, uint8_t ui8Pins);
extern void GPIO_UnlockPin(uint32_t ui32Port, uint8_t ui8Pins);

extern void GPIO_PinTypeGPIOK_Input(uint32_t port, uint8_t pins, uint32_t type);/*************          PK test             **************************/

#ifdef __cplusplus
}
#endif

#endif /* __HM_GPIO_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
