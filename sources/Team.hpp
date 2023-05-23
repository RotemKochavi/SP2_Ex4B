#pragma once
#include <cmath>
#include <stdexcept>
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#include <sstream>
#include <memory>

#include "Point.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Character.hpp"

const int MaxSizeOfTeam = 10;


namespace ariel
{

    class Team {

        protected:

            std::vector<Character *> _team;
            Character *_leader;

        public:

            Team(Character *_leader);

            virtual ~Team();

            Character *getLeader() const;
            
            void setLeader();

            const vector<Character *> &getTeam() const;

            void add(Character *player);

            virtual void attack(Team *other);

            int stillAlive() const;

            virtual void print() const;

            Character *findClosest(const Team*);
            
    };
}
