#pragma once

#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team {
 
        public:

            SmartTeam(Character*);

            void attack(Team*) override;
            
            void print() const override;

    };
}