#include "MatrixLayout.h"
#include <iostream>

const size_t MATRIX_AREA = LABYRINTH_MATRIX_ROWS * LABYRINTH_MATRIX_COLUMNS;

MatrixLayout::MatrixLayout(
	const sf::Vector2f& position,
	const sf::Vector2f& size,
	const sf::RenderWindow& window,
	LabyrinthMatrix& matrix
) :
	matrixPtr(&matrix),
	size(size),
	windowPtr(&window),
	hoveredLayoutNodePtr(NULL),
	matrixLayoutNodes(new MatrixLayoutNode [MATRIX_AREA])
{
	sf::Vector2f currentNodePosition(position);

	float nodeSize = this->calculateNodeSize();

	for (size_t i = 0; i < LABYRINTH_MATRIX_ROWS; i++) {
		currentNodePosition.x = 0;
		for (size_t j = 0; j < LABYRINTH_MATRIX_COLUMNS; j++)
		{
			size_t indexInLayoutNodesArray = i * LABYRINTH_MATRIX_COLUMNS + j;

			this->matrixLayoutNodes[indexInLayoutNodesArray] = MatrixLayoutNode(
				currentNodePosition,
				nodeSize,
				this->matrixPtr->getNode(i, j)
				);

			currentNodePosition.x += nodeSize + NODES_GAP;
		}
		currentNodePosition.y += nodeSize + NODES_GAP;
	}
}

void MatrixLayout::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved) {
		for (size_t i = 0; i < MATRIX_AREA; i++) {
			const sf::Vector2f worldPos = this->windowPtr->mapPixelToCoords(
				sf::Vector2i(event.mouseMove.x, event.mouseMove.y)
			);
			if (this->matrixLayoutNodes[i].getGlobalBounds().contains(worldPos)) {
				if (this->hoveredLayoutNodePtr != this->matrixLayoutNodes + i) {
					this->unhoverHoveredLayoutNode();
					this->hoveredLayoutNodePtr = this->matrixLayoutNodes + i;
					this->matrixLayoutNodes[i].setIsHovered(true);
				}
				return;
			}
		}
		this->unhoverHoveredLayoutNode();
	}
}

void MatrixLayout::build() {
	//sf::Vector2f currentNodePosition(this->getPosition());

	//float nodeSize = this->calculateNodeSize();

	//for (size_t i = 0; i < LABYRINTH_MATRIX_ROWS; i++) {
	//	currentNodePosition.x = 0;
	//	for (size_t j = 0; j < LABYRINTH_MATRIX_COLUMNS; j++)
	//	{
	//		sf::RectangleShape* rectangleShapePtr;
	//		size_t indexInDrawableArray = i * LABYRINTH_MATRIX_COLUMNS + j;

	//		if (this->drawables[indexInDrawableArray] == NULL) {
	//			rectangleShapePtr = new sf::RectangleShape;
	//			this->drawables[indexInDrawableArray] = rectangleShapePtr;
	//		}
	//		else
	//			rectangleShapePtr = static_cast<sf::RectangleShape*>(this->drawables[i * LABYRINTH_MATRIX_COLUMNS + j]);

	//		rectangleShapePtr->setSize(sf::Vector2f(nodeSize, nodeSize));
	//		rectangleShapePtr->setPosition(currentNodePosition);
	//		rectangleShapePtr->setFillColor(REGULAR_NODE_COLOR);

	//		currentNodePosition.x += nodeSize + NODES_GAP;
	//	}
	//	currentNodePosition.y += nodeSize + NODES_GAP;
	//}
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

void MatrixLayout::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (size_t i = 0; i < MATRIX_AREA; i++) {
		target.draw(this->matrixLayoutNodes[i], states);
	}
}

void MatrixLayout::unhoverHoveredLayoutNode()
{
	if (this->hoveredLayoutNodePtr != NULL) this->hoveredLayoutNodePtr->setIsHovered(false);
}

void MatrixLayout::setSize(const sf::Vector2f &size) {
	this->size = size;
}

MatrixLayout::~MatrixLayout()
{
	delete[] this->matrixLayoutNodes;
}
