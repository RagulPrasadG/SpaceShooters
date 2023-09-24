#pragma once
#include "SFML/Window.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include "SFML/Graphics.hpp"

class GameWindow 
{
public:
	const static int WIDTH = 800;
	const static int HEIGHT = 600;
	sf::RenderWindow* window;
	void Update();
	GameWindow();
	void DestroyWindow();
	void Close();
	void Clear();
	void Display();
	void Draw(sf::Sprite sprite);
	bool isOpen();
	bool PollEvent(sf::Event& event);

private:
	void CreateWindow();
};