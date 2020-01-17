#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Core.h"


class Transform
{
public:
	// Getters and setters
	glm::vec3 GetPosition() { return m_position; }
	void SetPosition(glm::vec3 _position) { m_position = _position; }
	//
	glm::vec3 GetRotation() { return m_rotation; }
	void SetRotation(glm::vec3 _rotation) { m_rotation = _rotation; }
	//
	glm::vec3 GetScale() { return m_scale; }
	void SetScale(glm::vec3 _scale) { m_scale = _scale; }
	//
	glm::mat4 GetModel();
private:
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;
	glm::mat4 m_model;
};


#endif