#include "Global.h"

namespace Constants {
    const double BASE_X = (double)(sf::VideoMode::getDesktopMode().width) ;
    const double BASE_Y = (double)(sf::VideoMode::getDesktopMode().height) ;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);

    const int WINDOW_WIDTH = sf::VideoMode::getDesktopMode().width/3*2;
    const int WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height/3*2;

    const int font_size_small = BASE_X/85;
    const int font_size_medium = BASE_X/75 ;
    const int font_size_large = BASE_X/60 ;

    const sf::Vector2f LowStart = {(float) WINDOW_WIDTH / 6 * 5,(float)WINDOW_HEIGHT/ 6 * 5 };


    const float NODE_POS_HEAD=(float) 80;
    const sf::Vector2f MENU_POS_BOTTOM_LEFT = {(float) 0,(float) WINDOW_HEIGHT/4*3+18};

    const float OUTLINE_THICKNESS = (float)(2.5);
    const float BUTTON_THICKNESS = (float) 0;

    const float NODE_RADIUS = 30.f;
    const float NODE_RADIUS_BIG = 50.f;
    const float EDGE_THICKNESS = 5.f;
    const sf::Vector2f BUTTON_SIZE = sf::Vector2f(50, 120);
    const sf::Vector2f TEXTBOX_SIZE = sf::Vector2f(50, 150);

    const float NODE_DISTANCE = NODE_RADIUS * 3/2;
    const float NODE_DISTANCE_BIG = NODE_RADIUS_BIG * 3/2;

    const int nothing=-999999999;

    const sf::Time TIME_PER_ANIME_FRAME = sf::seconds(3.f);
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
    sf::Color pink = sf::Color(214, 87, 117);
};

namespace ResourceManager
{
    sf::Font& getFont(FontID  ID, const std::string& filename)
    {
        auto it = fonts.find(ID);

        if (it != fonts.end()) return it->second; else
        {
            sf::Font font;
            if (font.loadFromFile(filename))
            {
                fonts.emplace(ID, font);
                return fonts[ID];
            }
        }
    }

    struct FontDestructor
    {
        ~FontDestructor()
        {
            fonts.clear(); 
        }
    };

    static FontDestructor destructor; 
}
