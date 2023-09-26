#include "../headers/Assets.h"

Assets* Assets::_instance = nullptr;
Assets::Assets()
{
    PlayerProjectileTexture.loadFromFile("assets/PlayerBullet.png");
    enemyTexture.loadFromFile("assets/EnemyImage.png");
    enemyProjectileTexture.loadFromFile("assets/EnemyBullet.png");

}

Assets* Assets::getInstance()
{
        if (_instance == nullptr)
        {
            _instance = new Assets();
            return _instance;
        }
        else
        {
            return _instance;
        }

}
