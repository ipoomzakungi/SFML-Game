#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Mons
{
public:
	Mons(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight,float monsterHitPoint, sf::Vector2f size, sf::Vector2f position);
	~Mons();

	void Update(float deltaTime, sf::Vector2f mobaSpawnPoint);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction, float deltaTime,int type);
	void monsGetHitFrom(bool Right);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }
	
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	float speedMem;
	bool faceRight;
	float monsterHitPoint;

	sf::Vector2f velocity;
	
	float jumpHeight;

	sf::Vector2f walk;
	


};

