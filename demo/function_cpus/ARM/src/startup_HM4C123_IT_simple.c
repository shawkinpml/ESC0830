/****************************************************************************//**
 * @file :    startup_HM3C1788.c
 * @brief : CMSIS Cortex-M3 Core Device Startup File
 * @version : V0.01
 * @date :    29. Sept. 2021
 *
 *----------------------------------------------------------------------------
 *
 * Copyright (C) 2021 PML Limited. All rights reserved.
 *
 *
 ******************************************************************************/

// Mod by nio for the .fastcode part

#ifdef CHIP_SEL_ESC0830
  #include "HM4C123.h"
#endif
#ifdef CHIP_SEL_ESC0820
#include "HM3S9B96.h"
#endif
#include "uart_print.h"
#include "io_arm.h"

#define WEAK __attribute__ ((weak))
//*****************************************************************************
//
// Forward declaration of the default fault handlers.
//
//*****************************************************************************
/* System exception vector handler */
// void WEAK 		Reset_Handler(void);             /* Reset Handler */
void WEAK 		NMI_Handler(void);               /* NMI Handler */
void WEAK 		HardFault_Handler(void);         /* Hard Fault Handler */
void WEAK 		MemManage_Handler(void);         /* MPU Fault Handler */
void WEAK 		BusFault_Handler(void);          /* Bus Fault Handler */
void WEAK 		UsageFault_Handler(void);        /* Usage Fault Handler */
void WEAK 		SVC_Handler(void);               /* SVCall Handler */
void WEAK 		DebugMon_Handler(void);          /* Debug Monitor Handler */
void WEAK 		PendSV_Handler(void);            /* PendSV Handler */
void WEAK 		SysTick_Handler(void);           /* SysTick Handler */
extern void save_context_handler();
extern unsigned plic_handler();

/* External interrupt vector handler */
void WEAK      	Default_IRQHandler(void);            

/* Exported types --------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
//extern unsigned long _etext;
extern unsigned long _sidata;		/* start address for the initialization values of the .data section. defined in linker script */
extern unsigned long _sdata;		/* start address for the .data section. defined in linker script */
extern unsigned long _edata;		/* end address for the .data section. defined in linker script */

extern unsigned long _sifastcode;		/* start address for the initialization values of the .fastcode section. defined in linker script */
extern unsigned long _sfastcode;		/* start address for the .fastcode section. defined in linker script */
extern unsigned long _efastcode;		/* end address for the .fastcode section. defined in linker script */

extern unsigned long _sbss;			/* start address for the .bss section. defined in linker script */
extern unsigned long _ebss;			/* end address for the .bss section. defined in linker script */

//extern void _estack;		/* init value for the stack pointer. defined in linker script */



/* Private typedef -----------------------------------------------------------*/
/* function prototypes ------------------------------------------------------*/
void Reset_Handler(void) __attribute__((__interrupt__));
extern int main(void);


/******************************************************************************
*
* The minimal vector table for a Cortex M3.  Note that the proper constructs
* must be placed on this to ensure that it ends up at physical address
* 0x0000.0000.
*
******************************************************************************/
// #define STACK_SIZE                              0x00000200
#ifdef __HEAP_SIZE
#define	Heap_Size __HEAP_SIZE
#else
#define	Heap_Size 0x00000C00
#endif
#define HEAP_SIZE                              (Heap_Size/4)
__attribute__ ((section(".heaparea")))
/* static */ unsigned long pulHeap[HEAP_SIZE];

#ifdef __STACK_SIZE
#define	Stack_Size __STACK_SIZE
#else
#define	Stack_Size 0x00000400
#endif
#define STACK_SIZE                              (Stack_Size/4)
__attribute__ ((section(".stackarea")))
/* static */ unsigned long pulStack[STACK_SIZE];

extern char __stack[];

__attribute__ ((section(".isr_vector")))
void (* const g_pfnVectors[])(void) =
{
        __stack,                   // The initial stack pointer
        /* &_estack,                   // The initial stack pointer */
		// (void (*)(void))((unsigned long)pulStack + sizeof(pulStack)),  // The initial stack pointer
        Reset_Handler,             /* Reset Handler */
        NMI_Handler,               /* NMI Handler */
        HardFault_Handler,         /* Hard Fault Handler */
        MemManage_Handler,         /* MPU Fault Handler */
        BusFault_Handler,          /* Bus Fault Handler */
        UsageFault_Handler,        /* Usage Fault Handler */
        0,                         /* Reserved */
        0,                         /* Reserved */
        0,                         /* Reserved */
        0,                         /* Reserved */
        SVC_Handler,               /* SVCall Handler */
        DebugMon_Handler,          /* Debug Monitor Handler */
        0,                         /* Reserved */
        PendSV_Handler,            /* PendSV Handler */
        SysTick_Handler,           /* SysTick Handler */

		// External Interrupts
        save_context_handler,            
        plic_handler,        
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,   
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,   
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,   
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,   
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,   
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,   
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,   
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,   
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,   
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,   
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler, //54
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler,
        Default_IRQHandler  //138
};
/*******************************************************************************
* Function Name  : Reset_Handler
* Description    : This is the code that gets called when the processor first starts execution
*		       following a reset event.  Only the absolutely necessary set is performed,
*		       after which the application supplied main() routine is called.
* Input          :
* Output         :
* Return         :
*******************************************************************************/
#define APP_EXIT				 (*(volatile unsigned long *)0x20094100)

void Reset_Handler(void)
{
	unsigned *pulDest;
    unsigned *pulSrc;
	unsigned temp=0;
    //
    // Copy the data segment initializers from flash to SRAM in ROM mode
    //

    if (&_sidata != &_sdata) {	// only if needed
		pulSrc = &_sidata;
		for(pulDest = &_sdata; pulDest < &_edata; ) {
			*(pulDest++) = *(pulSrc++);
		}
    }

    // Copy the .fastcode code from ROM to SRAM

    if (&_sifastcode != &_sfastcode) {	// only if needed
    	pulSrc = &_sifastcode;
		for(pulDest = &_sfastcode; pulDest < &_efastcode; ) {
			*(pulDest++) = *(pulSrc++);
		}
    }
	
    //
    // Zero fill the bss segment.
    //
    for(pulDest = &_sbss; pulDest < &_ebss; )
    {
        *(pulDest++) = 0;
    }

    //
    // Call the application's entry point.
    //
    SystemInit();
    main();

    //
    // exit TODO will goto Default_Handler
    //	
	// temp = APP_EXIT;
	// APP_EXIT = 0x80000000;
	while(1);
}

//*****************************************************************************
//
// Provide weak aliases for each Exception handler to the Default_Handler.
// As they are weak aliases, any function with the same name will override
// this definition.
//
//*****************************************************************************
// #pragma weak NMI_Handler = Default_Handler           	 /* NMI Handler Handler */
#pragma weak HardFault_Handler = Default_Handler         /* HardFault Handler */
#pragma weak MemManage_Handler = Default_Handler          /* MPU Fault Handler */
#pragma weak BusFault_Handler = Default_Handler           /* Bus Fault Handler */
#pragma weak UsageFault_Handler = Default_Handler         /* Usage Fault Handler */
#pragma weak SVC_Handler = Default_Handler                /* SVCall Handler */
#pragma weak DebugMon_Handler = Default_Handler           /* Debug Monitor Handler */
#pragma weak PendSV_Handler = Default_Handler             /* PendSV Handler */
#pragma weak SysTick_Handler = Default_Handler            /* SysTick Handler */

/* External interrupt vector handler */
#pragma weak Default_IRQHandler = Default_Handler            /* Watchdog Timer */


//*****************************************************************************
//
// This is the code that gets called when the processor receives an unexpected
// interrupt.  This simply enters an infinite loop, preserving the system state
// for examination by a debugger.
//
//*****************************************************************************
// void Default_Handler(void) {
// 	// Go into an infinite loop.
// 	//
// 	while (1) {
// 		// uart_printf("system error! \r\n");
// 	}
// }

void Default_Handler() {
//   unsigned active = SCB_GetVectorActive();
//   unsigned pending = SCB_GetVectorPending();
//   PERROR("ARM exception happended, pending=%08x, active=%08x, deadloop now.", pending, active);
  unsigned icsr = SCB->ICSR;
  uart_printf("ARM exception happended, icsr=0x%x, deadloop now.", icsr);
  // delay_cnt(0x100000);
  while (1) {
      ;  // Loop forever non-interrupt exception detected
    }
  // Reset_Handler();
}
