cmake_minimum_required(VERSION 2.8)
project(ide2dfx)

include_directories(include)
file(GLOB SOURCES src/*.cxx)

set(EXECUTABLE_NAME "ide2dfx")
add_executable(${EXECUTABLE_NAME} ${SOURCES})

target_link_libraries(${EXECUTABLE_NAME})
