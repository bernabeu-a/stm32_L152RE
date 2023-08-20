cmake_minimum_required(VERSION 3.5)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
# project name
project(hello_world_cmake)

# application sources
set(SRCS
    ${CMAKE_SOURCE_DIR}/main.c
)

include_directories(
    ${CMAKE_SOURCE_DIR}
)

set(APP_SRCS ${SRCS})

set(CPU_OPTIONS -mthumb -mcpu=cortex-m3 -O0 -Wall -g)

set(CMAKE_C_FLAGS_DEBUG "-O0 -Wno-deprecated -DDebug")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wno-deprecated -DDebug")
set(CMAKE_C_FLAGS_RELEASE "-O0 -Wno-deprecated -DDebug")
set(CMAKE_CXX_FLAGS_RELEASE "-O0 -Wno-deprecated -DDebug")

add_compile_options(
    ${CPU_OPTIONS}
    -ffunction-sections
    -Wall
    -Wextra
    -Wcast-align
    -Wshadow
    -Wlogical-op
    -Wsuggest-final-types
    -Wsuggest-final-methods
    # -fno-exceptions
    -g
)

set(SYSTEMSRCS
    ${CMAKE_SOURCE_DIR}/stm32_startup.c
)

add_executable(${PROJECT_NAME} ${APP_SRCS} ${SYSTEMSRCS})

set(LINKER_DIR ${CMAKE_SOURCE_DIR})
set(LINKER_SCRIPT "stm32_ls.ld")
set(LINKER_FLAGS
    -nostdlib
    -Wl,--gc-sections
    -Xlinker -Map=main.map
)

target_link_libraries(
    ${PROJECT_NAME}
    ${CPU_OPTIONS}
    -T${LINKER_DIR}/${LINKER_SCRIPT}
    ${LINKER_FLAGS}
)

set_property(TARGET ${PROJECT_NAME} PROPERTY LINK_DEPENDS ${LINKER_DIR}/${LINKER_SCRIPT})

add_custom_command(
    OUTPUT ${PROJECT_NAME}.bin
    DEPENDS ${PROJECT_NAME}
    COMMAND ${CMAKE_OBJCOPY} -Obinary ${PROJECT_NAME} ${PROJECT_NAME}.bin
)

add_custom_target(
    bin
    DEPENDS ${PROJECT_NAME}.bin
)

add_custom_target(
    flash
    DEPENDS ${PROJECT_NAME}.bin
    COMMAND st-flash --reset write ${PROJECT_NAME}.bin 0x8000000
)