#include "../headers/PlayerProjectilePool.h"

void PlayerProjectilePool::Add(PlayerProjectile* PlayerProjectile)
{
	PlayerProjectileList.push_back(PlayerProjectile);
}

void PlayerProjectilePool::Update(float deltaTime)
{
	for (auto PlayerProjectile = PlayerProjectileList.begin(); PlayerProjectile != PlayerProjectileList.end();)
	{
		/*if (*PlayerProjectile == nullptr)
		{
			delete *PlayerProjectile;

			PlayerProjectile = PlayerProjectileList.erase(PlayerProjectile);
		}
		else
		{*/
		if (!(*PlayerProjectile)->IsInBounds())
		{
			delete *PlayerProjectile;
			PlayerProjectile = PlayerProjectileList.erase(PlayerProjectile);
		}
		else
		{
			(*PlayerProjectile)->Move(deltaTime);
			++PlayerProjectile;
		}

	}

	
}


void PlayerProjectilePool::Draw(sf::RenderWindow* window)
{
	for (PlayerProjectile* PlayerProjectile : PlayerProjectileList)
	{
		if(PlayerProjectile)
		PlayerProjectile->Draw(window);
	}

}


