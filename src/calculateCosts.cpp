#include <queue>
#include "calculateCosts.h"

void calculateCosts(GraphNode* beginNode) {
	std::queue<GraphNode*> nodesProcessingQueue;
	nodesProcessingQueue.push(beginNode);

	unsigned cost = 0;

	while (!nodesProcessingQueue.empty()) {
		GraphNode* currentNode = nodesProcessingQueue.back();
		nodesProcessingQueue.pop();

		currentNode->becomeVisited();
		currentNode->visit(cost++);

		for (auto relatedNode : currentNode->getRelated()) {
			if (!relatedNode->isVisited()) {
				nodesProcessingQueue.push(relatedNode);
				relatedNode->becomeInQueue();
			}
		}
	}
}