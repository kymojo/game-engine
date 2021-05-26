#pragma once

#include "../lib/Component.hpp"
#include "../lib/Entity.hpp"
#include <map>
#include <queue>
#include <set>
#include <string>

class EntityManager {
    public:
    EntityManager() : nextEntityId(1) {}

    /**
     * @brief Add an entity to the manager
     * 
     * @tparam E entity class
     * @param p_entity entity to add
     */
    template <class E> void addEntity(E* p_entity)
    {
        unsigned int id = generateEntityId();
        p_entity->setId(id);
        addEntityToManager(p_entity);
    }

    /**
     * @brief Remove an entity from the manager
     * 
     * @tparam E entity class
     * @param p_entity entity to remove
     */
    template <class E> void removeEntity(E* p_entity)
    {
        removeEntityFromManager(p_entity);
    }

    /**
     * @brief Add a component to an entity
     * 
     * @tparam C component class
     * @tparam E entity class
     * @param p_component component to add
     * @param p_entity entity to add component to
     */
    template <class C, class E> void addComponentToEntity(C* p_component, E* p_entity)
    {
        std::string componentType = typeid(C).name();
        unsigned int entityId = p_entity->getId();
        mapOfComponentsByEntityId[entityId][componentType] = p_component;
        mapOfEntityIdsByComponent[componentType].insert(entityId);
    }

    /**
     * @brief Remove a component from an entity
     * 
     * @tparam C component class
     * @tparam E entity class
     * @param p_entity entity to remove component from
     */
    template <class C, class E> void removeComponentFromEntity(E* p_entity)
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
    
    /**
     * @brief Get a component from an entity
     * 
     * @tparam C component class
     * @tparam E entity class
     * @param p_entity entity to get component for
     * @return Component* component for entity (NULL if not found)
     */
    template <class C, class E> Component* getEntityComponentOfType(E* p_entity)
    {
        std::string componentType = typeid(C).name();
        unsigned int entityId = p_entity->getId();
        return mapOfComponentsByEntityId[entityId][componentType];
    }

    /**
     * @brief Check if entity is of class
     * 
     * @tparam E entity class
     * @param p_entity entity to check class of
     * @return true - entity is of type
     * @return false - entity is not of type
     */
    template <class E, class T> bool isEntityOfType(E* p_entity)
    {
        unsigned int entityId = p_entity->getId();
        auto entity = entities[entityId];
        std::string entityTypeCheck = typeid(T).name();
        std::string entityTypeActual = typeid(*entity).name();
        return entityTypeCheck == entityTypeActual;
    }


    /**
     * @brief Get components assigned to entity
     * 
     * @tparam E entity class
     * @param p_entity entity to get components for
     * @return Component** array of components; allocated memory requires manual delete
     */
    template <class E> Component** getEntityComponents(E* p_entity)
    {
        // IMPORTANT : Returned array uses memory; must be deleted when done
        unsigned int entityId = p_entity->getId();
        int arraySize = mapOfComponentsByEntityId[entityId].size();
        Component** componentArray = new Component*[arraySize];
        int i = 0;
        for(std::pair<std::string,Component*> mapPair : mapOfComponentsByEntityId[entityId])
        {
            componentArray[i++] = mapPair.second;
        }
        return componentArray;
    }

    /**
     * @brief Get all entities with an assigned component of given type
     * 
     * @tparam C component class
     * @return Entity** array of entities; allocated memory requires manual delete
     */
    template <class C> Entity** getEntitiesWithComponent()
    {
        // IMPORTANT : Returned array uses memory; must be deleted when done
        std::string componentType = typeid(C).name();
        int arraySize = mapOfEntityIdsByComponent[componentType].size();
        Entity** entityArray = new Entity*[arraySize];
        int i = 0;
        for(unsigned int eid : mapOfEntityIdsByComponent[componentType])
        {
            entityArray[i++] = entities[eid];
        }
        return entityArray;
    }

    /**
     * @brief Get all entities of class type
     * 
     * @tparam E entity class
     * @return Entity** array of entities; allocated memory requires manual delete
     */
    template <class E> Entity** getEntitiesOfType()
    {
        // IMPORTANT : Returned array uses memory; must be deleted when done
        std::string entityType = typeid(E).name();
        int arraySize = mapOfEntityIdsByType[entityType].size();
        Entity** entityArray = new Entity*[arraySize];
        int i = 0;
        for(unsigned int eid : mapOfEntityIdsByType[entityType])
        {
            entityArray[i++] = entities[eid];
        }
        return entityArray;
    }

    private:
    /** @brief Map of entities keyed by id */
    std::map<unsigned int, Entity*> entities;
    /** @brief Map of sets of entity ids keyed by component type string */
    std::map<std::string, std::set<unsigned int>> mapOfEntityIdsByComponent;
    /** @brief Map of sets of entity ids keyed by entity class string */
    std::map<std::string, std::set<unsigned int>> mapOfEntityIdsByType;
    /** @brief Map of maps of components keyed by entity ids, submaps keyed by component type strings */
    std::map<unsigned int, std::map<std::string, Component*>> mapOfComponentsByEntityId;
    /** @brief Highest never-assigned id */
    unsigned int nextEntityId;
    /** @brief Queue of freed-up entity ids */
    std::queue<unsigned int> freeEntityIds;

    /**
     * @brief Add entity to manager
     * 
     * @tparam E entity class
     * @param p_entity entity to add to manager
     */
    template <class E> void addEntityToManager(E* p_entity)
    {
        unsigned int id = p_entity->getId();
        std::string type = typeid(E).name();
        entities[id] = p_entity;
        mapOfEntityIdsByType[type].insert(id);
    }
    
    /**
     * @brief Remove entity from manager
     * 
     * @tparam E entity class
     * @param p_entity entity to remove from manager
     */
    template <class E> void removeEntityFromManager(E* p_entity)
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

    /**
     * @brief Get the next available entity id and update
     * 
     * @return unsigned int generated entity id
     */
    unsigned int generateEntityId()
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
    
};