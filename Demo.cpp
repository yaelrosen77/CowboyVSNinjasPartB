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
   Point s(2.1,4.5);
   Point w(-2,14);
   Point j(5,-2);
   Point z(-5,-4);
   Point a(-3,6);
   Point l(-7,9);
   Point b(-12,3.5);
   Point q(14,3);
   Point c(-3.65,11);
   Point e(6,7.9);
   Point p(0.5,-0.5);
   Point v(0.05,1.569);
   Point g(1.1,1.16);
   Point k(10,10);
   Point n(6,4);
   Point r(-5,8);
   Point f(12,-3);
   Point o(-3.3,3.2);
   Point x(-5.6,4);
   Point h(5,1); 

   Cowboy player1("vaquero",a);
   Cowboy player2("cowboy",b);
   Cowboy player3("rancher",c);
   Cowboy player4("vaqueiro",d);
   Cowboy player5("boker",g);
   YoungNinja player6("young",k);
   YoungNinja player7("joven",x);
   YoungNinja player8("giovane",e);
   YoungNinja player9("jovem",l);
   YoungNinja player10("iuvenis",z);
   OldNinja player11("old",f);
   OldNinja player12("viejo",h);
   OldNinja player13("vetus",q);
   OldNinja player14("vecchio",n);
   OldNinja player15("vieux",j);
   TrainedNinja player16("trained",r);
   TrainedNinja player17("qualifie",w);
   TrainedNinja player18("enetrenado",o);
   TrainedNinja player19("allenato",s);
   TrainedNinja player20("treinado",v);     

Team group(&player1);
SmartTeam equipo(&player2);
group.add(&player3);
group.add(&player5);
group.add(&player7);
group.add(&player9);
group.add(&player11);
group.add(&player13);
group.add(&player15);
group.add(&player17);
group.add(&player19);
equipo.add(&player4);
equipo.add(&player6);
equipo.add(&player8);
equipo.add(&player10);
equipo.add(&player12);
equipo.add(&player14);
equipo.add(&player16);
equipo.add(&player18);
equipo.add(&player20);

for (int i=0; i<5; i++){
   group.attack(&equipo);
   equipo.attack(&group);
   


}
   return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}