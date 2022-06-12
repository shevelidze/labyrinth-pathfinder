#include <queue>
#include "calculateCosts.h"

void calculateCosts(MatrixNode* beginNode, LabyrinthMatrix* matrix) {
	std::queue<MatrixNode*> nodesProcessingQueue;
	nodesProcessingQueue.push(beginNode);

	unsigned cost = 0;

	while (!nodesProcessingQueue.empty()) {
		MatrixNode* currentNode = nodesProcessingQueue.back();
		nodesProcessingQueue.pop();

		currentNode->setIsQueued(false);
		currentNode->setCost(cost++);

		for (auto relatedNode : matrix->findRelatedNodes(currentNode)) {
			if (!relatedNode->checkIfVisited()) {
				nodesProcessingQueue.push(relatedNode);
				relatedNode->setIsQueued(true);
			}
		}
	}
}