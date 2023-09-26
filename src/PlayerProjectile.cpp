
#include "../headers/PlayerProjectile.h"
#include  "../headers/Assets.h"

PlayerProjectile::PlayerProjectile(sf::Vector2f position)
{
	PlayerProjectileSprite.setTexture(Assets::getInstance()->PlayerProjectileTexture);
	PlayerProjectileSprite.setPosition(position);
	PlayerProjectileSprite.setScale(sf::Vector2f(0.2, 0.2));
}

void PlayerProjectile::Draw(sf::RenderWindow* window)
{
	window->draw(PlayerProjectileSprite);
}

void PlayerProjectile::Move(float deltaTime)
{
	PlayerProjectileSprite.setPosition(sf::Vector2f(PlayerProjectileSprite.getPosition().x, PlayerProjectileSprite.getPosition().y - force * deltaTime));
}

bool PlayerProjectile::IsInBounds()
{
	if (PlayerProjectileSprite.getPosition().y < 20)
	{
		return false;
	}
	return true;
}


PlayerProjectile::~PlayerProjectile()
{
	
}
