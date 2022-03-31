cmake_minimum_required(VERSION 3.21)
project(shashki_1c)

set(CMAKE_CXX_STANDARD 17)

add_executable(shashki_1c main.cpp src/Game/Game.cpp src/Game/Game.h src/Tools/Tools.cpp src/Tools/Tools.h src/Payload/Board.cpp src/Payload/Board.h src/Tools/IO.cpp src/Tools/IO.h src/Payload/Turn.cpp src/Payload/Turn.h src/GameBot/GameBot.cpp src/GameBot/GameBot.h)

include_directories(src)
#target_include_directories(shashki_1c Tools)
