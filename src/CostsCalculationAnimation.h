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
		MatrixNode* beginNodePtr,
		LabyrinthMatrix* matrixPtr,
		const sf::Time& stepDuration
	);

	virtual void step() override;

private:
	std::queue<MatrixNode*> nodesProcessingQueue;
	MatrixNode* beginNodePtr;
	LabyrinthMatrix* matrixPtr;
	unsigned cost = 0;
};

