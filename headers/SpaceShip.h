#pragma once
#include "SFML/Graphics.hpp"

class SpaceShip
{
public:
	sf::Texture texture;
	sf::Sprite shipSprite;
	bool canMove = false;
	float moveSpeed = 300.f;
	void CreateShip();
	void MoveRight(float deltaTime);
	void MoveLeft(float deltaTime);
	void MoveDown(float deltaTime);
	void MoveUp(float deltaTime);
};
