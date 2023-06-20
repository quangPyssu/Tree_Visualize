#pragma once

#include <SFML/Graphics.hpp>

namespace Constants
{
    extern const double BASE_X;
    extern const double BASE_Y;
    extern const sf::Time TIME_PER_FRAME;
    extern const int WINDOW_WIDTH;
    extern const int WINDOW_HEIGHT;
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

namespace Size {
    extern const float OUTLINE_THICKNESS;
    extern const float NODE_RADIUS;
    extern const float EDGE_THICKNESS;
};
