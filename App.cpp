#include "App.h"

App::App()
{
	videoMode.height = 800;
	videoMode.width = 1200;
	ContextSettings settings;
	settings.antialiasingLevel = 5.0;

	window = new RenderWindow(videoMode, "data Visual", Style::Default, settings);

	butt1 = new Button(Vector2f(50,50),Vector2f(50,100),"test",Color::Black,Color::Yellow,Color::Red,Color::Black);
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
}

void App::Render()
{
	window->clear(Color::White);

	butt1->render(window);
}