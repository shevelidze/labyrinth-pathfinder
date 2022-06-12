#include "HeaderButton.h"


HeaderButton::HeaderButton(
	const sf::Vector2f& position,
	const float& height,
	const sf::Font& font,
	const sf::String& text,
	ClickEventHandler clickEventHandler
) :
	Clickable(false),
	clickEventHandler(clickEventHandler)
{
	this->textDrawable.setString(text);
	this->textDrawable.setFont(font);
	this->textDrawable.setCharacterSize(HEADER_BUTTON_CHARACTER_SIZE);

	sf::FloatRect textGlobalBounds = this->textDrawable.getGlobalBounds();

	this->textDrawable.setOrigin(
		(textGlobalBounds.left + textGlobalBounds.width) / 2.0f,
		(textGlobalBounds.top + textGlobalBounds.height) / 2.0f
	);

	this->rectangleShape.setPosition(position);
	this->rectangleShape.setSize(
		sf::Vector2f(
			this->textDrawable.getGlobalBounds().width +
			2 * HEADER_BUTTON_HORIZONTAL_PADDING,
			height
		)
	);

	this->textDrawable.setPosition(
		position.x + this->rectangleShape.getSize().x / 2.0f,
		position.y + this->rectangleShape.getSize().y / 2.0f
	);

	this->stateChangeHandler();
}

sf::FloatRect HeaderButton::getGlobalBounds() const
{
	return this->rectangleShape.getGlobalBounds();
}

Clickable::ClickEventHandler HeaderButton::getClickEventHandler() const
{
	return this->clickEventHandler;
}

void HeaderButton::setIsHovered(const bool& isHovered)
{
	this->isHovered = isHovered;
	this->stateChangeHandler();
}

void HeaderButton::stateChangeHandler()
{
	if (this->isHovered) {
		this->rectangleShape.setFillColor(HOVERED_HEADER_BUTTON_BACKGROUND_COLOR);
		this->textDrawable.setFillColor(HOVERED_HEADER_BUTTON_FOREGROUND_COLOR);
	}
	else {
		this->rectangleShape.setFillColor(REGULAR_HEADER_BUTTON_BACKGROUND_COLOR);
		this->textDrawable.setFillColor(REGULAR_HEADER_BUTTON_FOREGROUND_COLOR);
	}
	return;
}

void HeaderButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->rectangleShape, states);
	target.draw(this->textDrawable, states);
}
