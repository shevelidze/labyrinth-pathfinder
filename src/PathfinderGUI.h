#pragma once

#include <SFML/Graphics.hpp>
#include "LabyrinthMatrix.h"

class PathfinderGUI {
public:
	void mainLoop();
	PathfinderGUI();
	~PathfinderGUI();
private:
	LabyrinthMatrix* matrix;
	float calculateNodeSize(sf::Vector2f windowViewSize);
};