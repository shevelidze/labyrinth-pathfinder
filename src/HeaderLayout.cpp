#include "HeaderLayout.h"
#include <iostream>


HeaderLayout::HeaderLayout(
	const sf::Font& font,
	const sf::RenderWindow& window,
	MatrixLayout& matrixLayout
) :
	matrixLayoutPtr(&matrixLayout),
	fontPtr(&font),
	windowPtr(&window)
{
	this->addButton("Button 1", []() {std::cout << "Button1 pressed\n"; });
	this->addButton("Button 2", []() {std::cout << "Button2 pressed\n"; });
	this->addButton("Button 3", []() {std::cout << "Button3 pressed\n"; });
}

HeaderLayout::~HeaderLayout()
{
	for (auto& buttonPtr : this->buttonPointersVector) delete buttonPtr;
}

void HeaderLayout::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto buttonPtr : this->buttonPointersVector) {
		target.draw(*buttonPtr, states);
	}
}

const std::vector<Clickable*>& HeaderLayout::getClickablePointersVector() const
{
	return this->clickablePointersVector;
}

const sf::RenderWindow& HeaderLayout::getWindow() const
{
	return *this->windowPtr;
}

void HeaderLayout::addButton(const sf::String& text, void(*clickEventHandler)())
{
	sf::Vector2f newButtonPosition(
		this->buttonPointersVector.empty() ? 0 : (
			this->buttonPointersVector.back()->getGlobalBounds().left +
			this->buttonPointersVector.back()->getGlobalBounds().width
		),
		0
	);

	HeaderButton* newButtonPtr = new HeaderButton(
		newButtonPosition,
		HEADER_HEIGHT,
		*(this->fontPtr),
		text,
		clickEventHandler
	);

	this->buttonPointersVector.push_back(newButtonPtr);
	this->clickablePointersVector.push_back(newButtonPtr);
}
