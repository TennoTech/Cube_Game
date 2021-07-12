#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
	float boundaries = 50.f;
	float outOfBounds = 125.f;
	sf::Vector2i mouse;
	sf::Vector2f contain;

	sf::RectangleShape player(sf::Vector2f(100.f, 25.f));

	sf::Mouse mouseLocation;
	//window.setMouseCursorVisible(false);

	std::vector<sf::CircleShape> shape;
	float enemySpeedDown;
	float enemySpeedSide;

	float spawnTimerMax = 1000.f;
	float spawnTimer = spawnTimerMax;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		// updating player
		player.setPosition(
			mouseLocation.getPosition(window).x - player.getLocalBounds().width / 2, outOfBounds);
		//mouseLocation.setPosition(sf::Vector2i(player.getPosition()), window);

		if (mouseLocation.getPosition(window).x <= boundaries)
		{
			player.setPosition(0, outOfBounds);
			//mouseLocation.setPosition(sf::Vector2i(boundaries, int(outOfBounds)), window);
		}

		if (mouseLocation.getPosition(window).x >= window.getDefaultView().getSize().x - boundaries)
		{
			player.setPosition(window.getDefaultView().getSize().x - (boundaries * 2), outOfBounds);
			//mouseLocation.setPosition(sf::Vector2i(
				//window.getDefaultView().getSize().x - boundaries, int(outOfBounds)), window);
		}

		// timer to spawn enemies
		if (spawnTimer >= spawnTimerMax)
		{
			if (shape.size() < 3)
			{
				shape.push_back(sf::CircleShape(50.f));
				shape[0].setPosition(400.f, 0.f);
				spawnTimer = 0.f;
			}
		}
		else
		{
			spawnTimer += 0.01f;
		}


		mouse = sf::Vector2i(player.getPosition());
		contain = window.mapPixelToCoords(mouse);

		// collision
		if (shape[0].getPosition().x <= (player.getPosition().x + player.getSize().x) &&
			(shape[0].getPosition().x + shape[0].getRadius() * 2) >= player.getPosition().x &&
			shape[0].getPosition().y + (shape[0].getRadius() * 2) >= outOfBounds)
			shape[0].setFillColor(sf::Color::Yellow);
		else
			shape[0].setFillColor(sf::Color::White);

		window.clear();
		window.draw(player);
		shape[0].move(0.01f, 0.005f);
		window.draw(shape[0]);
		/*for (auto& e : shape)
		{
			e.move(0.f, 0.01f);
			window.draw(e);
		}*/

		window.display();
	}

	return 0;
}