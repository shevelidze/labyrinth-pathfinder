#pragma once

#include <SFML/Graphics.hpp>
#include "LabyrinthMatrix.h"
#include "MatrixLayoutNode.h"
#include "ClickableWrapper.h"

const float NODES_GAP = 5;

class MatrixLayout : public sf::Drawable, public ClickableWrapper
{
public:
	enum class Mode {
		Initial,
		LabyrinthEditing,
		PointsChoosing,
		AnimationViewing
	};

	MatrixLayout(
		const sf::Vector2f& position,
		const sf::Vector2f& size,
		const sf::RenderWindow& window,
		LabyrinthMatrix &matrix
	);
	~MatrixLayout();

	void setSize(const sf::Vector2f &size);
	void setMode(MatrixLayout::Mode mode);

private:
	float calculateNodeSize();
	void modeChangeHandler();
	void removeBoundaryPoints();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	virtual const sf::RenderWindow& getWindow() const override;
	virtual const std::vector<Clickable*>& getClickablePointersVector() const override;

	sf::Vector2f size;
	MatrixLayout::Mode mode;

	LabyrinthMatrix *matrixPtr;
	const sf::RenderWindow* windowPtr;

	MatrixLayoutNode* matrixLayoutNodes;
	MatrixLayoutNode* hoveredLayoutNodePtr;
	
	std::vector<Clickable*> clickablePointersVector;

	MatrixLayoutNode* pathBeginLayoutNodePtr;
	MatrixLayoutNode* pathEndLayoutNodePtr;
};
