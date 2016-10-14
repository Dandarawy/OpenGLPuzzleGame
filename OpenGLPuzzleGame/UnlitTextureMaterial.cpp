#include "UnlitTextureMaterial.h"




UnlitTextureMaterial::UnlitTextureMaterial(std::shared_ptr<sf::Shader> shader)
	:Material(shader), offset(0, 0), tilling(1, 1), tint(1, 1, 1)
{
}

void UnlitTextureMaterial::Bind()
{
	Material::Bind();
	GLuint offsetLoc = GetUniformLoc("offset");
	glUniform2fv(offsetLoc, 1, glm::value_ptr(offset));
	GLuint tillingLoc = GetUniformLoc("tilling");
	glUniform2fv(tillingLoc, 1, glm::value_ptr(tilling));
	GLuint tintLoc = GetUniformLoc("tint");
	glUniform3fv(tintLoc, 1, glm::value_ptr(tint));
}

UnlitTextureMaterial::~UnlitTextureMaterial()
{
}
