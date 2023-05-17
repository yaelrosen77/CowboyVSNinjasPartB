#include <iostream>
using namespace std;
#include "Team.hpp"
using namespace ariel;

namespace ariel{
        class Team2 : public Team{
        public: 
        Team2(Character* leader):Team(leader){}
        void add(Character* mate) override;
    };
}