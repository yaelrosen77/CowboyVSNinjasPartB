#ifndef TRAINEDNINJA_
#define TRAINEDNINJA_
#include <iostream>
using namespace std; 
#include "Ninja.hpp"

namespace ariel{
    class TrainedNinja : public Ninja{
        public:     
            TrainedNinja(string name, Point location);
    };
}

#endif