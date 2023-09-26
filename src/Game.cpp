#include "../headers/Game.h"
#include "../headers/Assets.h"


void Game::Init()
{
    bgTexture.loadFromFile("assets/BG.jpg");
    bgSprite.setTexture(bgTexture);
    bgSprite.setPosition(sf::Vector2f(0,0));
    bgSprite.setScale(sf::Vector2f(bgSprite.getScale().x + 0.3f, bgSprite.getScale().y + 0.3f));
    gameWindow = new GameWindow();
    playerShip.CreateShip();
    enemyPool.CreateEnemyPool();
}

void Game::Run()
{
    Init();

    while (gameWindow->isOpen())
    {
        sf::Event event;

        while (gameWindow->PollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow->Close();
        }

        time = clock.restart();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            playerShip.MoveLeft(deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            playerShip.MoveRight(deltaTime);
        }


        playerShip.fireInterval += deltaTime;
        enemyPool.fireInterval += deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && playerShip.fireInterval >= playerShip.fireRate)
        {
            playerShip.Fire();
            playerShip.fireInterval = 0.f;
        }

        deltaTime = time.asSeconds();
     
        gameWindow->Clear();
        gameWindow->Draw(bgSprite);
        playerShip.Draw(gameWindow->GetWindow());
        playerShip.UpdatePlayerPlayerProjectiles(deltaTime);
        if (enemyPool.fireInterval >= enemyPool.fireRate)
        {
            enemyPool.Fire();
            enemyPool.fireInterval = 0;
        }
        enemyPool.Draw(gameWindow->GetWindow(),deltaTime);
        gameWindow->Display();

    }

}



void Game::QuitGame()
{
	delete gameWindow;
}


