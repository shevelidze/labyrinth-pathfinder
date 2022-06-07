#include "Layout.h"

void Layout::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (auto& drawable : this->getDrawables()) {
		target.draw(*drawable, states);
	}
};