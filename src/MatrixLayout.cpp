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
	matrixLayoutNodes(new MatrixLayoutNode [MATRIX_AREA]),
	mode(MatrixLayout::Mode::Initial)
{
	sf::Vector2f currentNodePosition(position);

	float nodeSize = this->calculateNodeSize();

	for (size_t i = 0; i < LABYRINTH_MATRIX_ROWS; i++) {
		currentNodePosition.x = 0;
		for (size_t j = 0; j < LABYRINTH_MATRIX_COLUMNS; j++)
		{
			size_t indexInLayoutNodesArray = i * LABYRINTH_MATRIX_COLUMNS + j;

			Clickable::ClickEventHandler clickEventHandler = 
				[i, j, this](Clickable* clickablePtr) {
				printf("Pressed node %i, %i\n", i, j);

				if (this->mode == MatrixLayout::Mode::LabyrinthEditing) {
					MatrixLayoutNode* const matrixLayoutNodePtr =
						static_cast<MatrixLayoutNode*>(clickablePtr);

					if (matrixLayoutNodePtr->matrixNodePtr == NULL)
					{
						this->matrixPtr->removeWall(i, j);
						matrixLayoutNodePtr->matrixNodePtr = &this->matrixPtr->getNode(i, j);
					}
					else {
						this->matrixPtr->addWall(i, j);
						matrixLayoutNodePtr->matrixNodePtr = NULL;
					}
				}
			};

			this->matrixLayoutNodes[indexInLayoutNodesArray] = MatrixLayoutNode(
				currentNodePosition,
				nodeSize,
				clickEventHandler,
				this->matrixPtr->getNode(i, j)
			);

			this->clickablePointersVector.push_back(
				&matrixLayoutNodes[indexInLayoutNodesArray]
			);

			currentNodePosition.x += nodeSize + NODES_GAP;
		}
		currentNodePosition.y += nodeSize + NODES_GAP;
	}
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

const sf::RenderWindow& MatrixLayout::getWindow() const
{
	return *(this->windowPtr);
}

const std::vector<Clickable*>& MatrixLayout::getClickablePointersVector() const
{
	return this->clickablePointersVector;
}

void MatrixLayout::setSize(const sf::Vector2f &size) {
	this->size = size;
}

void MatrixLayout::setMode(MatrixLayout::Mode mode)
{
	this->mode = mode;
}

MatrixLayout::~MatrixLayout()
{
	delete[] this->matrixLayoutNodes;
}
