#ifndef Shovel_HPP
#define Shovel_HPP

#include "Tool.hpp"
#include <iostream>

class Shovel : public Tool { 
    private:
        int _numberOfUses;

    public:
        Shovel() : _numberOfUses(0) {}
        void use() {
            _numberOfUses++;
            std::cout << "[Shovel usage] : " << _numberOfUses << std::endl;

        }
};

#endif