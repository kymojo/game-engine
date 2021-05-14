#pragma once

#include "GameObject.hpp"
#include <map>
#include <unordered_set>

using object_entry = std::pair<unsigned int, GameObject*>;
using object_map = std::map<unsigned int, GameObject*>;
using id_set = std::unordered_set<unsigned int>;

class GameObjectManager {
    public:
    GameObjectManager();
    object_map* getObjectsMap();

    GameObject* getObjectById(unsigned int p_objectId);

    template <class T> T* addObject()
    {
        unsigned int objectId = nextObjectId++;
        T* obj = new T(objectId);
        objects.insert(object_entry(objectId, obj));
        return obj;
    }

    void markForDeleteObject(GameObject* p_object);
    void markForDeleteObjectById(unsigned int p_objectId);
    void deleteMarkedObjects();
    void cleanUp();

    private:
    unsigned int nextObjectId;
    object_map objects;
    id_set objectsToDelete;
};