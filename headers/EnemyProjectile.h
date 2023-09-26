#pragma once
#include "SFML/Graphics.hpp"


class EnemyProjectile
{
public:
	EnemyProjectile(sf::Vector2f position);
	sf::Sprite enemyProjectileSprite;
	sf::Vector2f scale;
	float force = 5.f;
	void Draw(sf::RenderWindow* window);
	void Move(float deltaTime);
	bool IsInBounds();
	~EnemyProjectile();
private:

	sf::Vector2f position;

};
