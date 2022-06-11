#include "PathfinderGUI.h"
#include "MatrixLayout.h"
#include "HeaderLayout.h"
#include "LabyrinthMatrix.h"


sf::Vector2f calculateMatrixLayoutSize(sf::Vector2f windowSize) {
	return sf::Vector2f(windowSize.x, windowSize.y - HEADER_HEIGHT);
}

void PathfinderGUI::mainLoop()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Labyrinth pathfinder", sf::Style::Close);

	sf::Font font;
	if (!font.loadFromFile("Roboto-Medium.ttf")) throw std::runtime_error("Falied to load font");

	LabyrinthMatrix matrix;
	MatrixLayout matrixLayout(
		sf::Vector2f(0, HEADER_HEIGHT),
		calculateMatrixLayoutSize(window.getView().getSize()),
		window,
		matrix
	);
	HeaderLayout headerLayout(font, window, matrixLayout);
		
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else {
				matrixLayout.handleEvent(event);
				headerLayout.handleEvent(event);
			}
		}

		window.clear(WINDOW_BACKGROUND_COLOR);
		window.draw(matrixLayout);
		window.draw(headerLayout);
		window.display();
	}
}

PathfinderGUI::PathfinderGUI() {
	this->matrix = new LabyrinthMatrix;
}

PathfinderGUI::~PathfinderGUI() {
	delete this->matrix;
}

