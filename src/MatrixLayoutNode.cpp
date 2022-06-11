#include "MatrixLayoutNode.h"


MatrixLayoutNode::MatrixLayoutNode(
	const sf::Vector2f &position,
	const float &size,
	ClickEventHandler clickEventHandler,
	const MatrixNode& matrixNode
) :
	Clickable(false),
	matrixNodePtr(&matrixNode),
	clickEventHandler(clickEventHandler)
{
	this->setSize(sf::Vector2f(size, size));
	this->setPosition(position);
	this->stateChangeHandler();
}

MatrixLayoutNode::MatrixLayoutNode() :
	Clickable(false),
	matrixNodePtr(NULL),
	clickEventHandler(NULL)
{}

ClickEventHandler MatrixLayoutNode::getClickEventHandler() const
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
	else this->setFillColor(REGULAR_NODE_COLOR);
}