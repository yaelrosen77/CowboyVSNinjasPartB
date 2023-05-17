#include "Ninja.hpp"
using namespace ariel;

void Ninja:: move(Character* enemy){
    return;
}
void Ninja:: slash(Character* enemy){
    return;
}
string Ninja::print(){
    return name_;    
}
Ninja :: Ninja(string name, Point location):
    Character(name, location){}
