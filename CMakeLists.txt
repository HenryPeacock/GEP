cmake_minimum_required(VERSION 2.6)
project(PEACOCKENGINE)

add_library(PeacockEngine
	src/PeacockEngine/dummy.cpp
	src/PeacockEngine/macros.h
)
target_link_libraries(PeacockEngine SDL2 opengl32 glew32)

add_executable(game
	src/game/main.cpp
)
target_link_libraries(game PeacockEngine)