#include "Team.hpp"
using namespace ariel; 

Team :: Team(Character* leader){
    this->leader = leader;
}

void Team :: add(Character* mate){
    unsigned int position = 0;
    unsigned int iter = 0;
    while (typeid(warriors.at(iter))==typeid(Cowboy)){
        iter++;
    }
    position = iter;
    if (typeid(mate) == typeid(Cowboy))
        warriors.insert(warriors.begin() + position, mate);
    else   
        warriors.push_back(mate);
}

void Team :: attack(Team* enemies){
    if (leader->isAlive() == false){
        Setleader();
    }
    Character* target = findT(enemies);
    for (auto &warrior : warriors){
        if (warrior->isAlive())
            
    }


}

void Team :: Setleader(){
    Point closest(DBL_MAX,DBL_MAX);
    Character* newleader;
    for (unsigned int i=0; i<warriors.size(); i++){
        if (warriors.at(i)->isAlive() && warriors.at(i)->getLocation().distance(leader->getLocation()) <
            leader->getLocation().distance(closest)){
                closest = warriors.at(i)->getLocation();
                newleader = warriors.at(i);
            }
    }
    leader = newleader;
}

int Team :: stillAlive(){
    return 0;
}

void Team :: print() const{
    return;
}

Character* Team :: findT(Team* enemies){
    Character* ans; 
    double minDist = DBL_MAX;
    for (auto &enemy : enemies->warriors)
        if (enemy->isAlive() && leader->distance(enemy) < minDist){
            minDist = leader->distance(enemy);
            ans = enemy;
        }
    return ans;
}

Team :: ~Team(){}
