#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <windows.h>
#include <iostream>
#include "Core/Global.h"
#include "SceneNode.h"

using namespace sf;
using namespace std;
using namespace Colors;
using namespace ResourceManager;

class Button : public SceneNode
{
private:
    

    //attribute

    Color idleColor;
    Color hoverColor;
    Color activeColor;
    Color textColor;
    Color borderColor;
    RenderTarget* target;
    RectangleShape shape;
    
    states buttonState;

    float height = BUTTON_SIZE.x;
    float width = BUTTON_SIZE.y;

public:
    // Override the drawCurrent function from SceneNode
    virtual void drawCurrent(RenderTarget& target, RenderStates states) const override;
    virtual void updateCurrent(Event& event, Vector2f& MousePos) override;

public:

    // Button text

    Text text;

    //constructor

    Button(Vector2f pos, Vector2f size, string text, Color idleColor, Color hoverColor, Color activeColor,Color borderColor);

    //Accessors
    const bool isPressed() const;
    Event* event;

    //Function

    //void update(const Vector2f mousePos, Event* event);

    //void render(RenderTarget* target);


    // position &size
    Vector2f pos;
    Vector2f size;
};

