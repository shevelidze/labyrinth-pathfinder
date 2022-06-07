#pragma once

#include <SFML/Graphics.hpp>
#include "LabyrinthMatrix.h"
#include "HeaderLayout.h"

const sf::Color WINDOW_BACKGROUND_COLOR(85, 85, 85);

class PathfinderGUI {
public:
	void mainLoop();
	PathfinderGUI();
	~PathfinderGUI();
private:
	LabyrinthMatrix* matrix;
	sf::View windowView;
};