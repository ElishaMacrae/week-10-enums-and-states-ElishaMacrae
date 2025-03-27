#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");
	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::Escape)) {
		gameState->setCurrentState(State::MENU);
		std::cout << "\n Escape pressed.";
	}
	if (input->isPressed(sf::Keyboard::C)) {
		gameState->setCurrentState(State::CREDITS);
		std::cout << "\n C pressed.";
	}
	if (input->isPressed(sf::Keyboard::E)) {
		if (gameState->getCurrentState() != State::PAUSE) {
			gameState->setCurrentState(State::PAUSE);
		}
		else {
			gameState->setCurrentState(State::LEVEL);
		}

	}
}

// Update game objects
void Level::update(float dt)
{
	
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(box);

	endDraw();
}

