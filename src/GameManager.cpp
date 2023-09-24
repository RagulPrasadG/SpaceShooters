#include "../headers/GameManager.h"
void GameManager::Run()
{
	gameWindow = new GameWindow();
	spaceShip.CreateShip();

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

        deltaTime = time.asSeconds();
     
        gameWindow->Clear();
        gameWindow->Draw(spaceShip.shipSprite);
        gameWindow->Display();

    }

}



void GameManager::QuitGame()
{
	delete gameWindow;
}
