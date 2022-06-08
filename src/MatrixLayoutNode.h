#pragma once

#include <SFML/Graphics.hpp>
#include "MatrixNode.h"


const sf::Color REGULAR_NODE_COLOR(122, 12, 50);
const sf::Color HOVERED_NODE_COLOR(6, 10, 66);

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