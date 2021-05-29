#include "Entity.hpp"
#include "Game.hpp"

using namespace Game;

Entity::Entity(const std::string &p_type) {
    id = 0;
    Entities::add(this,p_type);
}
Entity::~Entity() {
    Entities::remove(this);
}

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