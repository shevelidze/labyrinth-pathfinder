#include "buildPath.h"

void buildPath(GraphNode* endNode) {
	if (!endNode->isVisited()) throw std::runtime_error("There aren't any routes to the node.");

	GraphNode* currentRouteNode = endNode;

	while (*(currentRouteNode->getCost()) != 0) {
		currentRouteNode->becomeUsedInRoute();

		unsigned minCost = UINT_MAX;
		GraphNode* minCostRelatedNode = NULL;

		for (auto relatedNode : currentRouteNode->getRelated()) {
			if (!relatedNode->isVisited()) continue;

			if (*(relatedNode->getCost()) < minCost) {
				minCost = *(relatedNode->getCost());
				minCostRelatedNode = relatedNode;
			}
		}

		currentRouteNode = minCostRelatedNode;
	}
}
