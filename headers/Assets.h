#pragma once
#include "SFML/Graphics.hpp"


class Assets
{
    public:
        sf::Texture playerTexture;
        sf::Texture PlayerProjectileTexture;
        sf::Texture enemyTexture;
        sf::Texture enemyProjectileTexture;
        Assets();
        static Assets* getInstance();
       
    private:
        static Assets* _instance;
};

