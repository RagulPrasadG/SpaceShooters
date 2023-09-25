#pragma once
#include <vector>
#include "../headers/Projectile.h"

class ProjectilePool
{
public:
	void Add(Projectile* projectile);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow* window);
private:
	std::vector<Projectile*> projectileList;

};
