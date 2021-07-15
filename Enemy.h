#pragma once
#include <vector>
#include "SFML/Graphics.hpp"

class Player;

class Enemy
{
public:
	Enemy();

	void SpawnEnemy();
	void CheckEnemyCollision(Player &player, sf::RenderWindow& window, float outOfBounds);
	void UpdateEnemies();
	void DrawAllEnemies(sf::RenderWindow& window);

private:
	std::vector<sf::CircleShape> shape;

	float enemySpeedDown;
	float enemySpeedSide;

	float spawnTimerMax;
	float spawnTimer;

};

