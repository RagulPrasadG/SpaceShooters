#pragma once
#include "SFML/Graphics.hpp"
#include "../headers/ProjectilePool.h"

class PlayerShip
{
public:
	sf::Texture texture;
	sf::Sprite shipSprite;
	sf::Vector2f firePos;
	ProjectilePool projectilePool;
	bool canMove = false;
	float moveSpeed = 300.f;
	float fireInterval = 0.0f;
	float fireRate = 0.5f;
	void CreateShip();
	void MoveRight(float deltaTime);
	void MoveLeft(float deltaTime);
	void MoveDown(float deltaTime);
	void MoveUp(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void Fire();
};
