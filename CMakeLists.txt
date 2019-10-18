cmake_minimum_required(VERSION 2.6)
project(PEACOCKENGINE)

add_library(PeacockEngine
	src/PeacockEngine/macros.h
	src/PeacockEngine/Entity.h
	src/PeacockEngine/Component.h
	src/PeacockEngine/Core.h
	src/PeacockEngine/Keyboard.h
	src/PeacockEngine/Environment.h
	src/PeacockEngine/Entity.cpp
	src/PeacockEngine/Core.cpp
	src/PeacockEngine/Component.cpp
	src/PeacockEngine/Keyboard.cpp
	src/PeacockEngine/Environment.cpp
)
target_link_libraries(PeacockEngine SDL2 opengl32 glew32)

add_executable(game
	src/game/main.cpp
)
target_link_libraries(game PeacockEngine)