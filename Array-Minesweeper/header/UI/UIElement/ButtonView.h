#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include <functional>

namespace UI
{
	namespace UIElement
	{
		enum class ButtonType
		{
			LEFT_MOUSE_BUTTON,
			RIGHT_MOUSE_BUTTON,
		};
		class ButtonView : public ImageView
		{
		private:
			
			using CallbackFunction = std::function<void(ButtonType)>;

			CallbackFunction callback_function = nullptr;

			void printButtonClicked();

		protected:
			sf::String button_title;

			virtual void handleButtonInteraction();
			
			virtual bool clickedLeftMouseButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position);
			virtual bool clickedRightMouseButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position);


		public:
			ButtonView();
			virtual ~ButtonView();

			virtual void initialize(sf::String title, sf::String texture_path, float button_width, float button_height, sf::Vector2f position);
			virtual void update() override;
			virtual void render() override;

			void registerCallbackFuntion(CallbackFunction button_callback);
		};
	}
}