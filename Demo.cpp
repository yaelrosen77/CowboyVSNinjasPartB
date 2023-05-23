/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

using namespace ariel;


int main() {
   Point d(2,1);  
   Point s(2.1,4.5);//
   Point w(-2,14);//
   Point j(5,-2);//
   Point z(-5,-4);
   Point a(-3,6);//
   Point l(-7,9);//
   Point b(-12,3.5);
   Point q(14,3);//
   Point c(-3.65,11);//
   Point e(6,7.9);
   Point p(0.5,-0.5);
   Point v(0.05,1.569);
   Point g(1.1,1.16);//
   Point k(10,10);
   Point n(6,4);
   Point r(-5,8);
   Point f(12,-3);//
   Point o(-3.3,3.2);
   Point x(-5.6,4);//
   Point h(5,1); 

   Cowboy* player1 = new Cowboy("vaquero",a);
   Cowboy* player2 = new Cowboy("cowboy",b);
   Cowboy* player3 = new Cowboy("rancher",c);
   Cowboy* player4 = new Cowboy("vaqueiro",d);
   Cowboy* player5 = new Cowboy("boker",g);
   YoungNinja* player6 = new YoungNinja("young",k);
   YoungNinja* player7 = new YoungNinja("joven",x);
   YoungNinja* player8 = new YoungNinja("giovane",e);
   YoungNinja* player9 = new YoungNinja("jovem",l);
   YoungNinja* player10 = new YoungNinja("iuvenis",z);
   OldNinja* player11 = new OldNinja("old",f);
   OldNinja* player12 = new OldNinja("viejo",h);
   OldNinja* player13 = new OldNinja("vetus",q);
   OldNinja* player14 = new OldNinja("vecchio",n);
   OldNinja* player15 = new OldNinja("vieux",j);
   TrainedNinja* player16 = new TrainedNinja("trained",r);
   TrainedNinja* player17 = new TrainedNinja("qualifie",w);
   TrainedNinja* player18 = new TrainedNinja("enetrenado",o);
   TrainedNinja* player19 = new TrainedNinja("allenato",s);
   TrainedNinja* player20 = new TrainedNinja("treinado",v);     

Team group(player13);
SmartTeam equipo(player4);
group.add(player3);
group.add(player5);
group.add(player7);
group.add(player9);
group.add(player11);
group.add(player1);
group.add(player15);
group.add(player17);
group.add(player19);
equipo.add(player2);
equipo.add(player6);
equipo.add(player8);
equipo.add(player10);
equipo.add(player12);
equipo.add(player14);
equipo.add(player16);
equipo.add(player18);
equipo.add(player20);

for (int i=0; i<10; i++){
   if (group.stillAlive()&&equipo.stillAlive()){
      group.attack(&equipo);
      equipo.attack(&group);
}
}
group.print();
equipo.print();
   return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}