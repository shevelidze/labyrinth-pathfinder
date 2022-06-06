#pragma once


class MatrixNode {
public:
	MatrixNode(size_t rowIndex, size_t columnIndex);
	bool checkIfVisited();

	const unsigned& getCost();
	const bool& getIsUsedInRoute();
	const bool& getIsQueued();

	void setCost(unsigned cost);
	void setIsUsedInRoute(bool isUsedInRoute);
	void setIsQueued(bool isQueued);

	friend class LabyrinthMatrix;

private:
	size_t columnIndex, rowIndex;
	unsigned cost;
	bool isQueued, isUsedInRoute;

};