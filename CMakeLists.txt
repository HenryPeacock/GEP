cmake_minimum_required(VERSION 2.6)
project(PEACOCKENGINE)

include_directories(src)

add_library(rend
  src/rend/Exception.h
  src/rend/Context.h
  src/rend/Texture.h
  src/rend/RenderTexture.h
  src/rend/Shader.h
  src/rend/Buffer.h
  src/rend/Mesh.h
  src/rend/Util.h
  src/rend/TextureAdapter.h

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
  target_link_libraries(rend glew32 opengl32 openal32)
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
	src/PeacockEngine/PeacockEngine.h
	src/PeacockEngine/MeshRenderer.h
	src/PeacockEngine/Transform.h
	src/PeacockEngine/Camera.h
	src/PeacockEngine/Resource.h
	src/PeacockEngine/Resources.h
	src/PeacockEngine/PMesh.h
	src/PeacockEngine/Material.h
	src/PeacockEngine/MaterialAttribute.h
	src/PeacockEngine/Sound.h
	src/PeacockEngine/SoundSource.h
	src/PeacockEngine/SoundManager.h
	src/PeacockEngine/stb_vorbis.h
	src/PeacockEngine/stb_image.h

	src/PeacockEngine/Entity.cpp
	src/PeacockEngine/Core.cpp
	src/PeacockEngine/Component.cpp
	src/PeacockEngine/Keyboard.cpp
	src/PeacockEngine/Environment.cpp
	src/PeacockEngine/MeshRenderer.cpp
	src/PeacockEngine/Transform.cpp
	src/PeacockEngine/Camera.cpp
	src/PeacockEngine/Resource.cpp
	src/PeacockEngine/Resources.cpp
	src/PeacockEngine/PMesh.cpp
	src/PeacockEngine/Material.cpp
	src/PeacockEngine/MaterialAttribute.cpp
	src/PeacockEngine/Sound.cpp
	src/PeacockEngine/SoundSource.cpp
	src/PeacockEngine/SoundManager.cpp
)
target_link_libraries(PeacockEngine SDL2 rend)

add_executable(game
	src/game/main.cpp
)
target_link_libraries(game PeacockEngine)