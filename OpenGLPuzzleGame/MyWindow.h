#pragma once
#include "GameWindow.h"
#include <SFML\Graphics\Shader.hpp>
#include <memory>
#include "Geometry.h"
#include<gl\glm\glm.hpp>
#include<gl\glm\gtc\type_ptr.hpp>
#include<gl\glm\gtx\transform.hpp>

#include "UnlitTextureMaterial.h"
class MyWindow :
	public GameWindow
{
public:
	MyWindow();
	~MyWindow();
	void Update(sf::Time dt) override;
	void Render(sf::Time dt) override;
	void Start() override;
	std::shared_ptr<sf::Texture> loadTexture(std::string imageFileName);
private:
	std::shared_ptr<Geometry> cubeGeometry;
	std::shared_ptr<sf::Shader> unlitTextureShader;
	float elapsedTime = 0;
	glm::mat4 view_mat;
	glm::mat4 proj_mat;
	std::shared_ptr<UnlitTextureMaterial> material1, material2;
};

