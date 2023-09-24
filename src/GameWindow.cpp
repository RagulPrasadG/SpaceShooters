#include "../headers/GameWindow.h"

void GameWindow::CreateWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "SpaceShooter",sf::Style::Titlebar | sf::Style::Close);
    
}

GameWindow::GameWindow()
{
    CreateWindow();
}

void GameWindow::Clear()
{
    window->clear();
}

bool GameWindow::PollEvent(sf::Event& event)
{
    return window->pollEvent(event);
}

void GameWindow::Draw(sf::Sprite sprite)
{
    window->draw(sprite);
}

void GameWindow::Display()
{
    window->display();
}

void GameWindow::Close()
{
    window->close();
}

bool GameWindow::isOpen()
{
    return window->isOpen();
}

void GameWindow::DestroyWindow()
{
    delete window;
}

