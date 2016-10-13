#pragma once
#include "GameWindow.h"
#include <SFML\Graphics\Shader.hpp>
#include <memory>
#include "Geometry.h"
#include<gl\glm\glm.hpp>
#include<gl\glm\gtc\type_ptr.hpp>
#include<gl\glm\gtx\transform.hpp>
class MyWindow :
	public GameWindow
{
public:
	MyWindow();
	~MyWindow();
	void Update(sf::Time dt) override;
	void Render(sf::Time dt) override;
	void Start() override;
private:
	std::shared_ptr<Geometry> cubeGeometry;
	sf::Shader normalColorShader;
	float elapsedTime = 0;
	glm::mat4 view_mat;
	glm::mat4 proj_mat;
};

