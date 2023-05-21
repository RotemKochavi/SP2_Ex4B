#include "Character.hpp"
#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *character) {}
    
    Team::Team(const Team &other) {}
    
    Team::Team(Team &&other) noexcept {}
    
    Team::~Team() {}
    
    void Team::add(Character *warrior){
        return;
    }
    void Team::attack(Team *enemies){
        return;
    }
    int Team::stillAlive(){
        return 0;
    }
    void Team::print(){
        return;
    }

    Team &Team::operator=(const Team &other){
        return *this;
    }
    
    Team &Team::operator=(Team &&other) noexcept{
        return *this;
    }
    
}