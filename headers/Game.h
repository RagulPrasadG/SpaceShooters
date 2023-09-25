#pragma once
#include "../headers/GameWindow.h"
#include "../headers/PlayerShip.h"
#include "../headers/ProjectilePool.h"

class Game
{
public:
	sf::Texture bgTexture;
	sf::Sprite bgSprite;
	int playerHealth;
	int score;
	sf::Clock clock;
	sf::Time time;
	float deltaTime;
	GameWindow* gameWindow;
	PlayerShip spaceShip;
	void Init();
	void Run();
	void QuitGame();

};

