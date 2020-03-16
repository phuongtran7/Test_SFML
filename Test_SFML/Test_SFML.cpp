#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(520, 520), "Hello World!");

	sf::RectangleShape frame(sf::Vector2f(500, 500));
	frame.setOutlineColor(sf::Color::White);
	frame.setOutlineThickness(5.0f);
	frame.setFillColor(sf::Color(0,0,0,0));
	frame.setPosition(10, 10);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();

		window.draw(frame);

		window.display();
	}

	return 0;
}