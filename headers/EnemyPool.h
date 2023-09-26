#pragma once
#include "../headers/Enemy.h"
#include "../headers/GameWindow.h"
#include "../headers/EnemyProjectilePool.h"


class EnemyPool
{
public:
	int width = 6;
	int height = 6;
	int cellSize = 55;
	int startX = 200;
	int startY = 50;
	float fireInterval = 0.0f;
	float fireRate = 3;
	Enemy* enemies[6][6];
	void Fire();
	void CreateEnemyPool();
	void Draw(sf::RenderWindow* window,float deltaTime);
private :
	EnemyProjectilePool enemyProjectilePool;

};

