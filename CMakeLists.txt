cmake_minimum_required(VERSION 3.16)
project(LDSV LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")  # Qt path si lo instalaste por brew

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_subdirectory(src)
