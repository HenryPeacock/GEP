#pragma once
#ifndef MATERIAL_H
#define MATERIAL_H

#include <vector>
#include "rend/Shader.h"
#include "rend/Texture.h"
#include "MaterialAttribute.h"
#include "Resource.h"
#include "macros.h"


class Material : public Resource
{
public:
	void OnLoad(std::string _path);


	GLuint TId;
private:
	shared<MaterialAttribute> m_materialAttributes;
};


#endif