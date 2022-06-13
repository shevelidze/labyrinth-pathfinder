#pragma once

#include <queue>
#include <SFML/System.hpp>
#include "StepAnimation.h"
#include "MatrixNode.h"
#include "LabyrinthMatrix.h"


class CostsCalculationAnimation : public StepAnimation
{
public:
	CostsCalculationAnimation(
		MatrixNode& beginNode,
		LabyrinthMatrix& matrix,
		const sf::Time& stepDuration
	);

private:
	virtual void step() override;

	std::queue<MatrixNode*> nodesProcessingQueue;
	MatrixNode* beginNodePtr;
	LabyrinthMatrix* matrixPtr;
	unsigned cost = 0;
};

