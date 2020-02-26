#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Ball :
	public GameObject
{
public:

	Ball();
	~Ball();

	void update(float dt);

	GameObject ball;



	float scale = 200;



	

	float current_speed;
	float speed;
	float accel;
	sf::Vector2f target;

};


