#include "Team2.hpp"
using namespace ariel;


void Team2 :: add(Character* mate){
    if (GetWarriors()->size()==10)
        throw runtime_error("team cannot contain more than 10 warriors");
    vector <Character*> * pointer = GetWarriors();
    for (Character* warrior : *pointer){
        if (mate == warrior)
            throw runtime_error("is already on this team");}
    if (mate->inTeam() == true)
        throw runtime_error("is in rival team");

    GetWarriors()->push_back(mate);  
    mate->Setin(true);
}
