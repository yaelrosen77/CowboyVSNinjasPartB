#pragma once
#include <iostream>
#include <sstream>
using namespace std; 
#include "Character.hpp"

namespace ariel{

    class Cowboy : public Character{
        int Bullets_;     

        public:
            int getNumOfBullets();
            string print() override;
            Cowboy(string name, Point location);
            void shoot(Character* enemy);
            bool hasboolets();
            void reload();  
    };

}