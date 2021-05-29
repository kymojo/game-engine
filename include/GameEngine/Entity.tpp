#pragma once
#include "Entity.hpp"
#include "Game.hpp"

using namespace Game;

template <class C> void Entity::addComponent(C* p_component)
{
    Entities::addComponentTo(p_component, this);
}
template <class C> void Entity::removeComponent()
{
    Entities::removeComponentFrom<C>(this);
}
template <class C> C* Entity::getComponent()
{
    return Entities::getComponentOf<C>(this);
}
template <class C> bool Entity::hasComponent()
{
    return (Entities::getComponentOf<C>(this) != NULL);
}
template <class E> bool Entity::isType()
{
    return Entities::isEntityOfType<E>(this);
}

template <class C> void Entity::add(C* p_component)
{
    addComponent<C>(p_component);
}
template <class C> void Entity::remove()
{
    return removeComponent<C>();
}
template <class C> C* Entity::get()
{
    return getComponent<C>();
}
template <class C> bool Entity::has()
{
    return hasComponent<C>();
}
template <class T> bool Entity::is()
{
    return isType<T>();
}