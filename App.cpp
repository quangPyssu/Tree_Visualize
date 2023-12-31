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
	mHash = new Hash_Table();
	mHeap = new Heap();
	mB = new B_Tree();
	mTrie = new Trie_Tree();
	mGraph = new Graphs();

	MasterDisplay.PushToObject(mAVL, &MasterDisplay);
	MasterDisplay.PushToObject(mHash, &MasterDisplay);
	MasterDisplay.PushToObject(mHeap, &MasterDisplay);
	MasterDisplay.PushToObject(mB, &MasterDisplay);
	MasterDisplay.PushToObject(mTrie, &MasterDisplay);
	MasterDisplay.PushToObject(mGraph, &MasterDisplay);

	btnBST = new Button(Vector2f(30, 1), Vector2f(38.f, 110), "Relax Menu", pink, grey, pink, black, TextAlign::Middle);
	btnBST->SecondText = "[>"+btnBST->FirstText+"<]";
	btnBST->isOn = true;
	MasterDisplay.PushToObject(btnBST, &MasterDisplay);

	btnAVL = new Button(btnBST->pos + Vector2f(btnBST->size.y + 1, 0), btnBST->size, "AVL tree", pink, grey, pink, black, TextAlign::Middle);
	btnAVL->SecondText = "[>" + btnAVL->FirstText + "<]";
	MasterDisplay.PushToObject(btnAVL, &MasterDisplay);

	btnHash = new Button(btnAVL->pos + Vector2f(btnAVL->size.y + 1, 0), btnAVL->size, "Hash Table", pink, grey, pink, black, TextAlign::Middle);
	btnHash->SecondText = "[>" + btnHash->FirstText + "<]";
	MasterDisplay.PushToObject(btnHash, &MasterDisplay);

	btnHeap = new Button(btnHash->pos + Vector2f(btnAVL->size.y + 1, 0), btnAVL->size, "Heap", pink, grey, pink, black, TextAlign::Middle);
	btnHeap->SecondText = "[>" + btnHeap->FirstText + "<]";
	MasterDisplay.PushToObject(btnHeap, &MasterDisplay);

	btn234 = new Button(btnHeap->pos + Vector2f(btnAVL->size.y + 1, 0), btnAVL->size, "2-3-4 tree", pink, grey, pink, black, TextAlign::Middle);
	btn234->SecondText = "[>" + btn234->FirstText + "<]";
	MasterDisplay.PushToObject(btn234, &MasterDisplay);

	btnTrie = new Button(btn234->pos + Vector2f(btnAVL->size.y + 1, 0), btnAVL->size, "Trie tree", pink, grey, pink, black, TextAlign::Middle);
	btnTrie->SecondText = "[>" + btnTrie->FirstText + "<]";
	MasterDisplay.PushToObject(btnTrie, &MasterDisplay);

	btnGraph = new Button(btnTrie->pos + Vector2f(btnAVL->size.y + 1, 0), btnAVL->size, "Graph", pink, grey, pink, black, TextAlign::Middle);
	btnGraph->SecondText = "[>" + btnGraph->FirstText + "<]";
	MasterDisplay.PushToObject(btnGraph, &MasterDisplay);

	dataStucture.push_back(mAVL);
	dataStucture.push_back(mHash);
	dataStucture.push_back(mHeap);
	dataStucture.push_back(mB);
	dataStucture.push_back(mTrie);
	dataStucture.push_back(mGraph);

	MenuGroup = new GUIGroup;
	StyleGroup = new GUIGroup;

	MenuGroup->adopt(btnBST, NULL);
	MenuGroup->adopt(btnAVL, NULL);
	MenuGroup->adopt(btnHash, NULL);
	MenuGroup->adopt(btnHeap, NULL);
	MenuGroup->adopt(btn234, NULL);
	MenuGroup->adopt(btnTrie, NULL);
	MenuGroup->adopt(btnGraph, NULL);

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
	else if (btnAVL->isOn)
	{
		for (int i = 0; i < dataStucture.size(); i++) if (i != 0) dataStucture[i]->Disable();

		mAVL->Able();
	} 
	else if (btnHash->isOn)
	{
		for (int i = 0; i < dataStucture.size(); i++) if (i != 1) dataStucture[i]->Disable();

		mHash->Able();
	}
	else if (btnHeap->isOn)
	{
		for (int i = 0; i < dataStucture.size(); i++) if (i != 2) dataStucture[i]->Disable();

		mHeap->Able();
	}
	else if (btn234->isOn)
	{
		for (int i = 0; i < dataStucture.size(); i++) if (i != 3) dataStucture[i]->Disable();

		mB->Able();
	}
	else if (btnTrie->isOn)
	{
		for (int i = 0; i < dataStucture.size(); i++) if (i != 4) dataStucture[i]->Disable();

		mTrie->Able();
	}
	else if (btnGraph->isOn)
	{
		for (int i = 0; i < dataStucture.size(); i++) if (i != 5) dataStucture[i]->Disable();

		mGraph->Able();
	}
}

void App::Render()
{	
	window->clear(white);

	window->draw(BG1);
	MasterDisplay.draw(*window, a);

	window->display();
}