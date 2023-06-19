#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <windows.h>

using namespace sf;
using namespace std;

enum button_states { BTN_IDLE = 0, BTN_HOVER = 1, BTN_PRESSED = 2 };

class Button
{
private:
    short unsigned buttonState;

    //attribute

    Font font;
    Color idleColor;
    Color hoverColor;
    Color activeColor;
    Color textColor;
    Color borderColor;
    Texture texture;
    RenderTarget* target;
    RectangleShape shape;

    float height=50;
    float width=120;

public:


    // Button text

    Text text;

    //constructor

    Button(Vector2f pos, Vector2f size, string text, Color idleColor, Color hoverColor, Color activeColor,Color borderColor);

    //Accessors
    const bool isPressed() const;
    Event* event;

    //Function

    void update(const Vector2f mousePos, Event* event);

    void render(RenderTarget* target);

    // position &size
    Vector2f pos;
    Vector2f size;
};

