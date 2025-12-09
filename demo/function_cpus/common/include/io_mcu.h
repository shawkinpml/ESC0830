#ifndef PML_IO_MCU_H
#define PML_IO_MCU_H
#ifdef TARGET_MIPS
#include "io_uc.h"
#endif
#ifdef TARGET_ARM
#include "io_arm.h"
#endif
#ifdef TARGET_RISCV
#include "io_e906.h"
#endif

#define COM_SRAM_SIZE      0x20000     // 128KB
#define DAT_SRAM_SIZE      0xC000      // 48KB
#define LOC_SRAM_SIZE      0x4000      // 16KB
#define COM_SRAM_USRE_SIZE 0x8000
#define LOC_SRAM_USRE_SIZE 0x1000      
#define REG_SAVE_SRAM_ADDR    (LOC_SRAM_BASEADDR + LOC_SRAM_SIZE - __REGS_SIZE)
#define STACK_SAVE_SRAM_ADDR  (LOC_SRAM_BASEADDR + LOC_SRAM_SIZE - __REGS_SIZE - __STACK_SIZE)
#define CHK_POINT_SP_ADDR     (LOC_SRAM_BASEADDR + 2*LOC_SRAM_USRE_SIZE)

#define LOC_SRAM_OFF            (*(volatile unsigned *)LOC_SRAM_BASEADDR           )
#define COM_SRAM_OFF            (*(volatile unsigned *)COM_SRAM_BASEADDR           )

#ifndef NULL
#define NULL ((void *)0)
#endif
#define TEL_ADDR (LOC_SRAM_BASEADDR + LOC_SRAM_SIZE - 3072)

typedef enum { 
    kCPU0 = 0, 
    kCPU1 = 1, 
    kCPU2 = 2, 
    kCPUMax 
} FunctionCPUID;

#endif