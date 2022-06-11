#pragma once

#include <SFML/Graphics.hpp>
#include "LabyrinthMatrix.h"
#include "MatrixLayoutNode.h"
#include "ClickableWrapper.h"

const float NODES_GAP = 5;

class MatrixLayout : public sf::Drawable, public ClickableWrapper
{
public:
	MatrixLayout(
		const sf::Vector2f& position,
		const sf::Vector2f& size,
		const sf::RenderWindow& window,
		LabyrinthMatrix &matrix
	);
	void setSize(const sf::Vector2f &size);
	~MatrixLayout();

private:
	float calculateNodeSize();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	virtual const sf::RenderWindow& getWindow() const override;
	virtual const std::vector<Clickable*>& getClickablePointersVector() const override;

	sf::Vector2f size;
	LabyrinthMatrix *matrixPtr;
	MatrixLayoutNode* matrixLayoutNodes;
	MatrixLayoutNode* hoveredLayoutNodePtr;
	const sf::RenderWindow* windowPtr;
	std::vector<Clickable*> clickablePointersVector;
};
