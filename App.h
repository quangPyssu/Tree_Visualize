#pragma once

#include "SFML/Graphics.hpp"
#include "Tools/Button.h"
#include "Tools/Core/Global.h"
#include "BST_Tree.cpp"

using namespace sf;
using namespace Constants;
using namespace Colors;

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

	// stuff
	Button* butt1;
	AssetManager* Manager;

	// 

	BST_Tree T;

};

