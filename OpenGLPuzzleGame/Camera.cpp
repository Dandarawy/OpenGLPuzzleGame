#include "Camera.h"


Camera::Camera(glm::vec3 position, glm::vec3 target,
	float _aspect_ratio,PROJECTION_TYPE _projection_type) :
	position( position ),
	target(target),
	fov(45),
	is_view_dirty( true ),
	is_proj_dirty( true ),
	aspect_ratio( _aspect_ratio ),
	height( 5 ),
	z_near( 0.1f ),
	z_far( 100 ),
	projection_type( _projection_type )
{

}

glm::mat4 Camera::GetView()
{
	if (is_view_dirty)
	{
		view_mat = glm::lookAt(position, target, glm::vec3(0,1,0));
		is_view_dirty = false;
	}
	return view_mat;
}

glm::mat4 Camera::GetProj()
{
	if (is_proj_dirty)
	{
		switch (projection_type)
		{
		case PROJECTION_TYPE::ORTHOGRAPHIC:
			proj_mat = glm::ortho((aspect_ratio*height) / -2.0f, (aspect_ratio*height) / 2.0f,
				-height / 2.0f, height / 2, z_near, z_far);
			break;
		default:
			proj_mat = glm::perspectiveFov(fov, height*aspect_ratio, height, z_near, z_far);
			break;
		}
		is_proj_dirty = false;
	}
	return proj_mat;
}
void Camera::SetPosition(glm::vec3 _position)
{
	position = _position;
	is_view_dirty = true;
}

void Camera::SetTarget(glm::vec3 target)
{
	this->target = target;
	is_view_dirty = true;
}

Camera::~Camera()
{
}
