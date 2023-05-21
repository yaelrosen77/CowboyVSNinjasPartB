#include "Team.hpp"
using namespace ariel; 

Team :: Team(Character* leader){
    this->leader = leader;
}

void Team :: add(Character* mate){
    if (warriors.size()==10)
        return;
    for (auto &warrior : warriors)
        if (warrior->getName() == mate->getName() && warrior->getLocation() == mate->getLocation())
            return;

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

void Team :: attack(Team* enemies) {
    if (stillAlive()==0 || enemies->stillAlive() ==0)
        return;
    if (leader->isAlive() == false){
        Setleader();
    }
    Character* target = findT(enemies);
    while (stillAlive()>0 && enemies->stillAlive()>0)
        for (auto &warrior : warriors){
            if (leader->isAlive() == false)
                Setleader();
            if (target->isAlive()==false)
                target = findT(enemies);
            if (target->isAlive()==false)
                return;
            if (warrior->isAlive())
                warrior->attack(target);
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
    int res =0;
    for (auto &warrior : warriors)
        if (warrior->isAlive())
            res++;
    return res;
}

void Team :: print() const{
    for (auto &warrior : warriors)
        warrior->print();
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
