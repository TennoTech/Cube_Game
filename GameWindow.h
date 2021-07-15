#pragma once
#include <SFML/Graphics.hpp>

class Player;
class Enemy;

class GameWindow
{
public:
	GameWindow();
	const bool IsWindowOpen() const;
	void PollingEvents();
	void UpdateEvents();

private:
	sf::RenderWindow* window;
	Player &player;
	Enemy* enemy;
};

