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

	sf::CircleShape ball(50.0f);
	ball.setFillColor(sf::Color::Green);
	ball.setPosition(100, 100);

	auto frame_bound = frame.getGlobalBounds();

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

		if (ball.getPosition().y + 50 > 500)
		{
			ballAngleRad = -ballAngleRad;
		}

		if (ball.getPosition().y - 50 < 0)
		{
			ballAngleRad = -ballAngleRad;
		}

		double elapsed = clock.restart().asMilliseconds();
		auto new_x = elapsed * ballSpeed * std::cos(ballAngleRad);
		auto new_y = elapsed * ballSpeed * std::sin(ballAngleRad);
		std::cout << new_x << ", " << new_y << "\n";
		ball.move(new_x, new_y);

		window.draw(frame);
		window.draw(ball);

		window.display();
	}

	return 0;
}