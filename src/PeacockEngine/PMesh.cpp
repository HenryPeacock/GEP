#include "PMesh.h"
#include "Core.h"

#include <fstream>

void PMesh::OnLoad(std::string _path)
{
	// Create the mesh
	m_mesh = GetCore()->m_context->createMesh();

	// Set the path, adding a .obj to it
	m_mesh->SetPath(_path + ".obj");
	
	// Open the model file
	std::cout << "Opening model: " << m_mesh->GetPath() << std::endl;
	std::ifstream f(m_mesh->GetPath().c_str());

	// Check that it opened
	if (!f.is_open())
	{
		throw rend::Exception("Failed to open model");
	}

	std::string data;
	std::string line;
	
	// Save the object data
	while(!f.eof())
	{
		std::getline(f, line);
		data += line + "\n";
	}

	// Parse the object data
	m_mesh->parse(data);
}
