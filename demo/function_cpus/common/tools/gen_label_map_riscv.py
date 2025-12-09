from gen_label_map_common import genfile
from gen_label_map_common import DEST_TAIL
import os

## RISCV
CPU2_PATH = os.path.join(os.getcwd(), "RISCV/app/build/riscv_app.lst")
DES2_PATH = os.path.join(os.getcwd(), "RISCV/src/gen.S")
DES2_HEAD = [
".section .labels, \"aw\", @progbits\n",
"    .align  2\n",
"    .globl  __Labels\n",
"    .type   __Labels, @object\n",
"__Labels:\n"
]

genfile(CPU2_PATH, DES2_PATH, DES2_HEAD, DEST_TAIL)
