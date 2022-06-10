#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "HeaderButton.h"
#include "MatrixLayout.h"


const float HEADER_HEIGHT = 50;

class HeaderLayout: public sf::Drawable {
public:
	HeaderLayout(
		const sf::Font& font,
		const sf::RenderWindow& window,
		MatrixLayout& matrixLayout
	);
	void handleEvent(const sf::Event& event);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void addButton(
		const sf::String& text,
		void (*clickEventHandler)()
	);
	void unhoverHoveredButton();

	MatrixLayout* matrixLayoutPtr;
	const sf::Font* fontPtr;
	std::vector<HeaderButton> buttons;
	HeaderButton* hoveredButtonPtr;
	const sf::RenderWindow* windowPtr;
};
