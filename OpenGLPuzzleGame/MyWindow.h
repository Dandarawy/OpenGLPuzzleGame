#pragma once
#include <fstream>
#include <memory>

#include <SFML\Graphics\Shader.hpp>
#include<glm\glm.hpp>
#include<glm\gtc\type_ptr.hpp>
#include<glm\gtx\transform.hpp>

#include "GameWindow.h"
#include "UnlitTextureMaterial.h"
#include "Mesh.h"
#include "Camera.h"
#include "CubeMappingMaterial.h"
#include "Block.h"
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
	int map[8][8] = {
		{ 0,0,0,0,1,0,0,1 },
		{ 2,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,1,0 },
		{ 1,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,1,0,0,0,1 },
		{ 0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,0,0,0,0 }
	};
	float elapsedTime = 0;
	int currentLevel = 1;
	Camera cam;
	std::vector<Block> mapBlocks;
	std::shared_ptr<Block> player;
	std::shared_ptr<Mesh> skybox;
	std::shared_ptr<Geometry> cubeGeometry;
	std::shared_ptr<UnlitTextureMaterial> blockMat;
	std::shared_ptr<UnlitTextureMaterial> mapMat;
	std::shared_ptr<UnlitTextureMaterial> targetMat;
	void LoadMap();
	void FillMapFromFile(std::string filename);
};

