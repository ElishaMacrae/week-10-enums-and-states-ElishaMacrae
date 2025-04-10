#pragma once
#include "Framework/BaseLevel.h"
#include "Framework/VectorHelper.h"
class Menu :
    public BaseLevel
{
public:
	Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Menu();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	// Default variables for level class.
	sf::RectangleShape Background;
	int controllerID = -1;
	bool controllerConnected = false;
	sf::RectangleShape square;
};

