#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Enemy.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test");

	// boundaries on the left side of window
	float boundaries = 50.f;

	// player location on y position
	const float outOfBounds = static_cast<float>(window.getSize().y) - 50.f;

	Player player;
	Enemy enemy;

	// setup font and makes sure its valid
	sf::Font font;
	if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
		std::cout << "Cant load font";

	// setting up score text 
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setPosition(sf::Vector2f(window.getView().getSize().x - 125.f, 25.f));
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(sf::Color::White);

	while (window.isOpen())
	{
		sf::Event event;

		// checking for input
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}

		enemy.CheckEnemyCollision(player, window);

		// running check to increase spawn speed and enemy speed
		enemy.IncreaseEnemyCount(player);

		player.UpdatePlayerPosition(window, boundaries, outOfBounds);

		// updating score text
		scoreText.setString("Score: " + std::to_string(player.GetScore()));

		window.clear();

		// updating enemy class
		enemy.SpawnEnemy(window);

		// drawing player, score text, and enemies to screen
		player.DrawPlayer(window);
		enemy.DrawAllEnemies(window);
		window.draw(scoreText);

		window.display();
	}

	return 0;
}