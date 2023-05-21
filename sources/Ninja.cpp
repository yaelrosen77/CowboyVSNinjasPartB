#include "Ninja.hpp"
using namespace ariel;

void Ninja:: move(Character* enemy){
    Point enemyloc = enemy->getLocation(); 
    Point tmp = Point :: moveTowards(location_,enemyloc,speed);
    location_ = tmp;
}

void Ninja:: slash(Character* enemy){
    if (isAlive() && distance(enemy) < 1){
        enemy->hit(40);
    }
}

string Ninja::print(){
    string str;
    string tmp;
    ostringstream local;            
    auto cout_buff = cout.rdbuf();
    cout.rdbuf(local.rdbuf());
    location_.print();
    cout.rdbuf(cout_buff);

    if (this->isAlive()){
        str = "N Fighter name is " + name_ + ". Num of hits are " + 
                    to_string(hitPoints_) + ". Located in " + local.str();
    }
    else {
        string str = "N Fighter name was (" + name_ + ") . Last seen in " + local.str();
    }
    return str;    
}

Ninja :: Ninja(string name, Point location):
    Character(name, location){}
