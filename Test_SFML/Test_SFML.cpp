#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

constexpr float PI = 3.14159265f;
std::random_device dev;
std::mt19937 rng(dev());

double getNewAngle() {
	std::uniform_real_distribution<> dist(0, 359);
	return dist(rng);
}

sf::Color getNewColor() {
	std::uniform_int_distribution<> dist(0, 255);
	return sf::Color(dist(rng), dist(rng), dist(rng));
}

int main()
{
	float ballSpeed = 0.2f;
	float ballAngleRad = getNewAngle() * (PI / 180);
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(520, 520), "Hello World!");

	sf::RectangleShape frame(sf::Vector2f(500, 500));
	frame.setOutlineColor(sf::Color::White);
	frame.setOutlineThickness(5.0f);
	frame.setFillColor(sf::Color(0,0,0,0));
	frame.setPosition(10, 10);

	auto frame_bound = frame.getGlobalBounds();

	sf::CircleShape ball(50.0f);
	ball.setFillColor(sf::Color::Green);
	ball.setPosition(100, 100);

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
		bool is_inside = frame_bound.contains(bound.left, bound.top)
			&& frame_bound.contains(bound.left + bound.width, bound.top)
			&& frame_bound.contains(bound.left, bound.top + bound.height)
			&& frame_bound.contains(bound.left + bound.width, bound.top + bound.height);

		if (!is_inside)
		{
			ballAngleRad = getNewAngle();
			ball.setFillColor(getNewColor());
		}

		auto new_x_offset = ballSpeed * std::cos(ballAngleRad);
		auto new_y_offset = ballSpeed * std::sin(ballAngleRad);
		//std::cout << new_x_offset << ", " << new_y_offset << "\n";
		ball.move(new_x_offset, new_y_offset);

		window.draw(frame);
		window.draw(ball);

		window.display();
	}

	return 0;
}