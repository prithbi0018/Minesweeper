#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class GameplayUIController
{
private:
	const sf::Color background_color = sf::Color::Black;
	sf::RenderWindow* game_window;

public:
	GameplayUIController(sf::RenderWindow* window);

	void show();
	void update();
};