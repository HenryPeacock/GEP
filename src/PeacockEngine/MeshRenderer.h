#pragma once
#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include "Core.h"
#include "Component.h"
#include "Entity.h"
#include "rend/rend.h"
#include <string>


class MeshRenderer : public Component
{
public:
	void OnInitialize(std::string _path);
	void OnDisplay();

	shared<PMesh> GetMesh() { return m_mesh; }
	void SetMesh(shared<PMesh> _mesh) { m_mesh = _mesh; }
	shared<Material> GetMaterial() { return m_material; }
	void SetMaterial(shared<Material> _material) { m_material = _material; }
private:
	shared<PMesh> m_mesh;
	shared<Material> m_material;
	shared<rend::Shader> m_shader;


};



#endif