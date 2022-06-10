#include "HeaderLayout.h"


HeaderLayout::HeaderLayout(
	const sf::Font& font,
	const sf::RenderWindow& window,
	MatrixLayout& matrixLayout
) :
	matrixLayoutPtr(&matrixLayout),
	fontPtr(&font),
	hoveredButtonPtr(NULL),
	windowPtr(&window)
{
	this->addButton("Button 1", []() {});
	this->addButton("Button 2", []() {});
	this->addButton("Button 3", []() {});
}

void HeaderLayout::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved) {
		for (auto& button : this->buttons) {
			if (button.getGlobalBounds().contains(
				this->windowPtr->mapPixelToCoords(sf::Vector2i(
					event.mouseMove.x,
					event.mouseMove.y
				))
			)) {
				unhoverHoveredButton();
				button.setIsHovered(true);
				this->hoveredButtonPtr = &button;
				return;
			}
		}
		unhoverHoveredButton();
	}
	else if (event.type == sf::Event::MouseLeft)
		this->unhoverHoveredButton();
}

void HeaderLayout::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto button : this->buttons) {
		target.draw(button, states);
	}
}

void HeaderLayout::addButton(const sf::String& text, void(*clickEventHandler)())
{
	sf::Vector2f newButtonPosition(
		this->buttons.empty() ? 0 : (
			this->buttons.back().getGlobalBounds().left +
			this->buttons.back().getGlobalBounds().width
		),
		0
	);
	this->buttons.push_back(
		HeaderButton(newButtonPosition, HEADER_HEIGHT, *(this->fontPtr), text, clickEventHandler)
	);
}

void HeaderLayout::unhoverHoveredButton()
{
	if (this->hoveredButtonPtr != NULL) {
		this->hoveredButtonPtr->setIsHovered(false);
		this->hoveredButtonPtr = NULL;
	}
}
