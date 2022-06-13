#pragma once

#include <SFML/System.hpp>


class StepAnimation
{
public:
	StepAnimation(const sf::Time& stepDuration);
	~StepAnimation();

	const bool& getIsFinished();

	void drawFrame();

protected:
	void finish();

private:
	virtual void step() = 0;

	sf::Time stepDuration;
	sf::Clock* clockPtr;
	bool isFinished;
};
