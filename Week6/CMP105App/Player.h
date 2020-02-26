#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"


class Player : public GameObject
{
public:

	Player();
	~Player();

	void update(float dt);

	GameObject player;

	sf::Vector2f stepVelocity;
	sf::Vector2f gravity;

	float scale = 200;
	bool jumping = false;
	sf::Vector2f pos;

	sf::Vector2f mousePos;

	sf::Vector2f speed;
};

