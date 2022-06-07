#pragma once

#include <vector>
#include "MatrixNode.h"


const int LABYRINTH_MATRIX_ROWS = 10;
const int LABYRINTH_MATRIX_COLUMNS = 20;

class LabyrinthMatrix {
public:
	void addWall(int rowIndex, int columnIndex);
	void removeWall(int rowIndex, int columnIndex);

	MatrixNode* getNode(int rowIndex, int columnIndex);
	std::vector<MatrixNode*> findRelatedNodes(MatrixNode* node);

	LabyrinthMatrix();
	~LabyrinthMatrix();
private:
	MatrixNode* matrix[LABYRINTH_MATRIX_ROWS][LABYRINTH_MATRIX_COLUMNS];
};
