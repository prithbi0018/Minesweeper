#include "UIService.h"

UIService::UIService() { game_Window = nullptr; }

void UIService::setGameWindow(sf::RenderWindow* window_to_set)
{
	game_Window = window_to_set;
	initializeControllers();
}

void UIService::initializeControllers()
{
	splash_screen_controller = new SplashScreenUIController(game_Window);
	main_menu_controller = new MainMenuUIController(game_Window);
}

UIService::~UIService()
{
	delete(splash_screen_controller);
	delete(main_menu_controller);
}

void UIService::updateUI()
{
	switch (current_state)
	{
	case UIState::MAIN_MENU:
		main_menu_controller->update();
		break;
	default:
		break;
	}
}

void UIService::setUIState(UIState new_state)
{
	current_state = new_state;

	switch (current_state)
	{
	case UIState::SPLASH_SCREEN:
		showSplashScreen();
		break;
	case UIState::MAIN_MENU:
		showMainMenu();
		break;
	default:
		break;
	}
}

void UIService::showSplashScreen() { splash_screen_controller->show(); }

void UIService::showMainMenu() { main_menu_controller->show(); }