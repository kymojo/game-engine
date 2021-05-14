#pragma once

#include "Vector.hpp"
#include "Sprite.hpp"
#include "Texture.hpp"
#include <string>
#include <unordered_map>

using namespace std;

class SpriteManager {
    public:
    /** @brief Construct a new Sprite Manager object */
    SpriteManager() {}
    /**
     * @brief Register a new Sprite for SpriteManager
     * @param p_spriteId String to use for Sprite id
     * @param p_texture Pointer to Texture this Sprite will use
     * @param p_config [default=NULL] SpriteSheetConfig
     */
    void registerSprite(const string& p_spriteId, Texture* p_texture,
                        SpriteSheetConfig* p_config = NULL);

    /**
     * @brief Get a Sprite from SpriteManager
     * @param p_spriteId Id of the Sprite to get
     * @return Pointer to Sprite in SpriteManager
     */
    Sprite* getSprite(const string& p_spriteId);
    /** @brief Free Sprite memory */
    void cleanUp();

    private:
    /** @brief Collection of Sprite pointers keyed by Sprite id strings */
    unordered_map<string, Sprite*> sprites;
};