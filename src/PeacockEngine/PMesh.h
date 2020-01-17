#pragma once
#ifndef P_MESH_H
#define P_MESH_H

#include "Resource.h"
#include <rend/rend.h>
#include <string>

/**
 * Engine side mesh system, not using rend directly
 */
class PMesh : public Resource
{
public:
	void OnLoad(std::string _path); ///< Function to be ran when loaded, sets up the mesh systems and loads file

private:
	friend class MeshRenderer;
	std::string m_path;
	shared<rend::Mesh> m_mesh; ///< Pointer to the mesh system in rend
};


#endif