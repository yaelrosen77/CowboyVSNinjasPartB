#ifndef NINJA_
#define NINJA_
#include <iostream>
#include <sstream>
using namespace std;
#include "Character.hpp"
using namespace ariel;

namespace ariel{
    class Ninja : public Character{
        public: 
            Ninja(string name, Point location);
            string print() override;
            void attack(Character* enemy) override;
            void move(Character* enemy);
            void slash(Character* enemy);
            int speed;
    };
}

#endif