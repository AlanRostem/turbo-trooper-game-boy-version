set(CMAKE_C_COMPILER lcc)

cmake_minimum_required(VERSION 2.8.12)

project(turbo-trooper C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wa-l -Wl-m -Wl-j -DUSE_SFR_FOR_REG")

include_directories(
    "."
    "C:/gbdk/include"
)

add_compile_definitions(__PORT_gbz80)

file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME} SUFFIX ".gb")