cmake_minimum_required(VERSION 3.0)

project(GraphicsProject)
set (CMAKE_CXX_STANDARD 11)
include_directories(include)
link_directories(lib)
file(GLOB SOURCES cppk/*)
link_libraries(graphics SDL2 SDL2_ttf)

add_executable(GraphicsProject main.cpp ${SOURCES})
