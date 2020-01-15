#pragma once
#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include "Core.h"
#include "Component.h"
#include "Entity.h"
#include "rend/rend.h"

namespace Peacock
{
	class MeshRenderer : public Component
	{
	public:
		void onInitialize();
		void onDisplay();
	private:
		shared<rend::Shader> m_shader;

	};
}


#endif