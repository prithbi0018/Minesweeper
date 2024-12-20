#include "../../header/UI/Gameplay/GameplayUIController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Sound/SoundService.h"
#include <sstream>
#include <iomanip>
namespace UI
{
    namespace GameplayUI
    {
        using namespace UIElement;
        using namespace Global;
        using namespace Sound;

        GameplayUIController::GameplayUIController()
        {
            createTexts();
            createButton();
        }
        GameplayUIController::~GameplayUIController()
        {
            destroy();
        }
        void GameplayUIController::createTexts()
        {
            time_text = new TextView();
            mine_text = new TextView();
        }
        void GameplayUIController::createButton()
        {
            restart_button = new ButtonView();
        }

        void GameplayUIController::initialize()
        {
            initializeTexts();
            initializeButton();
        }
        void GameplayUIController::update()
        {
            updateTimeText();
            updateMineText();
            restart_button->update();
        }
        void GameplayUIController::render()
        {
            time_text->render();
            mine_text->render();
            restart_button->render();
        }
        void GameplayUIController::initializeTexts()
        {
            initializeTimeText();
            initializeMineText();
        }
        void GameplayUIController::initializeTimeText()
        {
            time_text->initialize("000", sf::Vector2f(time_text_left_offset, time_text_top_offset), FontType::ROBOTO, font_size, text_color);
        }
        void GameplayUIController::initializeButton()
        {
            restart_button->initialize("Restart Button",
                Config::restart_button_texture_path,
                button_width, button_height,
                sf::Vector2f(restart_button_left_offset, restart_button_top_offset));
            registerButtonCallback();
        }
        void GameplayUIController::initializeMineText()
        {
            mine_text->initialize("000", sf::Vector2f(mine_text_left_offset, mine_text_top_offset), FontType::ROBOTO, font_size, text_color);
        }
        void GameplayUIController::show()
        {
            time_text->show();
            mine_text->show();
            restart_button->show();
        }
        void GameplayUIController::updateTimeText()
        {
            int remaining_time = ServiceLocator::getInstance()->getGameplayService()->getRemainingTime();
            std::stringstream stream;
            stream << std::setw(3) << std::setfill('0') << remaining_time;
            std::string string_remaining_time = stream.str();
            time_text->setText(string_remaining_time);
            time_text->update();
        }
        void GameplayUIController::updateMineText()
        {
            int mines_count = ServiceLocator::getInstance()->getGameplayService()->getMinesCount();
            std::stringstream stream;
            stream << std::setw(3) << std::setfill('0') << mines_count;
            std::string string_mine_count = stream.str();
            mine_text->setText(string_mine_count);
            mine_text->update();
        }

        void GameplayUIController::destroy()
        {
            delete (time_text);
            delete (mine_text);
            delete (restart_button);
        }
        void GameplayUIController::registerButtonCallback()
        {
            restart_button->registerCallbackFuntion(std::bind(&GameplayUIController::restartButtonCallback, this));
        }
        void GameplayUIController::restartButtonCallback()
        {
            ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
            ServiceLocator::getInstance()->getGameplayService()->startGame();
        }
        
    }
}