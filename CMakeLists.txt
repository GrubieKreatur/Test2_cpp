

# Pfad zur SFML-Installation
set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML-3.0.0/lib/cmake/SFML")

# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(Test2_cpp)

find_package(SFML 3.0 REQUIRED Graphics Window System)
# Include SFML headers
include_directories(./SFML-3.0.0/include)

include_directories(${SFML_INCLUDE_DIR})

add_executable(Test2_cpp main.cpp Game.cpp Bot.cpp GUI.cpp)

target_link_libraries(Test2_cpp sfml-Graphics sfml-window sfml-system)
