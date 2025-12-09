# Call Cmake from the 'build' subfolder with the command below.
# For using Make:
# cmake -DCMAKE_VERBOSE_MAKEFILE=ON -DCMAKE_MAKE_PROGRAM=make.exe -DCMAKE_TOOLCHAIN_FILE="arm.cmake" -G "MinGW Makefiles" ..
# followed by
# 'make' or 'cmake --build .' to build it
#

set(CMAKE_SYSTEM_NAME          Generic)
set(CMAKE_SYSTEM_PROCESSOR     ARM)

set(GNU_GDB $ENV{PMLPath}/third_party/ToolChains/GNUArmEmbeddedToolchain/bin/arm-none-eabi-gdb.exe)
# set(GNU_GDB D:/MCU_WorkSpace/StudyDoc/ARM/14.2.rel1-mingw-w64-i686/bin/arm-none-eabi-gdb.exe)

get_filename_component(TOOLCHAIN_BIN_PATH ${GNU_GDB} DIRECTORY)
get_filename_component(TOOLCHAIN_BIN_GCC ${GNU_GDB} NAME_WE)
get_filename_component(TOOLCHAIN_BIN_EXT ${GNU_GDB} EXT)
STRING(REGEX REPLACE "\-gdb" "-" CROSS_COMPILE ${TOOLCHAIN_BIN_GCC})
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(TOOLCHAIN_PREFIX ${TOOLCHAIN_BIN_PATH}/${CROSS_COMPILE})
message("Cross Compile Prefix: ${TOOLCHAIN_PREFIX}")

set(CMAKE_C_COMPILER "${TOOLCHAIN_PREFIX}gcc.exe")
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_PREFIX}g++.exe")
# set(CMAKE_C_LINK_EXECUTABLE "${TOOLCHAIN_PREFIX}ld.exe <FLAGS> <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")

set(CMAKE_SIZE_UTIL ${TOOLCHAIN_PREFIX}size CACHE INTERNAL "size tool")
set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}objcopy CACHE INTERNAL "objcopy tool")
set(CMAKE_OBJDUMP ${TOOLCHAIN_PREFIX}objdump CACHE INTERNAL "objdump tool")
set(CMAKE_READELF ${TOOLCHAIN_PREFIX}readelf CACHE INTERNAL "readelf tool")

set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_BIN_PATH})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

message( "-------------- config toolchain success --------------" )
