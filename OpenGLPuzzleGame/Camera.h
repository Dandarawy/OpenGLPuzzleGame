#pragma once
#include <gl\glm\glm.hpp>
#include<gl\glm\gtx\transform.hpp>
enum class PROJECTION_TYPE
{
	ORTHOGRAPHIC,
	PERSPECTIVE
};
class Camera
{
protected:
	//view
	glm::vec3 position;
	glm::vec3 target;
	glm::mat4 view_mat;
	bool is_view_dirty;
	//proj
	float z_near;
	float z_far;
	float aspect_ratio;
	//orthographic
	float height;
	//perspectvie
	float fov;
	glm::mat4 proj_mat;
	bool is_proj_dirty;
	PROJECTION_TYPE projection_type;
public:
	Camera(glm::vec3 position, glm::vec3 target, float _aspect_ratio 
		, PROJECTION_TYPE _projection_type = PROJECTION_TYPE::PERSPECTIVE
		);
	~Camera();
	void SetPosition(glm::vec3 _position);
	void SetTarget(glm::vec3 _position);
	glm::mat4 GetView();
	glm::mat4 GetProj();
	glm::vec3 GetPosition() const { return position; }
	glm::vec3 GetTarget() const { return target; }
};

