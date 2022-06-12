#include "StepAnimation.h"

StepAnimation::StepAnimation(const sf::Time& stepDuration) :
	stepDuration(stepDuration),
	clockPtr(NULL),
	isFinished(false)
{}

StepAnimation::~StepAnimation()
{
	if (this->clockPtr != NULL) delete this->clockPtr;
}

void StepAnimation::drawFrame()
{
	if (this->isFinished)
		throw std::runtime_error("It isn\'t able to call drawFrame on finished animation.");

	if (
		this->clockPtr == NULL ||
		this->clockPtr->getElapsedTime() >= this->stepDuration
		)
	{
		if (this->clockPtr == NULL) this->clockPtr = new sf::Clock;
		else this->clockPtr->restart();

		this->step();
	}
}

void StepAnimation::finish()
{
	this->isFinished = true;
}
