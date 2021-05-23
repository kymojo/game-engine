#include "EntityManager.hpp"

EntityManager::EntityManager()
{
    nextEntityId = 1;
}

// unsigned int EntityManager::generateEntityId()
// {
//     unsigned int id;
//     if (freeEntityIds.size() == 0)
//     {
//         id = nextEntityId++;
//     }
//     else
//     {
//         id = freeEntityIds.front();
//         freeEntityIds.pop();
//     }
//     return id;
// }

// Entity* EntityManager::createEntity()
// {
//     unsigned int id = generateEntityId();

//     Entity* entity; // TODO make entity

//     addEntityToManager(entity);
// }

// void EntityManager::destroyEntity(Entity* p_entity)
// {
//     removeEntityFromManager(p_entity);
// }

// Component** EntityManager::getEntityComponents(unsigned int p_eid) {
//     int arraySize = mapOfComponentsByEntityId.at(p_eid).size();
//     Component* componentArray[arraySize];
//     int i = 0;
//     for(std::pair<std::string,Component*> mapPair : mapOfComponentsByEntityId.at(p_eid))
//     {
//         componentArray[i++] = mapPair.second;
//     }
//     return componentArray;
// }
// Entity** EntityManager::getEntitiesWithComponent(std::string p_componentType) {
//     int arraySize = mapOfEntityIdsByComponent.at(p_componentType).size();
//     Entity* entityArray[arraySize];
//     int i = 0;
//     for(unsigned int eid : mapOfEntityIdsByComponent.at(p_componentType))
//     {
//         entityArray[i++] = entities.at(eid);
//     }
//     return entityArray;
// }


// void EntityManager::addEntityToManager(Entity* p_entity)
// {
//     entities.insert_or_assign(p_entity->getId(), p_entity);
// }

// void EntityManager::removeEntityFromManager(Entity* p_entity)
// {
//     unsigned int eid = p_entity->getId();
//     entities.erase(eid);
//     for (std::pair<std::string, Component*> mapPair :
//          mapOfComponentsByEntityId.at(eid))
//     {
//         std::string type = mapPair.first;
//         Component* component = mapPair.second;
//         mapOfEntityIdsByComponent.at(type).erase(eid);
//         component->cleanUp();
//     }
//     mapOfComponentsByEntityId.erase(eid);
//     freeEntityIds.push(eid);
// }

// void EntityManager::addComponentToManager(Component* p_component)
// {
//     std::string type = p_component->getComponentType();
//     unsigned int eid = p_component->getEntityId();
//     mapOfEntityIdsByComponent.at(type).insert(eid);
//     mapOfComponentsByEntityId.at(eid).insert_or_assign(type, p_component);
// }

// void EntityManager::removeComponentFromManager(Component* p_component)
// {
//     std::string type = p_component->getComponentType();
//     unsigned int eid = p_component->getEntityId();
//     mapOfEntityIdsByComponent.at(type).erase(eid);
//     mapOfComponentsByEntityId.at(eid).erase(type);
//     p_component->cleanUp();
// }