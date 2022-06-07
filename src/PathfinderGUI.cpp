#include "PathfinderGUI.h"
#include "MatrixLayout.h"
#include "LabyrinthMatrix.h"


void PathfinderGUI::mainLoop()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Labyrinth pathfinder");
	window.setFramerateLimit(30);

	LabyrinthMatrix matrix;
	MatrixLayout matrixLayout(window.getView().getSize(), matrix);
	matrixLayout.build();
		
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::Resized) {
				const sf::Vector2f floatWindowSize(window.getSize());
				const sf::Vector2f newViewCenter(floatWindowSize.x / 2, floatWindowSize.y / 2);

				matrixLayout.setSize(floatWindowSize);
				matrixLayout.build();

				this->windowView = sf::View(newViewCenter, floatWindowSize);
				window.setView(this->windowView);
			}
		}

		window.clear();

		window.draw(matrixLayout);

		window.display();
	}
}

PathfinderGUI::PathfinderGUI() {
	this->matrix = new LabyrinthMatrix;
}

PathfinderGUI::~PathfinderGUI() {
	delete this->matrix;
}

