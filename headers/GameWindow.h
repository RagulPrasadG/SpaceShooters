#pragma once
#include "SFML/Window.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include "SFML/Graphics.hpp"

class GameWindow 
{
public:
	const static int WIDTH = 800;
	const static int HEIGHT = 600;


	GameWindow();
	void DestroyWindow();
	void Close();
	void Clear();
	void Display();
	void Draw(sf::Sprite sprite);
	bool isOpen();
	bool PollEvent(sf::Event& event);
	sf::RenderWindow* GetWindow();

private:
	void CreateWindow();
	sf::RenderWindow* window;
};