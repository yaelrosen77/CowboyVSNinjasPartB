#include "Team.hpp"
using namespace ariel; 

Team :: Team(Character* leader){
    if (leader->inTeam())
        throw runtime_error("leader is on rival team");
    this->leader = leader;
    leader->Setin(true);
    warriors.insert(warriors.begin(),leader);
}

void Team :: add(Character* mate){
    if (warriors.size()==10)
        throw runtime_error("team cannot contain more than 10 warriors");
    for (Character* &warrior : warriors){
        if (mate == warrior)
            throw runtime_error("is already on this team");}
    if (mate->inTeam() == true)
        throw runtime_error("is in rival team");

    unsigned int position = 0;
    unsigned int iter = 0;
    while (typeid(warriors.at(iter))==typeid(Cowboy)){
        iter++;
    }
    position = iter;
    if (typeid(mate) == typeid(Cowboy)){
        warriors.insert(warriors.begin() + position, mate);
        mate->Setin(true);}
    else  { 
        warriors.push_back(mate);
        mate->Setin(true);}
}

void Team :: attack(Team* enemies) {
    if (enemies == nullptr)
        throw invalid_argument("null ptr");
    if (enemies->stillAlive() ==0 || stillAlive()==0)
        throw runtime_error("dead enemy team");
    if (leader->isAlive() == false){
        Setleader();
    }
    Character* target = findT(enemies);
    if (target == nullptr)
        return;
    for (Character* warrior : warriors){
        if (warrior->isAlive())
             warrior->attack(target);
        if (target->isAlive()==false){
            target = findT(enemies);
            if (target == nullptr)
                return;
        }
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
    for (Character* warrior : warriors){
        if (warrior->isAlive())
            res++;}
    return res;
}

void Team :: print() const{
    string str;
    for (Character* warrior : warriors){
        str.append(warrior->print());
        str.append("\n");}
    cout << str << endl; 
}

Character* Team :: findT(Team* enemies){
    Character* ans; 
    double minDist = DBL_MAX;
    if (enemies->stillAlive() ==0)
        return nullptr;
    for (Character* enemy : enemies->warriors)
        if (enemy->isAlive() && leader->distance(enemy) < minDist){
            minDist = leader->distance(enemy);
            ans = enemy;
        }
    return ans;
}

Team :: ~Team(){
    for (Character* warrior : warriors)
        delete warrior;
    leader = nullptr;
    warriors.clear();
}
