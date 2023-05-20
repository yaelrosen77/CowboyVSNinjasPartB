#include "Cowboy.hpp"
using namespace ariel;

Cowboy :: Cowboy(string name, Point location):Character(name, location){
    Bullets_ = 6;
    hitPoints_ = 110;
}

bool Cowboy :: Cowboy :: hasboolets(){
    return 1;
}

void Cowboy :: reload(){
    return;
}

void Cowboy ::shoot(Character* enemy){
    return;
}

string Cowboy :: print(){
    return name_;
}

int Cowboy :: getNumOfBullets(){
    return 1;
}