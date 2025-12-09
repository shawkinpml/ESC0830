/*============================================================================
 * Name        : chip_name.c
 * Author      : $(UserName)
 * Copyright   : Your copyright notice
 * Description : System Initialization before main
 * 1 CPU initialization
 * 2 memory & IO base address initialization
 * 3 flash size & address initialization
 * 4 interrupt resource initialization for the soc
 *============================================================================
 */
#include <string.h>
// #include <plic.h>
#include "driver_common.h"
/**
 * Globl symbols in ckcpu.ld 
 */
extern char __s_ram_data_1[];
extern char __e_rom[];
extern char __e_ram_data_1[];
extern char __e_ram_bss_1[];
extern char __s_ram_bss_1[];

static void MemoryInit( void ) 
{
  unsigned int count = (__e_ram_data_1 - __s_ram_data_1) / 4;
  if (__s_ram_data_1 != __e_rom) {
    for (unsigned int i = 0; i < count; i++) {
      *((volatile unsigned int *)(__s_ram_data_1 + i * 4)) = *((volatile unsigned int *)(__e_rom + i * 4));
    }
  }
  if (__e_ram_bss_1 - __s_ram_bss_1) {
    count = (__e_ram_bss_1 - __s_ram_bss_1) / 4;
    for (unsigned int i = 0; i < count; i++) {
      *((volatile unsigned int *)(__s_ram_bss_1 + i * 4)) = 0;
    }
  }
}


/**
 * @brief entry of whole chip initialization
 * Since here SystemInit is a weak symbol, any vendor can override this symbol on its own wishes.
 */
__attribute__((weak)) void  SystemInit(void) 
{
	/**
	 * Initial the bss section and data decompression from LMA to VMA
	 */
	MemoryInit();
#ifdef BOOTMODE
    return;
#endif

	/**
	 * TODO: initial IO, memory, flash... 
	 */
	// extern void Resource_Init(void);
  	Resource_Init();
    return;
}

__attribute__((weak)) void __main()
{
	// got to main 
	extern int main(void);
	main();
	// loop here;
	while(1);
}

// void __attribute__((weak)) handle_trap(unsigned int cause, unsigned int epc, unsigned int regs[32])
// {
// 	extern void general_handle_trap(unsigned int cause, unsigned int epc, unsigned int regs[32]);
// 	general_handle_trap(cause, epc, regs);
// }
