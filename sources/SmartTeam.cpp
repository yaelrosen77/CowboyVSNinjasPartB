#include <iostream>
using namespace std;
#include "SmartTeam.hpp"
#include "Team.hpp"
using namespace ariel;

Point po0(0,0);
void SmartTeam :: attack(Team* enemies){
    if (enemies == nullptr)
        throw invalid_argument("null ptr");
    if (enemies->stillAlive() ==0 || stillAlive()==0)
        throw runtime_error("dead enemy team");
    if (getleader()->isAlive() == false){
        Setleader();
    }
    vector<Point> convex;
    int actual_size = 0;
    for (Character* enemy : *(enemies->GetWarriors())){
        if (enemy->isAlive()){
            Point tmp = enemy->getLocation();
            convex.insert((convex.begin()+actual_size), tmp);
            actual_size++;
        }
    }
    vector<Point> convexed = findConvexHull(convex, actual_size);
    vector<Character*> selfteam = *GetWarriors();
    for (Point enemy : convexed){
         for (size_t i =0 ; i < selfteam.size(); i++){
            Character* warrior = selfteam[selfteam.size()-i-1];
            if (warrior->isAlive() && warrior->inPos()==false){
               if (typeid(warrior)==typeid(YoungNinja)){
                  Point tmp = Point :: moveTowards(warrior->getLocation(),enemy,14);  
                  if (tmp.distance(enemy)>2){
                     tmp = Point :: moveTowards(tmp,enemy,14);
                  }
                  warrior->SetLocation(tmp);
                  warrior->setPos(true);             
               }
               if (typeid(warrior)==typeid(TrainedNinja)){
                  Point tmp = Point :: moveTowards(warrior->getLocation(),enemy,12);
                  if (tmp.distance(enemy)>2){
                     tmp = Point :: moveTowards(tmp,enemy,12);
                  }
                  warrior->SetLocation(tmp);
                  warrior->setPos(true);
               }
               if (typeid(warrior)==typeid(OldNinja)){
                  Point tmp = Point :: moveTowards(warrior->getLocation(),enemy,10);
                  if (tmp.distance(enemy)>2){
                     tmp = Point :: moveTowards(tmp, enemy,10);
                  }
                  warrior->SetLocation(tmp);
                  warrior->setPos(true);
               }
            if (warrior->inPos())
               break;
         }
   }
}       

   Character* target = findT(enemies);
   if (target == nullptr)
      return;
   for (Character* warrior : selfteam){
      if (warrior->isAlive())
            warrior->attack(target);
        if (target->isAlive()==false){
            target = findT(enemies);
            if (target == nullptr)
                return;
        }
    }
po0.SetX(0);
po0.SetY(0);
for (Character* warrior : selfteam)
   if (warrior->inPos())
      warrior->setPos(false);
}


Point ariel :: secondTop(stack<Point> &stk) {
   Point tempPoint = stk.top(); 
   stk.pop();
   Point res = stk.top();    //get the second top element
   stk.push(tempPoint);      //push previous top again
   return res;
}

int ariel :: direction(Point apo, Point bpo, Point cpo) {
   double val = (bpo.getY()-apo.getY())*(cpo.getX()-bpo.getX())-(bpo.getX()-apo.getX())*(cpo.getY()-bpo.getY());
   if (val == 0)
      return 0;    //colinear
   else if(val < 0)
      return 2;    //anti-clockwise direction
    return 1;    //clockwise direction
}

int ariel :: comp(const void *point1, const void*point2) {
   Point *p1 = (Point*)point1;
   Point *p2 = (Point*)point2;
   int dir = direction(po0, *p1, *p2);
   if(dir == 0)
      return ((pow(po0.distance(*p2),2))>= pow(po0.distance(*p1),2)) ?-1 : 1;
   return (dir==2)? -1 : 1;
}

vector<Point> ariel :: findConvexHull(vector<Point>& points, int n) {
   vector<Point> convexHullPoints;
   double minY = points[0].getY();
   size_t min = 0;
   for(size_t i = 1; i<n; i++) {
      double yval = points[i].getY();
      //find bottom most or left most point
      if((yval < minY) || (minY == yval) && points[i].getX() < points[min].getX()) {
         minY = points[i].getY();
         min = i;
      }
   }
   swap(points[0], points[min]);    //swap min point to 0th location
   po0 = points[0];
   qsort(&points[1], (size_t)(n-1), sizeof(Point), comp);    //sort points from 1 place to end
   size_t arrSize = 1;    //used to locate items in modified array
   for(size_t i = 1; i<n; i++) {
      //when the angle of ith and (i+1)th elements are same, remove points
      while(i < n-1 && direction(po0, points[i], points[i+1]) == 0)
         i++;
         points[arrSize] = points[i];
         arrSize++;
   }
   if(arrSize < 3)
      return convexHullPoints;   
      stack<Point> stk;
      stk.push(points[0]); stk.push(points[1]); stk.push(points[2]);
   for(size_t i = 3; i<arrSize; i++) {  
      while(direction(secondTop(stk), stk.top(), points[i]) != 2)
         stk.pop();    
         stk.push(points[i]);
   }
   while(!stk.empty()) {
      convexHullPoints.push_back(stk.top());    
      stk.pop();
   }
   return convexHullPoints;
}