#pragma once
#include <gl\glm\glm.hpp>
#include<gl\glm\gtx\transform.hpp>
class Transform
{
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 euler_angles;
	glm::mat4x4 model_mat;
	bool is_mode_mat_dirty;
	void update_model_mat();
public:
	Transform();
	~Transform();
	void translate(float tx, float ty, float tz)
	{
		position = glm::vec3(position.x + tx, position.y + ty, position.z + tz);
		is_mode_mat_dirty = true;
	}
	glm::vec3 get_position() const
	{
		return position;
	}
	void set_scale(float sx, float sy, float sz)
	{
		scale = glm::vec3(scale.x*sx, scale.y*sy, scale.z*sz);
		is_mode_mat_dirty = true;
	}
	void set_position(glm::vec3 pos)
	{
		this->position = pos;
		is_mode_mat_dirty = true;
	}
	glm::vec3 get_scale()const
	{
		return scale;
	}
	void set_euler_angles(glm::vec3 _angles)
	{
		euler_angles = _angles;
		is_mode_mat_dirty = true;
	}
	glm::vec3 get_euler_angles() const
	{
		return euler_angles;
	}
	glm::mat4 get_model_mat() {
		if (is_mode_mat_dirty)
			update_model_mat();
		return model_mat;
	}
};

