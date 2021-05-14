#include "GameObject.hpp"

GameObject::GameObject(unsigned int p_id) : id(p_id)
{
    onCreate();
}
unsigned int GameObject::getId()
{
    return id;
}
void GameObject::onCreate() {}
void GameObject::update() {}
void GameObject::render() {}
void GameObject::onDelete() {}