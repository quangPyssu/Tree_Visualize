#include "App.h"

App::App()
{
	videoMode.height = WINDOW_HEIGHT;
	videoMode.width = WINDOW_WIDTH;
	ContextSettings settings;
	settings.antialiasingLevel = 5.0;

	window = new RenderWindow(videoMode, "data Visual", Style::Default, settings);

	window->setFramerateLimit(60);

	MasterDisplay = new SceneNode();

	mBST = new BST_Tree();
	//mAVL = new AVL_Tree();

	shared_ptr <BST_Tree> DmBST(mBST);

	MasterDisplay->attachChild(DmBST);

	BG1.setSize((Vector2f) window->getSize()-Vector2f(60,80));
	BG1.setPosition({ 30,40 });	
	BG1.setOutlineThickness(40);

	BG1.setOutlineColor(black);	
	BG1.setFillColor(Back_Ground_Color);

	srand(time(NULL));
}

App::~App()
{
	delete window;

	//delete MasterDisplay;

	delete mBST;
}

void App::pollEvents()
{
	timeSinceLastUpdate = Time::Zero;

	while (window->isOpen()) {
		
		ProcessInput();
		
		if (!isPaused)
		{
			timeSinceLastUpdate += clock.restart();

			while (timeSinceLastUpdate > TIME_PER_FRAME)
			{
				timeSinceLastUpdate -= TIME_PER_FRAME;
					//update with frame

				takeTime(TIME_PER_FRAME);
			}
		}
		
		Render();
	}
}

void App::ProcessInput()
{
	MousePos = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));

	while (window->pollEvent(event)) 
	{
		update();		

		if (event.type == Event::Closed) {
			window->close();
		}

		if (event.type == sf::Event::GainedFocus)
			isPaused = false; else 
		if (event.type == sf::Event::LostFocus)
			isPaused = true;
	}
}

void App::takeTime(Time dt)
{
	MasterDisplay->takeTime(dt);
}

void App::update()
{
	MasterDisplay->update(event, MousePos);
}

void App::Render()
{	
	window->clear(white);

	window->draw(BG1);
	MasterDisplay->draw(*window, a);

	window->display();
}