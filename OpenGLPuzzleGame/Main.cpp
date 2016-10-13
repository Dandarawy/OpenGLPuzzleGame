
#pragma comment(lib,"sfml-window-s-d.lib" )
#pragma comment(lib,"sfml-system-s-d.lib" )
#pragma comment(lib,"sfml-graphics-s-d.lib" )
#pragma comment(lib,"jpeg.lib" )
#pragma comment(lib,"opengl32.lib" )
#pragma comment(lib,"winmm.lib" )
#pragma comment(lib,"glew32s.lib")

#include <SFML/Graphics.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}