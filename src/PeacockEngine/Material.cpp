#include "Material.h"
#include "Core.h"
#include "stb_image.h"
#include <fstream>

void Material::OnLoad(std::string _path)
{
	// Set the material attributes and bind create a texture
	m_materialAttributes = makesh<MaterialAttribute>();
	//m_materialAttributes->m_texture = GetCore()->m_context->createTexture();
	shared<rend::Texture> rtn = GetCore()->m_context->createTexture();
	
	int w = 0;
	int h = 0;
	int channels = 0;
	GLuint id = 0;
	unsigned char *data = stbi_load(_path.c_str(), &w, &h, &channels, 4);
	
	if (!data)
	{
		throw rend::Exception("Can't load image");
	}
	// Create and bind texture
	glGenTextures(1, &id);
	if (!id)
	{
		throw rend::Exception("Can't generate texture id");
	}
	glBindTexture(GL_TEXTURE_2D, id);
	// Upload the image data to the bound texture unit in the GPU
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	// Free the loaded data because we now have a copy on the GPU
	free(data);
	// Generate Mipmap so the texture can be mapped correctly
	glGenerateMipmap(GL_TEXTURE_2D);
	// Unbind the texture because we are done operating on it
	glBindTexture(GL_TEXTURE_2D, 0);
	
	TId = id;
	m_materialAttributes->m_texture = rtn;

	/*
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
	m_materialAttributes->m_texture->parse(data);
	*/
}
