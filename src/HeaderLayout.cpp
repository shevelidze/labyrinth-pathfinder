#include "HeaderLayout.h"
#include <iostream>


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
	this->addButton("Button 1", []() {std::cout << "Button1 pressed\n"; });
	this->addButton("Button 2", []() {std::cout << "Button2 pressed\n"; });
	this->addButton("Button 3", []() {std::cout << "Button3 pressed\n"; });
}

void HeaderLayout::handleEvent(const sf::Event& event)
{
	if (
		event.type == sf::Event::MouseMoved ||
		(
			event.type == sf::Event::MouseButtonPressed &&
			event.mouseButton.button == sf::Mouse::Left
		)
	) {
		for (auto& button : this->buttons) {
			sf::Vector2i mousePosition(
				event.type == sf::Event::MouseMoved ? event.mouseMove.x : event.mouseButton.x,
				event.type == sf::Event::MouseMoved ? event.mouseMove.y : event.mouseButton.y
			);

			if (button.getGlobalBounds().contains(
				this->windowPtr->mapPixelToCoords(mousePosition)
			)) {
				unhoverHoveredButton();
				button.setIsHovered(true);
				this->hoveredButtonPtr = &button;

				if (event.type == sf::Event::MouseButtonPressed) {
					button.getClickEventHandler()();
				}

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
