#include "PathFindingAnimation.h"

PathFindingAnimation::PathFindingAnimation(MatrixNode& beginMatrixNode, MatrixNode& endMatrixNode, LabyrinthMatrix& matrix, const sf::Time& stepDuration) :
	StepAnimation(stepDuration),
	costsCalculationAnimation(
		beginMatrixNode,
		matrix,
		sf::Time()
	),
	pathRestoringAnimation(
		endMatrixNode,
		matrix,
		sf::Time()
	)
{
}

void PathFindingAnimation::step()
{
	if (!this->costsCalculationAnimation.getIsFinished())
		this->costsCalculationAnimation.drawFrame();
	else if (!this->pathRestoringAnimation.getIsFinished())
		this->pathRestoringAnimation.drawFrame();
	else
		this->finish();
}
