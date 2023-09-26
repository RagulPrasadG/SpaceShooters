#include "../headers/Enemy.h"
#include "../headers/Assets.h"

Enemy::Enemy(sf::Vector2f position)
{
	sprite.setTexture(Assets::getInstance()->enemyTexture);
	sprite.setScale(sf::Vector2f(0.4f, 0.4f));
	sprite.setPosition(position);
	this->position = position;
}

void Enemy::Draw(sf::RenderWindow* window)
{
   window->draw(sprite);
}

EnemyProjectile* Enemy::Fire()
{
	EnemyProjectile* enemyProjectile = new EnemyProjectile(sf::Vector2f(position.x + 18,
		position.y
		));
	return enemyProjectile;
}

