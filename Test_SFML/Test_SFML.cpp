#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(520, 520), "SFML works!");

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
			//else if (event.type == sf::Event::Resized) {
			//	auto size = window.getSize();
			//	sf::Vector2f vec{ (size.x / 2.0f),(size.y / 2.0f) };
			//	shape.setPosition(vec);
			//	shape2.setPosition(vec);
			//}
		}

		window.clear();

		/*window.draw(shape);
		window.draw(shape2);*/

		window.draw(frame);

		window.display();
	}

	return 0;
}