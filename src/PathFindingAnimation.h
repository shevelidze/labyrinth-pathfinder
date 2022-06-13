#pragma once

#include "StepAnimation.h"
#include "LabyrinthMatrix.h"

#include "CostsCalculationAnimation.h"
#include "PathRestoringAnimation.h"

class PathFindingAnimation :
    public StepAnimation
{
public:
    PathFindingAnimation(
        MatrixNode& beginMatrixNode,
        MatrixNode& endMatrixNode,
        LabyrinthMatrix& matrix,
        const sf::Time& stepDuration
    );

private:
    virtual void step() override;

    CostsCalculationAnimation costsCalculationAnimation;
    PathRestoringAnimation pathRestoringAnimation;
};

