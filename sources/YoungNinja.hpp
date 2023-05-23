#ifndef YOUNGNINJA_
#define YOUNGNINJA_
#include <iostream>
using namespace std;
#include "Ninja.hpp"

namespace ariel{

    class YoungNinja : public Ninja{
        public:     
            YoungNinja(string name, Point location);
    };

}
#endif