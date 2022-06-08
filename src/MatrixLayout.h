#pragma once

#include <SFML/Graphics.hpp>
#include "LabyrinthMatrix.h"
#include "MatrixLayoutNode.h"

const float NODES_GAP = 5;

class MatrixLayout : public sf::Drawable
{
public:
	MatrixLayout(const sf::Vector2f& posiition, const sf::Vector2f& size, LabyrinthMatrix &matrix);
	void handleEvent(const sf::Event& event);
	void build();
	void setSize(const sf::Vector2f &size);
	~MatrixLayout();

private:
	float calculateNodeSize();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void unhoverHoveredLayoutNode();

	sf::Vector2f size;
	LabyrinthMatrix& matrix;
	MatrixLayoutNode* matrixLayoutNodes;
	MatrixLayoutNode* hoveredLayoutNodePtr;
};
