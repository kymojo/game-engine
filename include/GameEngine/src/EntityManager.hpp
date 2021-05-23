#pragma once

#include "../lib/Component.hpp"
#include "../lib/Entity.hpp"
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>

class EntityManager
{
    public:
    EntityManager();
    unsigned int generateEntityId();
    // Entity* createEntity();
    // void destroyEntity(Entity* p_entity);
    // Component** getEntityComponents(unsigned int p_eid);
    // Entity** getEntitiesWithComponent(std::string p_componentType);

    private:
    unsigned int nextEntityId;
    // std::map<unsigned int, Entity*> entities;
    // std::map<std::string, std::set<unsigned int>> mapOfEntityIdsByComponent;
    // std::map<unsigned int,std::map<std::string,Component*>> mapOfComponentsByEntityId;
    // std::queue<unsigned int> freeEntityIds;

    // void addEntityToManager(Entity* p_entity);
    // void removeEntityFromManager(Entity* p_entity);
    // void addComponentToManager(Component* p_component);
    // void removeComponentFromManager(Component* p_component);
};