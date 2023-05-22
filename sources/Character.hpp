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
            bool inteam;

        public:
           Character(string name, Point location);
           Character(const Character &other) = delete;
           Character& operator=(const Character &other) = delete;
           Character& operator=(Character&& other) = delete;
           Character(Character&& other) = delete;
           void setName(string &name){name_=name;}
           string getName() const;
           Point getLocation() const;
           virtual string print() = 0;
           bool inTeam() const {return inteam;}
           void Setin(bool val){inteam = val;}
           virtual void attack(Character* other) = 0;
           bool isAlive() const;
           void hit(int hits);
           double distance(const Character* other) const;
           void SetLocation(Point& dest){location_=dest;}
           int Gethp() const {return hitPoints_;}    
           void sethp(const int num) {hitPoints_=num;}     
           virtual ~Character() = default;
    };

}