#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Layout : public sf::Drawable, public sf::Transformable {
public:
	virtual void handleEvent(const sf::Event& event) = 0;
protected:
	virtual const std::vector<sf::Drawable*>& getDrawables() const = 0;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
