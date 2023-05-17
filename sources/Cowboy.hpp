#pragma once
#include <iostream>
using namespace std; 
#include "Character.hpp"

namespace ariel{

    class Cowboy : public Character{
        int Bullets_;
        bool hasBullets();
        void reload();       

        public:
            int getNumOfBullets();
            string print() override;
            Cowboy(string name, Point location);
            void shoot(Character* enemy);
    };

}