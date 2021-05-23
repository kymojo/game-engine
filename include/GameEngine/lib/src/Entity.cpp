#include "../Entity.hpp"

Entity::Entity(unsigned int p_id)
{
    id = p_id;
}

template <class T> void Entity::addComponent()
{
    //
}

template <class T> T Entity::removeComponent()
{
    //
}

template <class T> T Entity::getComponent()
{
    //
}

template <class T> bool Entity::hasComponent()
{
    //
}

template <class T> bool Entity::isType()
{
    return typeid(T).name() == typeid(this).name();
}




template <class T> void Entity::add()
{
    addComponent<T>();
}
template <class T> T Entity::remove()
{
    return removeComponent<T>();
}
template <class T> T Entity::get()
{
    return getComponent<T>();
}
template <class T> bool Entity::has()
{
    return hasComponent<T>();
}
template <class T> bool Entity::is()
{
    return isType<T>();
}