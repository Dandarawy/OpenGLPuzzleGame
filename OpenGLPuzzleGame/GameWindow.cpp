#include "GameWindow.h"
#include<glew\glew.h>
#include<iostream>



GameWindow::GameWindow(std::string title, int Width, int Height)
	:window(sf::VideoMode(Width, Height), title.c_str(), sf::Style::Close, sf::ContextSettings(24, 8, 4, 3, 3)),
	width(Width),
	height(Height)
{

}
void GameWindow::Run()
{
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		std::cout << "Initiakizeing GLEW Error";
		return;
	}

	std::cout << "\tUsing glew " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "\tVendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "\tRenderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "\tVersion: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "\tGLSL:" << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	Start();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return;
			}
			if (event.type == sf::Event::Resized)
			{
				glViewport(0, 0, event.size.width, event.size.height);
				this->width = event.size.width;
				this->height = event.size.height;
			}
		}
		sf::Time time = clock.restart();
		Update(time);
		Render(time);
		window.display();
	}
}

GameWindow::~GameWindow()
{
}
