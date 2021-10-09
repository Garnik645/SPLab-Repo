cmake_minimum_required(VERSION 3.16.3)

project(SPLab)

add_executable(SPLab main.cpp)

add_subdirectory(MathFunctionLib)

target_link_libraries(SPLab PUBLIC MathFunctionLib)

target_include_directories(SPLab PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/MathFunctionLib"
                          )
