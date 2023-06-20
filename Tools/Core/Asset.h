#pragma once

#include <SFML/Graphics.hpp>
#include <map>

using namespace std;
using namespace sf;

class AssetManager {
private:
    map <string, Texture> textures;
    map <string, Font> fonts;

public:

    AssetManager();
    virtual ~AssetManager();

    bool loadTexture(const string& filename, const string& textureID);
    bool loadFont(const string& filename, const string& fontID);

    Texture& getTexture(const string& textureID);
    Font& getFont(const string& FontID);
};