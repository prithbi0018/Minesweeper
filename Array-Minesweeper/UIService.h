#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "MainMenuUIController.h"
#include "SplashScreenUIController.h"

enum class UIState
{
	SPLASH_SCREEN,
	MAIN_MENU,
};

class UIService
{
private:
	sf::RenderWindow* game_Window;
	SplashScreenUIController* splash_screen_controller;
	MainMenuUIController* main_menu_controller;
	UIState current_state;

	void initializeControllers();
	void showSplashScreen();
	void showMainMenu();

public:
	UIService();
	~UIService();

	void setGameWindow(sf::RenderWindow* window_to_set);
	void setUIState(UIState new_state);
	void updateUI();
};