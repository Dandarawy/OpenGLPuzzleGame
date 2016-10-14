#include "Mesh.h"


Mesh::Mesh(std::shared_ptr<Geometry> geometry, std::shared_ptr<Material> material) :
	transform(),
	material(material),
	geometry(geometry)
{

}

void Mesh::Render(glm::mat4 view_mat, glm::mat4 proj_mat)
{
	material->bind();
	geometry->Bind();
	GLuint mvp = material->get_uniform_loc("mvp_mat");
	glUniformMatrix4fv(mvp, 1, GL_FALSE, glm::value_ptr(proj_mat*view_mat*transform.get_model_mat()));
	GLuint model_mat_location = material->get_uniform_loc("model_mat");
	glUniformMatrix4fv(model_mat_location, 1, GL_FALSE, glm::value_ptr(transform.get_model_mat()));
	GLuint view_mat_location = material->get_uniform_loc("view_mat");
	glUniformMatrix4fv(view_mat_location, 1, GL_FALSE, glm::value_ptr(view_mat));
	GLuint proj_mat_location = material->get_uniform_loc("proj_mat");
	glUniformMatrix4fv(proj_mat_location, 1, GL_FALSE, glm::value_ptr(proj_mat));
	glDrawElements(GL_TRIANGLES, geometry->GetIndicesCount(), GL_UNSIGNED_INT, NULL);
}

Mesh::~Mesh()
{
}
