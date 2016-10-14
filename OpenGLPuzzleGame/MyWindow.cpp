#include "MyWindow.h"


MyWindow::MyWindow() :GameWindow("OpenGL Puzzle Game", 800, 600),
cam(glm::vec3(-4, 10, -4),glm::vec3(3,0,3),800.0f/600)
{
}


MyWindow::~MyWindow()
{
}

void MyWindow::Update(sf::Time dt)
{
	static float t = 0;
	static int fps = 0;
	fps++;
	t += dt.asSeconds();
	if (t > 1)
	{
		t -= 1;
		std::cout << "FPS: " << fps << std::endl;
		fps = 0;
	}
	elapsedTime += dt.asSeconds();

	skybox->transform.SetPosition(cam.GetPosition());
	skybox->transform.SetEulerAngles(glm::vec3(0, elapsedTime, 0));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		LoadMap();
	}
	if (player->GetState() == BlockState::Sationary)
	{

		int row = round(player->GetPosition().x);
		int col = round(player->GetPosition().z);
		if (map[row][col] == 2)
		{
			//Game Ended
			//Load Next Level
			LoadMap();
		}
	}
	if (player->GetState() == BlockState::Sationary)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			int row = round(player->GetPosition().x);
			int col = round(player->GetPosition().z);
			int target = 7;
			for (int z = col;z <8;z++)
				if (map[row][z] == 1) {
					target = z - 1;
					break;
				}
			player->MoveTo(glm::vec3(row, 1, target), 0.25f);
			
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			int row = round(player->GetPosition().x);
			int col = round(player->GetPosition().z);
			int target = 0;
			for (int z = col;z >= 0;z--)
				if (map[row][z] == 1) {
					target = z + 1;
					break;
				}
			player->MoveTo(glm::vec3(row, 1, target), 0.25f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			int row = round(player->GetPosition().x);
			int col = round(player->GetPosition().z);
			int target = 7;
			int movablePos = -1;
			for (int x = row;x < 8;x++)
				if (map[x][col] == 1) {
					target = x - 1;
					break;
				}
			player->MoveTo(glm::vec3(target, 1, col), 0.25f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			int row = round(player->GetPosition().x);
			int col = round(player->GetPosition().z);
			int target = 0;
			for (int x = row;x >= 0;x--)
				if (map[x][col] == 1) {
					target = x + 1;
					break;
				}
			player->MoveTo(glm::vec3(target, 1, col), 0.25f);
		}
	}



	player->Update(dt);
	for (auto& block : mapBlocks)
	{
		block.Update(dt);
	}
}


void MyWindow::Render(sf::Time dt)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	skybox->Render(cam.GetView(), cam.GetProj());
	glClear(GL_DEPTH_BUFFER_BIT);

	for (auto block : mapBlocks)
	{
		block.Render(cam);
	}

	player->Render(cam);
}

void MyWindow::Start()
{
	glClearColor(.192f, 0.302f, 0.475f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	std::shared_ptr<sf::Shader> unlitTextureShader = std::make_shared<sf::Shader>();
	unlitTextureShader->loadFromFile("UnlitTextureVS.glsl", "UnlitTextureFS.glsl");
	cubeGeometry = Geometry::Create_cube();


	std::shared_ptr<sf::Texture> blockTexture = loadTexture("images\\block.png");
	blockMat = std::make_shared<UnlitTextureMaterial>(unlitTextureShader);
	blockMat->AddTexture("color_map", blockTexture);
	blockMat->setTint(glm::vec3(0.5, 0.5, 0.5));

	mapMat = std::make_shared<UnlitTextureMaterial>(unlitTextureShader);
	mapMat->AddTexture("color_map", blockTexture);


	std::shared_ptr<sf::Texture> targetTexture = loadTexture("images\\target.png");
	targetMat = std::make_shared<UnlitTextureMaterial>(unlitTextureShader);
	targetMat->AddTexture("color_map", targetTexture);

	//player block
	std::shared_ptr<sf::Texture> playerTexture = loadTexture("images\\player.png");
	std::shared_ptr<UnlitTextureMaterial> playerMat = std::make_shared<UnlitTextureMaterial>(unlitTextureShader);
	playerMat->AddTexture("color_map", playerTexture);
	player = std::make_shared<Block>(cubeGeometry, playerMat);

	//Map Loading
	LoadMap();


	//creating skybox
	std::shared_ptr<sf::Shader> cubeMapShader = std::make_shared<sf::Shader>();
	cubeMapShader->loadFromFile("CubeMappingVS.glsl", "CubeMappingFS.glsl");;

	std::string cubMapImages[6] = {
		"images\\skybox\\0002.jpg",
		"images\\skybox\\0004.jpg",
		"images\\skybox\\0006.jpg",
		"images\\skybox\\0001.jpg",
		"images\\skybox\\0003.jpg",
		"images\\skybox\\0005.jpg"
	};
	std::shared_ptr<CubeMap> cubemap = CubeMap::Create(cubMapImages);
	std::shared_ptr<CubeMappingMaterial> skyboxMat = std::make_shared<CubeMappingMaterial>(cubeMapShader, cubemap);
	skybox = std::make_shared<Mesh>(cubeGeometry, skyboxMat);

}

std::shared_ptr<sf::Texture> MyWindow::loadTexture(std::string imageFileName)
{
	std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
	if (!texture->loadFromFile(imageFileName))
	{
		std::cout << "cannot load texture "<< imageFileName;
	}
	texture->setRepeated(true);
	texture->setSmooth(true);
	texture->generateMipmap();
	return texture;
}

void MyWindow::LoadMap()
{
	mapBlocks.clear();
	for (int x = 0;x < 8;x++)
	{
		for (int z = 0;z < 8;z++)
		{
			if (map[x][z] == 2)
			{
				Block block(cubeGeometry, targetMat, glm::vec3(x, 0, z));
				mapBlocks.push_back(block);
			}
			else
			{
				Block block(cubeGeometry, mapMat, glm::vec3(x, 0, z));
				mapBlocks.push_back(block);
			}

			if (map[x][z] == 1)
			{
				Block block(cubeGeometry, blockMat, glm::vec3(x, 0.5, z));
				block.MoveTo(glm::vec3(x, 1.0f, z), 0.5f);
				mapBlocks.push_back(block);
			}
		}
	}
	player->MoveTo(glm::vec3(0, 1.0f, 0), 0.5f);
}
