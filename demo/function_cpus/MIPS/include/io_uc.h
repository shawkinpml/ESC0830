#ifndef CPU0_MEMORY_MAPPED_H
#define CPU0_MEMORY_MAPPED_H

#define __REGS_SIZE  0x00000400        // 1KB
#define __STACK_SIZE 0x00004000        // 16KB; not 0x00000400 1KB        // FIXME not be used
#define __HEAP_SIZE  0x00002000        // 8KB; not 0x00000C00 3KB

#define USER_INT_CLR_ADDR 0x40000100 // TODO just for FPGA by liukai, to clear button user interrupt 0xB0000100 
#define USER_INT_CLR_STEP 4

#define COM_SRAM_BASEADDR  0x44000000  // 0x40010000
#define LOC_SRAM_BASEADDR  0x8012c000  // 0x44000000

#define BOOT_REMAP_CFG          (0x80132034) // 0x000fd300
#define FUNCBOOT_ORIGIN         (0xBFCFC800)
#define FUNCBOOT_START          (0x8011C800)
#define FUNCBOOT_SIZE           (0x00003800) // 14KB FuncBootCodeSize
#define USER_FLASH_START        (0xBFC00000)
#define USER_CODERAM_START      (0x80100000)
#define USER_SIZE               (0x0001C800) // 128KB codeRAM - 14KB FuncBootCodeSize = 114KB

enum MIPS_REGISTER{
    INT_CLR_EN_ADDR                 = 0x41000010,
    SAVE_CONTEXT_FINISH_ADDR        = 0x41000014,
    RESTORE_FINISH_ADDR             = 0x41000018,
    EVENT_END_ADDR                  = 0x4100001C,
    RD_RESTORE_FROM_CHECKER_ADDR    = 0x41000020,
    OTHER_CPU1_EVENT_END_ADDR       = 0x41000024, //   ARM, accessible only if just MIPS ERR, hardware set, software clear
    OTHER_CPU2_EVENT_END_ADDR       = 0x41000028, // RISCV, accessible only if just MIPS ERR, hardware set, software clear
    OTHER_CPU1_EVENT_INDEX_ADDR     = 0x4100002c,
    OTHER_CPU2_EVENT_INDEX_ADDR     = 0x41000030,
    EVENT_INDEX_ADDR                = 0x41000034,
    ALL_CPU_ERROR_ADDR              = 0x41000038,
    LAST_PASS_EVENT_INDEX_ADDR      = 0x4100003c,
    SAVE_CONTEXT_ADDR               = 0x41000040,
    SOFT_INT_TO_CTRL_ADDR           = 0x41000044,
    S0_CHK_PASS_CNT_ADDR            = 0x41000048,
    S1_CHK_PASS_CNT_ADDR            = 0x4100004c,
    S2_CHK_PASS_CNT_ADDR            = 0x41000050,
    CTRL_RST_FLAG_ADDR              = 0x41000058,
    BOOT_FINISH_FLAG_ADDR           = 0x41000064,
    START_APP_RESPONSE_ADDR         = 0x41000068,
    OTHER_CPU1_SAVE_CTX_FINISH_ADDR = 0x4100006c,
    OTHER_CPU2_SAVE_CTX_FINISH_ADDR = 0x41000070
};

#define INT_CLR_EN                 (*(volatile unsigned *)INT_CLR_EN_ADDR             )
#define SAVE_CONTEXT_FINISH        (*(volatile unsigned *)SAVE_CONTEXT_FINISH_ADDR    )
#define RESTORE_FINISH             (*(volatile unsigned *)RESTORE_FINISH_ADDR         )
#define EVENT_END                  (*(volatile unsigned *)EVENT_END_ADDR              )
#define RD_RESTORE_FROM_CHECKER    (*(volatile unsigned *)RD_RESTORE_FROM_CHECKER_ADDR)
#define OTHER_CPU1_EVENT_END       (*(volatile unsigned *)OTHER_CPU1_EVENT_END_ADDR   )
#define OTHER_CPU2_EVENT_END       (*(volatile unsigned *)OTHER_CPU2_EVENT_END_ADDR   )
#define OTHER_CPU1_EVENT_INDEX     (*(volatile unsigned *)OTHER_CPU1_EVENT_INDEX_ADDR )
#define OTHER_CPU2_EVENT_INDEX     (*(volatile unsigned *)OTHER_CPU2_EVENT_INDEX_ADDR )
#define EVENT_INDEX                (*(volatile unsigned *)EVENT_INDEX_ADDR            )
#define ALL_CPU_ERROR              (*(volatile unsigned *)ALL_CPU_ERROR_ADDR          )
#define LAST_PASS_EVENT_INDEX      (*(volatile unsigned *)LAST_PASS_EVENT_INDEX_ADDR  )
#define SAVE_CONTEXT               (*(volatile unsigned *)SAVE_CONTEXT_ADDR           )
#define SOFT_INT_TO_CTRL           (*(volatile unsigned *)SOFT_INT_TO_CTRL_ADDR       )
#define S0_CHK_PASS_CNT            (*(volatile unsigned *)S0_CHK_PASS_CNT_ADDR        )
#define S1_CHK_PASS_CNT            (*(volatile unsigned *)S1_CHK_PASS_CNT_ADDR        )
#define S2_CHK_PASS_CNT            (*(volatile unsigned *)S2_CHK_PASS_CNT_ADDR        )
#define CHK_POINT_SP               (*(volatile unsigned *)CHK_POINT_SP_ADDR           )
#define CTRL_RST_FLAG              (*(volatile unsigned *)CTRL_RST_FLAG_ADDR          )
#define BOOT_FINISH_FLAG           (*(volatile unsigned *)BOOT_FINISH_FLAG_ADDR       )
#define START_APP_RESPONSE         (*(volatile unsigned *)START_APP_RESPONSE_ADDR     )
#define OTHER_CPU1_SAVE_CTX_FINISH (*(volatile unsigned *)OTHER_CPU1_SAVE_CTX_FINISH_ADDR )
#define OTHER_CPU2_SAVE_CTX_FINISH (*(volatile unsigned *)OTHER_CPU2_SAVE_CTX_FINISH_ADDR ) 

#endif
