#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "HeaderButton.h"
#include "MatrixLayout.h"
#include "ClickableWrapper.h"


const float HEADER_HEIGHT = 50;

class HeaderLayout: public sf::Drawable, public ClickableWrapper {
public:
	HeaderLayout(
		const sf::Font& font,
		const sf::RenderWindow& window,
		MatrixLayout& matrixLayout
	);

	~HeaderLayout();

private:
	void addButton(
		const sf::String& text,
		Clickable::ClickEventHandler clickEventHandler
	);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual const std::vector<Clickable*>& getClickablePointersVector() const override;
	virtual const sf::RenderWindow& getWindow() const override;

	MatrixLayout* matrixLayoutPtr;
	const sf::Font* fontPtr;
	std::vector<HeaderButton*> buttonPointersVector;
	const sf::RenderWindow* windowPtr;

	std::vector<Clickable*> clickablePointersVector;
};
