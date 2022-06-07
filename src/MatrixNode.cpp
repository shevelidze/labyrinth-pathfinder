#include "MatrixNode.h"
#include <limits>

MatrixNode::MatrixNode(size_t rowIndex, size_t columnIndex) :
	isQueued(false),
	isUsedInRoute(false),
	rowIndex(rowIndex),
	columnIndex(columnIndex),
	cost(UINT_MAX)
{}

const unsigned& MatrixNode::getCost() {
	return this->cost;
}

const bool& MatrixNode::getIsQueued() {
	return this->isQueued;
}

const bool& MatrixNode::getIsUsedInRoute() {
	return this->isUsedInRoute;
}

void MatrixNode::setIsQueued(bool isQueued) {
	this->isQueued = isQueued;
}

void MatrixNode::setIsUsedInRoute(bool isUsedInRoute) {
	this->isUsedInRoute = isUsedInRoute;
}

void MatrixNode::setCost(unsigned cost) {
	this->cost = cost;
}

bool MatrixNode::checkIfVisited() {
	return this->cost != UINT_MAX;
}