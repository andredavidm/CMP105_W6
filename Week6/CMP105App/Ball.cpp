#include "Ball.h"

#include <iostream>
using namespace std;


Ball::Ball()
{
	
	ball.setSize(sf::Vector2f(40, 40));
	ball.setFillColor(sf::Color::Black);
	ball.setPosition(1, 1);



	
	speed = 100.f;
	accel = 100.f;
	target = { 1200, 675 };
	
}



Ball::~Ball()
{

}


void Ball::update(float dt)
{


	sf::Vector2f direction = target - ball.getPosition();
	direction = Vector::normalise(direction);


	

	if (Vector::magnitude(velocity) >= 100)
	{ 
		velocity = (direction * speed);
	}
	else
	{
		velocity += (direction * accel) *dt;
	}
	
	
	ball.move(velocity*dt);
	
	cout << Vector::magnitude(velocity) << endl;

	mousepos = sf::Vector2f(input->getMouseX(), input->getMouseY());
	target = mousepos;
}