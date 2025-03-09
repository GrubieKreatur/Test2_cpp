

# Pfad zur SFML-Installation
set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML-2.6.2/lib/cmake/SFML")

# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(Test2_cpp)

find_package(SFML 2.6 REQUIRED graphics window system)
# Include SFML headers
include_directories(./SFML-2.6.2/include)

include_directories(${SFML_INCLUDE_DIR})

add_executable(Test2_cpp main.cpp MainMenu.cpp
        TicTacToeView.cpp
        Player.h
        HumanPlayer.h
        EasyBotPlayer.h
        NormalBotSpieler.cpp
        HardBotPlayer.cpp
        GameUtility.h)

target_link_libraries(Test2_cpp sfml-graphics sfml-window sfml-system)
