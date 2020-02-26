#include "Ball.h"

#include <iostream>
using namespace std;


Ball::Ball()
{
	
	ball.setSize(sf::Vector2f(40, 40));
	ball.setFillColor(sf::Color::Black);
	ball.setPosition(1, 1);



	
	speed = 10;
	accel = 1.1;
	target = { 1200, 675 };
	current_speed = 1;
}



Ball::~Ball()
{

}


void Ball::update(float dt)
{

	sf::Vector2f direction = target - ball.getPosition();
	direction = Vector::normalise(direction);

	while (current_speed * dt <= speed)
	{
		velocity += (direction * accel) * dt;

		current_speed = (current_speed + 1);
	}
	
	ball.move(velocity *dt);
	cout << current_speed *dt << endl;
}