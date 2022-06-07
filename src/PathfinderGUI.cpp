#include "PathfinderGUI.h"
#include <iostream>

const float NODES_GAP = 3;

template <class T> void printVector(sf::Vector2<T> vector) {
	std::cout << vector.x << ' ' << vector.y << '\n';
}

void PathfinderGUI::mainLoop()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Labyrinth pathfinder");

	const float nodeSize = this->calculateNodeSize(window.getView().getSize());
		
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::Resized) {
				printVector<float>(window.getDefaultView().getSize());
				printVector<unsigned>(window.getSize());

				const sf::Vector2f floatWindowSize(window.getSize());
				const sf::Vector2f newViewCenter(floatWindowSize.x / 2, floatWindowSize.y / 2);

				this->windowView = sf::View(newViewCenter, floatWindowSize);
				window.setView(this->windowView);
			}
		}

		window.clear();

		sf::Vector2f currentNodePosition(0, 0);
		for (size_t i = 0; i < LABYRINTH_MATRIX_ROWS; i++) {
			currentNodePosition.x = 0;
			for (size_t j = 0; j < LABYRINTH_MATRIX_COLUMNS; j++)
			{
				sf::RectangleShape recktangleShape;
				recktangleShape.setSize(sf::Vector2f(nodeSize, nodeSize));
				recktangleShape.setPosition(currentNodePosition);
				recktangleShape.setFillColor(sf::Color::Magenta);
				window.draw(recktangleShape);
				currentNodePosition.x += nodeSize + NODES_GAP;
			}
			currentNodePosition.y += nodeSize + NODES_GAP;
		}

		window.display();
	}
}

PathfinderGUI::PathfinderGUI() {
	this->matrix = new LabyrinthMatrix;
}

PathfinderGUI::~PathfinderGUI() {
	delete this->matrix;
}

float PathfinderGUI::calculateNodeSize(sf::Vector2f matrixRectangleSize) {
	float nodesVerticalGapsSummary = static_cast<float>(LABYRINTH_MATRIX_ROWS - 1) * NODES_GAP;
	if (nodesVerticalGapsSummary < 0) throw std::overflow_error("Number of matrix rows is too big.");

	float nodesHorisontalGapsSummary = static_cast<float>(LABYRINTH_MATRIX_COLUMNS - 1) * NODES_GAP;
	if (nodesHorisontalGapsSummary < 0) throw std::overflow_error("Number of matrix columns is too big.");

	return std::min(
		static_cast<float>(matrixRectangleSize.y - nodesVerticalGapsSummary) / LABYRINTH_MATRIX_ROWS,
		static_cast<float>(matrixRectangleSize.x - nodesHorisontalGapsSummary) / LABYRINTH_MATRIX_COLUMNS
	);
}
