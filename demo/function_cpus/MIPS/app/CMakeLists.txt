# CMake file for program
cmake_minimum_required(VERSION 3.15.3)

# Optional: print out extra messages to see what is going on. Comment it to have less verbose messages
set(CMAKE_VERBOSE_MAKEFILE ON)

# Path to toolchain file. This one has to be before 'project()' below
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/../mips.cmake)

# Setup project, output and linker file
project(mips_app)
set(EXECUTABLE ${PROJECT_NAME}.elf)
set(LINKER_FILE ${CMAKE_SOURCE_DIR}/app.ld)
set(BASE_LINKER_FILE ${CMAKE_SOURCE_DIR}/../link.ld)
set(INC_DIR 
        ${CMAKE_SOURCE_DIR}/../include/
        ${CMAKE_SOURCE_DIR}/../../applicaion/
        ${CMAKE_SOURCE_DIR}/../../applicaion/work/
        ${CMAKE_SOURCE_DIR}/../../common/include/
        ${CMAKE_SOURCE_DIR}/../../common/include/plic/
        ${CMAKE_SOURCE_DIR}/../../common/include/device/
        ${CMAKE_SOURCE_DIR}/../../common/include/drivers/
        ${CMAKE_SOURCE_DIR}/../src/asm
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
        ../src/asm/start_app.S
        ../../application/main.c
        ../src/gen.S
        )

AUX_SOURCE_DIRECTORY(../../application/work WORK_SRC_FILES)

message(STATUS "WORK_SRC_FILES is: ${WORK_SRC_FILES}")

# Build the executable based on the source files
# add_executable(${EXECUTABLE} ${BASE_FILES} ${COMMON_SRC_FILES} ${PLIC_SRC_FILES} ${DRIVER_SRC_FILES})
add_executable(${EXECUTABLE} ${BASE_FILES} ${WORK_SRC_FILES})

link_directories(${MY_LIB_PATH})
target_link_libraries(${EXECUTABLE} PUBLIC ${MY_LIB_MIMIC_NAME} ${MY_LIB_DRIVERS_NAME})

set(DEFINE TARGET_MIPS)
target_compile_definitions(${EXECUTABLE} PUBLIC ${DEFINE})

# Compiler options
set(C_BASE_FLAGS
        -Wall -c -fmessage-length=0 -fno-common
	-EL -mno-mips16 -mno-micromips -msoft-float
	-march=mips32r2 -G0 -O0 
        )
set(C_FLAGS
        -g3
        ${C_BASE_FLAGS}
        )
target_compile_options(${EXECUTABLE} PRIVATE ${C_FLAGS})

set_property(SOURCE src/crt0.S APPEND_STRING PROPERTY
    COMPILE_FLAGS -D_BOOTCODE
)

# Linker options
set(LD_BASE_FLAGS
        -nostdlib
        -T${LINKER_FILE} 
        -T${BASE_LINKER_FILE}
        -Wl,--gc-sections
	-EL -mips32r2 -mno-mips16 -mno-micromips -msoft-float -Wcast-align
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