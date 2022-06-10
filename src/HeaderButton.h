#pragma once

#include <SFML/Graphics.hpp>


typedef void (*ClckEventHandler)();

const unsigned HEADER_BUTTON_CHARACTER_SIZE = 20;
const float HEADER_BUTTON_HORIZONTAL_PADDING = 15;

const sf::Color REGULAR_HEADER_BUTTON_BACKGROUND_COLOR(0, 0, 0, 0);
const sf::Color REGULAR_HEADER_BUTTON_FOREGROUND_COLOR(255, 255, 255);

const sf::Color HOVERED_HEADER_BUTTON_BACKGROUND_COLOR(255, 255, 255, 50);
const sf::Color HOVERED_HEADER_BUTTON_FOREGROUND_COLOR(255, 255, 255);

class HeaderButton : public sf::Drawable
{
public:
	HeaderButton(
		const sf::Vector2f &position,
		const float &height,
		const sf::Font& font,
		const sf::String& text,
		void (*clickEventHandler)()
	);

	const sf::FloatRect getGlobalBounds();
	ClckEventHandler getClickEventHandler();

	void setIsHovered(const bool& isHovered);

private:
	void updateColor();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::RectangleShape rectangleShape;
	sf::Text textDrawable;
	void (*clickEventHandler)();
	bool isHovered;
};

