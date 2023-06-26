#pragma once

#include <SFML/Graphics.hpp>

namespace Constants
{
    extern const double BASE_X;
    extern const double BASE_Y;
    extern const sf::Time TIME_PER_FRAME;
    extern const int WINDOW_WIDTH;
    extern const int WINDOW_HEIGHT;

    extern const int font_size_small;
    extern const int font_size_medium;
    extern const int font_size_large;

    extern const sf::Vector2f LowStart;

    extern const float OUTLINE_THICKNESS;
    extern const float NODE_POS_HEAD;
    extern const float NODE_RADIUS;
    extern const float NODE_RADIUS_BIG;
    extern const float EDGE_THICKNESS;
    extern const sf::Vector2f BUTTON_SIZE;
    extern const sf::Vector2f TEXTBOX_SIZE;

    extern const float NODE_DISTANCE;
    extern const float NODE_DISTANCE_BIG;
    extern const int nothing;

    enum Type
    {
        BST, AVL, Graph, Link,
    };

    enum childType
    {
        cFirst,cSecond,cThird,cFour,cNone
    };

    enum states { IDLE, HOVER , PRESSED , ACTIVE};
};

namespace Colors
{
    extern sf::Color white;
    extern sf::Color black;
    extern sf::Color red;
    extern sf::Color cyan;
    extern sf::Color yellow;
    extern sf::Color light_yellow;
    extern sf::Color grey;
};

namespace ResourceManager
{
    enum FontID { Arial };

    static std::map<FontID, sf::Font> fonts;

    sf::Font& getFont(FontID ID,const std::string& filename);

    // Add a similar namespace for textures
}
