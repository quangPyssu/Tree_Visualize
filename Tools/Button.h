#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <windows.h>
#include <iostream>
#include "Core/Global.h"
#include "Core/Asset.h"

using namespace sf;
using namespace std;
using namespace Colors;
using namespace Size;

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
    AssetManager Manager;
    RenderTarget* target;
    RectangleShape shape;

    float height=50;
    float width=120;

public:

    // Button text

    Text text;

    //constructor

    Button(Vector2f pos, Vector2f size, string text, Color idleColor, Color hoverColor, Color activeColor,Color borderColor,AssetManager& manager);

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

