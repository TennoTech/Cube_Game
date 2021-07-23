#include "Enemy.h"
#include "Player.h"

Enemy::Enemy()
	:
	enemySpeedDown{ 0.1f },
	spawnTimerMax{ 200.f },
	spawnTimer{ spawnTimerMax },
	increaseSpawnTimerAmount{ 0.1f },
	maxTimerIncreaseAmount{ 5 },
	spawnScoreAmount{ 5 },
	maxEnemies{ 10 }
{
}

void Enemy::SpawnEnemy(sf::RenderWindow& window)
{
	// timer to spawn enemies
	if (spawnTimer >= spawnTimerMax)
	{
		if (shape.size() < maxEnemies)
		{
			shape.push_back(sf::CircleShape(50.f));

			// randomizing colors
			sf::Color color;
			switch (std::rand() % 6)
			{
			case 0:
				color = sf::Color::Blue;
				break;
			case 1:
				color = sf::Color::Cyan;
				break;
			case 2:
				color = sf::Color::Magenta;
				break;
			case 3:
				color = sf::Color::Yellow;
				break;
			case 4:
				color = sf::Color::Green;
				break;
			case 5:
				color = sf::Color::Red;
				break;
			}

			shape[shape.size() - 1].setFillColor(color);

			// setting random position on x axis
			shape[shape.size() - 1].setPosition(
				1 + (((float)rand()) / (float)RAND_MAX) * (window.getSize().x - 50), 0);
			spawnTimer = 0.f;
		}
	}
	else
		spawnTimer += increaseSpawnTimerAmount;
}

void Enemy::IncreaseEnemyCount(Player& player)
{
	if (player.GetScore() >= spawnScoreAmount && increaseSpawnTimerAmount <= maxTimerIncreaseAmount)
	{
		spawnScoreAmount *= 2;
		maxEnemies++;
		enemySpeedDown += 0.01f;
		increaseSpawnTimerAmount += 0.025f;
		maxTimerIncreaseAmount++;
	}
}

void Enemy::CheckEnemyCollision(Player& player, sf::RenderWindow& window)
{
	// remove the certain shape player is colliding with
	int count = 0;

	for (auto& e : shape)
	{
		// if the player collides with enemy delete and add points
		if (e.getGlobalBounds().intersects(player.GetPlayer().getGlobalBounds()))
		{
			player.AddPoints(5);
			shape.erase(shape.begin() + count);
		}

		// if enemy goes out of bounds it gets deleted
		if (e.getPosition().y >= window.getView().getSize().y)
			shape.erase(shape.begin() + count);

		count++;
	}
}

void Enemy::DrawAllEnemies(sf::RenderWindow& window)
{
	for (auto& e : shape)
	{
		e.move(0, enemySpeedDown);
		window.draw(e);
	}
}
