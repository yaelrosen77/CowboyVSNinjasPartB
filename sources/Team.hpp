#pragma once
#include <iostream>
#include <float.h>
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
        private:
        vector <Character*> warriors;
        Character* leader;

        public:
            Team(Character* leader);
            vector <Character*> * GetWarriors(){return &warriors;}
            Team(const Team& other) = delete;
            Team& operator=(const Team& other);
            Team(Team&& other) = delete;
            Team& operator=(Team&& other) = delete;
            virtual void add(Character* mate);
            virtual void attack(Team* enemies);
            int stillAlive();
            void print() const;
            void Setleader();
            Character* findT(Team* enemies);
            virtual ~Team();
    };
}