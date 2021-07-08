#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test");

	sf::RectangleShape player(sf::Vector2f(100.f, 25.f));

	sf::Mouse mouseLocation;
	//window.setMouseCursorVisible(false);

	std::vector<sf::CircleShape> shape;

	float spawnTimerMax = 100.f;
	float spawnTimer = spawnTimerMax;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		player.setPosition(
			mouseLocation.getPosition(window).x - player.getLocalBounds().width / 2,
			mouseLocation.getPosition(window).y - player.getLocalBounds().height / 2);

		// timer to spawn enemiess
		if (spawnTimer >= spawnTimerMax)
		{
			if (shape.size() < 3)
			shape.push_back(sf::CircleShape(50.f));
			spawnTimer = 0.f;
		}
		else
		{
			spawnTimer += 0.01f;
		}

		std::cout << spawnTimer << std::endl;

		window.clear();
		window.draw(player);

		for (auto &e : shape)
		{
			e.move(0.f, 0.05f);
			window.draw(e);
		}
		
		window.display();
	}

	return 0;
}