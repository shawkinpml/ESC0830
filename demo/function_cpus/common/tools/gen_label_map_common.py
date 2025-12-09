import os
from enum import Enum
import sys
import traceback

class State(Enum):
  find_event = 1
  find_event_line_num = 2
  find_next_line_num = 3
  find_label_addr = 4

class CurState(object):
  def __init__(self, state):
    self.state = state
  def set(self, state):
    self.state = state
  def get(self):
    return self.state

def checkfile(lst_path, dst_path):
  if os.path.exists(lst_path):
    file_size = os.path.getsize(lst_path)
    # print("The size of file is %d, %s." % (file_size, lst_path))
  else:
    print("Err, file isn't exist, %s!" % lst_path)
    sys.exit(0)

  try:
    fs = open(lst_path, 'r')
  except IOError:
    traceback.print_exc()

  try:
    fd = open(dst_path, 'w')
  except IOError:
    traceback.print_exc()

  return fs, fd

def continue_line(fs, line, line_num, org_dict):
  line = fs.readline()
  line_num = line_num + 1
  org_dict[line_num] = len(line)
  return line, line_num

def gen_event_id(fd, line, state):
  key_start = line.find(KEY_EVENT) + KEY_SIZE
  key_end = line.find(");", key_start + 1)
  key_num = line[key_start:key_end].strip()
  fd.write("    .long	" + key_num + "\n")
  state.set(State.find_event_line_num)

def find_event_line(fs, line, cur_pos, line_num, state, org_dict):
  offset = -len(line) - 1
  fs.seek(cur_pos + offset, 0)
  cur_line_num = line_num
  while (state.get() == State.find_event_line_num):
    cur_line_num = cur_line_num - 1
    cur_len  = org_dict[cur_line_num]
    offset = offset - cur_len
    fs.seek(cur_pos + offset, 0)
    cur_line = fs.readline()
    if cur_line.find(".c:") >= 0 :
      num_start = cur_line.find(".c:") + 3
      num_line  = cur_line[num_start:-1] # strip \n
      if num_line.find(" ") >= 0:
        num_line = num_line[:num_line.find(" ")] # strip (discriminator 1)
      event_num = str(int(num_line))
      state.set(State.find_next_line_num)
  
  fs.seek(cur_pos, 0)
  return event_num

def genfile(lst_path, dst_path, dest_head, dest_tail):
  fs, fd = checkfile(lst_path, dst_path)

  for line in dest_head:
    fd.write(line)

  line = ''
  line_num = -1 # must be -1, for ++
  org_dict = {}
  cur_pos = 0
  event_num = 0
  state = CurState(State.find_event)

  line, line_num = continue_line(fs, line, line_num, org_dict)
  
  while(line != ''):
      cur_pos = fs.tell()
      if state.get() == State.find_event:
        if line.find(KEY_EVENT) >= 0 :
            gen_event_id(fd, line, state)
            event_num = find_event_line(fs, line, cur_pos, line_num, state, org_dict)
      elif state.get() == State.find_next_line_num:
        if line.find(".c:") >= 0:
          if line.find(".c:" + event_num) >= 0 :
            line = fs.readline()
            continue # skip the same c line
          else:
            state.set(State.find_label_addr)
      elif state.get() == State.find_label_addr:
        while (line.strip() == ''):
          line = fs.readline() # skip empty lst line
        while (line.find(":\t") <= 0):
          line = fs.readline() # move to the next line to skip c language code #TODO how to judge c code
        address_end = line.find(":\t")
        label_address = line[:address_end].strip()
        fd.write("    .long	0x" + label_address + "\n")
        state.set(State.find_event)
      line, line_num = continue_line(fs, line, line_num, org_dict)

  fs.close()

  for line in dest_tail:
    fd.write(line)

  fd.close()
  print("Gen finish, please check file: %s!" % dst_path)

## common
print("cwd: ", os.getcwd())
KEY_EVENT = "EVENT_END_WITH_LABEL("
KEY_SIZE = len(KEY_EVENT)
DEST_TAIL = [
"\n",
"	.size	__Labels, . - __Labels\n",
"\n",
"	.end\n"
]
