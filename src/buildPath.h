#pragma once

#include <stdexcept>
#include <limits>
#include "MatrixNode.h"
#include "LabyrinthMatrix.h"

void buildPath(MatrixNode* endNode, LabyrinthMatrix* matrix);
