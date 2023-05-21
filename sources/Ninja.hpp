#pragma once
#include <iostream>
#include <sstream>
using namespace std;
#include "Character.hpp"
using namespace ariel;

namespace ariel{
    class Ninja : public Character{
        public: 
            Ninja(string name, Point location);
            void print() override;
            void attack(Character* enemy) override;
            void move(Character* enemy);
            void slash(Character* enemy);
            int speed;
    };
}