#pragma once

#include <vector>
#include "Clickable.h"


class ClickableWrapper
{
public:
	void handleEvent(const sf::Event& event);

private:
	virtual const std::vector<Clickable*>& getClickablePointersVector() const = 0;
	virtual const sf::RenderWindow& getWindow() const = 0;

	void unhoverHoveredClickable();

	Clickable* hoveredClickablePtr;
};
