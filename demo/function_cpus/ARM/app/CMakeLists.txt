# CMake file for FRDM-K22F_Simple
cmake_minimum_required(VERSION 3.15.3)

# Optional: print out extra messages to see what is going on. Comment it to have less verbose messages
set(CMAKE_VERBOSE_MAKEFILE ON)

# Path to toolchain file. This one has to be before 'project()' below
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/../arm.cmake)

# Setup project, output and linker file
project(arm_app)
set(EXECUTABLE ${PROJECT_NAME}.elf)
set(LINKER_FILE ${CMAKE_SOURCE_DIR}/ARM_app.ld)
set(INC_DIR 
        ${CMAKE_SOURCE_DIR}/../include/
        ${CMAKE_SOURCE_DIR}/../../applicaion/
        ${CMAKE_SOURCE_DIR}/../../applicaion/work/
        ${CMAKE_SOURCE_DIR}/../../common/include/
        ${CMAKE_SOURCE_DIR}/../../common/include/plic/
        ${CMAKE_SOURCE_DIR}/../../common/include/device/
        ${CMAKE_SOURCE_DIR}/../../common/include/drivers/
)
INCLUDE_DIRECTORIES(${INC_DIR})
set(MY_LIB_PATH ${CMAKE_SOURCE_DIR}/../lib)
set(MY_LIB_MIMIC_NAME mimic)
set(MY_LIB_DRIVERS_NAME drivers)

enable_language(C ASM)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Optional: issue a message to be sure it uses the correct toolchain file.
message(STATUS "CMAKE_TOOLCHAIN_FILE is: ${CMAKE_TOOLCHAIN_FILE}")

# List of source files
set(BASE_FILES
        ../src/startup_HM4C123_IT_simple.c
        ../src/system_HM4C123_hc.c
        ../src/startup_helper.S
        ../src/gen.S
        ../../application/main.c
        )

AUX_SOURCE_DIRECTORY(../../application/work WORK_SRC_FILES)

message(STATUS "WORK_SRC_FILES is: ${WORK_SRC_FILES}")

# Build the executable based on the source files
# add_executable(${EXECUTABLE} ${COMMON_SRC_FILES} ${PLIC_SRC_FILES} ${DRIVER_SRC_FILES} ${BASE_FILES})
add_executable(${EXECUTABLE} ${BASE_FILES} ${WORK_SRC_FILES})

link_directories(${MY_LIB_PATH})
target_link_libraries(${EXECUTABLE} PUBLIC ${MY_LIB_MIMIC_NAME} ${MY_LIB_DRIVERS_NAME})

set(DEFINE _RTE_ ARMCM3 __STARTUP_CLEAR_BSS TARGET_ARM)
target_compile_definitions(${EXECUTABLE} PUBLIC ${DEFINE})

# Compiler options
set(C_BASE_FLAGS
        -mcpu=cortex-m3 -mthumb -march=armv7-m -mlittle-endian
        -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants
        -mfloat-abi=soft -std=gnu11 -O0
        -Wall -Wextra
)
set(C_FLAGS
        -g3
        ${C_BASE_FLAGS}
)
target_compile_options(${EXECUTABLE} PRIVATE ${C_FLAGS})

# Linker options
set(LD_BASE_FLAGS
        -mcpu=cortex-m3 -mthumb -march=armv7-m -nostdlib -mlittle-endian
        -nostartfiles -msoft-float
        -T${LINKER_FILE}
)
set(LD_FLAGS
        -L${MY_LIB_PATH}
        ${LD_BASE_FLAGS}
)
target_link_options(${EXECUTABLE} PRIVATE ${LD_FLAGS})

# Optional: Create hex, bin and S-Record files after the build
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND ${CMAKE_READELF} --headers --wide ${EXECUTABLE} > ${PROJECT_NAME}.lst
        COMMAND ${CMAKE_OBJDUMP} --source --all-headers --demangle --line-numbers --wide ${EXECUTABLE} >> ${PROJECT_NAME}.lst
        COMMAND ${CMAKE_OBJCOPY} -O binary ${EXECUTABLE} ${PROJECT_NAME}.bin
        )

# Optional: Print executable size as part of the post build process
add_custom_command(TARGET ${EXECUTABLE}
        POST_BUILD
        COMMAND ${CMAKE_SIZE_UTIL} ${EXECUTABLE})