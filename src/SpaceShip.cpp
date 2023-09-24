#include "../headers/SpaceShip.h"
#include "../headers/GameWindow.h"

void SpaceShip::CreateShip()
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

void SpaceShip::MoveRight(float deltaTime)
{
	//restrict ship from moving outside the screen
	float shipSpriteBorderX = shipSprite.getPosition().x + (shipSprite.getScale().x / 2);

	if (shipSpriteBorderX > GameWindow::WIDTH)
		return;



	sf::Vector2f moveVector = sf::Vector2f(shipSprite.getPosition().x + moveSpeed * deltaTime, shipSprite.getPosition().y);
	shipSprite.setPosition(moveVector);
}

void SpaceShip::MoveLeft(float deltaTime)
{
	sf::Vector2f moveVector = sf::Vector2f(shipSprite.getPosition().x - moveSpeed * deltaTime, shipSprite.getPosition().y);
	shipSprite.setPosition(moveVector);
}

void SpaceShip::MoveDown(float deltaTime)
{
	sf::Vector2f moveVector = sf::Vector2f(shipSprite.getPosition().x,shipSprite.getPosition().y + moveSpeed * deltaTime);
	shipSprite.setPosition(moveVector);
}

void SpaceShip::MoveUp(float deltaTime)
{
	sf::Vector2f moveVector = sf::Vector2f(shipSprite.getPosition().x,shipSprite.getPosition().y - moveSpeed * deltaTime);
	shipSprite.setPosition(moveVector);
}

