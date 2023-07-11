#include "App.h"

App::App()
{
	videoMode.height = WINDOW_HEIGHT;
	videoMode.width = WINDOW_WIDTH;
	ContextSettings settings;
	settings.antialiasingLevel = 5.0;

	window = new RenderWindow(videoMode, "data Visual", Style::Default, settings);

	window->setFramerateLimit(60);

	mAVL = new AVL_Tree();

	MasterDisplay.PushToObject(mAVL, &MasterDisplay);

	btnBST = new Button(Vector2f(30, 1), Vector2f(38.f, 110), "BST tree", pink, grey, pink, black, TextAlign::Middle);
	btnBST->SecondText = "[>"+btnBST->FirstText+"<]";
	btnBST->isOn = true;
	MasterDisplay.PushToObject(btnBST, &MasterDisplay);

	btnAVL = new Button(btnBST->pos+Vector2f(btnBST->size.y+1,0), btnBST->size, "AVL tree", pink, grey, pink, black, TextAlign::Middle);
	btnAVL->SecondText = "[>" + btnAVL->FirstText + "<]";
	MasterDisplay.PushToObject(btnAVL, &MasterDisplay);

	dataStucture.push_back(mAVL);

	MenuGroup = new GUIGroup;
	StyleGroup = new GUIGroup;

	MenuGroup->adopt(btnBST, NULL);
	MenuGroup->adopt(btnAVL, NULL);

	MasterDisplay.PushToObject(MenuGroup, &MasterDisplay);

	ChinhMau = new StyleEditor();
	MasterDisplay.PushToObject(ChinhMau, &MasterDisplay);

	btnColorHub = new Button(MENU_POS_BOTTOM_LEFT-Vector2f(0, ChinhMau->ColorBox.getSize().y+OUTLINE_THICKNESS*3+2), Vector2f(ChinhMau->ColorBox.getSize().y + OUTLINE_THICKNESS * 2+3, 30), ">", pink, pink, pink + Color(30, 0, 0), black, TextAlign::Middle);
	btnColorHub->SecondText="<";
	MasterDisplay.PushToObject(btnColorHub, &MasterDisplay);

	StyleGroup->FatherBtn(btnColorHub);
	StyleGroup->adopt(ChinhMau->btnCurrent, ChinhMau);
	MasterDisplay.PushToObject(StyleGroup, &MasterDisplay);

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

	//delete mBST;
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
	MasterDisplay.takeTime(dt);
}

void App::update()
{
	MasterDisplay.update(event, MousePos);

	if (btnBST->isOn)
	{
		for (int i = 0; i < dataStucture.size();i++) dataStucture[i]->Disable();
	}
	else
	{
		for (int i = 0; i < dataStucture.size(); i++) if (i != 0) dataStucture[i]->Disable();

		mAVL->Able();
	}
}

void App::Render()
{	
	window->clear(white);

	window->draw(BG1);
	MasterDisplay.draw(*window, a);

	window->display();
}