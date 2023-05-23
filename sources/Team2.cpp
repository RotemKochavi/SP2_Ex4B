#include <iostream>
#include "Team2.hpp"

using namespace std;
namespace ariel{

    Team2::Team2(Character *_leader) : Team(_leader) {}

    void Team2::attack(Team *other){

        if (other == nullptr)
            throw invalid_argument("There is no other team.\n");

        if (stillAlive() == 0)
            throw runtime_error("Team is dead. GAME OVER.\n");

        if(other->stillAlive() == 0)
		    throw runtime_error("Other team  is dead. GAME OVER.\n");

        if (!_leader->isAlive()){ //Choose new leader
            setLeader();
        }

        Character *victim = nullptr;

        for (Character *fighter : _team) {
            if (other->stillAlive() > 0)
                victim = findClosest(other);
            
            return;

            if (fighter != nullptr && fighter->isAlive()) {
                
                if (victim != nullptr && victim->isAlive()) {
                    if(typeid(Cowboy) == typeid(*fighter)){     // fighter = Cowboy
                        Cowboy *attacker = dynamic_cast<Cowboy*>(fighter);
                        if(attacker->hasBoolets()){
                            attacker->shoot(victim);
                        }
                        else{
                            attacker->reload();
                        }
                    }
                    else{
                        Ninja *attacker = dynamic_cast<Ninja*>(fighter);
                        if(attacker->distance(victim) < 1){
                            attacker->slash(victim);
                        }
                        else
                            attacker->move(victim);
                    
                    }
                }
                
                else
                {
                    return;
                }
            }
        }
    }

    void Team2::print() const {
    	cout << "Team Leader: " << getLeader()->getName() << endl;

    	for (Character *member : getTeam())
    		cout << member->print() << endl;
    }
}

