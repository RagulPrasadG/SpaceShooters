
#include "../headers/Projectile.h"

Projectile::Projectile(sf::Vector2f position)
{
	texture.loadFromFile("assets/PlayerBullet.png");
	projectileSprite.setTexture(texture);
	projectileSprite.setPosition(position);
	projectileSprite.setScale(sf::Vector2f(0.2, 0.2));
}

void Projectile::Draw(sf::RenderWindow* window)
{
	window->draw(projectileSprite);
}

void Projectile::Move(float deltaTime)
{
	projectileSprite.setPosition(sf::Vector2f(projectileSprite.getPosition().x, projectileSprite.getPosition().y - force * deltaTime));
}

Projectile::~Projectile()
{
	delete this;
}
