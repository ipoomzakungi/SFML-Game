#include "Platform.h"


Platform::~Platform()
{
}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{

	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
	
	//body.setFillColor(sf::Color(0, 0, 0, 255));

}

