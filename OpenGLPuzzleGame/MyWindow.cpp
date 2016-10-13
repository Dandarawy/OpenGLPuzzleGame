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
}


void MyWindow::Render(sf::Time dt)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES,0,6);
}

void MyWindow::Start()
{

	glClearColor(.192f, 0.302f, 0.475f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	
	sf::Shader shader;
	shader.loadFromFile("vertexShader.glsl", "fragmentShader.glsl");
	sf::Shader::bind(&shader);

	GLuint vao, vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	float vertices[18] = {
		-1,1,0,
		-1,-1,0,
		1,-1,0,

		-1,1,0,
		1,-1,0,
		1,1,0
	};
	GLuint vertexPositionLoc = glGetAttribLocation(shader.getNativeHandle(), "vertex_position");
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(vertexPositionLoc, 3, GL_FLOAT, true, 3 * sizeof(float), 0);
	glEnableVertexAttribArray(vertexPositionLoc);
}
