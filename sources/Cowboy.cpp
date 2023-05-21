#include "Cowboy.hpp"
using namespace ariel;

Cowboy :: Cowboy(string name, Point location):Character(name, location){
    Bullets_ = 6;
    hitPoints_ = 110;
}

bool Cowboy :: Cowboy :: hasboolets(){
    return Bullets_> 0 ? true : false; 
}

void Cowboy :: reload(){
    Bullets_ += 6;
}

void Cowboy ::shoot(Character* enemy){
    if (isAlive() && Bullets_ > 0){
        enemy->hit(10);
        Bullets_--;
    }
}

string Cowboy :: print(){
    string str;
    string tmp;
    ostringstream local;            
    auto cout_buff = cout.rdbuf();
    cout.rdbuf(local.rdbuf());
    location_.print();
    cout.rdbuf(cout_buff);

    if (this->isAlive()){
        str = "C Fighter name is " + name_ + ". Num of hits are " + 
                    to_string(hitPoints_) + ". Located in " + local.str();
    }
    else {
        string str = "C Fighter name was (" + name_ + ") . Last seen in " + local.str();
    }
    return str;
}

int Cowboy :: getNumOfBullets(){
    return Bullets_;
}

void Cowboy :: attack(){

}