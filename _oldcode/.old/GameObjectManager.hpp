#pragma once

#include "GameObject.hpp"
#include <unordered_map>

using namespace std;

class GameObjectManager
{
    public:
    GameObjectManager();

    private:
    unordered_map<unsigned int, GameObject*> objects;
    unordered_map<unsigned int, GameObject*> activeObjects;
    unordered_map<unsigned int, GameObject*> inactiveObjects;
};