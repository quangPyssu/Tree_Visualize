#pragma once

#include "SFML/Graphics.hpp"
#include "Tools/Button.h"

using namespace sf;

class App
{
public:
	App();                     //Constructor

	virtual ~App();            // Destructor

	//Event & Window

	RenderWindow* window;
	VideoMode videoMode;
	Event event;

	void pollEvents();

	void update();
	void Render();

	Vector2f MousePos;

	Button* butt1;
};

