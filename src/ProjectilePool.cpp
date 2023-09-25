#include "../headers/ProjectilePool.h"

void ProjectilePool::Add(Projectile* projectile)
{
	projectileList.push_back(projectile);
}

void ProjectilePool::Update(float deltaTime)
{
	for (Projectile* projectile : projectileList)
	{
		projectile->Move(deltaTime);
	}
}

void ProjectilePool::Draw(sf::RenderWindow* window)
{
	for (Projectile* projectile : projectileList)
	{
		projectile->Draw(window);
	}

}
