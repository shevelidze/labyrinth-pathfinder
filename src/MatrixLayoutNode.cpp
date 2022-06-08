#include "MatrixLayoutNode.h"
#include <iostream>

MatrixLayoutNode::MatrixLayoutNode(
	const sf::Vector2f &position,
	const float &size,
	const MatrixNode& matrixNode
) : matrixNode(&matrixNode), isHovered(false)
{
	this->setSize(sf::Vector2f(size, size));
	this->setPosition(position);
	this->updateColor();
}

MatrixLayoutNode::MatrixLayoutNode() {};

void MatrixLayoutNode::setIsHovered(bool isHovered)
{
	this->isHovered = isHovered;
	this->updateColor();
}

void MatrixLayoutNode::updateColor() {
	if (this->isHovered) {
		this->setFillColor(HOVERED_NODE_COLOR);
	}
	else this->setFillColor(REGULAR_NODE_COLOR);
}