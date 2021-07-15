#include "Player.h"

Player::Player()
	:
	player{ sf::Vector2f(100.f, 25.f) },
	points{ 0 }
{
}

void Player::UpdatePlayerPosition(sf::RenderWindow& window, float boundaries, float outOfBounds)
{
	// updating player
	player.setPosition(
		mouseLocation.getPosition(window).x - player.getLocalBounds().width / 2, outOfBounds);

	if (mouseLocation.getPosition(window).x <= boundaries)
		player.setPosition(0, outOfBounds);

	if (mouseLocation.getPosition(window).x >= window.getDefaultView().getSize().x - boundaries)
		player.setPosition(window.getDefaultView().getSize().x - (boundaries * 2), outOfBounds);
}

sf::RectangleShape& Player::GetPlayer()
{
	return player;
}

void Player::DrawPlayer(sf::RenderWindow& window)
{
	window.draw(player);
}

void Player::AddPoints(int pointsToAdd)
{
	points += pointsToAdd;
}

