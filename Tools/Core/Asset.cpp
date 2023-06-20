#include "Asset.h"

AssetManager::AssetManager()
{
    loadFont("asset/fonts/ArialTh.ttf","Arial");

}

AssetManager::~AssetManager()
{
}

bool AssetManager::loadTexture(const string& filename, const string& textureID)
{
    Texture texture;
    if (!texture.loadFromFile(filename)) return false; // Failed to load the texture

    textures[textureID] = texture;                     // Store the texture with the given ID
    return true;                                       // Texture loaded and stored successfully
}

Texture& AssetManager::getTexture(const string& textureID) {
    return textures[textureID];
}

bool AssetManager::loadFont(const string& filename, const string& FontID) {
    Font font;
    if (!font.loadFromFile(filename)) return false; // Failed to load the Font

    fonts[FontID] = font;                           // Store the Font with the given ID
    return true;                                    // Font loaded and stored successfully
}

Font& AssetManager::getFont(const string& FontID) {
    return fonts[FontID];
}