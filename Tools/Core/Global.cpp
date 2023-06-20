#include "Global.h"

namespace Constants {
    const double BASE_X = (double)(sf::VideoMode::getDesktopMode().width) / (2880);
    const double BASE_Y = (double)(sf::VideoMode::getDesktopMode().height) / (1800);
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

    const int WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width/3*2;
    const int WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height/3*2;
};

namespace Colors {
    sf::Color white = sf::Color::White;
    sf::Color black = sf::Color::Black;
    sf::Color red = sf::Color::Red;
    sf::Color cyan = sf::Color::Cyan;
    sf::Color yellow = sf::Color::Yellow;
    sf::Color light_yellow = sf::Color(255,255,153);
    sf::Color grey = sf::Color(128,128,128);
    sf::Color light_grey = sf::Color(192, 192, 192);
};

namespace Size {
    const float OUTLINE_THICKNESS = (float) (0);
    const float NODE_RADIUS = 30.f;
    const float EDGE_THICKNESS = 5.f;
    const sf::Vector2f BUTT_SIZE = sf::Vector2f(50,120);
};

namespace Animation {
    float SPEED = 1;
}