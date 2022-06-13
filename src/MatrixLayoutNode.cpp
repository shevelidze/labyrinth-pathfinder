#include "MatrixLayoutNode.h"


MatrixLayoutNode::MatrixLayoutNode(
	const sf::Vector2f &position,
	const float &size,
	ClickEventHandler clickEventHandler,
	MatrixNode& matrixNode
) :
	Clickable(false),
	matrixNodePtr(&matrixNode),
	clickEventHandler(clickEventHandler),
	isBoundary(false)
{
	this->setSize(sf::Vector2f(size, size));
	this->setPosition(position);
	this->stateChangeHandler();
}

MatrixLayoutNode::MatrixLayoutNode() :
	Clickable(false),
	matrixNodePtr(NULL),
	clickEventHandler(NULL),
	isBoundary(false)
{}

void MatrixLayoutNode::setIsBoundary(const bool& isBoundary)
{
	this->isBoundary = isBoundary;
	this->stateChangeHandler();
}

Clickable::ClickEventHandler MatrixLayoutNode::getClickEventHandler() const
{
	return this->clickEventHandler;
}

sf::FloatRect MatrixLayoutNode::getGlobalBounds() const
{
	return this->sf::RectangleShape::getGlobalBounds();
};

void MatrixLayoutNode::stateChangeHandler() {
	if (this->isHovered) this->setFillColor(HOVERED_NODE_COLOR);
	else if (this->matrixNodePtr == NULL) this->setFillColor(sf::Color::Black);
	else if (this->isBoundary) this->setFillColor(sf::Color::Yellow);
	else if (this->matrixNodePtr->checkIfVisited()) this->setFillColor(sf::Color::Magenta);
	else if (this->matrixNodePtr->getIsQueued()) this->setFillColor(sf::Color(50, 50, 50));
	else this->setFillColor(REGULAR_NODE_COLOR);
}