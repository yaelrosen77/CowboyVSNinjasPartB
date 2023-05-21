#include "Team2.hpp"
using namespace ariel;


void Team2 :: add(Character* mate){
    if (warriors.size()==10)
        throw runtime_error("team cannot contain more than 10 warriors");
    for (Character* warrior : warriors){
        if (mate == warrior)
            throw runtime_error("is already on this team");}
    if (mate->inTeam == true)
        throw runtime_error("is in rival team");

    warriors.push_back(mate);  
    mate->inTeam = true;
}
