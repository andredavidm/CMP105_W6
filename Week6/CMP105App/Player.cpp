#include "Player.h"
#include <iostream>
using namespace std;


Player::Player()
{

	player.setSize(sf::Vector2f(40, 40));
	player.setPosition(300, 100);


	//speed = { 100,100 };


	stepVelocity = sf::Vector2f (0, 0);
	gravity = sf::Vector2f( 0, 9.8f ) *scale;
}



Player::~Player()
{

}


void Player::update(float dt)
{
	// Apply gravity force, increasing velocity
	// Move shape by new velocity


	mousePos = sf::Vector2f(input->getMouseX(), input->getMouseY());

	if (player.getPosition().y <= 500)
	{ 
	pos = stepVelocity  * dt + (0.5f * gravity* (dt * dt)); //ut+ 1/2at^2
	stepVelocity += gravity; // v = u + at  note the += is not =
	}
	
	
	
	//player.setPosition(getPosition() + pos);

	// Check for collision with bottom of window
	
	
	//cout << pos.y << endl;
	//cout << player.getPosition().x << endl;
	//cout << pos.y << endl;

	player.move(pos*dt);
	
	
	if (input->isKeyDown(sf::Keyboard::Space) && !jumping)
	{
		stepVelocity = sf::Vector2f(0, -9000.f) * scale;
		jumping = true;
	}
	

	
	
	
	else if (player.getPosition().y >= 500)
	{
		int current_x = player.getPosition().x;
		player.setPosition(current_x, 500);
		stepVelocity = sf::Vector2f( 0, 0 );	
		jumping = false;
	}
	
	if (input->isMouseLDown())
	{
		player.setPosition(mousePos);
	}

	
}