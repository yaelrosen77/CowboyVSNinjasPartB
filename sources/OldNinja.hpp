#ifndef OLDNINJA_
#define OLDNINJA_
#include <iostream>
using namespace std; 
#include "Ninja.hpp"

namespace ariel {
    class OldNinja : public Ninja{
        public:     
            OldNinja(string name, Point location);
    };
}

#endif