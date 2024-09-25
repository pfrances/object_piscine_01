#ifndef HAMMER_HPP
#define HAMMER_HPP

#include "Tool.hpp"
#include <iostream>

class Hammer : public Tool {
    private:
        int _numberOfUses;

    public:
        Hammer() : _numberOfUses(0) {}
        void use() {
            _numberOfUses++;
            std::cout << "[Hammer usage] : " << _numberOfUses << std::endl;
        }
};

#endif