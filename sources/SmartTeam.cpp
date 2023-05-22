#include <iostream>
using namespace std;
#include "SmartTeam.hpp"
using namespace ariel;

void SmartTeam :: attack(Team* enemies){

}

Point ariel :: secondTop(stack<Point> &stk) {
   Point tempPoint = stk.top(); 
   stk.pop();
   Point res = stk.top();    //get the second top element
   stk.push(tempPoint);      //push previous top again
   return res;
}

int direction(Point apo, Point bpo, Point cpo) {
   double val = (bpo.getY()-apo.getY())*(cpo.getX()-bpo.getX())-(bpo.getX()-apo.getX())*(c.y-b.y);
   if (val == 0)
      return 0;    //colinear
   else if(val < 0)
      return 2;    //anti-clockwise direction
      return 1;    //clockwise direction
}