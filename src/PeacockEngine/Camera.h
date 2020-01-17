#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include "Transform.h"
#include "macros.h"
#include "Component.h"
#include <glm/glm.hpp>


class Camera
{
public:


	glm::mat4 GetProjection() { return m_projection; }
	glm::mat4 GetView() { return glm::inverse(m_transform.GetModel()); }

	Transform m_transform;
private:
	friend class Core;
	weak<Core> m_core;
	glm::mat4 m_projection;
};

#endif