#include "Player.h"

Player::Player()
	:
	player{ sf::Vector2f(100.f, 25.f) },
	score{ 0 }
{
}

void Player::UpdatePlayerPosition(sf::RenderWindow& window, float boundaries, float outOfBounds)
{
	// updating player
	player.setPosition(
		mouseLocation.getPosition(window).x - player.getLocalBounds().width / 2, outOfBounds);

	// player cant go off of screen to left
	if (mouseLocation.getPosition(window).x <= boundaries)
		player.setPosition(0, outOfBounds);

	// player cant go off of screen to right
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
	score += pointsToAdd;
}

unsigned Player::GetScore()
{
	return score;
}

