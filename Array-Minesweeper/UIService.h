#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameplayUIController.h"
#include "MainMenuUIController.h"
#include "SplashScreenUIController.h"

enum class UIState
{
	SPLASH_SCREEN,
	MAIN_MENU,
	GAMEPLAY,
};

class UIService
{
private:
	sf::RenderWindow* game_window;
	SplashScreenUIController* splash_screen_controller;
	MainMenuUIController* main_menu_controller;
	GameplayUIController* gameplay_ui_controller;
	UIState current_state;

	void initializeControllers();

public:
	UIService();
	~UIService();

	void setGameWindow(sf::RenderWindow* window_to_set);
	void setUIState(UIState new_state);
	void updateUI();
};