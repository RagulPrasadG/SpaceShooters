#pragma once
#include "../headers/EnemyProjectile.h"

class EnemyProjectilePool
{
public:
	void Add(EnemyProjectile* enemyProjectile);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void CreatePool();
private:
	float fireInterval = 1.f;
	std::vector<EnemyProjectile*> enemyProjectileList;

};
