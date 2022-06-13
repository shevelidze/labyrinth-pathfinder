#pragma once

#include <SFML/Graphics.hpp>
#include "MatrixNode.h"
#include "Clickable.h"


const sf::Color REGULAR_NODE_COLOR(93, 95, 105);
const sf::Color HOVERED_NODE_COLOR(63, 93, 224);

class MatrixLayoutNode : public sf::RectangleShape, public Clickable {
public:
	MatrixLayoutNode(
		const sf::Vector2f& position,
		const float& size,
		ClickEventHandler clickEventHandler,
		MatrixNode &matrixNode
	);
	MatrixLayoutNode();

	void setIsBoundary(const bool& isBoundary);

	virtual ClickEventHandler getClickEventHandler() const override;
	virtual sf::FloatRect getGlobalBounds() const override;

private:
	virtual void stateChangeHandler() override;

	MatrixNode *matrixNodePtr;
	ClickEventHandler clickEventHandler;

	bool isBoundary;

	friend class MatrixLayout;
};