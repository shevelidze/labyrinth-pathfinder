#include "MatrixLayout.h"
#include <iostream>

const float MATRIX_AREA = LABYRINTH_MATRIX_ROWS * LABYRINTH_MATRIX_COLUMNS;

MatrixLayout::MatrixLayout(const sf::Vector2f& size, LabyrinthMatrix& matrix) : 
	matrix(matrix),
	size(size),
	drawables(MATRIX_AREA),
	hoveredNodeShapePtr(NULL)
{}

void MatrixLayout::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved) {
		if (this->hoveredNodeShapePtr != NULL)
			this->hoveredNodeShapePtr->setFillColor(REGULAR_NODE_COLOR);

		for (auto drawablePtr : this->drawables) {
			auto rectangleShapePtr = static_cast<sf::RectangleShape*>(drawablePtr);
			if (rectangleShapePtr->getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y)) {
				this->hoveredNodeShapePtr = rectangleShapePtr;
				rectangleShapePtr->setFillColor(HOVERED_NODE_COLOR);
			}
		}
	}
}

void MatrixLayout::build() {
	sf::Vector2f currentNodePosition(this->getPosition());

	float nodeSize = this->calculateNodeSize();

	for (size_t i = 0; i < LABYRINTH_MATRIX_ROWS; i++) {
		currentNodePosition.x = 0;
		for (size_t j = 0; j < LABYRINTH_MATRIX_COLUMNS; j++)
		{
			sf::RectangleShape* rectangleShapePtr;
			size_t indexInDrawableArray = i * LABYRINTH_MATRIX_COLUMNS + j;

			if (this->drawables[indexInDrawableArray] == NULL) {
				rectangleShapePtr = new sf::RectangleShape;
				this->drawables[indexInDrawableArray] = rectangleShapePtr;
			}
			else
				rectangleShapePtr = static_cast<sf::RectangleShape*>(this->drawables[i * LABYRINTH_MATRIX_COLUMNS + j]);

			rectangleShapePtr->setSize(sf::Vector2f(nodeSize, nodeSize));
			rectangleShapePtr->setPosition(currentNodePosition);
			rectangleShapePtr->setFillColor(REGULAR_NODE_COLOR);

			currentNodePosition.x += nodeSize + NODES_GAP;
		}
		currentNodePosition.y += nodeSize + NODES_GAP;
	}
}

const std::vector<sf::Drawable*>& MatrixLayout::getDrawables() const
{
	return this->drawables;
}

float MatrixLayout::calculateNodeSize() {
	float nodesVerticalGapsSummary = static_cast<float>(LABYRINTH_MATRIX_ROWS - 1) * NODES_GAP;
	if (nodesVerticalGapsSummary < 0) throw std::overflow_error("Number of matrix rows is too big.");

	float nodesHorisontalGapsSummary = static_cast<float>(LABYRINTH_MATRIX_COLUMNS - 1) * NODES_GAP;
	if (nodesHorisontalGapsSummary < 0) throw std::overflow_error("Number of matrix columns is too big.");

	return std::min(
		static_cast<float>(this->size.y - nodesVerticalGapsSummary) / LABYRINTH_MATRIX_ROWS,
		static_cast<float>(this->size.x - nodesHorisontalGapsSummary) / LABYRINTH_MATRIX_COLUMNS
	);
}

void MatrixLayout::setSize(const sf::Vector2f &size) {
	this->size = size;
}

MatrixLayout::~MatrixLayout()
{
	for (auto drawablePtr : this->drawables) {
		if (drawablePtr != NULL) delete drawablePtr;
	}
}
