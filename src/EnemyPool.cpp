#include "../headers/EnemyPool.h"


void EnemyPool::Fire()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
	        EnemyProjectile* projectile = enemies[i][j]->Fire();
		    enemyProjectilePool.Add(projectile);
		}
	}
}

void EnemyPool::CreateEnemyPool()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			sf::Vector2f position = sf::Vector2f(startX, startY);
			enemies[i][j] = new Enemy(position);
			startX += cellSize;
		}
		startX = 200;
		startY += cellSize;
	}
}


void EnemyPool::Draw(sf::RenderWindow* window,float deltaTime)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			enemyProjectilePool.Draw(window);
			enemyProjectilePool.Update(deltaTime);
			enemies[i][j]->Draw(window);
		}
	}
}


