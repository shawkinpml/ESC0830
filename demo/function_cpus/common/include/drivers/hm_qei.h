/**********************************************************************
* $Id$		hm_qei.h			2021-09-29
*//**
* @file		hm_qei.h
* @brief	Contains all functions support for QEI firmware library
*			on HM3C1788,HM4C123,HM3S9B96
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
/** @defgroup QEI	
 * @ingroup HM3C1788,HM4C123,HM3S9B96CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __HM_QEI_H_
#define __HM_QEI_H_

/* Includes ------------------------------------------------------------------- */
#include "hm_libcfg_default.h"
#include "hm_types.h"


#ifdef __cplusplus
extern "C"
{
#endif

/* Public Macros -------------------------------------------------------------- */
/** @defgroup QEI_Public_Macros QEI Public Macros
 * @{
 */


//*****************************************************************************
//
// The following are defines for the QEI register offsets.
//
//*****************************************************************************
#define QEI_O_CTL               0x00000000  // QEI Control
#define QEI_O_STAT              0x00000004  // QEI Status
#define QEI_O_POS               0x00000008  // QEI Position
#define QEI_O_MAXPOS            0x0000000C  // QEI Maximum Position
#define QEI_O_LOAD              0x00000010  // QEI Timer Load
#define QEI_O_TIME              0x00000014  // QEI Timer
#define QEI_O_COUNT             0x00000018  // QEI Velocity Counter
#define QEI_O_SPEED             0x0000001C  // QEI Velocity
#define QEI_O_INTEN             0x00000020  // QEI Interrupt Enable
#define QEI_O_RIS               0x00000024  // QEI Raw Interrupt Status
#define QEI_O_ISC               0x00000028  // QEI Interrupt Status and Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_CTL register.
//
//*****************************************************************************
#define QEI_CTL_FILTCNT_M       0x000F0000  // Input Filter Prescale Count
#define QEI_CTL_FILTEN          0x00002000  // Enable Input Filter
#define QEI_CTL_STALLEN         0x00001000  // Stall QEI
#define QEI_CTL_INVI            0x00000800  // Invert Index Pulse
#define QEI_CTL_INVB            0x00000400  // Invert PhB
#define QEI_CTL_INVA            0x00000200  // Invert PhA
#define QEI_CTL_VELDIV_M        0x000001C0  // Predivide Velocity
#define QEI_CTL_VELDIV_1        0x00000000  // QEI clock /1
#define QEI_CTL_VELDIV_2        0x00000040  // QEI clock /2
#define QEI_CTL_VELDIV_4        0x00000080  // QEI clock /4
#define QEI_CTL_VELDIV_8        0x000000C0  // QEI clock /8
#define QEI_CTL_VELDIV_16       0x00000100  // QEI clock /16
#define QEI_CTL_VELDIV_32       0x00000140  // QEI clock /32
#define QEI_CTL_VELDIV_64       0x00000180  // QEI clock /64
#define QEI_CTL_VELDIV_128      0x000001C0  // QEI clock /128
#define QEI_CTL_VELEN           0x00000020  // Capture Velocity
#define QEI_CTL_RESMODE         0x00000010  // Reset Mode
#define QEI_CTL_CAPMODE         0x00000008  // Capture Mode
#define QEI_CTL_SIGMODE         0x00000004  // Signal Mode
#define QEI_CTL_SWAP            0x00000002  // Swap Signals
#define QEI_CTL_ENABLE          0x00000001  // Enable QEI
#define QEI_CTL_FILTCNT_S       16

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_STAT register.
//
//*****************************************************************************
#define QEI_STAT_DIRECTION      0x00000002  // Direction of Rotation
#define QEI_STAT_ERROR          0x00000001  // Error Detected

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_POS register.
//
//*****************************************************************************
#define QEI_POS_M               0xFFFFFFFF  // Current Position Integrator
                                            // Value
#define QEI_POS_S               0

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_MAXPOS register.
//
//*****************************************************************************
#define QEI_MAXPOS_M            0xFFFFFFFF  // Maximum Position Integrator
                                            // Value
#define QEI_MAXPOS_S            0

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_LOAD register.
//
//*****************************************************************************
#define QEI_LOAD_M              0xFFFFFFFF  // Velocity Timer Load Value
#define QEI_LOAD_S              0

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_TIME register.
//
//*****************************************************************************
#define QEI_TIME_M              0xFFFFFFFF  // Velocity Timer Current Value
#define QEI_TIME_S              0

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_COUNT register.
//
//*****************************************************************************
#define QEI_COUNT_M             0xFFFFFFFF  // Velocity Pulse Count
#define QEI_COUNT_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_SPEED register.
//
//*****************************************************************************
#define QEI_SPEED_M             0xFFFFFFFF  // Velocity
#define QEI_SPEED_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_INTEN register.
//
//*****************************************************************************
#define QEI_INTEN_ERROR         0x00000008  // Phase Error Interrupt Enable
#define QEI_INTEN_DIR           0x00000004  // Direction Change Interrupt
                                            // Enable
#define QEI_INTEN_TIMER         0x00000002  // Timer Expires Interrupt Enable
#define QEI_INTEN_INDEX         0x00000001  // Index Pulse Detected Interrupt
                                            // Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_RIS register.
//
//*****************************************************************************
#define QEI_RIS_ERROR           0x00000008  // Phase Error Detected
#define QEI_RIS_DIR             0x00000004  // Direction Change Detected
#define QEI_RIS_TIMER           0x00000002  // Velocity Timer Expired
#define QEI_RIS_INDEX           0x00000001  // Index Pulse Asserted

//*****************************************************************************
//
// The following are defines for the bit fields in the QEI_O_ISC register.
//
//*****************************************************************************
#define QEI_ISC_ERROR           0x00000008  // Phase Error Interrupt
#define QEI_ISC_DIR             0x00000004  // Direction Change Interrupt
#define QEI_ISC_TIMER           0x00000002  // Velocity Timer Expired Interrupt
#define QEI_ISC_INDEX           0x00000001  // Index Pulse Interrupt


//*****************************************************************************
//
// Values that can be passed to QEIConfigure as the ui32Config paramater.
//
//*****************************************************************************
#define QEI_CONFIG_CAPTURE_A    0x00000000  // Count on ChA edges only
#define QEI_CONFIG_CAPTURE_A_B  0x00000008  // Count on ChA and ChB edges
#define QEI_CONFIG_NO_RESET     0x00000000  // Do not reset on index pulse
#define QEI_CONFIG_RESET_IDX    0x00000010  // Reset position on index pulse
#define QEI_CONFIG_QUADRATURE   0x00000000  // ChA and ChB are quadrature
#define QEI_CONFIG_CLOCK_DIR    0x00000004  // ChA and ChB are clock and dir
#define QEI_CONFIG_NO_SWAP      0x00000000  // Do not swap ChA and ChB
#define QEI_CONFIG_SWAP         0x00000002  // Swap ChA and ChB

//*****************************************************************************
//
// Values that can be passed to QEIFilterConfigure as the ui32PreDiv
// parameter.
//
//*****************************************************************************
#define QEI_FILTCNT_2           0x00000000  // Filter Count of 2 System Clocks
#define QEI_FILTCNT_3           0x00010000  // Filter Count of 3 System Clocks
#define QEI_FILTCNT_4           0x00020000  // Filter Count of 4 System Clocks
#define QEI_FILTCNT_5           0x00030000  // Filter Count of 5 System Clocks
#define QEI_FILTCNT_6           0x00040000  // Filter Count of 6 System Clocks
#define QEI_FILTCNT_7           0x00050000  // Filter Count of 7 System Clocks
#define QEI_FILTCNT_8           0x00060000  // Filter Count of 8 System Clocks
#define QEI_FILTCNT_9           0x00070000  // Filter Count of 9 System Clocks
#define QEI_FILTCNT_10          0x00080000  // Filter Count of 10 System Clocks
#define QEI_FILTCNT_11          0x00090000  // Filter Count of 11 System Clocks
#define QEI_FILTCNT_12          0x000A0000  // Filter Count of 12 System Clocks
#define QEI_FILTCNT_13          0x000B0000  // Filter Count of 13 System Clocks
#define QEI_FILTCNT_14          0x000C0000  // Filter Count of 14 System Clocks
#define QEI_FILTCNT_15          0x000D0000  // Filter Count of 15 System Clocks
#define QEI_FILTCNT_16          0x000E0000  // Filter Count of 16 System Clocks
#define QEI_FILTCNT_17          0x000F0000  // Filter Count of 17 System Clocks

//*****************************************************************************
//
// Values that can be passed to QEIVelocityConfigure as the ui32PreDiv
// parameter.
//
//*****************************************************************************
#define QEI_VELDIV_1            0x00000000  // Predivide by 1
#define QEI_VELDIV_2            0x00000040  // Predivide by 2
#define QEI_VELDIV_4            0x00000080  // Predivide by 4
#define QEI_VELDIV_8            0x000000C0  // Predivide by 8
#define QEI_VELDIV_16           0x00000100  // Predivide by 16
#define QEI_VELDIV_32           0x00000140  // Predivide by 32
#define QEI_VELDIV_64           0x00000180  // Predivide by 64
#define QEI_VELDIV_128          0x000001C0  // Predivide by 128

//*****************************************************************************
//
// Values that can be passed to QEIEnableInts, QEIDisableInts, and QEIClearInts
// as the ui32IntFlags parameter, and returned by QEIGetIntStatus.
//
//*****************************************************************************
#define QEI_INTERROR            0x00000008  // Phase error detected
#define QEI_INTDIR              0x00000004  // Direction change
#define QEI_INTTIMER            0x00000002  // Velocity timer expired
#define QEI_INTINDEX            0x00000001  // Index pulse detected

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void QEI_Enable(HM_QEI_TypeDef *QEIx);
extern void QEI_Disable(HM_QEI_TypeDef *QEIx);
extern void QEI_Configure(HM_QEI_TypeDef *QEIx, uint32_t ui32Config,uint32_t ui32MaxPosition);
extern uint32_t QEI_PositionGet(HM_QEI_TypeDef *QEIx);
extern void QEI_PositionSet(HM_QEI_TypeDef *QEIx, uint32_t ui32Position);
extern int32_t QEI_DirectionGet(HM_QEI_TypeDef *QEIx);
extern Bool QEI_ErrorGet(HM_QEI_TypeDef *QEIx);
extern void QEI_FilterEnable(HM_QEI_TypeDef *QEIx);
extern void QEI_FilterDisable(HM_QEI_TypeDef *QEIx);
extern void QEI_FilterConfigure(HM_QEI_TypeDef *QEIx, uint32_t ui32FiltCnt);
extern void QEI_VelocityEnable(HM_QEI_TypeDef *QEIx);
extern void QEI_VelocityDisable(HM_QEI_TypeDef *QEIx);
extern void QEI_VelocityConfigure(HM_QEI_TypeDef *QEIx, uint32_t ui32PreDiv, uint32_t ui32Period);
extern uint32_t QEI_VelocityGet(HM_QEI_TypeDef *QEIx);
extern void QEI_IntRegister(HM_QEI_TypeDef *QEIx, void (*pfnHandler)(void));
extern void QEI_IntUnregister(HM_QEI_TypeDef *QEIx);
extern void QEI_IntEnable(HM_QEI_TypeDef *QEIx, uint32_t ui32IntFlags);
extern void QEI_IntDisable(HM_QEI_TypeDef *QEIx, uint32_t ui32IntFlags);
extern uint32_t QEI_IntStatus(HM_QEI_TypeDef *QEIx, Bool bMasked);
extern void QEI_IntClear(HM_QEI_TypeDef *QEIx, uint32_t ui32IntFlags);



/**
 * @}
 */


#ifdef __cplusplus
}
#endif


#endif /* __HM_QEI_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
