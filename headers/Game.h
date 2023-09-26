#pragma once
#include "../headers/GameWindow.h"
#include "../headers/PlayerShip.h"
#include "../headers/PlayerProjectilePool.h"
#include "../headers/EnemyPool.h"

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
	PlayerShip playerShip;
	EnemyPool enemyPool;
	void Init();
	void Run();
	void QuitGame();

};

