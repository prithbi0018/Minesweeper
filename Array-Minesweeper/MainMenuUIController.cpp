#include "MainMenuUIController.h"
#include "ServiceLocator.h"

MainMenuUIController::MainMenuUIController(sf::RenderWindow* window)
{
    this->game_window = window;
    setBackgroundImage();
    initializeButtons();
}

// Load the background texture and sprite
void MainMenuUIController::setBackgroundImage()
{
    if (background_texture.loadFromFile("textures/minesweeper_bg.png")) {
        background_sprite.setTexture(background_texture);
        scaleBackgroundImage();
    }
}

void MainMenuUIController::scaleBackgroundImage()
{
    background_sprite.setScale(
        static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
        static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
    );
}

void MainMenuUIController::initializeButtons()
{
    if (loadButtonTexturesFromFile())
    {
        setButtonSprites();
        scaleAllButttons();
        positionButtons();
    }
}

bool MainMenuUIController::loadButtonTexturesFromFile()
{
    return play_button_texture.loadFromFile("textures/play_button.png") &&
        instructions_button_texture.loadFromFile("textures/instructions_button.png") &&
        quit_button_texture.loadFromFile("textures/quit_button.png");
}

void MainMenuUIController::setButtonSprites()
{
    play_button_sprite.setTexture(play_button_texture);
    instructions_button_sprite.setTexture(instructions_button_texture);
    quit_button_sprite.setTexture(quit_button_texture);
}

void MainMenuUIController::scaleAllButttons()
{
    scaleButton(&play_button_sprite);
    scaleButton(&instructions_button_sprite);
    scaleButton(&quit_button_sprite);
}

void MainMenuUIController::scaleButton(sf::Sprite* buttonToScale)
{
    buttonToScale->setScale(
        button_width / buttonToScale->getTexture()->getSize().x,
        button_height / buttonToScale->getTexture()->getSize().y
    );
}

void MainMenuUIController::positionButtons()
{
    float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;

    play_button_sprite.setPosition({ x_position, 300.f });
    instructions_button_sprite.setPosition({ x_position, 500.f });
    quit_button_sprite.setPosition({ x_position, 700.f });
}

void MainMenuUIController::show()
{

}

void MainMenuUIController::update()
{
    game_window->clear();

    game_window->draw(background_sprite);
    game_window->draw(play_button_sprite);
    game_window->draw(instructions_button_sprite);
    game_window->draw(quit_button_sprite);

    if (pressedMouseButton())
        handleButtonInteractions();
}

bool MainMenuUIController::pressedMouseButton() { return sf::Mouse::isButtonPressed(sf::Mouse::Left); }

void MainMenuUIController::handleButtonInteractions()
{
    sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

    if (clickedButton(&play_button_sprite, mouse_position))
        printf("Clicked Play Button \n");

    if (clickedButton(&instructions_button_sprite, mouse_position))
        printf("Clicked Instruction Button \n");

    if (clickedButton(&quit_button_sprite, mouse_position))
        game_window->close();
}

bool MainMenuUIController::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
{
    return button_sprite->getGlobalBounds().contains(mouse_position);
}