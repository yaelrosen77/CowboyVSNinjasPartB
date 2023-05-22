#include "TrainedNinja.hpp"
using namespace ariel;

TrainedNinja :: TrainedNinja(string name, Point location):Ninja(name,location){
    speed = 12;
    sethp(120);
}