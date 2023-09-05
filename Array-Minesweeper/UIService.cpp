#include "UIService.h"

UIService::UIService() { game_window = nullptr; }

void UIService::setGameWindow(sf::RenderWindow* window_to_set)
{
	game_window = window_to_set;
	initializeControllers();
}

void UIService::initializeControllers()
{
	splash_screen_controller = new SplashScreenUIController(game_window);
	main_menu_controller = new MainMenuUIController(game_window);
	gameplay_ui_controller = new GameplayUIController(game_window);
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
	case UIState::GAMEPLAY:
		gameplay_ui_controller->update();
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
		splash_screen_controller->show();
		break;
	case UIState::MAIN_MENU:
		main_menu_controller->show();
		break;
	case UIState::GAMEPLAY:
		gameplay_ui_controller->show();
		break;
	default:
		break;
	}
}
