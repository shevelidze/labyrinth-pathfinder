#pragma once

#include "Layout.h"

const float HEADER_HEIGHT = 50;

class HeaderLayout : public Layout {
public:
	HeaderLayout(float width);

private:
	virtual const std::vector<sf::Drawable*>& getDrawables() const override;
	float width;
};
