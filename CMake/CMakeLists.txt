cmake_minimum_required(VERSION 3.16.3)

project(GcdCounter)

add_executable(GcdCounter main.cpp)

add_subdirectory(MathFunctionLib)

target_link_libraries(GcdCounter PUBLIC MathFunctionLib)

target_include_directories(GcdCounter PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MathFunctionLib"
                          )
