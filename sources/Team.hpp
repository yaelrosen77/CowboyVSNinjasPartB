#pragma once
#include <iostream>
#include <vector>
using namespace std;

#include "Point.hpp"
#include "Character.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"

namespace ariel{
    class Team{
        vector <Character*> warriors;
        Character* leader;

        public:
            Team(Character* leader);
            virtual void add(Character* mate);
            void attack(Team* enemies);
            int stillAlive();
            void print() const;
            virtual ~Team();
    };
}