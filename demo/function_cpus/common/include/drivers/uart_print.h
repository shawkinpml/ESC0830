#ifndef UART_STDOUT_H
#define UART_STDOUT_H
#include <stdio.h>
#include <stdarg.h>
#include "hm_libcfg_default.h"
#include "hm_uart.h"

void uart_printf(const char *fmt,...);
void uart2_init(const unsigned pll_type);
void uart_stdout_init(const unsigned pll_type);
void uart_putc(char data);

#define PINFO(format, ...) uart_printf("[PML INFO]%s:%u.\n" format "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define PWARNING(format, ...) uart_printf("[PML WARNING]%s:%u.\n" format "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define PERROR(format, ...) uart_printf("[PML ERROR]%s:%u.\n" format "\n", __FILE__, __LINE__, ##__VA_ARGS__)
// #define PERROR(format, ...) uart_printf("[E]\n" format "\n", ##__VA_ARGS__)
#define PFATAL(format, ...) uart_printf("[PML FATAL]%s:%u.\n" format "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#endif
