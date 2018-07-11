#pragma once
#include <glm\glm.hpp>
#include<glm\gtx\transform.hpp>
class Transform
{
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 euler_angles;
	glm::mat4x4 model_mat;
	bool is_mode_mat_dirty;
	void UpdateModelMat();
public:
	Transform();
	~Transform();
	void Translate(float tx, float ty, float tz)
	{
		position = glm::vec3(position.x + tx, position.y + ty, position.z + tz);
		is_mode_mat_dirty = true;
	}
	glm::vec3 GetPosition() const
	{
		return position;
	}
	void SetScale(float sx, float sy, float sz)
	{
		scale = glm::vec3(scale.x*sx, scale.y*sy, scale.z*sz);
		is_mode_mat_dirty = true;
	}
	void SetPosition(glm::vec3 pos)
	{
		this->position = pos;
		is_mode_mat_dirty = true;
	}
	glm::vec3 GetScale()const
	{
		return scale;
	}
	void SetEulerAngles(glm::vec3 _angles)
	{
		euler_angles = _angles;
		is_mode_mat_dirty = true;
	}
	glm::vec3 GetEulerAngles() const
	{
		return euler_angles;
	}
	glm::mat4 get_model_mat() {
		if (is_mode_mat_dirty)
			UpdateModelMat();
		return model_mat;
	}
};

