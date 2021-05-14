#include "GameObjectManager.hpp"

GameObjectManager::GameObjectManager() : nextObjectId(0) {}

object_map* GameObjectManager::getObjectsMap()
{
    return &objects;
}

GameObject* GameObjectManager::getObjectById(unsigned int p_objectId)
{
    return objects.at(p_objectId);
}

void GameObjectManager::markForDeleteObject(GameObject* p_object)
{
    markForDeleteObjectById(p_object->getId());
}
void GameObjectManager::markForDeleteObjectById(unsigned int p_objectId)
{
    objectsToDelete.insert(p_objectId);
}
void GameObjectManager::deleteMarkedObjects()
{
    for (unsigned int objectId : objectsToDelete)
    {
        GameObject* object = objects.at(objectId);
        objects.erase(objectId);
        delete object;
    }
}
void GameObjectManager::cleanUp()
{
    for (object_entry objectEntry : objects)
    {
        GameObject* object = objectEntry.second;
        delete object;
    }
    objects.clear();
    objectsToDelete.clear();
}