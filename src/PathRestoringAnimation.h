#pragma once

#include "StepAnimation.h"
#include "LabyrinthMatrix.h"


class PathRestoringAnimation :
    public StepAnimation
{
public:
    PathRestoringAnimation(
        MatrixNode& endNode,
        LabyrinthMatrix& matrix,
        const sf::Time& stepDuration);

private:
    virtual void step() override;

    MatrixNode* endNodePtr;
    LabyrinthMatrix* matrixPtr;
    MatrixNode* currentNodePtr;
};

