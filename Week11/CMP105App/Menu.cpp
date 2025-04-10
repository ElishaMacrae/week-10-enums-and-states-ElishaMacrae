#include "Menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;
	

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");
	Background.setFillColor(sf::Color::Green);
	Background.setPosition(0, 0);

	square.setFillColor(sf::Color::Blue);
	square.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	square.setOutlineColor(sf::Color::Black);
	square.setSize(sf::Vector2f(50.f, 50.f));
}

Menu::~Menu()
{
}

void Menu::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::Space)) {
		gameState->setCurrentState(State::LEVEL);
		std::cout << "\n Escape pressed.";
	}
	if (input->isPressed(sf::Keyboard::C)) {
		gameState->setCurrentState(State::CREDITS);
		std::cout << "\n C pressed.";
	}
}

void Menu::update(float dt)
{
	if (!controllerConnected) {
		for (int i = 0; i <= 7; i++) {
			if (sf::Joystick::isConnected(i)) {
				controllerID = i;
				controllerConnected = true;
				break;
			}
		}
	}
	else {
		if (!sf::Joystick::isConnected(controllerID)) {
			controllerID = -1;
			controllerConnected = false;
		}
	}
	
	//X is lef stick right to left. Y is left stick up and down. U is righ stick left and right. V is right up and down. Z is for R&LT
	if (controllerConnected) {
		/*float xPos = sf::Joystick::getAxisPosition(controllerID, sf::Joystick::X) * 100.f;
		xPos = std::round(xPos);
		xPos = xPos / 100;

		float yPos = sf::Joystick::getAxisPosition(controllerID, sf::Joystick::Y) * 100.f;
		yPos = std::round(yPos);
		yPos = yPos / 100;

		sf::Vector2f newPos = square.getPosition() + VectorHelper::normalise(sf::Vector2f(xPos, yPos) * 0.002f);
		square.move(sf::Vector2f(xPos, yPos) * 0.002f);*/
		/*for (int i = 0; i <= 31;i++) {
			if (sf::Joystick::isButtonPressed(controllerID, i)) {
				std::cout << "Button " << i << " is the one you pressed ";
				
			}

		}*/
		if (sf::Joystick::getAxisPosition(controllerID, sf::Joystick::Axis::Z) < -90.f ){
			
			direction = VectorHelper::normalise(sf::Vector2f(sf::Joystick::getAxisPosition(controllerID, sf::Joystick::Axis::U), sf::Joystick::getAxisPosition(controllerID, sf::Joystick::Axis::V)));
			projectile.setFillColor(sf::Color::Black);
			projectile.setPosition(square.getPosition());
			projectile.setOutlineColor(sf::Color::Black);
			projectile.setSize(sf::Vector2f(5.f, 5.f));
		}
		projectile.move(direction);
		}
	
	}
	
	


void Menu::render()
{
	beginDraw();
	window->draw(Background);
	window->draw(square);
	window->draw(projectile);
	endDraw();
}
