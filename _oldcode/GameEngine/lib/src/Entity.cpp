#include "../Entity.hpp"
#include "../../GameEngine.hpp"
#include <string>

using namespace Game;

Entity::Entity() : id(0) {}
Entity::~Entity() {}

void Entity::setId(unsigned int p_id)
{
    if (id == 0)
        id = p_id;
    else
        throw "Entity::setId() failed. Entity already has an id.";
}
unsigned int Entity::getId()
{
    return id;
}

/**
 * @brief Add a component to this entity
 *
 * @tparam C component class
 * @param p_component component to add
 */
template <class C> void Entity::addComponent(C* p_component)
{
    Entities::addComponentTo(p_component, this);
}

/**
 * @brief Remove component from this entity
 *
 * @tparam C component class
 */
template <class C> void Entity::removeComponent()
{
    Entities::removeComponentFrom<C>(this);
}

/**
 * @brief Get component of type for this entity
 *
 * @tparam C component class
 * @return C component to get
 */
template <class C> C* Entity::getComponent()
{
    return Entities::getComponentOf<C>(this);
}

/**
 * @brief Check if this entity has a component of given type
 *
 * @tparam C component class
 * @return true - entity has component of type
 * @return false - entity does not have component of type
 */
template <class C> bool Entity::hasComponent()
{
    return (Entities::getComponentOf<C>(this) != NULL);
}

/**
 * @brief Check if this entity is of a given class
 *
 * @tparam E entity class
 * @return true - entity is of class
 * @return false - entity is not of class
 */
template <class E> bool Entity::isType()
{
    return Entities::isEntityOfType<E>(this);
}

/** @brief Alias of Entity::addComponent */
template <class C> void Entity::add(C* p_component)
{
    addComponent<C>(p_component);
}
/** @brief Alias of Entity::removeComponent */
template <class C> void Entity::remove()
{
    return removeComponent<C>();
}
/** @brief Alias of Entity::getComponent */
template <class C> C* Entity::get()
{
    return getComponent<C>();
}
/** @brief Alias of Entity::hasComponent */
template <class C> bool Entity::has()
{
    return hasComponent<C>();
}
/** @brief Alias of Entity::isType */
template <class T> bool Entity::is()
{
    return isType<T>();
}