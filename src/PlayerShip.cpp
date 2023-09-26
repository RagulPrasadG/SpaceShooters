#include "../headers/PlayerShip.h"
#include "../headers/GameWindow.h"
#include "../headers/PlayerProjectile.h"

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
	sf::Vector2f centerPos = sf::Vector2f(GameWindow::WIDTH / 2, GameWindow::HEIGHT - 100);
	shipSprite.setPosition(centerPos);
}


void PlayerShip::MoveRight(float deltaTime)
{
	//restrict ship from moving outside the screen
	float shipRightBounds = shipSprite.getPosition().x + shipSprite.getGlobalBounds().getSize().x;
	if (shipRightBounds > GameWindow::WIDTH)
		return;

	sf::Vector2f moveVector = sf::Vector2f(shipSprite.getPosition().x + moveSpeed * deltaTime, shipSprite.getPosition().y);
	shipSprite.setPosition(moveVector);
}

void PlayerShip::MoveLeft(float deltaTime)
{
	float shipLeftBounds = shipSprite.getPosition().x;
	if (shipLeftBounds < 0)
		return;

	sf::Vector2f moveVector = sf::Vector2f(shipSprite.getPosition().x - moveSpeed * deltaTime, shipSprite.getPosition().y);
	shipSprite.setPosition(moveVector);
}


void PlayerShip::Draw(sf::RenderWindow* window)
{
	window->draw(shipSprite);
	playerPlayerProjectiles.Draw(window);
}

void PlayerShip::Fire()
{
	firePos = sf::Vector2f(shipSprite.getPosition().x + 18.f, shipSprite.getPosition().y - 20.f);
	playerPlayerProjectiles.Add(new PlayerProjectile(firePos));
}

void PlayerShip::UpdatePlayerPlayerProjectiles(float deltaTime)
{
	playerPlayerProjectiles.Update(deltaTime);
}


