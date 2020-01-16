#pragma once
#ifndef P_MESH_H
#define P_MESH_H

#include "Resource.h"
#include <rend/rend.h>
#include <string>


class PMesh : public Resource
{
public:
	void OnLoad(std::string _path);

private:
	friend class MeshRenderer;
	std::string m_path;
	shared<rend::Mesh> m_mesh;
};


#endif