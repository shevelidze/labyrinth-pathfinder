#include "MatrixNode.h"

MatrixNode::MatrixNode(size_t rowIndex, size_t columnIndex) :
	isQueued(false),
	isUsedInPath(false),
	rowIndex(rowIndex),
	columnIndex(columnIndex),
	cost(UINT_MAX),
	propertyChangeHandler(NULL)
{}

const unsigned& MatrixNode::getCost() {
	return this->cost;
}

const bool& MatrixNode::getIsQueued() {
	return this->isQueued;
}

const bool& MatrixNode::getIsUsedInPath() {
	return this->isUsedInPath;
}

bool MatrixNode::checkIfVisited() {
	return this->cost != UINT_MAX;
}

void MatrixNode::setIsQueued(bool isQueued) {
	this->isQueued = isQueued;
	this->callPropertyChangeHandler();
}

void MatrixNode::callPropertyChangeHandler()
{
	if (this->propertyChangeHandler != NULL) (this->propertyChangeHandler)();
	else printf("NULL handler\n");
}

void MatrixNode::setPropertyChangeHandler(std::function<void ()> propertyChangeHandler)
{
	this->propertyChangeHandler = propertyChangeHandler;
}

void MatrixNode::setIsUsedInPath(bool isUsedInPath) {
	this->isUsedInPath = isUsedInPath;
	this->callPropertyChangeHandler();
}

void MatrixNode::setCost(unsigned cost) {
	this->cost = cost;
	this->callPropertyChangeHandler();
}
