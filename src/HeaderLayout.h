#pragma once

#include <SFML/Graphics.hpp>


const float HEADER_HEIGHT = 50;

class HeaderLayout: public sf::Drawable {
public:
	HeaderLayout(float width);

private:
	float width;
};
