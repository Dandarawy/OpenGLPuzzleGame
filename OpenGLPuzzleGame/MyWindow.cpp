#include "MyWindow.h"


MyWindow::MyWindow() :GameWindow("OpenGL Puzzle Game", 800, 600),
cam(glm::vec3(8, 8, 0),glm::vec3(),800.0f/600)
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
	float x = 8 * sin(elapsedTime);
	float z = 8 * cos(elapsedTime);
	cam.SetPosition(glm::vec3(x, 8, z));

	skybox->transform.SetPosition(cam.GetPosition());
}


void MyWindow::Render(sf::Time dt)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	skybox->Render(cam.GetView(), cam.GetProj());
	glClear(GL_DEPTH_BUFFER_BIT);

	for (auto cube : cubes)
	{
		cube.Render(cam.GetView(), cam.GetProj());
	}
}

void MyWindow::Start()
{
	glClearColor(.192f, 0.302f, 0.475f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	std::shared_ptr<sf::Shader> unlitTextureShader = std::make_shared<sf::Shader>();
	unlitTextureShader->loadFromFile("UnlitTextureVS.glsl", "UnlitTextureFS.glsl");
	std::shared_ptr<Geometry> cubeGeometry = Geometry::Create_cube();

	std::shared_ptr<sf::Texture> texture1 = loadTexture("images\\block.png");
	std::shared_ptr<UnlitTextureMaterial> material1 = std::make_shared<UnlitTextureMaterial>(unlitTextureShader);
	material1->AddTexture("color_map", texture1);


	std::shared_ptr<sf::Texture> texture2 = loadTexture("images\\target.png");
	std::shared_ptr<UnlitTextureMaterial> material2 = std::make_shared<UnlitTextureMaterial>(unlitTextureShader);
	material2->AddTexture("color_map", texture2);

	cubes.push_back(Mesh(cubeGeometry, material1));
	cubes.push_back(Mesh(cubeGeometry, material1));
	cubes.push_back(Mesh(cubeGeometry, material2));
	cubes.push_back(Mesh(cubeGeometry, material2));

	cubes[0].transform.SetPosition(glm::vec3(1, 0, 1));
	cubes[1].transform.SetPosition(glm::vec3(1, 0, -1));
	cubes[2].transform.SetPosition(glm::vec3(-1, 0, 1));
	cubes[3].transform.SetPosition(glm::vec3(-1, 0, -1));

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
