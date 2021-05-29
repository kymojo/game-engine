#pragma once
#include "EntityManager.hpp"

template <class E> void EntityManager::addEntity(E* p_entity, const std::string &p_type)
{
    unsigned int id = generateEntityId();
    p_entity->setId(id);
    addEntityToManager(p_entity, p_type);
}

template <class E> void EntityManager::removeEntity(E* p_entity)
{
    removeEntityFromManager(p_entity);
}

template <class C, class E> void EntityManager::addComponentToEntity(C* p_component, E* p_entity)
{
    std::string componentType = typeid(C).name();
    unsigned int entityId = p_entity->getId();
    mapOfComponentsByEntityId[entityId][componentType] = p_component;
    mapOfEntityIdsByComponent[componentType].insert(entityId);
}

template <class C, class E> void EntityManager::removeComponentFromEntity(E* p_entity)
{
    std::string componentType = typeid(C).name();
    unsigned int entityId = p_entity->getId();
    C* component = mapOfComponentsByEntityId[entityId][componentType];
    if (component != NULL)
    {
        mapOfEntityIdsByComponent[componentType].erase(entityId);
        mapOfComponentsByEntityId[entityId].erase(componentType);
        delete component;
    }
}

template <class C, class E> C* EntityManager::getEntityComponentOfType(E* p_entity)
{
    std::string componentType = typeid(C).name();
    unsigned int entityId = p_entity->getId();
    C* component = dynamic_cast<C*>(mapOfComponentsByEntityId[entityId][componentType]);
    return component;
}

template <class E, class T> bool EntityManager::isEntityOfType(E* p_entity)
{
    unsigned int entityId = p_entity->getId();
    auto entity = entities[entityId];
    std::string entityTypeCheck = typeid(T).name();
    std::string entityTypeActual = typeid(*entity).name();
    return entityTypeCheck == entityTypeActual;
}


template <class E> std::vector<Component*> EntityManager::getEntityComponents(E* p_entity)
{
    unsigned int entityId = p_entity->getId();
    std::vector<Component*> componentArray;
    for(std::pair<std::string,Component*> mapPair : mapOfComponentsByEntityId[entityId])
        componentArray.push_back(mapPair.second);

    return componentArray;
}

template <class C> std::vector<Entity*> EntityManager::getEntitiesWithComponent()
{
    std::string componentType = typeid(C).name();
    std::vector<Entity*> entityArray;
    for(unsigned int eid : mapOfEntityIdsByComponent[componentType])
        entityArray.push_back(entities[eid]);

    return entityArray;
}

template <class E> std::vector<E*> EntityManager::getEntitiesOfType()
{
    std::string entityType = typeid(E).name();
    std::vector<E*> entityArray;
    for(unsigned int eid : mapOfEntityIdsByType[entityType])
        entityArray.push_back(dynamic_cast<E*>(entities[eid]));

    return entityArray;
}

template <class E> void EntityManager::addEntityToManager(E* p_entity, const std::string &p_type)
{
    unsigned int id = p_entity->getId();
    std::string type = (!p_type.empty() ? p_type : typeid(E).name());
    entities[id] = p_entity;
    mapOfEntityIdsByType[type].insert(id);
}

template <class E> void EntityManager::removeEntityFromManager(E* p_entity)
{
    unsigned int entityId = p_entity->getId();

    // Remove components
    for(std::pair<std::string,Component*> entry : mapOfComponentsByEntityId[entityId])
    {
        Component* component = entry.second;
        std::string componentType = entry.first;
        mapOfEntityIdsByComponent[componentType].erase(entityId);
        delete component;
    }
    mapOfComponentsByEntityId[entityId].clear();

    // Remove entity
    std::string entityType = typeid(E).name();
    entities.erase(entityId);
    mapOfEntityIdsByType[entityType].erase(entityId);
    delete p_entity;
}
    