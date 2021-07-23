#pragma once
#include <vector>
#include "SFML/Graphics.hpp"

class Player;

class Enemy
{
public:
	Enemy();

	void SpawnEnemy(sf::RenderWindow& window);
	void IncreaseEnemyCount(Player &player);
	void CheckEnemyCollision(Player &player, sf::RenderWindow& window);
	void DrawAllEnemies(sf::RenderWindow& window);

private:
	std::vector<sf::CircleShape> shape;

	float enemySpeedDown;

	float spawnTimerMax;
	float spawnTimer;
	float increaseSpawnTimerAmount;
	int maxTimerIncreaseAmount;

	unsigned spawnScoreAmount;
	unsigned maxEnemies;
};

