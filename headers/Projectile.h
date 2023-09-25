#pragma once
#include "SFML/Graphics.hpp"

class Projectile
{
public:
	Projectile(sf::Vector2f position);
	sf::Texture texture;
	sf::Sprite projectileSprite;
	sf::Vector2f scale;
	float force = 300.f;
	void Draw(sf::RenderWindow* window);
	void Move(float deltaTime);
	~Projectile();
private:
	sf::Vector2f position;

};

