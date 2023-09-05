#include "ServiceLocator.h"

ServiceLocator::ServiceLocator() { initializeServices(); }

ServiceLocator::~ServiceLocator() { clearAllServices(); }

void ServiceLocator::initializeServices()
{
	event_service = new EventService();
	graphic_service = new GraphicService();
	ui_service = new UIService();
}

void ServiceLocator::clearAllServices()
{
	delete(event_service);
	delete(graphic_service);
	delete(ui_service);
}

ServiceLocator* ServiceLocator::getInstance()
{
	static ServiceLocator instance;
	return &instance;
}

void ServiceLocator::setGameWindow()
{
	// Fetch Game Window from Graphic Service
	game_window = graphic_service->getWindow();

	// Pass down the reference of Game Window to other Services.
	event_service->setGameWindow(game_window);
	ui_service->setGameWindow(game_window);
}

void ServiceLocator::updateServices()
{
	ui_service->updateUI();
	graphic_service->updateGraphics();
}

EventService* ServiceLocator::getEventService() { return event_service; }

GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

UIService* ServiceLocator::getUIService() { return ui_service; }

void ServiceLocator::deleteServiceLocator() { delete(this); }