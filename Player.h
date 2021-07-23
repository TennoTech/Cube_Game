#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	void UpdatePlayerPosition(sf::RenderWindow& window, float boundaries, float outOfBounds);
	sf::RectangleShape& GetPlayer();
	void DrawPlayer(sf::RenderWindow& window);
	void AddPoints(int pointsToAdd);
	unsigned GetScore();

private:
	sf::RectangleShape player;
	sf::Mouse mouseLocation;

	unsigned score;
};

