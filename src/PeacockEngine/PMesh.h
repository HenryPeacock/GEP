#pragma once
#ifndef P_MESH_H
#define P_MESH_H

#include "Core.h"

namespace Peacock
{
	class PMesh
	{
	public:
		void onLoad(std::string _path);

	private:
		friend class MeshRenderer;
		std::string m_path;
		shared<rend::Mesh> m_mesh;
	};
}

#endif