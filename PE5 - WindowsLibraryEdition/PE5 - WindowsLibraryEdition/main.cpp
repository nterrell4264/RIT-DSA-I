//Nathan Terrell
//Section 01

#include "stdafx.h"
#define SFML_STATIC
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;


int main()
{
	RenderWindow window(sf::VideoMode(800, 600), "Test window");
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		CircleShape eye1(25);
		eye1.setFillColor(Color(0, 127, 255));

		CircleShape eye2(25);
		eye2.setPosition(Vector2f(100, 0));
		eye2.setFillColor(Color(255, 0, 127));

		RectangleShape mouth(Vector2f(150, 50));
		mouth.setPosition(Vector2f(0, 100));

		window.clear(Color::Black);
		window.draw(eye1);
		window.draw(eye2);
		window.draw(mouth);
		window.display();
	}

    return 0;
}

