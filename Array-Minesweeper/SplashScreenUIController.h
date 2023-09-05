#pragma once
#include <SFML/Graphics.hpp>

class SplashScreenUIController
{
private:
	// Constants:
	const float logo_animation_time = 2.0f;
	const float splash_screen_time = 6.0f;

	sf::RenderWindow* game_window;
	sf::Texture outscal_logo_texture;
	sf::Sprite outscal_logo_sprite;
	sf::Clock clock;
	float elapsedTime;

	// Initialization:
	void initializeVariables(sf::RenderWindow* window);
	void initializeOutscalLogo();
	void loadOutscalTexture();
	bool tryLoadingOutscalLogo();
	void setPositionToCenter();

	float showLogoWithFade();
	void hideLogoWithFade(float alpha);
	void renderBrandLogo();
	void logoAnimationComplete();
	void updateLogo(float deltaTime);

public:
	SplashScreenUIController(sf::RenderWindow* window);

	void show();
};