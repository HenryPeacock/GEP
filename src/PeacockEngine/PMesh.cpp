#include "PMesh.h"
#include "Core.h"

#include <fstream>

void PMesh::OnLoad(std::string _path)
{
	m_mesh = GetCore()->m_context->createMesh();

	// ToDo: Check if this matters
	m_mesh->SetPath(_path + ".obj");
	
	std::cout << "Opening model: " << m_mesh->GetPath() << std::endl;
	std::ifstream f(m_mesh->GetPath().c_str());

	if (!f.is_open())
	{
		throw rend::Exception("Failed to open model");
	}

	std::string data;
	std::string line;

	while(!f.eof())
	{
		std::getline(f, line);
		data += line + "\n";
	}

	m_mesh->parse(data);
}
