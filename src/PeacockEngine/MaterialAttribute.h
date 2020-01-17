#pragma once
#ifndef MATERIAL_ATTRIBUTE_H
#define MATERIAL_ATTRIBUTE_H
#include <string>
#include "rend/Texture.h"
#include "macros.h"

/**
 * Class containing the attributes which a material will need
 */
class MaterialAttribute
{
public:

private:
	friend class Material;

	std::string m_name; ///< Name
	int m_type; ///< Type
	float m_value; ///< Value
	weak<rend::Texture> m_texture; ///< Pointer to texture
};

#endif