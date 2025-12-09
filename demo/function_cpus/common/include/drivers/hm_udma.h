//*****************************************************************************
//
// hm_udma.h - Prototypes and macros for the uDMA controller.
//
//*****************************************************************************

#ifndef __HM_UDMA_H__
#define __HM_UDMA_H__
#include "hm_libcfg_default.h"
#include "hm_types.h"

//*****************************************************************************
//
// A structure that defines an entry in the channel control table.  These
// fields are used by the uDMA controller and normally it is not necessary for
// software to directly read or write fields in the table.
//
//*****************************************************************************
typedef struct
{
    //
    // The ending source address of the data transfer.
    //
    volatile void *pvSrcEndAddr;

    //
    // The ending destination address of the data transfer.
    //
    volatile void *pvDstEndAddr;

    //
    // The channel control mode.
    //
    volatile uint32_t ui32Control;

    //
    // An unused location.
    //
    volatile uint32_t ui32Spare;
}
tDMAControlTable;

//*****************************************************************************
//
//! A helper macro for building scatter-gather task table entries.
//!
//! \param ui32TransferCount is the count of items to transfer for this task.
//! \param ui32ItemSize is the bit size of the items to transfer for this task.
//! \param ui32SrcIncrement is the bit size increment for source data.
//! \param pvSrcAddr is the starting address of the data to transfer.
//! \param ui32DstIncrement is the bit size increment for destination data.
//! \param pvDstAddr is the starting address of the destination data.
//! \param ui32ArbSize is the arbitration size to use for the transfer task.
//! \param ui32Mode is the transfer mode for this task.
//!
//! This macro is intended to be used to help populate a table of uDMA tasks
//! for a scatter-gather transfer.  This macro will calculate the values for
//! the fields of a task structure entry based on the input parameters.
//!
//! There are specific requirements for the values of each parameter.  No
//! checking is done so it is up to the caller to ensure that correct values
//! are used for the parameters.
//!
//! The \e ui32TransferCount parameter is the number of items that will be
//! transferred by this task.  It must be in the range 1-1024.
//!
//! The \e ui32ItemSize parameter is the bit size of the transfer data.  It
//! must be one of \b UDMA_SIZE_8, \b UDMA_SIZE_16, or \b UDMA_SIZE_32.
//!
//! The \e ui32SrcIncrement parameter is the increment size for the source
//! data.  It must be one of \b UDMA_SRC_INC_8, \b UDMA_SRC_INC_16,
//! \b UDMA_SRC_INC_32, or \b UDMA_SRC_INC_NONE.
//!
//! The \e pvSrcAddr parameter is a void pointer to the beginning of the source
//! data.
//!
//! The \e ui32DstIncrement parameter is the increment size for the destination
//! data.  It must be one of \b UDMA_DST_INC_8, \b UDMA_DST_INC_16,
//! \b UDMA_DST_INC_32, or \b UDMA_DST_INC_NONE.
//!
//! The \e pvDstAddr parameter is a void pointer to the beginning of the
//! location where the data will be transferred.
//!
//! The \e ui32ArbSize parameter is the arbitration size for the transfer, and
//! must be one of \b UDMA_ARB_1, \b UDMA_ARB_2, \b UDMA_ARB_4, and so on
//! up to \b UDMA_ARB_1024.  This is used to select the arbitration size in
//! powers of 2, from 1 to 1024.
//!
//! The \e ui32Mode parameter is the mode to use for this transfer task.  It
//! must be one of \b UDMA_MODE_BASIC, \b UDMA_MODE_AUTO,
//! \b UDMA_MODE_MEM_SCATTER_GATHER, or \b UDMA_MODE_PER_SCATTER_GATHER.  Note
//! that normally all tasks will be one of the scatter-gather modes while the
//! last task is a task list will be AUTO or BASIC.
//!
//! This macro is intended to be used to initialize individual entries of
//! a structure of tDMAControlTable type, like this:
//!
//! \verbatim
//!     tDMAControlTable MyTaskList[] =
//!     {
//!         uDMATaskStructEntry(Task1Count, UDMA_SIZE_8,
//!                             UDMA_SRC_INC_8, MySourceBuf,
//!                             UDMA_DST_INC_8, MyDestBuf,
//!                             UDMA_ARB_8, UDMA_MODE_MEM_SCATTER_GATHER),
//!         uDMATaskStructEntry(Task2Count, ...),
//!     }
//! \endverbatim
//!
//! \return Nothing; this is not a function.
//
//*****************************************************************************
#define uDMATaskStructEntry(ui32TransferCount,                                \
                            ui32ItemSize,                                     \
                            ui32SrcIncrement,                                 \
                            pvSrcAddr,                                        \
                            ui32DstIncrement,                                 \
                            pvDstAddr,                                        \
                            ui32ArbSize,                                      \
                            ui32Mode)                                         \
    {                                                                         \
        (((ui32SrcIncrement) == UDMA_SRC_INC_NONE) ? (void *)(pvSrcAddr) :    \
            ((void *)(&((uint8_t *)(pvSrcAddr))[((ui32TransferCount) <<       \
                                         ((ui32SrcIncrement) >> 26)) - 1]))), \
            (((ui32DstIncrement) == UDMA_DST_INC_NONE) ? (void *)(pvDstAddr) :\
            ((void *)(&((uint8_t *)(pvDstAddr))[((ui32TransferCount) <<       \
                                         ((ui32DstIncrement) >> 30)) - 1]))), \
        (ui32SrcIncrement) | (ui32DstIncrement) | (ui32ItemSize) |            \
            (ui32ArbSize) |                                                   \
        (((ui32TransferCount) - 1) << 4) |                                    \
        ((((ui32Mode) == UDMA_MODE_MEM_SCATTER_GATHER) ||                     \
          ((ui32Mode) == UDMA_MODE_PER_SCATTER_GATHER)) ?                     \
                (ui32Mode) | UDMA_MODE_ALT_SELECT : (ui32Mode)), 0            \
    }



//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_STAT register.
//
//*****************************************************************************
#define UDMA_STAT_DMACHANS_M    0x001F0000  // Available uDMA Channels Minus 1
#define UDMA_STAT_STATE_M       0x000000F0  // Control State Machine Status
#define UDMA_STAT_STATE_IDLE    0x00000000  // Idle
#define UDMA_STAT_STATE_RD_CTRL 0x00000010  // Reading channel controller data
#define UDMA_STAT_STATE_RD_SRCENDP                                            \
								0x00000020	// Reading source end pointer
#define UDMA_STAT_STATE_RD_DSTENDP                                            \
								0x00000030	// Reading destination end pointer
#define UDMA_STAT_STATE_RD_SRCDAT                                             \
								0x00000040	// Reading source data
#define UDMA_STAT_STATE_WR_DSTDAT                                             \
								0x00000050	// Writing destination data
#define UDMA_STAT_STATE_WAIT    0x00000060  // Waiting for uDMA request to
											// clear
#define UDMA_STAT_STATE_WR_CTRL 0x00000070  // Writing channel controller data
#define UDMA_STAT_STATE_STALL   0x00000080  // Stalled
#define UDMA_STAT_STATE_DONE    0x00000090  // Done
#define UDMA_STAT_STATE_UNDEF   0x000000A0  // Undefined
#define UDMA_STAT_MASTEN        0x00000001  // Master Enable Status
#define UDMA_STAT_DMACHANS_S    16

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_CFG register.
//
//*****************************************************************************
#define UDMA_CFG_MASTEN         0x00000001  // Controller Master Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_CTLBASE register.
//
//*****************************************************************************
#define UDMA_CTLBASE_ADDR_M     0xFFFFFC00  // Channel Control Base Address
#define UDMA_CTLBASE_ADDR_S     10

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ALTBASE register.
//
//*****************************************************************************
#define UDMA_ALTBASE_ADDR_M     0xFFFFFFFF  // Alternate Channel Address
											// Pointer
#define UDMA_ALTBASE_ADDR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_WAITSTAT register.
//
//*****************************************************************************
#define UDMA_WAITSTAT_WAITREQ_M 0xFFFFFFFF  // Channel [n] Wait Status

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_SWREQ register.
//
//*****************************************************************************
#define UDMA_SWREQ_M            0xFFFFFFFF  // Channel [n] Software Request

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_USEBURSTSET
// register.
//
//*****************************************************************************
#define UDMA_USEBURSTSET_SET_M  0xFFFFFFFF  // Channel [n] Useburst Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_USEBURSTCLR
// register.
//
//*****************************************************************************
#define UDMA_USEBURSTCLR_CLR_M  0xFFFFFFFF  // Channel [n] Useburst Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_REQMASKSET
// register.
//
//*****************************************************************************
#define UDMA_REQMASKSET_SET_M   0xFFFFFFFF  // Channel [n] Request Mask Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_REQMASKCLR
// register.
//
//*****************************************************************************
#define UDMA_REQMASKCLR_CLR_M   0xFFFFFFFF  // Channel [n] Request Mask Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ENASET register.
//
//*****************************************************************************
#define UDMA_ENASET_SET_M       0xFFFFFFFF  // Channel [n] Enable Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ENACLR register.
//
//*****************************************************************************
#define UDMA_ENACLR_CLR_M       0xFFFFFFFF  // Clear Channel [n] Enable Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ALTSET register.
//
//*****************************************************************************
#define UDMA_ALTSET_SET_M       0xFFFFFFFF  // Channel [n] Alternate Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ALTCLR register.
//
//*****************************************************************************
#define UDMA_ALTCLR_CLR_M       0xFFFFFFFF  // Channel [n] Alternate Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_PRIOSET register.
//
//*****************************************************************************
#define UDMA_PRIOSET_SET_M      0xFFFFFFFF  // Channel [n] Priority Set

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_PRIOCLR register.
//
//*****************************************************************************
#define UDMA_PRIOCLR_CLR_M      0xFFFFFFFF  // Channel [n] Priority Clear

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_ERRCLR register.
//
//*****************************************************************************
#define UDMA_ERRCLR_ERRCLR      0x00000001  // uDMA Bus Error Status

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_CHASGN register.
//
//*****************************************************************************
#define UDMA_CHASGN_M           0xFFFFFFFF  // Channel [n] Assignment Select
#define UDMA_CHASGN_PRIMARY     0x00000000  // Use the primary channel
											// assignment
#define UDMA_CHASGN_SECONDARY   0x00000001  // Use the secondary channel
											// assignment

//*****************************************************************************
//
// The following are defines for the Micro Direct Memory Access (uDMA) offsets.
//
//*****************************************************************************
#define UDMA_O_SRCENDP          0x00000000  // DMA Channel Source Address End
											// Pointer
#define UDMA_O_DSTENDP          0x00000004  // DMA Channel Destination Address
											// End Pointer
#define UDMA_O_CHCTL            0x00000008  // DMA Channel Control Word

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_O_SRCENDP register.
//
//*****************************************************************************
#define UDMA_SRCENDP_ADDR_M     0xFFFFFFFF  // Source Address End Pointer
#define UDMA_SRCENDP_ADDR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_O_DSTENDP register.
//
//*****************************************************************************
#define UDMA_DSTENDP_ADDR_M     0xFFFFFFFF  // Destination Address End Pointer
#define UDMA_DSTENDP_ADDR_S     0

//*****************************************************************************
//
// The following are defines for the bit fields in the UDMA_O_CHCTL register.
//
//*****************************************************************************
#define UDMA_CHCTL_DSTINC_M     0xC0000000  // Destination Address Increment
#define UDMA_CHCTL_DSTINC_8     0x00000000  // Byte
#define UDMA_CHCTL_DSTINC_16    0x40000000  // Half-word
#define UDMA_CHCTL_DSTINC_32    0x80000000  // Word
#define UDMA_CHCTL_DSTINC_NONE  0xC0000000  // No increment
#define UDMA_CHCTL_DSTSIZE_M    0x30000000  // Destination Data Size
#define UDMA_CHCTL_DSTSIZE_8    0x00000000  // Byte
#define UDMA_CHCTL_DSTSIZE_16   0x10000000  // Half-word
#define UDMA_CHCTL_DSTSIZE_32   0x20000000  // Word
#define UDMA_CHCTL_SRCINC_M     0x0C000000  // Source Address Increment
#define UDMA_CHCTL_SRCINC_8     0x00000000  // Byte
#define UDMA_CHCTL_SRCINC_16    0x04000000  // Half-word
#define UDMA_CHCTL_SRCINC_32    0x08000000  // Word
#define UDMA_CHCTL_SRCINC_NONE  0x0C000000  // No increment
#define UDMA_CHCTL_SRCSIZE_M    0x03000000  // Source Data Size
#define UDMA_CHCTL_SRCSIZE_8    0x00000000  // Byte
#define UDMA_CHCTL_SRCSIZE_16   0x01000000  // Half-word
#define UDMA_CHCTL_SRCSIZE_32   0x02000000  // Word
#define UDMA_CHCTL_DSTPROT0     0x00200000  // Destination Privilege Access
#define UDMA_CHCTL_SRCPROT0     0x00040000  // Source Privilege Access
#define UDMA_CHCTL_ARBSIZE_M    0x0003C000  // Arbitration Size
#define UDMA_CHCTL_ARBSIZE_1    0x00000000  // 1 Transfer
#define UDMA_CHCTL_ARBSIZE_2    0x00004000  // 2 Transfers
#define UDMA_CHCTL_ARBSIZE_4    0x00008000  // 4 Transfers
#define UDMA_CHCTL_ARBSIZE_8    0x0000C000  // 8 Transfers
#define UDMA_CHCTL_ARBSIZE_16   0x00010000  // 16 Transfers
#define UDMA_CHCTL_ARBSIZE_32   0x00014000  // 32 Transfers
#define UDMA_CHCTL_ARBSIZE_64   0x00018000  // 64 Transfers
#define UDMA_CHCTL_ARBSIZE_128  0x0001C000  // 128 Transfers
#define UDMA_CHCTL_ARBSIZE_256  0x00020000  // 256 Transfers
#define UDMA_CHCTL_ARBSIZE_512  0x00024000  // 512 Transfers
#define UDMA_CHCTL_ARBSIZE_1024 0x00028000  // 1024 Transfers
#define UDMA_CHCTL_XFERSIZE_M   0x00003FF0  // Transfer Size (minus 1)
#define UDMA_CHCTL_NXTUSEBURST  0x00000008  // Next Useburst
#define UDMA_CHCTL_XFERMODE_M   0x00000007  // uDMA Transfer Mode
#define UDMA_CHCTL_XFERMODE_STOP                                              \
								0x00000000	// Stop
#define UDMA_CHCTL_XFERMODE_BASIC                                             \
								0x00000001	// Basic
#define UDMA_CHCTL_XFERMODE_AUTO                                              \
								0x00000002	// Auto-Request
#define UDMA_CHCTL_XFERMODE_PINGPONG                                          \
								0x00000003	// Ping-Pong
#define UDMA_CHCTL_XFERMODE_MEM_SG                                            \
								0x00000004	// Memory Scatter-Gather
#define UDMA_CHCTL_XFERMODE_MEM_SGA                                           \
								0x00000005	// Alternate Memory Scatter-Gather
#define UDMA_CHCTL_XFERMODE_PER_SG                                            \
								0x00000006	// Peripheral Scatter-Gather
#define UDMA_CHCTL_XFERMODE_PER_SGA                                           \
								0x00000007	// Alternate Peripheral
											// Scatter-Gather
#define UDMA_CHCTL_XFERSIZE_S   4


//*****************************************************************************
//
// Flags that can be passed to uDMAChannelAttributeEnable(),
// uDMAChannelAttributeDisable(), and returned from uDMAChannelAttributeGet().
//
//*****************************************************************************
#define UDMA_ATTR_USEBURST      0x00000001
#define UDMA_ATTR_ALTSELECT     0x00000002
#define UDMA_ATTR_HIGH_PRIORITY 0x00000004
#define UDMA_ATTR_REQMASK       0x00000008
#define UDMA_ATTR_ALL           0x0000000F

//*****************************************************************************
//
// DMA control modes that can be passed to uDMAModeSet() and returned
// uDMAModeGet().
//
//*****************************************************************************
#define UDMA_MODE_STOP          0x00000000
#define UDMA_MODE_BASIC         0x00000001
#define UDMA_MODE_AUTO          0x00000002
#define UDMA_MODE_PINGPONG      0x00000003
#define UDMA_MODE_MEM_SCATTER_GATHER                                          \
                                0x00000004
#define UDMA_MODE_PER_SCATTER_GATHER                                          \
                                0x00000006
#define UDMA_MODE_ALT_SELECT    0x00000001

//*****************************************************************************
//
// Channel configuration values that can be passed to uDMAControlSet().
//
//*****************************************************************************
#define UDMA_DST_INC_8          0x00000000
#define UDMA_DST_INC_16         0x40000000
#define UDMA_DST_INC_32         0x80000000
#define UDMA_DST_INC_NONE       0xc0000000
#define UDMA_SRC_INC_8          0x00000000
#define UDMA_SRC_INC_16         0x04000000
#define UDMA_SRC_INC_32         0x08000000
#define UDMA_SRC_INC_NONE       0x0c000000
#define UDMA_SIZE_8             0x00000000
#define UDMA_SIZE_16            0x11000000
#define UDMA_SIZE_32            0x22000000
#define UDMA_DST_PROT_PRIV      0x00200000
#define UDMA_SRC_PROT_PRIV      0x00040000
#define UDMA_ARB_1              0x00000000
#define UDMA_ARB_2              0x00004000
#define UDMA_ARB_4              0x00008000
#define UDMA_ARB_8              0x0000c000
#define UDMA_ARB_16             0x00010000
#define UDMA_ARB_32             0x00014000
#define UDMA_ARB_64             0x00018000
#define UDMA_ARB_128            0x0001c000
#define UDMA_ARB_256            0x00020000
#define UDMA_ARB_512            0x00024000
#define UDMA_ARB_1024           0x00028000
#define UDMA_NEXT_USEBURST      0x00000008

//*****************************************************************************
//
// Channel numbers to be passed to API functions that require a channel number
// ID.
//
//*****************************************************************************
#define UDMA_CHANNEL_USBEP1RX   0
#define UDMA_CHANNEL_USBEP1TX   1
#define UDMA_CHANNEL_USBEP2RX   2
#define UDMA_CHANNEL_USBEP2TX   3
#define UDMA_CHANNEL_USBEP3RX   4
#define UDMA_CHANNEL_USBEP3TX   5
#define UDMA_CHANNEL_ETH0RX     6
#define UDMA_CHANNEL_ETH0TX     7
#define UDMA_CHANNEL_UART0RX    8
#define UDMA_CHANNEL_UART0TX    9
#define UDMA_CHANNEL_SSI0RX     10
#define UDMA_CHANNEL_SSI0TX     11
#define UDMA_CHANNEL_ADC0       14
#define UDMA_CHANNEL_ADC1       15
#define UDMA_CHANNEL_ADC2       16
#define UDMA_CHANNEL_ADC3       17
#define UDMA_CHANNEL_TMR0A      18
#define UDMA_CHANNEL_TMR0B      19
#define UDMA_CHANNEL_TMR1A      20
#define UDMA_CHANNEL_TMR1B      21
#define UDMA_CHANNEL_UART1RX    22
#define UDMA_CHANNEL_UART1TX    23
#define UDMA_CHANNEL_SSI1RX     24
#define UDMA_CHANNEL_SSI1TX     25
#define UDMA_CHANNEL_I2S0RX     28
#define UDMA_CHANNEL_I2S0TX     29
#define UDMA_CHANNEL_SW         30

//*****************************************************************************
//
// Flags to be OR'd with the channel ID to indicate if the primary or alternate
// control structure should be used.
//
//*****************************************************************************
#define UDMA_PRI_SELECT         0x00000000
#define UDMA_ALT_SELECT         0x00000020

//*****************************************************************************
//
// Channel numbers to be passed to API functions that require a channel number
// ID.  These are for secondary peripheral assignments.
//
//*****************************************************************************
#define UDMA_SEC_CHANNEL_UART2RX_0                                            \
                                0
#define UDMA_SEC_CHANNEL_UART2TX_1                                            \
                                1
#define UDMA_SEC_CHANNEL_TMR3A  2
#define UDMA_SEC_CHANNEL_TMR3B  3
#define UDMA_SEC_CHANNEL_TMR2A_4                                              \
                                4
#define UDMA_SEC_CHANNEL_TMR2B_5                                              \
                                5
#define UDMA_SEC_CHANNEL_TMR2A_6                                              \
                                6
#define UDMA_SEC_CHANNEL_TMR2B_7                                              \
                                7
#define UDMA_SEC_CHANNEL_UART1RX                                              \
                                8
#define UDMA_SEC_CHANNEL_UART1TX                                              \
                                9
#define UDMA_SEC_CHANNEL_SSI1RX 10
#define UDMA_SEC_CHANNEL_SSI1TX 11
#define UDMA_SEC_CHANNEL_UART2RX_12                                           \
                                12
#define UDMA_SEC_CHANNEL_UART2TX_13                                           \
                                13
#define UDMA_SEC_CHANNEL_TMR2A_14                                             \
                                14
#define UDMA_SEC_CHANNEL_TMR2B_15                                             \
                                15
#define UDMA_SEC_CHANNEL_TMR1A  18
#define UDMA_SEC_CHANNEL_TMR1B  19
#define UDMA_SEC_CHANNEL_EPI0RX 20
#define UDMA_SEC_CHANNEL_EPI0TX 21
#define UDMA_SEC_CHANNEL_ADC10  24
#define UDMA_SEC_CHANNEL_ADC11  25
#define UDMA_SEC_CHANNEL_ADC12  26
#define UDMA_SEC_CHANNEL_ADC13  27
#define UDMA_SEC_CHANNEL_SW     30

//*****************************************************************************
//
// Values that can be passed to uDMAChannelAssign() to select peripheral
// mapping for each channel.  
//
//*****************************************************************************
//
// Channel 0
//
#define UDMA_CH0_SOFTWARE0          0x00000000
#define UDMA_CH0_UART2RX            0x00010000
#define UDMA_CH0_SOFTWARE2          0x00020000
#define UDMA_CH0_TIMER4A            0x00030000
#define UDMA_CH0_SOFTWARE4          0x00040000

//
// Channel 1
//
#define UDMA_CH1_SOFTWARE0          0x00000001
#define UDMA_CH1_UART2TX            0x00010001
#define UDMA_CH1_SOFTWARE2          0x00020001
#define UDMA_CH1_TIMER4B            0x00030001
#define UDMA_CH1_SOFTWARE4          0x00040001

//
// Channel 2
//
#define UDMA_CH2_SOFTWARE0          0x00000002
#define UDMA_CH2_TIMER3A            0x00010002
#define UDMA_CH2_SOFTWARE2          0x00020002
#define UDMA_CH2_SOFTWARE3          0x00030002
#define UDMA_CH2_SOFTWARE4          0x00040002

//
// Channel 3
//
#define UDMA_CH3_USB0EP2TX          0x00000003
#define UDMA_CH3_TIMER3B            0x00010003
#define UDMA_CH3_SOFTWARE2          0x00020003
#define UDMA_CH3_SOFTWARE0          0x00030003
#define UDMA_CH3_SOFTWARE4          0x00040003

//
// Channel 4
//
#define UDMA_CH4_SOFTWARE0          0x00000004
#define UDMA_CH4_TIMER2A            0x00010004
#define UDMA_CH4_SOFTWARE2          0x00020004
#define UDMA_CH4_GPIOA              0x00030004
#define UDMA_CH4_SOFTWARE4          0x00040004

//
// Channel 5
//
#define UDMA_CH5_SOFTWARE0          0x00000005
#define UDMA_CH5_TIMER2B            0x00010005
#define UDMA_CH5_SOFTWARE2          0x00020005
#define UDMA_CH5_GPIOB              0x00030005
#define UDMA_CH5_SOFTWARE4          0x00040005

//
// Channel 6
//
#define UDMA_CH6_SOFTWARE0          0x00000006
#define UDMA_CH6_ETH0RX             0x00000006
#define UDMA_CH6_TIMER2A            0x00010006
#define UDMA_CH6_UART5RX            0x00020006
#define UDMA_CH6_GPIOC              0x00030006
#define UDMA_CH6_SOFTWARE4          0x00040006

//
// Channel 7
//
#define UDMA_CH7_SOFTWARE0          0x00000007
#define UDMA_CH7_ETH0TX             0x00000007
#define UDMA_CH7_TIMER2B            0x00010007
#define UDMA_CH7_UART5TX            0x00020007
#define UDMA_CH7_GPIOD              0x00030007
#define UDMA_CH7_SOFTWARE4          0x00040007

//
// Channel 8
//
#define UDMA_CH8_UART0RX            0x00000008
#define UDMA_CH8_UART1RX            0x00010008
#define UDMA_CH8_SOFTWARE2          0x00020008
#define UDMA_CH8_TIMER5A            0x00030008
#define UDMA_CH8_SOFTWARE4          0x00040008

//
// Channel 9
//
#define UDMA_CH9_UART0TX            0x00000009
#define UDMA_CH9_UART1TX            0x00010009
#define UDMA_CH9_SOFTWARE2          0x00020009
#define UDMA_CH9_TIMER5B            0x00030009
#define UDMA_CH9_SOFTWARE4          0x00040009

//
// Channel 10
//
#define UDMA_CH10_SSI0RX            0x0000000A
#define UDMA_CH10_SSI1RX            0x0001000A
#define UDMA_CH10_UART6RX           0x0002000A
#define UDMA_CH10_WTIMER0A          0x0003000A
#define UDMA_CH10_SOFTWARE4         0x0004000A

//
// Channel 11
//
#define UDMA_CH11_SSI0TX            0x0000000B
#define UDMA_CH11_SSI1TX            0x0001000B
#define UDMA_CH11_UART6TX           0x0002000B
#define UDMA_CH11_WTIMER0B          0x0003000B
#define UDMA_CH11_SOFTWARE4         0x0004000B

//
// Channel 12
//
#define UDMA_CH12_SOFTWARE0         0x0000000C
#define UDMA_CH12_UART2RX           0x0001000C
#define UDMA_CH12_SSI2RX            0x0002000C
#define UDMA_CH12_WTIMER1A          0x0003000C
#define UDMA_CH12_GPIOK             0x0004000C

//
// Channel 13
//
#define UDMA_CH13_SOFTWARE0         0x0000000D
#define UDMA_CH13_UART2TX           0x0001000D
#define UDMA_CH13_SSI2TX            0x0002000D
#define UDMA_CH13_WTIMER1B          0x0003000D
#define UDMA_CH13_GPIOL             0x0004000D

//
// Channel 14
//
#define UDMA_CH14_ADC0_0            0x0000000E
#define UDMA_CH14_TIMER2A           0x0001000E
#define UDMA_CH14_SSI3RX            0x0002000E
#define UDMA_CH14_GPIOE             0x0003000E
#define UDMA_CH14_GPIOM             0x0004000E

//
// Channel 15
//
#define UDMA_CH15_ADC0_1            0x0000000F
#define UDMA_CH15_TIMER2B           0x0001000F
#define UDMA_CH15_SSI3TX            0x0002000F
#define UDMA_CH15_GPIOF             0x0003000F
#define UDMA_CH15_GPION             0x0004000F

//
// Channel 16
//
#define UDMA_CH16_ADC0_2            0x00000010
#define UDMA_CH16_SOFTWARE1         0x00010010
#define UDMA_CH16_UART3RX           0x00020010
#define UDMA_CH16_WTIMER2A          0x00030010
#define UDMA_CH16_GPIOP             0x00040010

//
// Channel 17
//
#define UDMA_CH17_ADC0_3            0x00000011
#define UDMA_CH17_SOFTWARE1         0x00010011
#define UDMA_CH17_UART3TX           0x00020011
#define UDMA_CH17_WTIMER2B          0x00030011
#define UDMA_CH17_SOFTWARE4         0x00040011

//
// Channel 18
//
#define UDMA_CH18_TIMER0A           0x00000012
#define UDMA_CH18_TIMER1A           0x00010012
#define UDMA_CH18_UART4RX           0x00020012
#define UDMA_CH18_GPIOB             0x00030012
#define UDMA_CH18_SOFTWARE4         0x00040012

//
// Channel 19
//
#define UDMA_CH19_TIMER0B           0x00000013
#define UDMA_CH19_TIMER1B           0x00010013
#define UDMA_CH19_UART4TX           0x00020013
#define UDMA_CH19_GPIOG             0x00030013
#define UDMA_CH19_SOFTWARE4         0x00040013

//
// Channel 20
//
#define UDMA_CH20_TIMER1A           0x00000014
#define UDMA_CH20_SOFTWARE1         0x00010014
#define UDMA_CH20_EPI0RX            0x00010014
#define UDMA_CH20_UART7RX           0x00020014
#define UDMA_CH20_GPIOH             0x00030014
#define UDMA_CH20_SOFTWARE4         0x00040014

//
// Channel 21
//
#define UDMA_CH21_TIMER1B           0x00000015
#define UDMA_CH21_SOFTWARE1         0x00010015
#define UDMA_CH21_EPI0TX            0x00010015
#define UDMA_CH21_UART7TX           0x00020015
#define UDMA_CH21_GPIOJ             0x00030015
#define UDMA_CH21_SOFTWARE4         0x00040015

//
// Channel 22
//
#define UDMA_CH22_UART1RX           0x00000016
#define UDMA_CH22_SOFTWARE1         0x00010016
#define UDMA_CH22_SOFTWARE2         0x00020016
#define UDMA_CH22_SOFTWARE3         0x00030016
#define UDMA_CH22_SOFTWARE4         0x00040016

//
// Channel 23
//
#define UDMA_CH23_UART1TX           0x00000017
#define UDMA_CH23_SOFTWARE1         0x00010017
#define UDMA_CH23_SOFTWARE2         0x00020017
#define UDMA_CH23_SOFTWARE3         0x00030017
#define UDMA_CH23_SOFTWARE4         0x00040017

//
// Channel 24
//
#define UDMA_CH24_SSI1RX            0x00000018
#define UDMA_CH24_ADC1_0            0x00010018
#define UDMA_CH24_SOFTWARE2         0x00020018
#define UDMA_CH24_WTIMER3A          0x00030018
#define UDMA_CH24_SOFTWARE4         0x00040018

//
// Channel 25
//
#define UDMA_CH25_SSI1TX            0x00000019
#define UDMA_CH25_ADC1_1            0x00010019
#define UDMA_CH25_SOFTWARE2         0x00020019
#define UDMA_CH25_WTIMER3B          0x00030019
#define UDMA_CH25_SOFTWARE4         0x00040019

//
// Channel 26
//
#define UDMA_CH26_SOFTWARE0         0x0000001A
#define UDMA_CH26_ADC1_2            0x0001001A
#define UDMA_CH26_SOFTWARE2         0x0002001A
#define UDMA_CH26_WTIMER4A          0x0003001A
#define UDMA_CH26_SOFTWARE4         0x0004001A

//
// Channel 27
//
#define UDMA_CH27_SOFTWARE0         0x0000001B
#define UDMA_CH27_ADC1_3            0x0001001B
#define UDMA_CH27_SOFTWARE2         0x0002001B
#define UDMA_CH27_WTIMER4B          0x0003001B
#define UDMA_CH27_SOFTWARE4         0x0004001B

//
// Channel 28
//
#define UDMA_CH28_SOFTWARE0         0x0000001C
#define UDMA_CH28_SOFTWARE1         0x0001001C
#define UDMA_CH28_SOFTWARE2         0x0002001C
#define UDMA_CH28_WTIMER5A          0x0003001C
#define UDMA_CH28_SOFTWARE4         0x0004001C

//
// Channel 29
//
#define UDMA_CH29_SOFTWARE0         0x0000001D
#define UDMA_CH29_SOFTWARE1         0x0001001D
#define UDMA_CH29_SOFTWARE2         0x0002001D
#define UDMA_CH29_WTIMER5B          0x0003001D
#define UDMA_CH29_SOFTWARE4         0x0004001D

//
// Channel 30
//
#define UDMA_CH30_SOFTWARE0         0x0000001E
#define UDMA_CH30_SOFTWARE1         0x0001001E
#define UDMA_CH30_SOFTWARE2         0x0002001E
#define UDMA_CH30_SOFTWARE3         0x0003001E
#define UDMA_CH30_SOFTWARE4         0x0004001E

//
// Channel 31
//
#define UDMA_CH31_SOFTWARE0         0x0000001F
#define UDMA_CH31_SOFTWARE1         0x0001001F
#define UDMA_CH31_SOFTWARE2         0x0002001F
#define UDMA_CH31_SOFTWARE3         0x0003001F
#define UDMA_CH31_SOFTWARE4         0x0004001F

//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void UDMA_Enable(void);
extern void UDMA_Disable(void);
extern uint32_t UDMA_ErrorStatusGet(void);
extern void UDMA_ErrorStatusClear(void);
extern void UDMA_ChannelEnable(uint32_t ui32ChannelNum);
extern void UDMA_ChannelDisable(uint32_t ui32ChannelNum);
extern Bool UDMA_ChannelIsEnabled(uint32_t ui32ChannelNum);
extern void UDMA_ControlBaseSet(void *pControlTable);
extern void *UDMA_ControlBaseGet(void);
extern void *UDMA_ControlAlternateBaseGet(void);
extern void UDMA_ChannelRequest(uint32_t ui32ChannelNum);
extern void UDMA_ChannelAttributeEnable(uint32_t ui32ChannelNum,
                                       uint32_t ui32Attr);
extern void UDMA_ChannelAttributeDisable(uint32_t ui32ChannelNum,
                                        uint32_t ui32Attr);
extern uint32_t UDMA_ChannelAttributeGet(uint32_t ui32ChannelNum);
extern void UDMA_ChannelControlSet(uint32_t ui32ChannelStructIndex,
                                  uint32_t ui32Control);
extern void UDMA_ChannelTransferSet(uint32_t ui32ChannelStructIndex,
                                   uint32_t ui32Mode, void *pvSrcAddr,
                                   void *pvDstAddr, uint32_t ui32TransferSize);
extern void UDMA_ChannelScatterGatherSet(uint32_t ui32ChannelNum,
                                        uint32_t ui32TaskCount,
                                        void *pvTaskList,
                                        uint32_t ui32IsPeriphSG);
extern uint32_t UDMA_ChannelSizeGet(uint32_t ui32ChannelStructIndex);
extern uint32_t UDMA_ChannelModeGet(uint32_t ui32ChannelStructIndex);
extern void UDMA_ChannelAssign(uint32_t ui32Mapping);

#ifdef TARGET_MIPS
  #define COM_READ_SHIFT        (0x24000000) // COM_SRAM_BASEADDR - 0x20000000
#endif
#ifdef TARGET_ARM
  #define COM_READ_SHIFT        (0)
#endif
#ifdef TARGET_RISCV
  #define COM_READ_SHIFT        (0x24000000)
#endif

#endif // __HM_UDMA_H__
