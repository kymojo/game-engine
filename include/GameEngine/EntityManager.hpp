#pragma once

#include "Entity.hpp"
#include "Component.hpp"
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

class EntityManager {
    public:
    EntityManager();

    template <class E> void addEntity(E* p_entity, const std::string &p_type);
    template <class E> void removeEntity(E* p_entity);
    template <class C, class E> void addComponentToEntity(C* p_component, E* p_entity);
    template <class C, class E> void removeComponentFromEntity(E* p_entity);
    template <class C, class E> C* getEntityComponentOfType(E* p_entity);
    template <class E, class T> bool isEntityOfType(E* p_entity);
    template <class E> std::vector<Component*> getEntityComponents(E* p_entity);
    template <class C> std::vector<Entity*> getEntitiesWithComponent();
    template <class E> std::vector<E*> getEntitiesOfType();

    private:
    std::map<unsigned int, Entity*> entities;
    std::map<std::string, std::set<unsigned int>> mapOfEntityIdsByComponent;
    std::map<std::string, std::set<unsigned int>> mapOfEntityIdsByType;
    std::map<unsigned int, std::map<std::string, Component*>> mapOfComponentsByEntityId;
    unsigned int nextEntityId;
    std::queue<unsigned int> freeEntityIds;

    template <class E> void addEntityToManager(E* p_entity, const std::string &p_type);
    template <class E> void removeEntityFromManager(E* p_entity);

    unsigned int generateEntityId();
};