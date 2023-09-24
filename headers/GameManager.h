#pragma once
#include "../headers/GameWindow.h"
#include "../headers/SpaceShip.h"

class GameManager
{
public:

	int playerHealth;
	int score;
	sf::Clock clock;
	sf::Time time;
	float deltaTime;
	GameWindow* gameWindow;
	SpaceShip spaceShip;
	void Run();
	void QuitGame();

};

