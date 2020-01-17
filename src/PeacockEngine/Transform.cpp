#include "Transform.h"

glm::mat4 Transform::GetModel()
{
	// Make model into an identity matrix
	/*m_model = glm::mat4(1.0f);
	m_model = glm::translate(m_model,m_position);
	m_model = glm::rotate(m_model, m_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
	m_model = glm::rotate(m_model, m_rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	m_model = glm::rotate(m_model, m_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	m_model = glm::scale(m_model, m_scale);*/
	return m_model;
}
