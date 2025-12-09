#include "../work.h"

typedef void (*callback_t)(void);
#define MAX_CALLBACKS 4
callback_t callback_table[MAX_CALLBACKS];
volatile callback_t emergency_stop_callback = 0;

void register_callback(int index, callback_t cb) { callback_table[index] = cb; }

char incMsg[2][100] = {
  {"The battery voltage exceeds the permissible threshold! Stop it now!!!\n"},
  {"The battery voltage is normal.\n"}
};
void legitimate_callback() { pml_print(incMsg[0]); }

void malicious_payload() { pml_print(incMsg[1]); }

void set_emergency_stop_callback(callback_t cb) { emergency_stop_callback = cb; }

#define MAX_SAFE_VOLTAGE (420)  // GB/T 18487.1-2015
unsigned read_battery_voltage() { return 500; }

const FunctionCPUID id = kCPU2;
void DemoAttack(void) {
  set_emergency_stop_callback(legitimate_callback);

  // exploiting callback register vulnerability
  unsigned malicious_addr = (unsigned)malicious_payload;
  int byte_offset = (char*)&emergency_stop_callback - (char*)callback_table;
  int exploit_index = byte_offset / sizeof(callback_t);
#ifdef TARGET_MIPS
  if (id == kCPU0) {
    register_callback(exploit_index, (callback_t)malicious_addr);
  }
#endif
#ifdef TARGET_ARM
  if (id == kCPU1) {
    register_callback(exploit_index, (callback_t)malicious_addr);
  }
#endif
#ifdef TARGET_RISCV
  if (id == kCPU2) {
    register_callback(exploit_index, (callback_t)malicious_addr);
  }
#endif

  // trigger 2vs.1
  unsigned voltage = read_battery_voltage();
  if (voltage > MAX_SAFE_VOLTAGE) {
    emergency_stop_callback();
  }
}