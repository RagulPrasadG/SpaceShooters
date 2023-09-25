#include "../headers/PlayerShip.h"
#include "../headers/GameWindow.h"
#include "../headers/Projectile.h"

void PlayerShip::CreateShip()
{
	if (!texture.loadFromFile("assets/ShipImage.png")) {
		// Texture loaded successfully
		//error
		return;
	}

	texture.setSmooth(true);
	shipSprite.setTexture(texture);
	shipSprite.setScale(sf::Vector2f(0.5f, 0.5f));
	sf::Vector2f centerPos = sf::Vector2f(GameWindow::WIDTH / 2, GameWindow::HEIGHT / 2);
	shipSprite.setPosition(centerPos);
}

void PlayerShip::MoveRight(float deltaTime)
{
	//restrict ship from moving outside the screen
	float shipSpriteBorderX = shipSprite.getPosition().x + (shipSprite.getScale().x / 2);

	if (shipSpriteBorderX > GameWindow::WIDTH)
		return;

	sf::Vector2f moveVector = sf::Vector2f(shipSprite.getPosition().x + moveSpeed * deltaTime, shipSprite.getPosition().y);
	shipSprite.setPosition(moveVector);
}

void PlayerShip::MoveLeft(float deltaTime)
{
	sf::Vector2f moveVector = sf::Vector2f(shipSprite.getPosition().x - moveSpeed * deltaTime, shipSprite.getPosition().y);
	shipSprite.setPosition(moveVector);
}

void PlayerShip::MoveDown(float deltaTime)
{
	sf::Vector2f moveVector = sf::Vector2f(shipSprite.getPosition().x,shipSprite.getPosition().y + moveSpeed * deltaTime);
	shipSprite.setPosition(moveVector);
}

void PlayerShip::MoveUp(float deltaTime)
{
	sf::Vector2f moveVector = sf::Vector2f(shipSprite.getPosition().x,shipSprite.getPosition().y - moveSpeed * deltaTime);
	shipSprite.setPosition(moveVector);
}

void PlayerShip::Draw(sf::RenderWindow* window)
{
	window->draw(shipSprite);
	projectilePool.Draw(window);
}

void PlayerShip::Fire()
{
	firePos = sf::Vector2f(shipSprite.getPosition().x + 18.f, shipSprite.getPosition().y - 20.f);
	projectilePool.Add(new Projectile(firePos));
}


