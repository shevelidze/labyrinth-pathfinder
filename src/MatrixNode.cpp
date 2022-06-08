#include "MatrixNode.h"
#include <limits>

MatrixNode::MatrixNode(size_t rowIndex, size_t columnIndex) :
	isQueued(false),
	isUsedInRoute(false),
	rowIndex(rowIndex),
	columnIndex(columnIndex),
	cost(UINT_MAX),
	propertyChangeHandlerPtr(NULL)
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

bool MatrixNode::checkIfVisited() {
	return this->cost != UINT_MAX;
}

void MatrixNode::setIsQueued(bool isQueued) {
	this->callPropertyChangeHandler();
	this->isQueued = isQueued;
}

void MatrixNode::callPropertyChangeHandler()
{
	if (this->propertyChangeHandlerPtr != NULL) (this->propertyChangeHandlerPtr)();
}

void MatrixNode::setPropertyChangeHandlerPtr(void (*propertyChangeHandlerPtr)())
{
	this->propertyChangeHandlerPtr = propertyChangeHandlerPtr;
}

void MatrixNode::setIsUsedInRoute(bool isUsedInRoute) {
	this->callPropertyChangeHandler();
	this->isUsedInRoute = isUsedInRoute;
}

void MatrixNode::setCost(unsigned cost) {
	this->callPropertyChangeHandler();
	this->cost = cost;
}
