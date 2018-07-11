#pragma once
#include <glew\glew.h>
#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include <memory>
#include <string>
#include<glm\glm.hpp>
#include<glm\gtc\type_ptr.hpp>
#include<glm\gtx\transform.hpp>
class Material
{
private:
	std::shared_ptr<sf::Shader> shader;
	std::map<std::string, std::shared_ptr< sf::Texture>> textures;
	//bool active = false;
	static Material* active;
public:
	Material(std::shared_ptr<sf::Shader> shader);
	~Material();
	virtual void Bind();
	GLuint GetUniformLoc(std::string uniform)
	{
		return glGetUniformLocation(shader->getNativeHandle(), uniform.c_str());
	}
	GLuint GetAttribLoc(std::string attrib)
	{
		return glGetAttribLocation(shader->getNativeHandle(), attrib.c_str());
	}
	void AddTexture(std::string tex_uniform_name, std::shared_ptr< sf::Texture> _texture)
	{
		//if the tex_uniform_name exists it will be overwrite otherwise it will be added
		textures[tex_uniform_name] = _texture;
	}
};