#include "Ninja.hpp"
using namespace ariel;

void Ninja:: move(Character* enemy){
    Point enemyloc = enemy->getLocation(); 
    Point tmp = Point :: moveTowards(location_,enemyloc,speed);
    location_ = tmp;
}

void Ninja:: slash(Character* enemy){
    if (isAlive() == false || enemy->isAlive()==false)
        throw runtime_error("dead character mal-function");
    if (enemy == this)
        throw runtime_error("no self harm");
    if (distance(enemy) < 1){
        enemy->hit(40);
    }
}

string Ninja::print(){
    string str;
    if (this->isAlive()){
        str = "N Fighter name is " + name_ + ". Num of hitpoints are " + 
                    to_string(hitPoints_) + ". Located in " + location_.print();
    }
    else str = "N Fighter name was (" + name_ + ") . Last seen in " + location_.print();
    return str;    
}

Ninja :: Ninja(string name, Point location):
    Character(name, location){}

void Ninja ::attack(Character* enemy){
    if (distance(enemy)<1)
        slash(enemy);
    else move(enemy);
} 