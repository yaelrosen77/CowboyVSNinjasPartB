#pragma once
#include <iostream>
using namespace std;
#include "Point.hpp"
using namespace ariel; 

namespace ariel{
    class Character{
        private:
            Point location_;
            int hitPoints_;
            string name_;


        public:
           Character(string name, Point location);
           void setName(string name){name_=name;}
           string getName() const;
           Point getLocation() const;
           virtual string print() = 0;
           virtual void attack(Character* other) = 0;
           bool isAlive() const;
           void hit(int hits);
           double distance(const Character* other) const;
           void SetLocation(Point& dest){location_=dest;}
           bool inTeam;
           int Gethp() const {return hitPoints_;}         
    };

}