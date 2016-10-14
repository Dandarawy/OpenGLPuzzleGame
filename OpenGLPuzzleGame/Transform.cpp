#include "Transform.h"

void Transform::UpdateModelMat()
{
	glm::mat4 scale_mat = glm::scale(scale);
	glm::mat4 translate_mat = glm::translate(position);
	glm::mat4 rotation_mat = glm::rotate(euler_angles.x, glm::vec3(1, 0, 0))*
		glm::rotate(euler_angles.y, glm::vec3(0, 1, 0))*
		glm::rotate(euler_angles.z, glm::vec3(0, 0, 1));
	model_mat = translate_mat*rotation_mat*scale_mat;
	is_mode_mat_dirty = false;
}

Transform::Transform() :
	scale(1.0f, 1.0f, 1.0f)
{
}


Transform::~Transform()
{
}
