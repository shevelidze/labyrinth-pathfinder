#include "CostsCalculationAnimation.h"

CostsCalculationAnimation::CostsCalculationAnimation(
	MatrixNode* beginNodePtr,
	LabyrinthMatrix* matrixPtr,
	const sf::Time& stepDuration
) :
	StepAnimation(stepDuration),
	cost(0),
	beginNodePtr(beginNodePtr),
	matrixPtr(matrixPtr)
{
	this->nodesProcessingQueue.push(beginNodePtr);
}

void CostsCalculationAnimation::step()
{
	if (this->nodesProcessingQueue.empty()) {
		this->finish();
		return;
	}

	MatrixNode* currentNode = this->nodesProcessingQueue.front();
	this->nodesProcessingQueue.pop();

	currentNode->setIsQueued(false);
	currentNode->setCost(this->cost++);

	for (auto relatedNode : this->matrixPtr->findRelatedNodes(currentNode)) {
		if (!relatedNode->checkIfVisited() && !relatedNode->getIsQueued()) {
			this->nodesProcessingQueue.push(relatedNode);
			relatedNode->setIsQueued(true);
		}
	}
}
