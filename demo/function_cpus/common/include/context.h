#ifndef PML_CONTEXT_H
#define PML_CONTEXT_H

#ifdef TARGET_ARM
#define pml_get_sp(P)                                          \
({                                                             \
  __asm volatile("movs %0, r7" : "=r"(*P));                    \
})
#elif TARGET_MIPS
#define pml_get_sp(P)                                          \
({                                                             \
  __asm volatile("move	%0, $sp" : "=r"(*P));                  \
})
#endif

void event_delay();

#define EVENT_END_WITH_LABEL(P)                                \
({                                                             \
  unsigned int result = 0;                                     \
  pml_get_sp(&result);                                         \
  CHK_POINT_SP = result;                                       \
  EVENT_INDEX = P;                                             \
  EVENT_END = 1;                                               \
  event_delay();                                               \
})

void SRAM_Init(void);
void GetLabelAddr(unsigned int event_id, unsigned** plad);
unsigned pml_com_malloc(int length);
unsigned pml_loc_malloc(int length);
void pml_loc_save();
void pml_loc_restore();
void pml_stack_save();
void pml_save_inc(unsigned int* src, unsigned int* dest, unsigned int len);
void pml_save_dec(unsigned int* src, unsigned int* dest, unsigned int len);
void TellSche(unsigned k);

#endif