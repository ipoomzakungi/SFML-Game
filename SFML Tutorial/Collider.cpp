#include "Collider.h"


Collider::Collider(sf::RectangleShape& body) :
	body(body)
{
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider & other, sf::Vector2f& direction, float push,int checkPush)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	printf("%0.2f %0.2f\n", otherPosition.x-42.0f, otherPosition.y+57.0f);

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f )
	{
		
		
		std::min(std::max(push, 0.0f), 1.0f);

		if (intersectX > intersectY && checkPush)
		{
			if (deltaX > 0.0f)
			{
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);

				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else 
			{
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else if (intersectX <= intersectY && checkPush)
		{
			if (deltaY > 0.0f)
			{
				Move(0.0f,intersectY * (1.0f - push));
				other.Move(0.0f ,-intersectY * push);
				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else
			{
				Move(0.0f,-intersectY * (1.0f - push));
				other.Move(0.0f,intersectY * push);
				direction.x = 0.0f;
				direction.y = -1.0f;
			}
		}

		return true;
	}


	return false;
}
