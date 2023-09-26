#include "../headers/EnemyProjectile.h"
#include "../headers/Assets.h"

EnemyProjectile::EnemyProjectile(sf::Vector2f position)
{
	enemyProjectileSprite.setTexture(Assets::getInstance()->enemyProjectileTexture);
	enemyProjectileSprite.setPosition(position);
	enemyProjectileSprite.setScale(sf::Vector2f(0.1, 0.1));
}

void EnemyProjectile::Draw(sf::RenderWindow* window)
{
	window->draw(enemyProjectileSprite);
}

void EnemyProjectile::Move(float deltaTime)
{
	enemyProjectileSprite.setPosition(sf::Vector2f(enemyProjectileSprite.getPosition().x, enemyProjectileSprite.getPosition().y + force * deltaTime));
}

bool EnemyProjectile::IsInBounds()
{
	if (enemyProjectileSprite.getPosition().y >= 600)
	{
		return false;
	}
	return true;
}

EnemyProjectile::~EnemyProjectile()
{

}
