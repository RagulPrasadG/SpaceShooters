#include "../headers/Game.h"

void Game::Init()
{
    bgTexture.loadFromFile("assets/BG.jpg");
    bgSprite.setTexture(bgTexture);
    bgSprite.setPosition(sf::Vector2f(0,0));
    bgSprite.setScale(sf::Vector2f(bgSprite.getScale().x + 0.3f, bgSprite.getScale().y + 0.3f));
    gameWindow = new GameWindow();
    spaceShip.CreateShip();
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
            spaceShip.MoveLeft(deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            spaceShip.MoveRight(deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            spaceShip.MoveUp(deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            spaceShip.MoveDown(deltaTime);
        }

        spaceShip.fireInterval += deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space) && spaceShip.fireInterval >= spaceShip.fireRate)
        {
            spaceShip.Fire();
            spaceShip.fireInterval = 0.f;
        }

        deltaTime = time.asSeconds();
     
        gameWindow->Clear();
        gameWindow->Draw(bgSprite);
        spaceShip.Draw(gameWindow->GetWindow());
        spaceShip.projectilePool.Update(deltaTime);
        gameWindow->Display();

    }

}



void Game::QuitGame()
{
	delete gameWindow;
}


