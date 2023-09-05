#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "EventService.h"
#include "GraphicService.h"
#include "UIService.h"

class ServiceLocator
{
private:
    sf::RenderWindow* game_window;
    EventService* event_service;
    GraphicService* graphic_service;
    UIService* ui_service;

    ServiceLocator();
    ~ServiceLocator();

    void initializeServices();
    void clearAllServices();

public:
    static ServiceLocator* getInstance();

    void updateServices();
    void setGameWindow();
    EventService* getEventService();
    GraphicService* getGraphicService();
    UIService* getUIService();
    void deleteServiceLocator();

    enum GameState
    {
        SPLASH_SCREEN,
        MAIN_MENU,
        INSTRUCTIONS
    };
};