#pragma once
#include <SFML\Graphics\Shader.hpp>
#include <memory>
#include<gl\glm\glm.hpp>
#include<gl\glm\gtc\type_ptr.hpp>
#include<gl\glm\gtx\transform.hpp>

#include "GameWindow.h"
#include "UnlitTextureMaterial.h"
#include "Mesh.h"
#include "Camera.h"
#include "CubeMappingMaterial.h"
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
	float elapsedTime = 0;
	Camera cam;
	std::vector<Mesh> cubes;
	std::shared_ptr<Mesh> skybox;
};

