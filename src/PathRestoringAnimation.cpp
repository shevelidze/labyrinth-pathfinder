#include "PathRestoringAnimation.h"


PathRestoringAnimation::PathRestoringAnimation(MatrixNode& endNode, LabyrinthMatrix& matrix, const sf::Time& stepDuration) :
	StepAnimation(stepDuration),
	endNodePtr(&endNode),
	matrixPtr(&matrix),
	currentNodePtr(NULL)
{
	this->currentNodePtr = this->endNodePtr;
}

void PathRestoringAnimation::step()
{
	if (!this->endNodePtr->checkIfVisited()) {
		this->finish();
		return;
	}

	if (this->currentNodePtr->getCost() == 0) {
		this->finish();
		return;
	}

	this->currentNodePtr->setIsUsedInPath(true);

	unsigned minCost = UINT_MAX;
	MatrixNode* minCostRelatedNodePtr = NULL;

	for (auto relatedNodePtr : this->matrixPtr->findRelatedNodes(currentNodePtr)) {
		if (relatedNodePtr->getCost() < minCost) {
			minCost = relatedNodePtr->getCost();
			minCostRelatedNodePtr = relatedNodePtr;
		}
	}

	this->currentNodePtr = minCostRelatedNodePtr;
}
