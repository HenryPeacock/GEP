#include "Material.h"
#include "Core.h"
#include <fstream>

void Material::OnLoad(std::string _path)
{
	// Set the material attributes and bind create a texture
	m_materialAttributes = makesh<MaterialAttribute>();
	m_materialAttributes->m_texture = GetCore()->m_context->createTexture();

	// Open the texture from file
	std::cout << "Opening texture: " << _path << std::endl;
	std::ifstream f(_path.c_str());

	// Make sure the file is open
	if (!f.is_open())
	{
		throw rend::Exception("Failed to open texture");
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
	//m_materialAttributes->m_texture->parse(data);
}
