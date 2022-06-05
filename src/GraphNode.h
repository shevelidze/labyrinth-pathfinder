#pragma once

#include <vector>

class GraphNode {
public:
	virtual std::vector<GraphNode*> getRelated() = 0;
	virtual const unsigned * getCost() = 0;
	virtual const bool * isVisited() = 0;
	virtual void visit(unsigned cost) = 0;

	virtual void becomeInQueue() = 0;
	virtual void becomeVisited() = 0;
	virtual void becomeUsedInRoute() = 0;
};
