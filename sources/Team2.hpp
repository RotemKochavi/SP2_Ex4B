#pragma once
#include "Team.hpp"

#include <vector>

namespace ariel
{
    class Team2 : public Team {

    public:
        Team2(Character *);
        
        void attack(Team *) override;
        void print() const override;

    };
}