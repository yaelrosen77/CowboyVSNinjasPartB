#include "YoungNinja.hpp"
using namespace ariel; 

YoungNinja :: YoungNinja(string name, Point location):Ninja(name,location){
    speed = 14;
    sethp(100);
}