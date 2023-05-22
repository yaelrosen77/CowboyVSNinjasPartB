#include "Cowboy.hpp"
using namespace ariel;

Cowboy :: Cowboy(string name, Point location):Character(name, location){
    Bullets_ = 6;
    sethp(110);
}

bool Cowboy :: Cowboy :: hasboolets(){
    return Bullets_> 0 ? true : false; 
}

void Cowboy :: reload(){
    if (isAlive() == false)
        throw runtime_error("dead character mal-function");
    Bullets_ = 6;
}

void Cowboy ::shoot(Character* enemy){
    if (isAlive() == false || enemy->isAlive() == false)
        throw runtime_error("dead character mal-function");
    if (enemy == this)
        throw runtime_error("no self harm");
    if (isAlive() && Bullets_ > 0){
        enemy->hit(10);
        Bullets_--;
    }
}

string Cowboy :: print(){
    string str;
    if (this->isAlive()){
        str = "C Fighter name is " + getName() + ". Num of hitpoints are " + 
                    to_string(Gethp()) + ". Located in " + getLocation().print();
    }
    else {
        str = "C Fighter name was (" + getName() + ") . Last seen in " + getLocation().print();
    }
    return str;
}

void Cowboy :: attack(Character* enemy){
    if (Bullets_>0)
        shoot(enemy);
    else reload();
}