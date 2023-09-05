#include "SplashScreenUIController.h"
#include "ServiceLocator.h"

SplashScreenUIController::SplashScreenUIController(sf::RenderWindow* window)
{
    initializeVariables(window);
    initializeOutscalLogo();
}

void SplashScreenUIController::initializeVariables(sf::RenderWindow* window)
{
    this->game_window = window;
    elapsedTime = 0.0f;
}

void SplashScreenUIController::initializeOutscalLogo()
{
    loadOutscalTexture();
    outscal_logo_sprite.setTexture(outscal_logo_texture);
    setPositionToCenter();
}

void SplashScreenUIController::loadOutscalTexture()
{
    if (!tryLoadingOutscalLogo())
        printf("ERROR :: UIService :: Unable to find Outscal Logo Texture");
}

bool SplashScreenUIController::tryLoadingOutscalLogo() { return outscal_logo_texture.loadFromFile("textures/outscal_logo.png"); }

void SplashScreenUIController::setPositionToCenter()
{
    sf::Vector2u windowSize = game_window->getSize();
    sf::Vector2u logoSize = outscal_logo_texture.getSize();
    outscal_logo_sprite.setPosition((windowSize.x - logoSize.x) / 2.0f, (windowSize.y - logoSize.y) / 2.0f);
}

void SplashScreenUIController::show()
{
    // Reset the Clock:
    clock.restart();
    elapsedTime = 0.0f;
    float totalElapsedTime = 0.0f;

    // Loop for Splash Screen Time
    while (totalElapsedTime < splash_screen_time) {
        float deltaTime = clock.restart().asSeconds();
        totalElapsedTime += deltaTime;
        updateLogo(deltaTime);
    }

    logoAnimationComplete();
}

void SplashScreenUIController::updateLogo(float deltaTime)
{
    elapsedTime += deltaTime;
    float alpha = showLogoWithFade();
    if (elapsedTime > 4.0f) // Show for 4 seconds total:
        hideLogoWithFade(alpha);
    renderBrandLogo();
}

// Calculate the alpha value based on elapsed time (e.g., linear interpolation)
float SplashScreenUIController::showLogoWithFade()
{
    float alpha = std::min(1.0f, elapsedTime / logo_animation_time); // Gradually becomes visible over 2 seconds
    outscal_logo_sprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
    return alpha;
}

// Once the logo is fully visible, start fading out after 2 seconds.
void SplashScreenUIController::hideLogoWithFade(float alpha)
{
    alpha = std::max(0.0f, 1.0f - ((elapsedTime - 4.0f) / logo_animation_time));
    outscal_logo_sprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
}

// Draw the brand logo sprite on the window
void SplashScreenUIController::renderBrandLogo()
{
    game_window->clear();
    game_window->draw(outscal_logo_sprite);
    game_window->display();
}

void SplashScreenUIController::logoAnimationComplete() { ServiceLocator::getInstance()->getUIService()->setUIState(UIState::MAIN_MENU); }