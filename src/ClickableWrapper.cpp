#include "ClickableWrapper.h"
#include <iostream>


ClickableWrapper::ClickableWrapper() :
	hoveredClickablePtr(NULL),
	lastClickedClickablePtr(NULL),
	leftMouseButtonIsPressed(false)
{}


void ClickableWrapper::handleEvent(const sf::Event& event)
{
	if (
		event.type == sf::Event::MouseButtonPressed &&
		event.mouseButton.button == sf::Mouse::Left
		)
		this->leftMouseButtonIsPressed = true;
	else if (
		event.type == sf::Event::MouseButtonReleased &&
		event.mouseButton.button == sf::Mouse::Left
		)
	{
		this->leftMouseButtonIsPressed = false;
		this->lastClickedClickablePtr = NULL;
	}

	if (event.type == sf::Event::MouseMoved || 
		event.type == sf::Event::MouseButtonPressed
		) {
		for (auto clickablePtr : this->getClickablePointersVector()) {
			sf::Vector2i mousePosition(
				event.type == sf::Event::MouseMoved ? event.mouseMove.x : event.mouseButton.x,
				event.type == sf::Event::MouseMoved ? event.mouseMove.y : event.mouseButton.y
			);

			if (
				clickablePtr->getGlobalBounds().contains(
					this->getWindow().mapPixelToCoords(mousePosition)
				)
			) {
				this->unhoverHoveredClickable();
				clickablePtr->setIsHovered(true);
				this->hoveredClickablePtr = clickablePtr;

				if (
					this->leftMouseButtonIsPressed &&
					clickablePtr != this->lastClickedClickablePtr
				) {
					clickablePtr->getClickEventHandler()(clickablePtr);
					this->lastClickedClickablePtr = clickablePtr;
				}

				return;
			}
		}
		this->unhoverHoveredClickable();
	}
	else if (event.type == sf::Event::MouseLeft)
		this->unhoverHoveredClickable();
}

void ClickableWrapper::unhoverHoveredClickable()
{
	if (this->hoveredClickablePtr != NULL) {
		this->hoveredClickablePtr->setIsHovered(false);
		this->hoveredClickablePtr = NULL;
	}
}
