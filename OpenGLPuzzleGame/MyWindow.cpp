#include "MyWindow.h"


MyWindow::MyWindow() :GameWindow("OpenGL Puzzle Game", 800, 600)
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

	view_mat = glm::lookAt(glm::vec3(x, 8.0f, z), glm::vec3(), glm::vec3(0, 1, 0));
	proj_mat = glm::perspective(45.0f, width*1.0f / height, 0.1f, 100.0f);
}


void MyWindow::Render(sf::Time dt)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (auto cube : cubes)
	{
		cube.Render(view_mat, proj_mat);
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
	material1->add_texture("color_map", texture1);


	std::shared_ptr<sf::Texture> texture2 = loadTexture("images\\target.png");
	std::shared_ptr<UnlitTextureMaterial> material2 = std::make_shared<UnlitTextureMaterial>(unlitTextureShader);
	material2->add_texture("color_map", texture2);

	cubes.push_back(Mesh(cubeGeometry, material1));
	cubes.push_back(Mesh(cubeGeometry, material1));
	cubes.push_back(Mesh(cubeGeometry, material2));
	cubes.push_back(Mesh(cubeGeometry, material2));

	cubes[0].transform.set_position(glm::vec3(1, 0, 1));
	cubes[1].transform.set_position(glm::vec3(1, 0, -1));
	cubes[2].transform.set_position(glm::vec3(-1, 0, 1));
	cubes[3].transform.set_position(glm::vec3(-1, 0, -1));

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
