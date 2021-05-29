#include "EntityManager.hpp"

EntityManager::EntityManager() : nextEntityId(1) {}

unsigned int EntityManager::generateEntityId()
{
    unsigned int id;
    if (freeEntityIds.size() == 0)
    {
        id = nextEntityId++;
    }
    else
    {
        id = freeEntityIds.front();
        freeEntityIds.pop();
    }
    return id;
}