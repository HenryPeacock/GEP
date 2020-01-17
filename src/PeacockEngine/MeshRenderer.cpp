#include "MeshRenderer.h"
#include "PMesh.h"
#include "Material.h"
#include <fstream>
#include "Camera.h"

void MeshRenderer::OnInitialize(std::string _path)
{
	// Create the shader
	m_shader = GetCore()->m_context->createShader();

	// Open the shader from file
	std::cout << "Opening shader: " << _path << std::endl;
	std::ifstream f(_path.c_str());

	// Make sure the file is open
	if (!f.is_open())
	{
		throw rend::Exception("Failed to open shader");
	}

	std::string data;
	std::string line;

	// Save the file
	while (!f.eof())
	{
		std::getline(f, line);
		data += line + "\n";
	}

	// Parse the file data
	m_shader->parse(data);
}

void MeshRenderer::OnDisplay()
{

	//std::cout << "Renderer::onDisplay" << std::endl;

	m_shader->setMesh(m_mesh->m_mesh);
	m_shader->setUniform("u_Model", rend::mat4(1.0f));
	m_shader->setUniform("u_Model", rend::translate(rend::mat4(1.0f), rend::vec3(0, 0, GetCore()->m_move)));
	m_shader->setUniform("u_View", GetCore()->m_camera->GetView());
	m_shader->setUniform("u_Projection", rend::perspective(rend::radians(45.0f), 1.0f, 0.1f, 100.0f));
	//m_shader->setUniform("in_Texture", m_material->TId);
	m_shader->render();
}


