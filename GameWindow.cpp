#include "GameWindow.h"
#include "Player.h"
#include "Enemy.h"


void GameWindow::PollingEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window->close();
	}
}

void GameWindow::UpdateEvents()
{
	player.UpdatePlayerPosition(*window);
	enemy->CheckEnemyCollision(*player, *window, 125.f);
}
