#pragma once
#ifndef MATERIAL_H
#define MATERIAL_H

#include <vector>
#include "rend/Shader.h"
#include "rend/Texture.h"
#include "MaterialAttribute.h"
#include "Resource.h"
#include "macros.h"

/**
 * Class containing the material for an object
 */
class Material : public Resource
{
public:
	void OnLoad(std::string _path); ///< Function to be called when material is loaded


	GLuint TId;
private:
	shared<MaterialAttribute> m_materialAttributes; ///< pointer to the material's attributes
};


#endif