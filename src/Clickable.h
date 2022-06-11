#pragma once

#include <functional>
#include <SFML/Graphics.hpp>

typedef std::function<void()> ClickEventHandler;


class Clickable
{
public:
	Clickable(const bool& isHovered);

	virtual ClickEventHandler getClickEventHandler() const = 0;
	virtual sf::FloatRect getGlobalBounds() const = 0;
	virtual void stateChangeHandler() = 0;

	void setIsHovered(const bool& isHovered);

protected:
	bool isHovered;
};

