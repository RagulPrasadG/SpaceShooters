#include "../headers/EnemyProjectilePool.h"

void EnemyProjectilePool::Add(EnemyProjectile* EnemyProjectile)
{
	enemyProjectileList.push_back(EnemyProjectile);
}

void EnemyProjectilePool::Update(float deltaTime)
{
	for (auto enemyProjectile = enemyProjectileList.begin(); enemyProjectile != enemyProjectileList.end();)
	{
		if (!(*enemyProjectile)->IsInBounds())
		{
			delete* enemyProjectile;
			enemyProjectile = enemyProjectileList.erase(enemyProjectile);
		}
		else
		{
			(*enemyProjectile)->Move(deltaTime);
			++enemyProjectile;
		}

	}
}

void EnemyProjectilePool::Draw(sf::RenderWindow* window)
{
	for (EnemyProjectile* enemyProjectile : enemyProjectileList)
	{
		if (enemyProjectile)
			enemyProjectile->Draw(window);
	}

}



void EnemyProjectilePool::CreatePool()
{
}
