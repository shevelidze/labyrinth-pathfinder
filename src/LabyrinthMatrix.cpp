#include "LabyrinthMatrix.h"
#include <stdexcept>


void LabyrinthMatrix::addWall(int rowIndex, int columnIndex) {
	if (this->matrix[rowIndex][columnIndex] == NULL) {
		throw std::runtime_error("There already is wall on the position.");
	}
	delete this->matrix[rowIndex][columnIndex];
	this->matrix[rowIndex][columnIndex] = NULL;
}

void LabyrinthMatrix::removeWall(int rowIndex, int columnIndex) {
	if (this->matrix[rowIndex][columnIndex] != NULL) {
		throw std::runtime_error("There is no wall on the position.");
	}
	this->matrix[rowIndex][columnIndex] = new MatrixNode(rowIndex, columnIndex);
}

MatrixNode &LabyrinthMatrix::getNode(int rowIndex, int columnIndex) {
	return *(this->matrix[rowIndex][columnIndex]);
}

template <class T> void pushBackIfNotNULL(std::vector<T*> &vector, T* value) {
	if (value != NULL) vector.push_back(value);
}

std::vector<MatrixNode*> LabyrinthMatrix::findRelatedNodes(MatrixNode* node)
{
	std::vector<MatrixNode*> result;
	if (node->rowIndex > 0) {
		pushBackIfNotNULL<MatrixNode>(result, this->matrix[node->rowIndex - 1][node->columnIndex]);
	}
	if (node->rowIndex < LABYRINTH_MATRIX_ROWS - 1) {
		pushBackIfNotNULL<MatrixNode>(result, this->matrix[node->rowIndex + 1][node->columnIndex]);
	}
	if (node->columnIndex > 0) {
		pushBackIfNotNULL<MatrixNode>(result, this->matrix[node->rowIndex][node->columnIndex - 1]);
	}
	if (node->columnIndex < LABYRINTH_MATRIX_COLUMNS - 1) {
		pushBackIfNotNULL<MatrixNode>(result, this->matrix[node->rowIndex][node->columnIndex + 1]);
	}
	return result;
}

LabyrinthMatrix::LabyrinthMatrix()
{
	for (int i = 0; i < LABYRINTH_MATRIX_ROWS; i++) {
		for (int j = 0; j < LABYRINTH_MATRIX_COLUMNS; j++) {
			this->matrix[i][j] = new MatrixNode(i, j);
		}
	}
}

LabyrinthMatrix::~LabyrinthMatrix()
{
	for (int i = 0; i < LABYRINTH_MATRIX_ROWS; i++) {
		for (int j = 0; j < LABYRINTH_MATRIX_COLUMNS; j++) {
			delete this->matrix[i][j];
		}
	}
}
