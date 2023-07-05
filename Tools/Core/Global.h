#pragma once

#include <SFML/Graphics.hpp>

#define ff first
#define ss second

namespace Constants
{
    extern const double pi;
    extern const double BASE_X;
    extern const double BASE_Y;
    extern const sf::Time TIME_PER_FRAME;
    extern const int WINDOW_WIDTH;
    extern const int WINDOW_HEIGHT;

    extern const int font_size_small;
    extern const int font_size_medium;
    extern const int font_size_large;

    extern const sf::Vector2f LowStart;

    extern const sf::Vector2f MENU_POS_BOTTOM_LEFT;
    extern const float OUTLINE_THICKNESS;
    extern const float BUTTON_THICKNESS;
    extern const float NODE_POS_HEAD;
    extern const float NODE_RADIUS;
    extern const float NODE_RADIUS_BIG;
    extern const float EDGE_THICKNESS;
    extern const sf::Vector2f BUTTON_SIZE;
    extern const sf::Vector2f TEXTBOX_SIZE;

    extern const float NODE_DISTANCE;
    extern const float NODE_DISTANCE_BIG;
    extern const int nothing;

    extern const sf::Time TIME_PER_ANIME_FRAME;
    extern const float FRAME_PER_FRAME;

    enum Type
    {
        BST, AVL, Graph, Link, noType
    };

    enum childType
    {
        cFirst,cSecond,cThird,cFour,cNone
    };

    enum states { IDLE, HOVER , PRESSED , ACTIVE};

    enum TextAlign {Left,Middle,Right};
};

namespace Colors
{
    extern sf::Color trans;
    extern sf::Color white;
    extern sf::Color black;
    extern sf::Color red;
    extern sf::Color cyan;
    extern sf::Color yellow;
    extern sf::Color light_yellow;
    extern sf::Color grey;
    extern sf::Color pink;
    extern sf::Color Back_Ground_Color;
    extern sf::Color Default_Color;
    extern sf::Color Chosen_Color;
    extern sf::Color Delete_Color;
    extern sf::Color Insert_Color;
    extern sf::Color Search_Color;
};

namespace ResourceManager
{
    enum FontID { Arial };

    static std::map<FontID, sf::Font> fonts;

    sf::Font& getFont(FontID ID,const std::string& filename);

    // Add a similar namespace for textures
}
