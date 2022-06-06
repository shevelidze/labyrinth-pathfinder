#include "buildPath.h"

void buildPath(MatrixNode* endNode, LabyrinthMatrix* matrix) {
	if (!endNode->checkIfVisited()) throw std::runtime_error("There aren't any routes to the node.");

	MatrixNode* currentRouteNode = endNode;

	while (currentRouteNode->getCost() != 0) {
		currentRouteNode->setIsUsedInRoute(true);

		unsigned minCost = UINT_MAX;
		MatrixNode* minCostRelatedNode = NULL;

		for (auto relatedNode : matrix->findRelatedNodes(currentRouteNode)) {
			if (!relatedNode->checkIfVisited()) continue;

			if (relatedNode->getCost() < minCost) {
				minCost = relatedNode->getCost();
				minCostRelatedNode = relatedNode;
			}
		}

		currentRouteNode = minCostRelatedNode;
	}
}
