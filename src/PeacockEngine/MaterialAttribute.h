#pragma once
#ifndef MATERIAL_ATTRIBUTE_H
#define MATERIAL_ATTRIBUTE_H
#include <string>
#include "rend/Texture.h"
#include "macros.h"


class MaterialAttribute
{
public:

private:
	friend class Material;

	std::string m_name;
	int m_type;
	float m_value;
	weak<rend::Texture> m_texture;
};

#endif