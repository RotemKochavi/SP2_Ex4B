#pragma once
#include "Team.hpp"

#include <vector>

namespace ariel
{
    class Team2 : public Team
    {

    public:
        Team2(Character *leader);
        ~Team2();
        
        void attack(Team *enemy) override;
        void print() const override;

    };
}