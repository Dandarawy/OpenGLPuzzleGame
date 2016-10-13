#pragma once
#include<string>
#include <SFML/Graphics.hpp>
#include <glew\glew.h>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <memory>

class GameWindow
{
protected:
	sf::Window window;
	sf::Clock clock;
	int width, height;
public:
	GameWindow(std::string title, int Width, int Height);
	GameWindow(const GameWindow& window) = delete;
	GameWindow& operator=(const GameWindow& window) = delete;
	void Run();
	virtual void Start() {}
	virtual void Update(sf::Time dt) = 0;
	virtual void Render(sf::Time dt) = 0;
	virtual ~GameWindow();
	int getWidth()const { return width; }
	int getHeight()const { return height; }
};

