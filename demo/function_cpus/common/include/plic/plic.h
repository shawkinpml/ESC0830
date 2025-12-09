#ifndef PML_PLIC_H
#define PML_PLIC_H
#include <stdint.h>
#include "plic_core.h"
#include "hm_libcfg_default.h"
#ifdef TARGET_MIPS
  #include "m32c0.h"
#elif TARGET_ARM
#ifdef CHIP_SEL_ESC0830
  #include "HM4C123.h"
#endif
#ifdef CHIP_SEL_ESC0820
#include "HM3S9B96.h"
#endif
#elif TARGET_RISCV
  #include "plic_base.h"
#endif

#ifdef CHIP_SEL_ESC0830
typedef enum PLIC_IRQn
{
  PLIC_RESERVED_IRQn       =  0,  // Device external Interrupt 0
  PLIC_GPIOA_IRQn          =  1,  // assign  interrupt_per[9:0]   =  INTISR[9:0]
  PLIC_GPIOB_IRQn          =  2,
  PLIC_GPIOC_IRQn          =  3,
  PLIC_GPIOD_IRQn          =  4,
  PLIC_GPIOE_IRQn          =  5,
  PLIC_UART0_IRQn          =  6,
  PLIC_UART1_IRQn          =  7,
  PLIC_SSI0_IRQn           =  8,
  PLIC_I2C0_IRQn           =  9,
  PLIC_PWM0_IRQn           = 10,
  PLIC_QEI0_IRQn           = 11,  // assign  interrupt_per[24:10] =  INTISR[27:13]
  PLIC_ADC0SS0_IRQn        = 12,
  PLIC_ADC0SS1_IRQn        = 13,
  PLIC_ADC0SS2_IRQn        = 14,
  PLIC_ADC0SS3_IRQn        = 15,
  PLIC_WATCHDOG0_IRQn      = 16,
  PLIC_TIMER0A_IRQn        = 17,
  PLIC_TIMER0B_IRQn        = 18,
  PLIC_TIMER1A_IRQn        = 19,
  PLIC_TIMER1B_IRQn        = 20,
  PLIC_TIMER2A_IRQn        = 21,
  PLIC_TIMER2B_IRQn        = 22,
  PLIC_COMP0_IRQn          = 23,
  PLIC_COMP1_IRQn          = 24,
  PLIC_COMP2_IRQn          = 25,
  PLIC_GPIOF_IRQn          = 26,  // assign  interrupt_per[35:25] =  INTISR[40:30]
  PLIC_GPIOG_IRQn          = 27,
  PLIC_GPIOH_IRQn          = 28,
  PLIC_UART2_IRQn          = 29,
  PLIC_SSI1_IRQn           = 30,
  PLIC_TIMER3A_IRQn        = 31,
  PLIC_TIMER3B_IRQn        = 32,
  PLIC_I2C1_IRQn           = 33,
  PLIC_QEI1_IRQn           = 34,
  PLIC_CAN0_IRQn           = 35,
  PLIC_CAN1_IRQn           = 36,
  PLIC_HIB_LOWV_IRQn       = 37,  // assign  interrupt_per[36]    =  INTISR[43]
  PLIC_USB0_IRQn           = 38,  // assign  interrupt_per[37]    =  INTISR[44]
  PLIC_UDMA_IRQn           = 39,  // assign  interrupt_per[38]    =  INTISR[46]
  PLIC_ADC1SS0_IRQn        = 40,  // assign  interrupt_per[42:39] =  INTISR[51:48]
  PLIC_ADC1SS1_IRQn        = 41,
  PLIC_ADC1SS2_IRQn        = 42,
  PLIC_ADC1SS3_IRQn        = 43,
  PLIC_GPIOJ_IRQn          = 44,  // assign  interrupt_per[52:43] =  INTISR[63:54]
  PLIC_GPIOK_IRQn          = 45,
  PLIC_GPIOL_IRQn          = 46,
  PLIC_SSI2_IRQn           = 47,
  PLIC_SSI3_IRQn           = 48,
  PLIC_UART3_IRQn          = 49,
  PLIC_UART4_IRQn          = 50,
  PLIC_UART5_IRQn          = 51,
  PLIC_UART6_IRQn          = 52,
  PLIC_UART7_IRQn          = 53,
  PLIC_WATCHDOG1_IRQn      = 54,  // assign  interrupt_per[53]    =  INTISR[66]
  PLIC_I2C2_IRQn           = 55,  // assign  interrupt_per[72:54] =  INTISR[86:68]
  PLIC_I2C3_IRQn           = 56,
  PLIC_TIMER4A_IRQn        = 57,
  PLIC_TIMER4B_IRQn        = 58,
  PLIC_ADC0_0_IRQn         = 59,
  PLIC_ADC0_1_IRQn         = 60,
  PLIC_ADC0_2_IRQn         = 61,
  PLIC_ADC0_3_IRQn         = 62,
  PLIC_ADC1_0_IRQn         = 63,
  PLIC_INT_MAX             = __PLIC_INTNUM - 1,
} PLIC_IRQn_Type;
#endif

#ifdef CHIP_SEL_ESC0820
typedef enum PLIC_IRQn
{
  PLIC_RESERVED_IRQn       =  0,  // Device external Interrupt 0
  PLIC_GPIOA_IRQn          =  1,  // assign  interrupt_per[9:0]   =  INTISR[9:0]
  PLIC_GPIOB_IRQn          =  2,
  PLIC_GPIOC_IRQn          =  3,
  PLIC_GPIOD_IRQn          =  4,
  PLIC_GPIOE_IRQn          =  5,
  PLIC_UART0_IRQn          =  6,
  PLIC_UART1_IRQn          =  7,
  PLIC_SSI0_IRQn           =  8,
  PLIC_I2C0_IRQn           =  9,
  PLIC_PWM0_IRQn           = 10,
  PLIC_QEI0_IRQn           = 11,  // assign  interrupt_per[24:10] =  INTISR[27:13]
  PLIC_ADC0SS0_IRQn        = 12,
  PLIC_ADC0SS1_IRQn        = 13,
  PLIC_ADC0SS2_IRQn        = 14,
  PLIC_ADC0SS3_IRQn        = 15,
  PLIC_WATCHDOG0_IRQn      = 16,
  PLIC_TIMER0A_IRQn        = 17,
  PLIC_TIMER0B_IRQn        = 18,
  PLIC_TIMER1A_IRQn        = 19,
  PLIC_TIMER1B_IRQn        = 20,
  PLIC_TIMER2A_IRQn        = 21,
  PLIC_TIMER2B_IRQn        = 22,
  PLIC_COMP0_IRQn          = 23,
  PLIC_COMP1_IRQn          = 24,
  PLIC_COMP2_IRQn          = 25,
  PLIC_GPIOF_IRQn          = 26,  // assign  interrupt_per[35:25] =  INTISR[40:30]
  PLIC_GPIOG_IRQn          = 27,
  PLIC_GPIOH_IRQn          = 28,
  PLIC_UART2_IRQn          = 29,
  PLIC_SSI1_IRQn           = 30,
  PLIC_TIMER3A_IRQn        = 31,
  PLIC_TIMER3B_IRQn        = 32,
  PLIC_I2C1_IRQn           = 33,
  PLIC_QEI1_IRQn           = 34,
  PLIC_CAN0_IRQn           = 35,
  PLIC_CAN1_IRQn           = 36,
  PLIC_HIB_LOWV_IRQn       = 37,  // assign  interrupt_per[36]    =  INTISR[43]
  PLIC_USB0_IRQn           = 38,  // assign  interrupt_per[37]    =  INTISR[44]
  PLIC_UDMA_IRQn           = 39,  // assign  interrupt_per[38]    =  INTISR[46]
  PLIC_ADC1SS0_IRQn        = 40,  // assign  interrupt_per[42:39] =  INTISR[51:48]
  PLIC_ADC1SS1_IRQn        = 41,
  PLIC_ADC1SS2_IRQn        = 42,
  PLIC_ADC1SS3_IRQn        = 43,
  PLIC_GPIOJ_IRQn          = 44,  // assign  interrupt_per[52:43] =  INTISR[63:54]
  PLIC_GPIOK_IRQn          = 45,
  PLIC_GPIOL_IRQn          = 46,
  PLIC_SSI2_IRQn           = 47,
  PLIC_SSI3_IRQn           = 48,
  PLIC_UART3_IRQn          = 49,
  PLIC_UART4_IRQn          = 50,
  PLIC_UART5_IRQn          = 51,
  PLIC_UART6_IRQn          = 52,
  PLIC_UART7_IRQn          = 53,
  PLIC_WATCHDOG1_IRQn      = 54,  // assign  interrupt_per[53]    =  INTISR[66]
  PLIC_I2C2_IRQn           = 55,  // assign  interrupt_per[72:54] =  INTISR[86:68]
  PLIC_I2C3_IRQn           = 56,
  PLIC_TIMER4A_IRQn        = 57,
  PLIC_TIMER4B_IRQn        = 58,
  PLIC_ADC0_0_IRQn         = 59,
  PLIC_ADC0_1_IRQn         = 60,
  PLIC_ADC0_2_IRQn         = 61,
  PLIC_ADC0_3_IRQn         = 62,
  PLIC_ADC1_0_IRQn         = 63,
  PLIC_INT_MAX             = __PLIC_INTNUM - 1,
} PLIC_IRQn_Type;
#endif

int32_t PLIC_Register_IRQ(uint32_t source, uint8_t priority, void *handler);
void PLIC_Init(uint32_t num_sources);

#endif