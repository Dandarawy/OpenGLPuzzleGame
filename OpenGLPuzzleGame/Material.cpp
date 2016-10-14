#include "Material.h"

Material* Material::active = nullptr;

Material::Material(std::shared_ptr<sf::Shader> shader) :
	shader(shader)
{
}

Material::~Material()
{
}
void Material::Bind()
{
	if (active != this)
	{
		sf::Shader::bind(shader.get());
		if (textures.size() > 0)
		{
			GLuint i = 0;
			for (auto& itr : textures)
			{
				glActiveTexture(GL_TEXTURE0 + i);
				sf::Texture::bind(itr.second.get());
				GLint loc = glGetUniformLocation(shader->getNativeHandle(), itr.first.c_str());
				glUniform1i(loc, i++);
			}
		}
		else
			glBindTexture(GL_TEXTURE_2D, -1);
		active = this;
	}
}
