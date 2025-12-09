//*****************************************************************************
//
// hm_timer.h - Prototypes for the timer module
//
//*****************************************************************************

#ifndef __DRIVERLIB_TIMER_H__
#define __DRIVERLIB_TIMER_H__

#include "hm_libcfg_default.h"
#include "hm_types.h"
//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_CFG register.
//
//*****************************************************************************
#define TIMER_CFG_M             0x00000007  // GPTM Configuration
#define TIMER_CFG_32_BIT_TIMER  0x00000000  // For a 16/32-bit timer, this
                                            // value selects the 32-bit timer
                                            // configuration
#define TIMER_CFG_32_BIT_RTC    0x00000001  // For a 16/32-bit timer, this
                                            // value selects the 32-bit
                                            // real-time clock (RTC) counter
                                            // configuration
#define TIMER_CFG_16_BIT        0x00000004  // For a 16/32-bit timer, this
                                            // value selects the 16-bit timer
                                            // configuration

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAMR register.
//
//*****************************************************************************
#define TIMER_TAMR_TCACT_M      0x0000E000  // Timer Compare Action Select
#define TIMER_TAMR_TCACT_NONE   0x00000000  // Disable compare operations
#define TIMER_TAMR_TCACT_TOGGLE 0x00002000  // Toggle State on Time-Out
#define TIMER_TAMR_TCACT_CLRTO  0x00004000  // Clear CCP on Time-Out
#define TIMER_TAMR_TCACT_SETTO  0x00006000  // Set CCP on Time-Out
#define TIMER_TAMR_TCACT_SETTOGTO                                             \
                                0x00008000  // Set CCP immediately and toggle
                                            // on Time-Out
#define TIMER_TAMR_TCACT_CLRTOGTO                                             \
                                0x0000A000  // Clear CCP immediately and toggle
                                            // on Time-Out
#define TIMER_TAMR_TCACT_SETCLRTO                                             \
                                0x0000C000  // Set CCP immediately and clear on
                                            // Time-Out
#define TIMER_TAMR_TCACT_CLRSETTO                                             \
                                0x0000E000  // Clear CCP immediately and set on
                                            // Time-Out
#define TIMER_TAMR_TACINTD      0x00001000  // One-shot/Periodic Interrupt
                                            // Disable
#define TIMER_TAMR_TAPLO        0x00000800  // GPTM Timer A PWM Legacy
                                            // Operation
#define TIMER_TAMR_TAMRSU       0x00000400  // GPTM Timer A Match Register
                                            // Update
#define TIMER_TAMR_TAPWMIE      0x00000200  // GPTM Timer A PWM Interrupt
                                            // Enable
#define TIMER_TAMR_TAILD        0x00000100  // GPTM Timer A Interval Load Write
#define TIMER_TAMR_TASNAPS      0x00000080  // GPTM Timer A Snap-Shot Mode
#define TIMER_TAMR_TAWOT        0x00000040  // GPTM Timer A Wait-on-Trigger
#define TIMER_TAMR_TAMIE        0x00000020  // GPTM Timer A Match Interrupt
                                            // Enable
#define TIMER_TAMR_TACDIR       0x00000010  // GPTM Timer A Count Direction
#define TIMER_TAMR_TAAMS        0x00000008  // GPTM Timer A Alternate Mode
                                            // Select
#define TIMER_TAMR_TACMR        0x00000004  // GPTM Timer A Capture Mode
#define TIMER_TAMR_TAMR_M       0x00000003  // GPTM Timer A Mode
#define TIMER_TAMR_TAMR_1_SHOT  0x00000001  // One-Shot Timer mode
#define TIMER_TAMR_TAMR_PERIOD  0x00000002  // Periodic Timer mode
#define TIMER_TAMR_TAMR_CAP     0x00000003  // Capture mode

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBMR register.
//
//*****************************************************************************
#define TIMER_TBMR_TCACT_M      0x0000E000  // Timer Compare Action Select
#define TIMER_TBMR_TCACT_NONE   0x00000000  // Disable compare operations
#define TIMER_TBMR_TCACT_TOGGLE 0x00002000  // Toggle State on Time-Out
#define TIMER_TBMR_TCACT_CLRTO  0x00004000  // Clear CCP on Time-Out
#define TIMER_TBMR_TCACT_SETTO  0x00006000  // Set CCP on Time-Out
#define TIMER_TBMR_TCACT_SETTOGTO                                             \
                                0x00008000  // Set CCP immediately and toggle
                                            // on Time-Out
#define TIMER_TBMR_TCACT_CLRTOGTO                                             \
                                0x0000A000  // Clear CCP immediately and toggle
                                            // on Time-Out
#define TIMER_TBMR_TCACT_SETCLRTO                                             \
                                0x0000C000  // Set CCP immediately and clear on
                                            // Time-Out
#define TIMER_TBMR_TCACT_CLRSETTO                                             \
                                0x0000E000  // Clear CCP immediately and set on
                                            // Time-Out
#define TIMER_TBMR_TBCINTD      0x00001000  // One-Shot/Periodic Interrupt
                                            // Disable
#define TIMER_TBMR_TBPLO        0x00000800  // GPTM Timer B PWM Legacy
                                            // Operation
#define TIMER_TBMR_TBMRSU       0x00000400  // GPTM Timer B Match Register
                                            // Update
#define TIMER_TBMR_TBPWMIE      0x00000200  // GPTM Timer B PWM Interrupt
                                            // Enable
#define TIMER_TBMR_TBILD        0x00000100  // GPTM Timer B Interval Load Write
#define TIMER_TBMR_TBSNAPS      0x00000080  // GPTM Timer B Snap-Shot Mode
#define TIMER_TBMR_TBWOT        0x00000040  // GPTM Timer B Wait-on-Trigger
#define TIMER_TBMR_TBMIE        0x00000020  // GPTM Timer B Match Interrupt
                                            // Enable
#define TIMER_TBMR_TBCDIR       0x00000010  // GPTM Timer B Count Direction
#define TIMER_TBMR_TBAMS        0x00000008  // GPTM Timer B Alternate Mode
                                            // Select
#define TIMER_TBMR_TBCMR        0x00000004  // GPTM Timer B Capture Mode
#define TIMER_TBMR_TBMR_M       0x00000003  // GPTM Timer B Mode
#define TIMER_TBMR_TBMR_1_SHOT  0x00000001  // One-Shot Timer mode
#define TIMER_TBMR_TBMR_PERIOD  0x00000002  // Periodic Timer mode
#define TIMER_TBMR_TBMR_CAP     0x00000003  // Capture mode

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_CTL register.
//
//*****************************************************************************
#define TIMER_CTL_TBPWML        0x00004000  // GPTM Timer B PWM Output Level
#define TIMER_CTL_TBOTE         0x00002000  // GPTM Timer B Output Trigger
                                            // Enable
#define TIMER_CTL_TBEVENT_M     0x00000C00  // GPTM Timer B Event Mode
#define TIMER_CTL_TBEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TBEVENT_NEG   0x00000400  // Negative edge
#define TIMER_CTL_TBEVENT_BOTH  0x00000C00  // Both edges
#define TIMER_CTL_TBSTALL       0x00000200  // GPTM Timer B Stall Enable
#define TIMER_CTL_TBEN          0x00000100  // GPTM Timer B Enable
#define TIMER_CTL_TAPWML        0x00000040  // GPTM Timer A PWM Output Level
#define TIMER_CTL_TAOTE         0x00000020  // GPTM Timer A Output Trigger
                                            // Enable
#define TIMER_CTL_RTCEN         0x00000010  // GPTM RTC Stall Enable
#define TIMER_CTL_TAEVENT_M     0x0000000C  // GPTM Timer A Event Mode
#define TIMER_CTL_TAEVENT_POS   0x00000000  // Positive edge
#define TIMER_CTL_TAEVENT_NEG   0x00000004  // Negative edge
#define TIMER_CTL_TAEVENT_BOTH  0x0000000C  // Both edges
#define TIMER_CTL_TASTALL       0x00000002  // GPTM Timer A Stall Enable
#define TIMER_CTL_TAEN          0x00000001  // GPTM Timer A Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_SYNC register.
//
//*****************************************************************************
#define TIMER_SYNC_SYNCWT5_M    0x00C00000  // Synchronize GPTM 32/64-Bit Timer
                                            // 5
#define TIMER_SYNC_SYNCWT5_NONE 0x00000000  // GPTM 32/64-Bit Timer 5 is not
                                            // affected
#define TIMER_SYNC_SYNCWT5_TA   0x00400000  // A timeout event for Timer A of
                                            // GPTM 32/64-Bit Timer 5 is
                                            // triggered
#define TIMER_SYNC_SYNCWT5_TB   0x00800000  // A timeout event for Timer B of
                                            // GPTM 32/64-Bit Timer 5 is
                                            // triggered
#define TIMER_SYNC_SYNCWT5_TATB 0x00C00000  // A timeout event for both Timer A
                                            // and Timer B of GPTM 32/64-Bit
                                            // Timer 5 is triggered
#define TIMER_SYNC_SYNCWT4_M    0x00300000  // Synchronize GPTM 32/64-Bit Timer
                                            // 4
#define TIMER_SYNC_SYNCWT4_NONE 0x00000000  // GPTM 32/64-Bit Timer 4 is not
                                            // affected
#define TIMER_SYNC_SYNCWT4_TA   0x00100000  // A timeout event for Timer A of
                                            // GPTM 32/64-Bit Timer 4 is
                                            // triggered
#define TIMER_SYNC_SYNCWT4_TB   0x00200000  // A timeout event for Timer B of
                                            // GPTM 32/64-Bit Timer 4 is
                                            // triggered
#define TIMER_SYNC_SYNCWT4_TATB 0x00300000  // A timeout event for both Timer A
                                            // and Timer B of GPTM 32/64-Bit
                                            // Timer 4 is triggered
#define TIMER_SYNC_SYNCWT3_M    0x000C0000  // Synchronize GPTM 32/64-Bit Timer
                                            // 3
#define TIMER_SYNC_SYNCWT3_NONE 0x00000000  // GPTM 32/64-Bit Timer 3 is not
                                            // affected
#define TIMER_SYNC_SYNCWT3_TA   0x00040000  // A timeout event for Timer A of
                                            // GPTM 32/64-Bit Timer 3 is
                                            // triggered
#define TIMER_SYNC_SYNCWT3_TB   0x00080000  // A timeout event for Timer B of
                                            // GPTM 32/64-Bit Timer 3 is
                                            // triggered
#define TIMER_SYNC_SYNCWT3_TATB 0x000C0000  // A timeout event for both Timer A
                                            // and Timer B of GPTM 32/64-Bit
                                            // Timer 3 is triggered
#define TIMER_SYNC_SYNCWT2_M    0x00030000  // Synchronize GPTM 32/64-Bit Timer
                                            // 2
#define TIMER_SYNC_SYNCWT2_NONE 0x00000000  // GPTM 32/64-Bit Timer 2 is not
                                            // affected
#define TIMER_SYNC_SYNCWT2_TA   0x00010000  // A timeout event for Timer A of
                                            // GPTM 32/64-Bit Timer 2 is
                                            // triggered
#define TIMER_SYNC_SYNCWT2_TB   0x00020000  // A timeout event for Timer B of
                                            // GPTM 32/64-Bit Timer 2 is
                                            // triggered
#define TIMER_SYNC_SYNCWT2_TATB 0x00030000  // A timeout event for both Timer A
                                            // and Timer B of GPTM 32/64-Bit
                                            // Timer 2 is triggered
#define TIMER_SYNC_SYNCT7_M     0x0000C000  // Synchronize GPTM Timer 7
#define TIMER_SYNC_SYNCT7_NONE  0x00000000  // GPT7 is not affected
#define TIMER_SYNC_SYNCT7_TA    0x00004000  // A timeout event for Timer A of
                                            // GPTM7 is triggered
#define TIMER_SYNC_SYNCT7_TB    0x00008000  // A timeout event for Timer B of
                                            // GPTM7 is triggered
#define TIMER_SYNC_SYNCT7_TATB  0x0000C000  // A timeout event for both Timer A
                                            // and Timer B of GPTM7 is
                                            // triggered
#define TIMER_SYNC_SYNCWT1_M    0x0000C000  // Synchronize GPTM 32/64-Bit Timer
                                            // 1
#define TIMER_SYNC_SYNCWT1_NONE 0x00000000  // GPTM 32/64-Bit Timer 1 is not
                                            // affected
#define TIMER_SYNC_SYNCWT1_TA   0x00004000  // A timeout event for Timer A of
                                            // GPTM 32/64-Bit Timer 1 is
                                            // triggered
#define TIMER_SYNC_SYNCWT1_TB   0x00008000  // A timeout event for Timer B of
                                            // GPTM 32/64-Bit Timer 1 is
                                            // triggered
#define TIMER_SYNC_SYNCWT1_TATB 0x0000C000  // A timeout event for both Timer A
                                            // and Timer B of GPTM 32/64-Bit
                                            // Timer 1 is triggered
#define TIMER_SYNC_SYNCWT0_M    0x00003000  // Synchronize GPTM 32/64-Bit Timer
                                            // 0
#define TIMER_SYNC_SYNCWT0_NONE 0x00000000  // GPTM 32/64-Bit Timer 0 is not
                                            // affected
#define TIMER_SYNC_SYNCWT0_TA   0x00001000  // A timeout event for Timer A of
                                            // GPTM 32/64-Bit Timer 0 is
                                            // triggered
#define TIMER_SYNC_SYNCWT0_TB   0x00002000  // A timeout event for Timer B of
                                            // GPTM 32/64-Bit Timer 0 is
                                            // triggered
#define TIMER_SYNC_SYNCWT0_TATB 0x00003000  // A timeout event for both Timer A
                                            // and Timer B of GPTM 32/64-Bit
                                            // Timer 0 is triggered
#define TIMER_SYNC_SYNCT6_M     0x00003000  // Synchronize GPTM Timer 6
#define TIMER_SYNC_SYNCT6_NONE  0x00000000  // GPTM6 is not affected
#define TIMER_SYNC_SYNCT6_TA    0x00001000  // A timeout event for Timer A of
                                            // GPTM6 is triggered
#define TIMER_SYNC_SYNCT6_TB    0x00002000  // A timeout event for Timer B of
                                            // GPTM6 is triggered
#define TIMER_SYNC_SYNCT6_TATB  0x00003000  // A timeout event for both Timer A
                                            // and Timer B of GPTM6 is
                                            // triggered
#define TIMER_SYNC_SYNCT5_M     0x00000C00  // Synchronize GPTM Timer 5
#define TIMER_SYNC_SYNCT5_NONE  0x00000000  // GPTM5 is not affected
#define TIMER_SYNC_SYNCT5_TA    0x00000400  // A timeout event for Timer A of
                                            // GPTM5 is triggered
#define TIMER_SYNC_SYNCT5_TB    0x00000800  // A timeout event for Timer B of
                                            // GPTM5 is triggered
#define TIMER_SYNC_SYNCT5_TATB  0x00000C00  // A timeout event for both Timer A
                                            // and Timer B of GPTM5 is
                                            // triggered
#define TIMER_SYNC_SYNCT4_M     0x00000300  // Synchronize GPTM Timer 4
#define TIMER_SYNC_SYNCT4_NONE  0x00000000  // GPTM4 is not affected
#define TIMER_SYNC_SYNCT4_TA    0x00000100  // A timeout event for Timer A of
                                            // GPTM4 is triggered
#define TIMER_SYNC_SYNCT4_TB    0x00000200  // A timeout event for Timer B of
                                            // GPTM4 is triggered
#define TIMER_SYNC_SYNCT4_TATB  0x00000300  // A timeout event for both Timer A
                                            // and Timer B of GPTM4 is
                                            // triggered
#define TIMER_SYNC_SYNCT3_M     0x000000C0  // Synchronize GPTM Timer 3
#define TIMER_SYNC_SYNCT3_NONE  0x00000000  // GPTM3 is not affected
#define TIMER_SYNC_SYNCT3_TA    0x00000040  // A timeout event for Timer A of
                                            // GPTM3 is triggered
#define TIMER_SYNC_SYNCT3_TB    0x00000080  // A timeout event for Timer B of
                                            // GPTM3 is triggered
#define TIMER_SYNC_SYNCT3_TATB  0x000000C0  // A timeout event for both Timer A
                                            // and Timer B of GPTM3 is
                                            // triggered
#define TIMER_SYNC_SYNCT2_M     0x00000030  // Synchronize GPTM Timer 2
#define TIMER_SYNC_SYNCT2_NONE  0x00000000  // GPTM2 is not affected
#define TIMER_SYNC_SYNCT2_TA    0x00000010  // A timeout event for Timer A of
                                            // GPTM2 is triggered
#define TIMER_SYNC_SYNCT2_TB    0x00000020  // A timeout event for Timer B of
                                            // GPTM2 is triggered
#define TIMER_SYNC_SYNCT2_TATB  0x00000030  // A timeout event for both Timer A
                                            // and Timer B of GPTM2 is
                                            // triggered
#define TIMER_SYNC_SYNCT1_M     0x0000000C  // Synchronize GPTM Timer 1
#define TIMER_SYNC_SYNCT1_NONE  0x00000000  // GPTM1 is not affected
#define TIMER_SYNC_SYNCT1_TA    0x00000004  // A timeout event for Timer A of
                                            // GPTM1 is triggered
#define TIMER_SYNC_SYNCT1_TB    0x00000008  // A timeout event for Timer B of
                                            // GPTM1 is triggered
#define TIMER_SYNC_SYNCT1_TATB  0x0000000C  // A timeout event for both Timer A
                                            // and Timer B of GPTM1 is
                                            // triggered
#define TIMER_SYNC_SYNCT0_M     0x00000003  // Synchronize GPTM Timer 0
#define TIMER_SYNC_SYNCT0_NONE  0x00000000  // GPTM0 is not affected
#define TIMER_SYNC_SYNCT0_TA    0x00000001  // A timeout event for Timer A of
                                            // GPTM0 is triggered
#define TIMER_SYNC_SYNCT0_TB    0x00000002  // A timeout event for Timer B of
                                            // GPTM0 is triggered
#define TIMER_SYNC_SYNCT0_TATB  0x00000003  // A timeout event for both Timer A
                                            // and Timer B of GPTM0 is
                                            // triggered

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_IMR register.
//
//*****************************************************************************
#define TIMER_IMR_WUEIM         0x00010000  // 32/64-Bit Wide GPTM Write Update
                                            // Error Interrupt Mask
#define TIMER_IMR_DMABIM        0x00002000  // GPTM Timer B DMA Done Interrupt
                                            // Mask
#define TIMER_IMR_TBMIM         0x00000800  // GPTM Timer B Match Interrupt
                                            // Mask
#define TIMER_IMR_CBEIM         0x00000400  // GPTM Timer B Capture Mode Event
                                            // Interrupt Mask
#define TIMER_IMR_CBMIM         0x00000200  // GPTM Timer B Capture Mode Match
                                            // Interrupt Mask
#define TIMER_IMR_TBTOIM        0x00000100  // GPTM Timer B Time-Out Interrupt
                                            // Mask
#define TIMER_IMR_DMAAIM        0x00000020  // GPTM Timer A DMA Done Interrupt
                                            // Mask
#define TIMER_IMR_TAMIM         0x00000010  // GPTM Timer A Match Interrupt
                                            // Mask
#define TIMER_IMR_RTCIM         0x00000008  // GPTM RTC Interrupt Mask
#define TIMER_IMR_CAEIM         0x00000004  // GPTM Timer A Capture Mode Event
                                            // Interrupt Mask
#define TIMER_IMR_CAMIM         0x00000002  // GPTM Timer A Capture Mode Match
                                            // Interrupt Mask
#define TIMER_IMR_TATOIM        0x00000001  // GPTM Timer A Time-Out Interrupt
                                            // Mask

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_RIS register.
//
//*****************************************************************************
#define TIMER_RIS_WUERIS        0x00010000  // 32/64-Bit Wide GPTM Write Update
                                            // Error Raw Interrupt Status
#define TIMER_RIS_DMABRIS       0x00002000  // GPTM Timer B DMA Done Raw
                                            // Interrupt Status
#define TIMER_RIS_TBMRIS        0x00000800  // GPTM Timer B Match Raw Interrupt
#define TIMER_RIS_CBERIS        0x00000400  // GPTM Timer B Capture Mode Event
                                            // Raw Interrupt
#define TIMER_RIS_CBMRIS        0x00000200  // GPTM Timer B Capture Mode Match
                                            // Raw Interrupt
#define TIMER_RIS_TBTORIS       0x00000100  // GPTM Timer B Time-Out Raw
                                            // Interrupt
#define TIMER_RIS_DMAARIS       0x00000020  // GPTM Timer A DMA Done Raw
                                            // Interrupt Status
#define TIMER_RIS_TAMRIS        0x00000010  // GPTM Timer A Match Raw Interrupt
#define TIMER_RIS_RTCRIS        0x00000008  // GPTM RTC Raw Interrupt
#define TIMER_RIS_CAERIS        0x00000004  // GPTM Timer A Capture Mode Event
                                            // Raw Interrupt
#define TIMER_RIS_CAMRIS        0x00000002  // GPTM Timer A Capture Mode Match
                                            // Raw Interrupt
#define TIMER_RIS_TATORIS       0x00000001  // GPTM Timer A Time-Out Raw
                                            // Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_MIS register.
//
//*****************************************************************************
#define TIMER_MIS_WUEMIS        0x00010000  // 32/64-Bit Wide GPTM Write Update
                                            // Error Masked Interrupt Status
#define TIMER_MIS_DMABMIS       0x00002000  // GPTM Timer B DMA Done Masked
                                            // Interrupt
#define TIMER_MIS_TBMMIS        0x00000800  // GPTM Timer B Match Masked
                                            // Interrupt
#define TIMER_MIS_CBEMIS        0x00000400  // GPTM Timer B Capture Mode Event
                                            // Masked Interrupt
#define TIMER_MIS_CBMMIS        0x00000200  // GPTM Timer B Capture Mode Match
                                            // Masked Interrupt
#define TIMER_MIS_TBTOMIS       0x00000100  // GPTM Timer B Time-Out Masked
                                            // Interrupt
#define TIMER_MIS_DMAAMIS       0x00000020  // GPTM Timer A DMA Done Masked
                                            // Interrupt
#define TIMER_MIS_TAMMIS        0x00000010  // GPTM Timer A Match Masked
                                            // Interrupt
#define TIMER_MIS_RTCMIS        0x00000008  // GPTM RTC Masked Interrupt
#define TIMER_MIS_CAEMIS        0x00000004  // GPTM Timer A Capture Mode Event
                                            // Masked Interrupt
#define TIMER_MIS_CAMMIS        0x00000002  // GPTM Timer A Capture Mode Match
                                            // Masked Interrupt
#define TIMER_MIS_TATOMIS       0x00000001  // GPTM Timer A Time-Out Masked
                                            // Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_ICR register.
//
//*****************************************************************************
#define TIMER_ICR_WUECINT       0x00010000  // 32/64-Bit Wide GPTM Write Update
                                            // Error Interrupt Clear
#define TIMER_ICR_DMABINT       0x00002000  // GPTM Timer B DMA Done Interrupt
                                            // Clear
#define TIMER_ICR_TBMCINT       0x00000800  // GPTM Timer B Match Interrupt
                                            // Clear
#define TIMER_ICR_CBECINT       0x00000400  // GPTM Timer B Capture Mode Event
                                            // Interrupt Clear
#define TIMER_ICR_CBMCINT       0x00000200  // GPTM Timer B Capture Mode Match
                                            // Interrupt Clear
#define TIMER_ICR_TBTOCINT      0x00000100  // GPTM Timer B Time-Out Interrupt
                                            // Clear
#define TIMER_ICR_DMAAINT       0x00000020  // GPTM Timer A DMA Done Interrupt
                                            // Clear
#define TIMER_ICR_TAMCINT       0x00000010  // GPTM Timer A Match Interrupt
                                            // Clear
#define TIMER_ICR_RTCCINT       0x00000008  // GPTM RTC Interrupt Clear
#define TIMER_ICR_CAECINT       0x00000004  // GPTM Timer A Capture Mode Event
                                            // Interrupt Clear
#define TIMER_ICR_CAMCINT       0x00000002  // GPTM Timer A Capture Mode Match
                                            // Interrupt Clear
#define TIMER_ICR_TATOCINT      0x00000001  // GPTM Timer A Time-Out Raw
                                            // Interrupt

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAILR register.
//
//*****************************************************************************
#define TIMER_TAILR_M           0xFFFFFFFF  // GPTM Timer A Interval Load
                                            // Register
#define TIMER_TAILR_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBILR register.
//
//*****************************************************************************
#define TIMER_TBILR_M           0xFFFFFFFF  // GPTM Timer B Interval Load
                                            // Register
#define TIMER_TBILR_S           0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAMATCHR
// register.
//
//*****************************************************************************
#define TIMER_TAMATCHR_TAMR_M   0xFFFFFFFF  // GPTM Timer A Match Register
#define TIMER_TAMATCHR_TAMR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBMATCHR
// register.
//
//*****************************************************************************
#define TIMER_TBMATCHR_TBMR_M   0xFFFFFFFF  // GPTM Timer B Match Register
#define TIMER_TBMATCHR_TBMR_S   0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAPR register.
//
//*****************************************************************************
#define TIMER_TAPR_TAPSRH_M     0x0000FF00  // GPTM Timer A Prescale High Byte
#define TIMER_TAPR_TAPSR_M      0x000000FF  // GPTM Timer A Prescale
#define TIMER_TAPR_TAPSRH_S     8
#define TIMER_TAPR_TAPSR_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBPR register.
//
//*****************************************************************************
#define TIMER_TBPR_TBPSRH_M     0x0000FF00  // GPTM Timer B Prescale High Byte
#define TIMER_TBPR_TBPSR_M      0x000000FF  // GPTM Timer B Prescale
#define TIMER_TBPR_TBPSRH_S     8
#define TIMER_TBPR_TBPSR_S      0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAPMR register.
//
//*****************************************************************************
#define TIMER_TAPMR_TAPSMRH_M   0x0000FF00  // GPTM Timer A Prescale Match High
                                            // Byte
#define TIMER_TAPMR_TAPSMR_M    0x000000FF  // GPTM TimerA Prescale Match
#define TIMER_TAPMR_TAPSMRH_S   8
#define TIMER_TAPMR_TAPSMR_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBPMR register.
//
//*****************************************************************************
#define TIMER_TBPMR_TBPSMRH_M   0x0000FF00  // GPTM Timer B Prescale Match High
                                            // Byte
#define TIMER_TBPMR_TBPSMR_M    0x000000FF  // GPTM TimerB Prescale Match
#define TIMER_TBPMR_TBPSMRH_S   8
#define TIMER_TBPMR_TBPSMR_S    0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAR register.
//
//*****************************************************************************
#define TIMER_TAR_M             0xFFFFFFFF  // GPTM Timer A Register
#define TIMER_TAR_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBR register.
//
//*****************************************************************************
#define TIMER_TBR_M             0xFFFFFFFF  // GPTM Timer B Register
#define TIMER_TBR_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAV register.
//
//*****************************************************************************
#define TIMER_TAV_M             0xFFFFFFFF  // GPTM Timer A Value
#define TIMER_TAV_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBV register.
//
//*****************************************************************************
#define TIMER_TBV_M             0xFFFFFFFF  // GPTM Timer B Value
#define TIMER_TBV_S             0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_RTCPD register.
//
//*****************************************************************************
#define TIMER_RTCPD_RTCPD_M     0x0000FFFF  // RTC Predivide Counter Value
#define TIMER_RTCPD_RTCPD_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAPS register.
//
//*****************************************************************************
#define TIMER_TAPS_PSS_M        0x0000FFFF  // GPTM Timer A Prescaler Snapshot
#define TIMER_TAPS_PSS_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBPS register.
//
//*****************************************************************************
#define TIMER_TBPS_PSS_M        0x0000FFFF  // GPTM Timer A Prescaler Value
#define TIMER_TBPS_PSS_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TAPV register.
//
//*****************************************************************************
#define TIMER_TAPV_PSV_M        0x0000FFFF  // GPTM Timer A Prescaler Value
#define TIMER_TAPV_PSV_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_TBPV register.
//
//*****************************************************************************
#define TIMER_TBPV_PSV_M        0x0000FFFF  // GPTM Timer B Prescaler Value
#define TIMER_TBPV_PSV_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_DMAEV register.
//
//*****************************************************************************
#define TIMER_DMAEV_TBMDMAEN    0x00000800  // GPTM B Mode Match Event DMA
                                            // Trigger Enable
#define TIMER_DMAEV_CBEDMAEN    0x00000400  // GPTM B Capture Event DMA Trigger
                                            // Enable
#define TIMER_DMAEV_CBMDMAEN    0x00000200  // GPTM B Capture Match Event DMA
                                            // Trigger Enable
#define TIMER_DMAEV_TBTODMAEN   0x00000100  // GPTM B Time-Out Event DMA
                                            // Trigger Enable
#define TIMER_DMAEV_TAMDMAEN    0x00000010  // GPTM A Mode Match Event DMA
                                            // Trigger Enable
#define TIMER_DMAEV_RTCDMAEN    0x00000008  // GPTM A RTC Match Event DMA
                                            // Trigger Enable
#define TIMER_DMAEV_CAEDMAEN    0x00000004  // GPTM A Capture Event DMA Trigger
                                            // Enable
#define TIMER_DMAEV_CAMDMAEN    0x00000002  // GPTM A Capture Match Event DMA
                                            // Trigger Enable
#define TIMER_DMAEV_TATODMAEN   0x00000001  // GPTM A Time-Out Event DMA
                                            // Trigger Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_ADCEV register.
//
//*****************************************************************************
#define TIMER_ADCEV_TBMADCEN    0x00000800  // GPTM B Mode Match Event ADC
                                            // Trigger Enable
#define TIMER_ADCEV_CBEADCEN    0x00000400  // GPTM B Capture Event ADC Trigger
                                            // Enable
#define TIMER_ADCEV_CBMADCEN    0x00000200  // GPTM B Capture Match Event ADC
                                            // Trigger Enable
#define TIMER_ADCEV_TBTOADCEN   0x00000100  // GPTM B Time-Out Event ADC
                                            // Trigger Enable
#define TIMER_ADCEV_TAMADCEN    0x00000010  // GPTM A Mode Match Event ADC
                                            // Trigger Enable
#define TIMER_ADCEV_RTCADCEN    0x00000008  // GPTM RTC Match Event ADC Trigger
                                            // Enable
#define TIMER_ADCEV_CAEADCEN    0x00000004  // GPTM A Capture Event ADC Trigger
                                            // Enable
#define TIMER_ADCEV_CAMADCEN    0x00000002  // GPTM A Capture Match Event ADC
                                            // Trigger Enable
#define TIMER_ADCEV_TATOADCEN   0x00000001  // GPTM A Time-Out Event ADC
                                            // Trigger Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_PP register.
//
//*****************************************************************************
#define TIMER_PP_ALTCLK         0x00000040  // Alternate Clock Source
#define TIMER_PP_SYNCCNT        0x00000020  // Synchronize Start
#define TIMER_PP_CHAIN          0x00000010  // Chain with Other Timers
#define TIMER_PP_SIZE_M         0x0000000F  // Count Size
#define TIMER_PP_SIZE_16        0x00000000  // Timer A and Timer B counters are
                                            // 16 bits each with an 8-bit
                                            // prescale counter
#define TIMER_PP_SIZE_32        0x00000001  // Timer A and Timer B counters are
                                            // 32 bits each with a 16-bit
                                            // prescale counter

//*****************************************************************************
//
// The following are defines for the bit fields in the TIMER_O_CC register.
//
//*****************************************************************************
#define TIMER_CC_ALTCLK         0x00000001  // Alternate Clock Source

//*****************************************************************************
//
// Values that can be passed to TimerConfigure as the ui32Config parameter.
//
//*****************************************************************************
#define TIMER_CFG_ONE_SHOT       0x00000021  // Full-width one-shot timer
#define TIMER_CFG_ONE_SHOT_UP    0x00000031  // Full-width one-shot up-count
                                            // timer
#define TIMER_CFG_PERIODIC       0x00000022  // Full-width periodic timer
#define TIMER_CFG_PERIODIC_UP    0x00000032  // Full-width periodic up-count
                                            // timer
#define TIMER_CFG_RTC            0x01000000  // Full-width RTC timer
#define TIMER_CFG_SPLIT_PAIR     0x04000000  // Two half-width timers
#define TIMER_CFG_A_ONE_SHOT     0x00000021  // Timer A one-shot timer
#define TIMER_CFG_A_ONE_SHOT_UP  0x00000031  // Timer A one-shot up-count timer
#define TIMER_CFG_A_PERIODIC     0x00000022  // Timer A periodic timer
#define TIMER_CFG_A_PERIODIC_UP  0x00000032  // Timer A periodic up-count timer
#define TIMER_CFG_A_CAP_COUNT    0x00000003  // Timer A event counter
#define TIMER_CFG_A_CAP_COUNT_UP 0x00000013  // Timer A event up-counter
#define TIMER_CFG_A_CAP_TIME     0x00000007  // Timer A event timer
#define TIMER_CFG_A_CAP_TIME_UP  0x00000017  // Timer A event up-count timer
#define TIMER_CFG_A_ONE_SHOT_PWM 0x00000009  // Timer A one-shot PWM output
#define TIMER_CFG_A_PWM          0x0000000A  // Timer A PWM output
#define TIMER_CFG_B_ONE_SHOT     0x00002100  // Timer B one-shot timer
#define TIMER_CFG_B_ONE_SHOT_UP  0x00003100  // Timer B one-shot up-count timer
#define TIMER_CFG_B_PERIODIC     0x00002200  // Timer B periodic timer
#define TIMER_CFG_B_PERIODIC_UP  0x00003200  // Timer B periodic up-count timer
#define TIMER_CFG_B_CAP_COUNT    0x00000300  // Timer B event counter
#define TIMER_CFG_B_CAP_COUNT_UP 0x00001300  // Timer B event up-counter
#define TIMER_CFG_B_CAP_TIME     0x00000700  // Timer B event timer
#define TIMER_CFG_B_CAP_TIME_UP  0x00001700  // Timer B event up-count timer
#define TIMER_CFG_B_ONE_SHOT_PWM 0x00000900  // Timer B one-shot PWM output
#define TIMER_CFG_B_PWM          0x00000A00  // Timer B PWM output
#define TIMER_CFG_A_ACT_TOINTD   0x00010000  // Timer A compare action disable
                                             // time-out interrupt.
#define TIMER_CFG_A_ACT_NONE     0x00000000  // Timer A compare action none.
#define TIMER_CFG_A_ACT_TOGGLE   0x00020000  // Timer A compare action toggle.
#define TIMER_CFG_A_ACT_CLRTO    0x00040000  // Timer A compare action CCP
                                             // clear on time-out.
#define TIMER_CFG_A_ACT_SETTO    0x00060000  // Timer A compare action CCP set
                                             // on time-out.
#define TIMER_CFG_A_ACT_SETTOGTO 0x00080000  // Timer A compare action set CCP
                                             // toggle on time-out.
#define TIMER_CFG_A_ACT_CLRTOGTO 0x000A0000  // Timer A compare action clear
                                             // CCP toggle on time-out.
#define TIMER_CFG_A_ACT_SETCLRTO 0x000C0000  // Timer A compare action set CCP
                                             // clear on time-out.
#define TIMER_CFG_A_ACT_CLRSETTO 0x000E0000  // Timer A compare action clear
                                             // CCP set on time-out.
#define TIMER_CFG_B_ACT_TOINTD   0x00100000  // Timer B compare action disable
                                             // time-out interrupt.
#define TIMER_CFG_B_ACT_NONE     0x00000000  // Timer A compare action none.
#define TIMER_CFG_B_ACT_TOGGLE   0x00200000  // Timer A compare action toggle.
#define TIMER_CFG_B_ACT_CLRTO    0x00400000  // Timer A compare action CCP
                                             // clear on time-out.
#define TIMER_CFG_B_ACT_SETTO    0x00600000  // Timer A compare action CCP set
                                             // on time-out.
#define TIMER_CFG_B_ACT_SETTOGTO 0x00800000  // Timer A compare action set CCP
                                             // toggle on time-out.
#define TIMER_CFG_B_ACT_CLRTOGTO 0x00A00000  // Timer A compare action clear
                                             // CCP toggle on time-out.
#define TIMER_CFG_B_ACT_SETCLRTO 0x00C00000  // Timer A compare action set CCP
                                             // clear on time-out.
#define TIMER_CFG_B_ACT_CLRSETTO 0x0000E000  // Timer A compare action clear
                                             // CCP set on time-out.

//*****************************************************************************
//
// Values that can be passed to TimerIntEnable, TimerIntDisable, and
// TimerIntClear as the ui32IntFlags parameter, and returned from
// TimerIntStatus.
//
//*****************************************************************************
#define TIMER_TIMB_DMA          0x00002000 // TimerB DMA Complete Interrupt.
#define TIMER_TIMB_MATCH        0x00000800  // TimerB match interrupt
#define TIMER_CAPB_EVENT        0x00000400  // CaptureB event interrupt
#define TIMER_CAPB_MATCH        0x00000200  // CaptureB match interrupt
#define TIMER_TIMB_TIMEOUT      0x00000100  // TimerB time out interrupt
#define TIMER_TIMA_DMA          0x00000020 // TimerA DMA Complete Interrupt.
#define TIMER_TIMA_MATCH        0x00000010  // TimerA match interrupt
#define TIMER_RTC_MATCH         0x00000008  // RTC interrupt mask
#define TIMER_CAPA_EVENT        0x00000004  // CaptureA event interrupt
#define TIMER_CAPA_MATCH        0x00000002  // CaptureA match interrupt
#define TIMER_TIMA_TIMEOUT      0x00000001  // TimerA time out interrupt

//*****************************************************************************
//
// Values that can be passed to TimerControlEvent as the ui32Event parameter.
//
//*****************************************************************************
#define TIMER_EVENT_POS_EDGE    0x00000000  // Count positive edges
#define TIMER_EVENT_NEG_EDGE    0x00000404  // Count negative edges
#define TIMER_EVENT_BOTH_EDGES  0x00000C0C  // Count both edges

//*****************************************************************************
//
// Values that can be passed to most of the timer APIs as the ui32Timer
// parameter.
//
//*****************************************************************************
#define TIMER_A                 0x000000ff  // Timer A
#define TIMER_B                 0x0000ff00  // Timer B
#define TIMER_BOTH              0x0000ffff  // Timer Both

//*****************************************************************************
//
// Values that can be passed to TimerSynchronize as the ui32Timers parameter.
//
//*****************************************************************************
#define TIMER_0A_SYNC           0x00000001  // Synchronize Timer 0A
#define TIMER_0B_SYNC           0x00000002  // Synchronize Timer 0B
#define TIMER_1A_SYNC           0x00000004  // Synchronize Timer 1A
#define TIMER_1B_SYNC           0x00000008  // Synchronize Timer 1B
#define TIMER_2A_SYNC           0x00000010  // Synchronize Timer 2A
#define TIMER_2B_SYNC           0x00000020  // Synchronize Timer 2B
#define TIMER_3A_SYNC           0x00000040  // Synchronize Timer 3A
#define TIMER_3B_SYNC           0x00000080  // Synchronize Timer 3B
#define TIMER_4A_SYNC           0x00000100  // Synchronize Timer 4A
#define TIMER_4B_SYNC           0x00000200  // Synchronize Timer 4B
#define TIMER_5A_SYNC           0x00000400  // Synchronize Timer 5A
#define TIMER_5B_SYNC           0x00000800  // Synchronize Timer 5B
#define WTIMER_0A_SYNC          0x00001000  // Synchronize Wide Timer 0A
#define WTIMER_0B_SYNC          0x00002000  // Synchronize Wide Timer 0B
#define WTIMER_1A_SYNC          0x00004000  // Synchronize Wide Timer 1A
#define WTIMER_1B_SYNC          0x00008000  // Synchronize Wide Timer 1B
#define WTIMER_2A_SYNC          0x00010000  // Synchronize Wide Timer 2A
#define WTIMER_2B_SYNC          0x00020000  // Synchronize Wide Timer 2B
#define WTIMER_3A_SYNC          0x00040000  // Synchronize Wide Timer 3A
#define WTIMER_3B_SYNC          0x00080000  // Synchronize Wide Timer 3B
#define WTIMER_4A_SYNC          0x00100000  // Synchronize Wide Timer 4A
#define WTIMER_4B_SYNC          0x00200000  // Synchronize Wide Timer 4B
#define WTIMER_5A_SYNC          0x00400000  // Synchronize Wide Timer 5A
#define WTIMER_5B_SYNC          0x00800000  // Synchronize Wide Timer 5B

//*****************************************************************************
//
// Values that can be passed to TimerClockSourceSet() or returned from
// TimerClockSourceGet().
//
//*****************************************************************************
#define TIMER_CLOCK_SYSTEM      0x00000000
#define TIMER_CLOCK_PIOSC       0x00000001

//*****************************************************************************
//
// Values that can be passed to TimerDMAEventSet() or returned from
// TimerDMAEventGet().
//
//*****************************************************************************
#define TIMER_DMA_MODEMATCH_B   0x00000800
#define TIMER_DMA_CAPEVENT_B    0x00000400
#define TIMER_DMA_CAPMATCH_B    0x00000200
#define TIMER_DMA_TIMEOUT_B     0x00000100
#define TIMER_DMA_MODEMATCH_A   0x00000010
#define TIMER_DMA_RTC_A         0x00000008
#define TIMER_DMA_CAPEVENT_A    0x00000004
#define TIMER_DMA_CAPMATCH_A    0x00000002
#define TIMER_DMA_TIMEOUT_A     0x00000001

//*****************************************************************************
//
// Values that can be passed to TimerADCEventSet() or returned from
// TimerADCEventGet().
//
//*****************************************************************************
#define TIMER_ADC_MODEMATCH_B   0x00000800
#define TIMER_ADC_CAPEVENT_B    0x00000400
#define TIMER_ADC_CAPMATCH_B    0x00000200
#define TIMER_ADC_TIMEOUT_B     0x00000100
#define TIMER_ADC_MODEMATCH_A   0x00000010
#define TIMER_ADC_RTC_A         0x00000008
#define TIMER_ADC_CAPEVENT_A    0x00000004
#define TIMER_ADC_CAPMATCH_A    0x00000002
#define TIMER_ADC_TIMEOUT_A     0x00000001

//*****************************************************************************
//
// Values that can be passed to TimerUpdateMode().
//
//*****************************************************************************
#define TIMER_UP_LOAD_IMMEDIATE 0x00000000
#define TIMER_UP_LOAD_TIMEOUT   0x00000100
#define TIMER_UP_MATCH_IMMEDIATE                                              \
                                0x00000000
#define TIMER_UP_MATCH_TIMEOUT  0x00000400

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void TIMER_Enable(HM_TIM_TypeDef *timer, uint32_t ui32Timer);
extern void TIMER_Disable(HM_TIM_TypeDef *timer, uint32_t ui32Timer);
void TIMER_Configure(HM_TIM_TypeDef *timer, uint32_t ui32Config);
extern void TIMER_ControlLevel(HM_TIM_TypeDef *timer, uint32_t ui32Timer, Bool bInvert);
//extern void TIMER_ControlTrigger(uint32_t ui32Base, uint32_t ui32Timer,Bool bEnable);
extern void TIMER_ControlEvent(HM_TIM_TypeDef *timer, uint32_t ui32Timer,
                  uint32_t ui32Event);
extern void TIMER_ControlStall(HM_TIM_TypeDef *timer, uint32_t ui32Timer,Bool bStall);
extern void TIMER_ControlWaitOnTrigger(HM_TIM_TypeDef *timer, uint32_t ui32Timer, Bool bWait);
extern void TIMER_RTCEnable(HM_TIM_TypeDef *timer);
extern void TIMER_RTCDisable(HM_TIM_TypeDef *timer);
extern void TIMER_PrescaleSet(HM_TIM_TypeDef *timer, uint32_t ui32Timer, uint32_t ui32Value);
extern uint32_t TIMER_PrescaleGet(HM_TIM_TypeDef *timer, uint32_t ui32Timer);
extern void TIMER_PrescaleMatchSet(HM_TIM_TypeDef *timer, uint32_t ui32Timer, uint32_t ui32Value);
extern uint32_t TIMER_PrescaleMatchGet(HM_TIM_TypeDef *timer, uint32_t ui32Timer);
extern void TIMER_LoadSet(HM_TIM_TypeDef *timer, uint32_t ui32Timer, uint32_t ui32Value);
extern uint32_t TIMER_LoadGet(HM_TIM_TypeDef *timer, uint32_t ui32Timer);
extern void TIMER_LoadSet64(HM_TIM_TypeDef *timer, uint64_t ui64Value);
extern uint64_t TIMER_LoadGet64(HM_TIM_TypeDef *timer);
extern uint32_t TIMER_ValueGet(HM_TIM_TypeDef *timer, uint32_t ui32Timer);
extern uint64_t TIMER_ValueGet64(HM_TIM_TypeDef *timer);
extern void TIMER_MatchSet(HM_TIM_TypeDef *timer, uint32_t ui32Timer,
              uint32_t ui32Value);
extern uint32_t TIMER_MatchGet(HM_TIM_TypeDef *timer, uint32_t ui32Timer);
extern void TIMER_MatchSet64(HM_TIM_TypeDef *timer, uint64_t ui64Value);
extern uint64_t TIMER_MatchGet64(HM_TIM_TypeDef *timer);
extern void TIMER_IntEnable(HM_TIM_TypeDef *timer, uint32_t ui32IntFlags);
extern void TIMER_IntDisable(HM_TIM_TypeDef *timer, uint32_t ui32IntFlags);
extern uint32_t TIMER_IntStatus(HM_TIM_TypeDef *timer, Bool bMasked);
extern void TIMER_IntClear(HM_TIM_TypeDef *timer, uint32_t ui32IntFlags);
extern void TIMER_Synchronize(HM_TIM_TypeDef *timer, uint32_t ui32Timers);
extern void TIMER_UpdateMode(HM_TIM_TypeDef *timer, uint32_t ui32Timer, uint32_t ui32Config);
//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __DRIVERLIB_TIMER_H__
