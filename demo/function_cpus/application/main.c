#include "io_mcu.h"
#include "plic.h"
#include "uart_print.h"
#include "driver_common.h"
#include "context.h"
#include "work.h"

void pml_putc(char data) {
  while ((HM_UART0->CSR & UART_CSR_TFUL_MASK));
  HM_UART0->TFIFO = data;
}

static const char charmap[16] = "0123456789abcdef";

static void pml_printn(unsigned n, unsigned bas) {
  unsigned r;

  if ((r = n / bas) != 0) pml_printn(r, bas);
  pml_putc(charmap[n % bas]);
}

void pml_print(const char *fmt, ...) {
  char c = 0, *s = NULL;
  unsigned n = 0;

  va_list args;
  int t = 0;

  va_start(args, fmt);

  while ((c = *fmt++) != '\0') {
    if (c != '%') {
      pml_putc(c);
      continue;
    }

    switch (c = *fmt++) {
      case 'o':
        t = va_arg(args, int);
        pml_printn(t, 8);
        break;
      case 'u':
        t = va_arg(args, int);
        pml_printn(t, 10);
        break;
      case 'x':
      case 'X':
        n = va_arg(args, unsigned int);

        if (n >> 28) pml_putc(charmap[(n >> 28) & 0x0f]);
        if (n >> 24) pml_putc(charmap[(n >> 24) & 0x0f]);
        if (n >> 20) pml_putc(charmap[(n >> 20) & 0x0f]);
        if (n >> 16) pml_putc(charmap[(n >> 16) & 0x0f]);
        if (n >> 12) pml_putc(charmap[(n >> 12) & 0x0f]);
        if (n >> 8) pml_putc(charmap[(n >> 8) & 0x0f]);
        if (n >> 4) pml_putc(charmap[(n >> 4) & 0x0f]);
        pml_putc(charmap[n & 0x0f]);
        break;

      case 's':
        s = va_arg(args, char *);
        for (; *s != '\0'; ++s) {
          pml_putc(*s);
        }
        break;

      default:
        c = va_arg(args, int);
        pml_putc(c);
        continue;
    }
  }
  va_end(args);
}

void TestOneCPUErr() {
  int t = 0;
  if (CTRL_RST_FLAG == 1) {
    CTRL_RST_FLAG = 0;
    // BOOT_FINISH_FLAG = 1; // todo, influence vary at DMR, and the next time

    if (RD_RESTORE_FROM_CHECKER == 1) {
      pml_stack_restore();
      pml_loc_restore();
      unsigned all_cpu_err = ALL_CPU_ERROR;
      RESTORE_FINISH = 0x1; // this will make hardware clear ALL_CPU_ERROR
      t = 1;

      if (all_cpu_err == 1) {
        unsigned* lad = NULL;
        // pml_print("\r\nli = %u\r\n", LAST_PASS_EVENT_INDEX);
        GetLabelAddr(LAST_PASS_EVENT_INDEX, &lad);
        goto *lad;
      } else {
        while (1) {
          if (OTHER_CPU1_EVENT_END && OTHER_CPU2_EVENT_END) {
            if (OTHER_CPU1_EVENT_INDEX == OTHER_CPU2_EVENT_INDEX) {
              OTHER_CPU1_EVENT_END = 0;
              OTHER_CPU2_EVENT_END = 0;
              break;
            }
          }
        }

        unsigned* lad = NULL;
        GetLabelAddr(OTHER_CPU1_EVENT_INDEX, &lad);

        while (1) {
          if(OTHER_CPU1_SAVE_CTX_FINISH && OTHER_CPU2_SAVE_CTX_FINISH) {
            OTHER_CPU1_SAVE_CTX_FINISH = 0;
            OTHER_CPU2_SAVE_CTX_FINISH = 0;
            break;
          }
        } 
        goto *lad;
      }
    } else {
      t = 1;
    }
  }
  
  int* common = (int*)pml_com_malloc(sizeof(int));
  *common = 1000;
  int* local = (int*)pml_loc_malloc(sizeof(int));
  *local = 99;
  // pml_print("o:%u,%u\r\n", *common, *local);

  // triple modular redundancy
  *common = *common - 10;
  *local = *local - 10;
  EVENT_END_WITH_LABEL(10);

  if (t == 0) {
    pml_print("\r\n********************   DemoAttack start...   ********************\r\n");
    DemoAttack();
    pml_print("********************   DemoAttack end.       ********************\r\n");
  } else {
    pml_print("\r\n********************   DemoAttack end.       ********************\r\n");
    pml_print("Reboot end.\r\n");
  }
  

  // dual modular redundancy
  *common = *common - *local;
  // *local = *local - 1;  // 2cpu-mode, change *local will cause the err cpu's value different below.
  pml_print("chk_pass_cnt=%u,%u,%u\r\n", S0_CHK_PASS_CNT, S1_CHK_PASS_CNT, S2_CHK_PASS_CNT);
  
  // wait for the failed cpu recovering
  Delay(5);
  EVENT_END_WITH_LABEL(11);
  
  // If recovered, here should be equal; otherwise, wait more time.
  pml_print("chk_pass_cnt=%u,%u,%u\r\n", S0_CHK_PASS_CNT, S1_CHK_PASS_CNT, S2_CHK_PASS_CNT);
  
  *common = *common - 10;
  *local = *local - 10;
  // pml_print("r:%u,%u\r\n", *common, *local); // 891,79p
}


int main() {
  SetEDAMode(1);

  TestOneCPUErr();  // 0：don't test irq; 1: test irq.
  return 0;
}
