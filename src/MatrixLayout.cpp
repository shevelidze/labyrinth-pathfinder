#include "MatrixLayout.h"

MatrixLayout::MatrixLayout(const sf::Vector2f& size, LabyrinthMatrix& matrix) : 
	matrix(matrix),
	size(size),
	drawables(LABYRINTH_MATRIX_ROWS * LABYRINTH_MATRIX_COLUMNS)
{}

void MatrixLayout::handleEvent(const sf::Event& event)
{
}

void MatrixLayout::build() {
	sf::Vector2f currentNodePosition(this->getPosition());

	float nodeSize = this->calculateNodeSize();

	for (size_t i = 0; i < LABYRINTH_MATRIX_ROWS; i++) {
		currentNodePosition.x = 0;
		for (size_t j = 0; j < LABYRINTH_MATRIX_COLUMNS; j++)
		{
			sf::RectangleShape* recktangleShape = new sf::RectangleShape;
			recktangleShape->setSize(sf::Vector2f(nodeSize, nodeSize));
			recktangleShape->setPosition(currentNodePosition);
			recktangleShape->setFillColor(sf::Color::Magenta);
			this->drawables[i * LABYRINTH_MATRIX_COLUMNS + j] = recktangleShape;
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
