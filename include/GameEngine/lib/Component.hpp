#pragma once

#include <string>

class Component
{
    public:
    Component(std::string p_type);
    virtual void cleanUp();

    private:
    std::string type;
};