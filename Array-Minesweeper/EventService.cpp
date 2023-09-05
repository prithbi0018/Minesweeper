#include "EventService.h"
#include "ServiceLocator.h"

EventService::EventService() { game_window = nullptr; }

EventService::~EventService() = default;

void EventService::setGameWindow(sf::RenderWindow* window_to_set) { game_window = window_to_set; }

void EventService::processEvents()
{
	if (isGameWindowOpen())
	{
		// Iterate over all events in the queue.
		while (game_window->pollEvent(game_event))
		{
			if (gameWindowWasClosed() || hasQuitGame())
				game_window->close();
		}
	}
}

bool EventService::isGameWindowOpen() { return game_window != nullptr; }

bool EventService::gameWindowWasClosed() { return game_event.type == sf::Event::Closed; }

bool EventService::hasQuitGame() { return (isKeyboardEvent() && pressedEscapeKey()); }

bool EventService::isKeyboardEvent() { return game_event.type == sf::Event::KeyPressed; }

bool EventService::pressedEscapeKey() { return game_event.key.code == sf::Keyboard::Escape; }