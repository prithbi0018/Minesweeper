#include "GameService.h"

int main()
{
    GameService* game_service = new GameService();
    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
    }

    return 0;
}