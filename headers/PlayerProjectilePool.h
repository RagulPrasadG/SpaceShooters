#pragma once
#include <vector>
#include "../headers/PlayerProjectile.h"

class PlayerProjectilePool
{
public:
	void Add(PlayerProjectile* PlayerProjectile);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
	void CreatePool();
private:
	std::vector<PlayerProjectile*> PlayerProjectileList;
	PlayerProjectile* PlayerProjectiles[20];

};
