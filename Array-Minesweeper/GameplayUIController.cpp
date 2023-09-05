#include "GameplayUIController.h"

GameplayUIController::GameplayUIController(sf::RenderWindow* window)
{
	this->game_window = window;
}

void GameplayUIController::update()
{
	game_window->clear(background_color);
}

void GameplayUIController::show() {}