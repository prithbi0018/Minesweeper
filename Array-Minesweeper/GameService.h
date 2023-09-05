#pragma once
#include "ServiceLocator.h"

class GameService
{
private:
	const int frame_rate = 60;
	ServiceLocator* service_locator;

	void initializeVariables();
	void initializeGameWindow();
	void showSplashScreen();

public:
	GameService();
	virtual ~GameService();

	void ignite();
	void update();
	bool isRunning();
};
