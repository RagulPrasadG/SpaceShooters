#pragma once
#include "SFML/Graphics.hpp"

class PlayerProjectile
{
public:
	PlayerProjectile(sf::Vector2f position);
	sf::Sprite PlayerProjectileSprite;
	sf::Vector2f scale;
	float force = 300.f;
	void Draw(sf::RenderWindow* window);
	void Move(float deltaTime);
	bool IsInBounds();
	~PlayerProjectile();
private:

	sf::Vector2f position;

};

