#pragma once
#include "SFML/Graphics.hpp"
#include "../headers/EnemyProjectile.h"

class Enemy
{
public:
	Enemy(sf::Vector2f position);
	sf::Sprite sprite;
	sf::Vector2f position;
	void Draw(sf::RenderWindow* window);
	EnemyProjectile* Fire();
};