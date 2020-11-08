#include "Mons.h"

Mons::Mons(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, sf::Vector2f size, sf::Vector2f position) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = false;

	body.setSize(sf::Vector2f(84.0f, 114.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(500.0f, 800.0f);
	body.setTexture(texture);

	walk.x = 0.0f;
	

	

}

Mons::~Mons()
{
}

void Mons::Update(float deltaTime, sf::Vector2f mobSpawnPoint)
{
	velocity.x = 0.0f;
	velocity.y += 1962.0f * deltaTime;//981.0f * deltaTime;
	
	walk.y = 5.0f;
	if (walk.x < walk.y/2.0f)
	{
		walk.x += deltaTime;
		velocity.x += speed;
	}
	else if (walk.x < walk.y)
	{
		walk.x += deltaTime;
		velocity.x -= speed;
	}
	else
	{
		walk.x = 0.0f;
	}
	/*velocity.x += speed;
	if(ve)*/
	if (velocity.x > 0.0f)
		faceRight = false;
	else
		faceRight = true;
	
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Mons::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Mons::OnCollision(sf::Vector2f direction, float deltaTime)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left.
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collsion on the right
		velocity.x = 0.0f;
	}
	if (direction.y <= 0.0f)
	{
		//Collision on the bottom
		velocity.y *= 0.0f;
		
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		velocity.y = 0.0f;
	}
}
