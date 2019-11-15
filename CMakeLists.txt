cmake_minimum_required(VERSION 2.6)
project(PEACOCKENGINE)

include_directories(src)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)
if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

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
	src/PeacockEngine/PeacockEngine.h
)
target_link_libraries(PeacockEngine SDL2 rend)

add_executable(game
	src/game/main.cpp
)
target_link_libraries(game PeacockEngine)