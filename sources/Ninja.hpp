#pragma once
#include <iostream>
using namespace std;
#include "Character.hpp"
using namespace ariel;

namespace ariel{
    class Ninja : public Character{
        public: 
            Ninja(string name, Point location);
            string print() override;
            void move(Character* enemy);
            void slash(Character* enemy);
            int speed;
    };
}