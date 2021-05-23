#pragma once
// #include "../../GameEngine.hpp"
#include "../../lib/Entity.hpp"
#include "../../lib/Component.hpp"
// #include "EntityManager.hpp"

/** @brief Game entity management */
namespace Entities
{
    template <class T> Entity* create(T* p_entity);
    void destroy(unsigned int p_entityId);
    template <class T> Entity** withComponent();
    template <class T> Entity** ofType();
}