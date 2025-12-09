from gen_label_map_common import genfile
from gen_label_map_common import DEST_TAIL
import os

## ARM
CPU1_PATH = os.path.join(os.getcwd(), "ARM/app/build/arm_app.lst")
DES1_PATH = os.path.join(os.getcwd(), "ARM/src/gen.S")
DES1_HEAD = [
"	.syntax	unified\n",
"	.arch	armv7-m\n",
"\n",
"	.section .labels\n",
"	.align	2\n",
"	.globl	__Labels\n",
"__Labels:\n"
]

genfile(CPU1_PATH, DES1_PATH, DES1_HEAD, DEST_TAIL)
