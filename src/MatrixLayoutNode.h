#pragma once

#include <SFML/Graphics.hpp>
#include "MatrixNode.h"


const sf::Color REGULAR_NODE_COLOR(93, 95, 105);
const sf::Color HOVERED_NODE_COLOR(63, 93, 224);

class MatrixLayoutNode : public sf::RectangleShape {
public:
	MatrixLayoutNode(const sf::Vector2f &position, const float &size, const MatrixNode &matrixNode);
	MatrixLayoutNode();
	void setIsHovered(bool isHovered);
private:
	void updateColor();
	bool isHovered;
	const MatrixNode *matrixNode;
};