#ifndef DRIVER_INIT_H
#define DRIVER_INIT_H
#ifdef TARGET_MIPS
#include "io_uc.h"
#endif
#ifdef TARGET_ARM
#include "io_arm.h"
#endif
#ifdef TARGET_RISCV
#include "io_e906.h"
#endif

#include "uart_print.h"

void Resource_Init(void);
unsigned GetMainCLK();
void SetMainCLK(unsigned type);

#endif
