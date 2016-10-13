#pragma once
#include "GameWindow.h"
#include <SFML\Graphics\Shader.hpp>

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

};

