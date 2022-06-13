#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "LabyrinthMatrix.h"
#include "MatrixLayoutNode.h"
#include "ClickableWrapper.h"
#include "PathFindingAnimation.h"

const float NODES_GAP = 5;
const sf::Time ANIMATION_STEP_DURATION = sf::milliseconds(50);

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
	bool setMode(MatrixLayout::Mode mode);
	void startPathFindingAnimation();

private:
	float calculateNodeSize();
	void modeChangeHandler();
	void removeBoundaryPoints();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	virtual const sf::RenderWindow& getWindow() const override;
	virtual const std::vector<Clickable*>& getClickablePointersVector() const override;

	sf::Vector2f size;
	const sf::RenderWindow* windowPtr;

	MatrixLayout::Mode mode;
	LabyrinthMatrix *matrixPtr;

	MatrixLayoutNode* matrixLayoutNodes;
	MatrixLayoutNode* hoveredLayoutNodePtr;
	
	std::vector<Clickable*> clickablePointersVector;

	MatrixLayoutNode* pathBeginLayoutNodePtr;
	MatrixLayoutNode* pathEndLayoutNodePtr;

	mutable std::vector<StepAnimation*> stepAnimationPointersVector;
};
