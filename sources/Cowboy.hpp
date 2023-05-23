#ifndef COWBOY_
#define COWBOY_
#include <iostream>
#include <sstream>
using namespace std; 
#include "Character.hpp"

namespace ariel{

    class Cowboy : public Character{
        int Bullets_;     

        public:
            string print() override;
            void attack(Character* enemy) override;
            Cowboy(string name, Point location);
            void shoot(Character* enemy);
            bool hasboolets();
            void reload(); 
    };

}

#endif