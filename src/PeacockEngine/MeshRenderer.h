#pragma once
#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include "Core.h"
#include "Component.h"
#include "Entity.h"
#include "rend/rend.h"
#include <string>

/**
 * Class to render the models etc.
 */
class MeshRenderer : public Component
{
public:
	void OnInitialize(std::string _path); ///< When created, this sets it up
	void OnDisplay(); ///< function to display the models etc.

	shared<PMesh> GetMesh() { return m_mesh; }
	void SetMesh(shared<PMesh> _mesh) { m_mesh = _mesh; }
	shared<Material> GetMaterial() { return m_material; }
	void SetMaterial(shared<Material> _material) { m_material = _material; }
private:
	shared<PMesh> m_mesh; ///< Pointer to mesh
	shared<Material> m_material; ///< Pointer to material
	shared<rend::Shader> m_shader; ///< Pointer to shader


};



#endif