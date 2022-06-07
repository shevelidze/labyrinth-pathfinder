#pragma once

#include "Layout.h"
#include "LabyrinthMatrix.h"

const float NODES_GAP = 5;

class MatrixLayout : public Layout 
{
public:
	MatrixLayout(const sf::Vector2f& size, LabyrinthMatrix &matrix);
	void handleEvent(const sf::Event& event);
	void build();
	void setSize(const sf::Vector2f &size);
private:
	virtual const std::vector<sf::Drawable*>& getDrawables() const override;
	float calculateNodeSize();

	sf::Vector2f size;
	LabyrinthMatrix& matrix;
	std::vector<sf::Drawable *> drawables;
};
