#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Gameplay/GameplayController.h"

namespace Gameplay
{

	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}

	GameplayService::~GameplayService()
	{
		destroy();
	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
	}

	void GameplayService::startGame()
	{
		gameplay_controller->reset();
	}

	void GameplayService::destroy()
	{
		delete(gameplay_controller);
	}
}