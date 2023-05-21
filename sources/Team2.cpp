#include "Team2.hpp"
using namespace ariel;


void Team2 :: add(Character* mate){
    if (warriors.size()==10)
        return;
    warriors.push_back(mate);  
}
