#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight,float playerHitPoint) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	this->playerHitPoint = playerHitPoint;
	row = 0;
	faceRight = false;
	
    body.setSize(sf::Vector2f(62.4f, 86.4f));
	body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(192.0f, 856.0f);
    body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float deltaTime,int playerstatus)
{
	/*
	0 = stand walk jump;
	1 = attack;
	*/
	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		velocity.x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump)
	{
		canJump = false;
		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
		//square root ( 2.0f * gravity * jumpHeight);

	}

	
	

	velocity.y += 1962.0f * deltaTime;//981.0f * deltaTime;
		
	

	if (velocity.x == 0.0f && playerstatus == 0)
	{
		row = 0;
	}
	else if (velocity.x != 0.0f && playerstatus == 0)
	{
		row = 1;

		if (velocity.x > 0.0f)
			faceRight = false;
		else
			faceRight = true;
	}
	if (velocity.y <= 0.0f && playerstatus == 0)
	{
		row = 2;
	}
	 
	if (playerstatus)
	{
		row = 0;
		speed = 0;
		
	}
	else
	{
		speed = 450;

	}


	
	
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction,float deltaTime,int type) 
{
	/*type
	0 = platforms
	1 = mushrooms
	2 = snails
	*/
	switch (type)
	{
		if (type == 1)
		{
			playerHitPoint -= 16;
			break;
		}
		if (type == 2)
		{
			playerHitPoint -= 6;
			break;
		}
	default:
		break;
	}
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
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//Collision on the top
		velocity.y = 0.0f;
	}

}

