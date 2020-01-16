#pragma once
#ifndef MESH_RENDERER_H
#define MESH_RENDERER_H

#include "Core.h"
#include "Component.h"
#include "Entity.h"
#include "rend/rend.h"


class MeshRenderer : public Component
{
public:
	void OnInitialize();
	void OnDisplay();

	shared<PMesh> GetMesh() { return m_mesh; }
	void SetMesh(shared<PMesh> _mesh) { m_mesh = _mesh; }
private:
	shared<PMesh> m_mesh;

	shared<rend::Shader> m_shader;

};



#endif