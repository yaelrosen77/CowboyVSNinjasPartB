#ifndef SMARTTEAM_
#define SMARTTEAM_
#include "Team.hpp"
#include <iostream>
#include <stack>
#include <algorithm>
using namespace ariel;
using namespace std;

namespace ariel {
    class SmartTeam : public Team{
        public:
        SmartTeam(Character* leader):Team(leader){}
        void attack(Team* enemies) override;
    };
    Point secondTop(stack<Point> &stk);
    int direction(Point apo, Point bpo, Point cpo);
    int comp(const void *point1, const void*point2); 
    vector<Point> findConvexHull(vector <Point>& points, int n);
}

#endif