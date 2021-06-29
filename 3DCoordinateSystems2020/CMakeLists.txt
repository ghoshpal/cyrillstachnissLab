cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(CMAKE_CXX_FLAGS_DEBUG "-g -o0")

project(CyrilStanchisLabCS)


include_directories(includes)
#include_directories(src)
#add_subdirectory(src)

#Adding a library
# add the MathFunctions library
#add_subdirectory(MathFunctionsLib)

add_executable(${PROJECT_NAME} src/3DCS_main.cpp src/3DCS_01.cpp)

#To add .h files for project hello world
#target_include_directories(${PROJECT_NAME} PUBLIC
#                           "${PROJECT_BINARY_DIR}"
#                            "${PROJECT_SOURCE_DIR/MathFunctionsLib}"
#                           )


#linking the libraries to the target
#target_link_libraries(${PROJECT_NAME} PUBLIC MathFunctions)
