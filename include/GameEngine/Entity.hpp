#pragma once
#include <string>

class Entity {
    public:
    Entity(const std::string& p_type);
    ~Entity();
    virtual void polymorph() {}
    void setId(unsigned int p_id);
    unsigned int getId();

    template <class C> void addComponent(C* p_component);
    template <class C> void removeComponent();
    template <class C> C* getComponent();
    template <class C> bool hasComponent();
    template <class E> bool isType();
    void destroy();

    template <class C> void add(C* p_component);
    template <class C> void remove();
    template <class C> C* get();
    template <class C> bool has();
    template <class T> bool is();

    private:
    unsigned int id;
};