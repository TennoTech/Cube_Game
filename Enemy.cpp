#include <iostream>
#include "Enemy.h"
#include "Player.h"

Enemy::Enemy()
	:
	enemySpeedDown{ 0.01f },
	enemySpeedSide{ 0.01f },
	spawnTimerMax{ 1000.f },
	spawnTimer{ spawnTimerMax }
{
}

void Enemy::SpawnEnemy()
{
	// timer to spawn enemies
	if (spawnTimer >= spawnTimerMax)
	{
		if (shape.size() < 2)
		{
			shape.push_back(sf::CircleShape(50.f));
			std::cout << shape.size() << std::endl;
			spawnTimer = 0.f;
		}
	}
	else
		spawnTimer += 0.1f;
}

void Enemy::CheckEnemyCollision(Player &player, sf::RenderWindow& window, float outOfBounds)
{
	int count = 0;
	for (auto& e : shape)
	{
		if (e.getGlobalBounds().intersects(player.GetPlayer().getGlobalBounds()))
		{
			player.AddPoints(5);
			shape.erase(shape.begin() + count);
		}
		count++;
	}
}

void Enemy::UpdateEnemies()
{
	SpawnEnemy();
}

void Enemy::DrawAllEnemies(sf::RenderWindow& window)
{
	for (auto& e : shape)
	{
		e.move(0.f, enemySpeedDown);
		window.draw(e);
	}
}
