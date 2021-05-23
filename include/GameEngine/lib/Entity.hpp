#pragma once

// #include "../src/entities/EntityManager.hpp"
#include <string>

class Entity {
    public:
    Entity(unsigned int p_id);
    unsigned int getId();
    
    template <class T> void addComponent();
    template <class T> T removeComponent();
    template <class T> T getComponent();
    template <class T> bool hasComponent();
    template <class T> bool isType();

    template <class T> void add();
    template <class T> T remove();
    template <class T> T get();
    template <class T> bool has();
    template <class T> bool is();

    private:
    unsigned int id;
};