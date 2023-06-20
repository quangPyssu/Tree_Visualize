#include "App.h"

App::App()
{
	videoMode.height = WINDOW_HEIGHT;
	videoMode.width = WINDOW_WIDTH;
	ContextSettings settings;
	settings.antialiasingLevel = 5.0;

	window = new RenderWindow(videoMode, "data Visual", Style::Default, settings);

	window->setFramerateLimit(60);

	Manager = new AssetManager;

	butt1 = new Button(Vector2f(50,50),Vector2f(50,100),"test",cyan,yellow,red,black,*Manager);

	srand(time(NULL));
}

App::~App()
{
	delete window;
}

void App::pollEvents()
{

	while (window->isOpen()) {

		while (window->pollEvent(event)) {

			update();
			
			Render();

			if (event.type == Event::Closed) {
				window->close();
			}

		}

		window->display();
	}
}

void App::update()
{
	MousePos = this->window->mapPixelToCoords(Mouse::getPosition(*this->window));

	butt1->update(MousePos, &event);

	if (butt1->isPressed())
	{
		cout << "roger that" << endl;

		T.DelAll(T.root);

		for (int i = 0; i < 10; i++)
		{
			T.insertT(T.root, rand()%50+10);
		}

		cout << "reoger that" << endl;

		T.print_console();
	}
}

void App::Render()
{
	window->clear(white);

	butt1->render(window);
}