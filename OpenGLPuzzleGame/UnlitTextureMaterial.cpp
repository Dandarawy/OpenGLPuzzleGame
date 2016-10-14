#include "UnlitTextureMaterial.h"




UnlitTextureMaterial::UnlitTextureMaterial(std::shared_ptr<sf::Shader> shader)
	:Material(shader), offset(0, 0), tilling(1, 1), tint(1, 1, 1)
{
}

void UnlitTextureMaterial::bind()
{
	Material::bind();
	GLuint offsetLoc = get_uniform_loc("offset");
	glUniform2fv(offsetLoc, 1, glm::value_ptr(offset));
	GLuint tillingLoc = get_uniform_loc("tilling");
	glUniform2fv(tillingLoc, 1, glm::value_ptr(tilling));
	GLuint tintLoc = get_uniform_loc("tint");
	glUniform3fv(tintLoc, 1, glm::value_ptr(tint));
}

UnlitTextureMaterial::~UnlitTextureMaterial()
{
}
