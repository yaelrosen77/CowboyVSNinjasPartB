#pragma once
#include <iostream>
using namespace std;
#include "Point.hpp"
using namespace ariel; 

namespace ariel{
    class Character{
        protected:
            Point location_;
            int hitPoints_;
            string name_;
            void hit(int hits);
            double distance(const Character& other) const;

        public:
           Character(string name, Point location);
           string getName() const;
           Point getLocation() const;
           virtual string print() = 0;
           bool isAlive() const;
           virtual ~Character(){};
    };

}