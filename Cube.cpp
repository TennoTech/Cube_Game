#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "GameWindow.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
	// boundaries on the left side of window
	float boundaries = 50.f;
	// player location on y position
	float outOfBounds = 125.f;

	Player player;
	Enemy enemy;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		enemy.CheckEnemyCollision(player, window, outOfBounds);
		player.UpdatePlayerPosition(window, boundaries, outOfBounds);

		window.clear();
		enemy.UpdateEnemies();
		player.DrawPlayer(window);
		enemy.DrawAllEnemies(window);

		window.display();
	}

	return 0;
}