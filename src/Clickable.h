#pragma once

#include <functional>
#include <SFML/Graphics.hpp>



class Clickable
{
public:
	typedef std::function<void(Clickable*)> ClickEventHandler;

	Clickable(const bool& isHovered);

	virtual ClickEventHandler getClickEventHandler() const = 0;
	virtual sf::FloatRect getGlobalBounds() const = 0;
	virtual void stateChangeHandler() = 0;

	void setIsHovered(const bool& isHovered);

protected:
	bool isHovered;
};

