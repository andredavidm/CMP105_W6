#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	myPlayer.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	myBall.setInput(input);
}

// Update game objects
void Level::update(float dt)
{
	myPlayer.update(dt);
	myBall.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(myPlayer.player);
	window->draw(myBall.ball);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}