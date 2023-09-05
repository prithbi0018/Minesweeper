#include "GameService.h"


GameService::GameService() { initializeVariables(); }

GameService::~GameService() { service_locator->deleteServiceLocator(); }

void GameService::initializeVariables() { service_locator = ServiceLocator::getInstance(); }

void GameService::ignite()
{
	initializeGameWindow();
	showSplashScreen();
}

void GameService::initializeGameWindow()
{
	// Game Window will be created here.
	service_locator->getGraphicService()->createGameWindow();
	service_locator->getGraphicService()->setFrameRate(frame_rate);

	// Pass down the reference of game window through service locator.
	service_locator->setGameWindow();
}

void GameService::showSplashScreen() { service_locator->getUIService()->setUIState(UIState::SPLASH_SCREEN); }

bool GameService::isRunning() { return service_locator->getGraphicService()->isGameWindowOpen(); }

// Main Game Loop.
void GameService::update()
{
	// Process Events.
	service_locator->getEventService()->processEvents();

	// Update Game Logic.
	service_locator->updateServices();

	// Render Next Frame.
	service_locator->getGraphicService()->drawNextFrame();
}