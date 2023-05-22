#pragma once
#include <iostream>
#include<stack>
using namespace std;
#include "Team.hpp"
using namespace ariel;

namespace ariel {
    class SmartTeam : public Team{
        public:
        SmartTeam(Character* leader):Team(leader){}
        void attack(Team* enemies) override;
    };
    Point secondTop(stack<Point> &stk);
}