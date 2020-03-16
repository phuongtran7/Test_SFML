#include <SFML/Graphics.hpp>
#include <iostream>

constexpr float PI = 3.14159265f;

int main()
{
	float ballSpeed = 0.2f;
	float ballAngleRad = 90 * (PI / 180);
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(520, 520), "Hello World!");

	sf::RectangleShape frame(sf::Vector2f(500, 500));
	frame.setOutlineColor(sf::Color::White);
	frame.setOutlineThickness(5.0f);
	frame.setFillColor(sf::Color(0,0,0,0));
	frame.setPosition(10, 10);

	auto frame_bound = frame.getGlobalBounds();
	frame_bound.top += 5;
	frame_bound.left += 5;
	frame_bound.height -= 5;

	sf::CircleShape ball(50.0f);
	ball.setFillColor(sf::Color::Green);
	ball.setPosition(250, 250);

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

		auto bound = ball.getGlobalBounds();
		bool result = frame_bound.contains(bound.top, bound.top + bound.height);
		if (!result)
		{
			ballAngleRad = -ballAngleRad;
		}

		double elapsed = clock.restart().asMilliseconds();
		elapsed = 0.1;
		auto new_x = elapsed * ballSpeed * std::cos(ballAngleRad);
		auto new_y = elapsed * ballSpeed * std::sin(ballAngleRad);
		ball.move(new_x, new_y);

		window.draw(frame);
		window.draw(ball);

		window.display();
	}

	return 0;
}