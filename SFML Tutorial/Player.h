#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"


class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed,float jumpHeight,float playerHitPoint);
	~Player();

	void Update(float deltatTime,int playerstatus);
	void Draw(sf::RenderWindow& window); 
	void OnCollision(sf::Vector2f direction,float deltaTime,int type);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }


private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;


	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
	float cdJump = 0.5f;
	float coolingJump = 0.0f;
	float playerHitPoint;

};

