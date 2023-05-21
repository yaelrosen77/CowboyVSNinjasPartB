#include "Character.hpp"
using namespace ariel;

Character :: Character(string name, Point location):
    location_(location),name_(name){}

void Character :: hit(int hits){
    hitPoints_ -= hits;
}

double Character :: distance(const Character* other) const{
    return location_.distance(other->getLocation());
}

string Character :: getName() const{
    return name_;
}

Point Character :: getLocation() const{
    return location_;
}

bool Character :: isAlive() const{
    if (hitPoints_>0){
        return true;
    }
    return false;
} 