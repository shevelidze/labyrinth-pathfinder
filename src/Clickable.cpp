#include "Clickable.h"


Clickable::Clickable(const bool& isHovered) : isHovered(isHovered) {};

void Clickable::setIsHovered(const bool& isHovered)
{
	bool isHoveredOldValue = this->isHovered;
	this->isHovered = isHovered;
	if (isHoveredOldValue != this->isHovered) this->stateChangeHandler();
}
