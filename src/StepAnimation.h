#pragma once

#include <SFML/System.hpp>


class StepAnimation
{
public:
	virtual void step() = 0;

	StepAnimation(const sf::Time& stepDuration);
	~StepAnimation();

	void drawFrame();

protected:
	void finish();

private:
	sf::Time stepDuration;
	sf::Clock* clockPtr;
	bool isFinished;
};
