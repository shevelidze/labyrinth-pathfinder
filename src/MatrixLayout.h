#pragma once

#include <set>
#include "Layout.h"
#include "LabyrinthMatrix.h"

const float NODES_GAP = 5;
const sf::Color REGULAR_NODE_COLOR(122, 12, 50);
const sf::Color HOVERED_NODE_COLOR(6, 10, 66);

class MatrixLayout : public Layout 
{
public:
	MatrixLayout(const sf::Vector2f& size, LabyrinthMatrix &matrix);
	void handleEvent(const sf::Event& event);
	void build();
	void setSize(const sf::Vector2f &size);
	~MatrixLayout();
private:
	virtual const std::vector<sf::Drawable*>& getDrawables() const override;
	float calculateNodeSize();

	sf::Vector2f size;
	LabyrinthMatrix& matrix;
	std::vector<sf::Drawable*> drawables;
	sf::RectangleShape* hoveredNodeShapePtr;
};
