# cmake_minimum_required(VERSION <specify CMake version here>)
project(test)

set(CMAKE_CXX_STANDARD 11)

add_executable(test main.cpp)

add_subdirectory(lib/glfw)
include_directories(lib/glfw/include)
target_link_libraries(test glfw ${GLFW_LIBRARIES})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(OpenGL REQUIRED)
target_link_libraries(test OpenGL::GL)