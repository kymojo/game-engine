#include "Game.hpp"

using namespace Game;

template <class E> void Entities::add(E* p_entity, const std::string &p_type)
{
    if (!_isInitialized) throw "Entities::add() failed. GameEngine is not initialized.";
    _entities->addEntity(p_entity, p_type);
}
template <class E> void Entities::remove(E* p_entity)
{
    if (!_isInitialized) throw "Entities::remove() failed. GameEngine is not initialized.";
    _entities->removeEntity(p_entity);
}
template <class C, class E> void Entities::addComponentTo(C* p_component, E* p_entity)
{
    if (!_isInitialized) throw "Entities::addComponentTo() failed. GameEngine is not initialized.";
    _entities->addComponentToEntity(p_component,p_entity);
}
template <class C, class E> void Entities::removeComponentFrom(E* p_entity)
{
    if (!_isInitialized) throw "Entities::removeComponentFrom() failed. GameEngine is not initialized.";
    _entities->removeComponentFromEntity<C>();
}
template <class C> std::vector<Entity*> Entities::getAllWithComponent()
{
    if (!_isInitialized) throw "Entities::getAllWithComponent() failed. GameEngine is not initialized.";
    return _entities->getEntitiesWithComponent<C>();
}
template <class E> std::vector<E*> Entities::getAllOfClass()
{
    if (!_isInitialized) throw "Entities::getAllOfClass() failed. GameEngine is not initialized.";
    return _entities->getEntitiesOfType<E>();
}
template <class E> void Entities::forEach(void(*p_each)(E*))
{
    if (!_isInitialized) throw "Entities::forEach() failed. GameEngine is not initialized.";
    std::vector<E*> entitiesOfType = Entities::getAllOfClass<E>();
    for(E* entity : entitiesOfType)
        p_each(entity);
}
template <class C, class E> C* Entities::getComponentOf(E* p_entity)
{
    if (!_isInitialized) throw "Entities::getComponentOf() failed. GameEngine is not initialized.";
    return _entities->getEntityComponentOfType<C>(p_entity);
}
template <class E, class T> bool Entities::isEntityOfType(E* p_entity)
{
    if (!_isInitialized) throw "Entities::isEntityOfType() failed. GameEngine is not initialized.";
    return _entities->isEntityOfType<T>(p_entity);
}