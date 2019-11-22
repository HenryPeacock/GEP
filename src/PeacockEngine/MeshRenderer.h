#pragma once
#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include "Component.h"

namespace Peacock
{
	class MeshRenderer : public Component
	{
		void onDisplay();
	};
}


#endif