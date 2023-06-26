#pragma once

#include "SFML/Graphics.hpp"
#include "Tools/Button.h"
#include "Tools/Core/Global.h"
#include "Tools/SceneNode.h"
#include "Tools/TreeNode.h"
#include "Tools/Edge.h"
#include "BST_Tree.h"

using namespace sf;
using namespace std;
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
	Event event{};

	RenderStates a;

	void pollEvents();

	void update();
	void Render();
	void ProcessInput();

	Vector2f MousePos;

	//var

	enum ScreenState { BST_Menu,AVL_Menu };

	bool isPaused = false;

	// stuff
	
	SceneNode* MasterDisplay;
	BST_Tree* mBST;
	//Edge* s;

	// Timer
	
	Clock clock;
	Time timeSinceLastUpdate = Time::Zero;

	//

};

