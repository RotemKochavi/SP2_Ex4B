#include "Character.hpp"
#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *_leader) : _leader(_leader) {

        if (_leader == nullptr)
            throw invalid_argument("Team leader cannot be null");

        this->add(_leader);
    }

    Team::~Team() {
        for (auto fighter : _team)
            delete fighter;
    }
    
    void Team::add(Character *player) {
        if (player == nullptr)
		    throw invalid_argument("There is no player.");

        else if (player->getInTeam())
            throw runtime_error("The player is already in a team.");

        else if (_team.size() == 10)
            throw runtime_error("There are no additional places in the group.The team is full.");

        _team.push_back(player);

        player->setInTeam(true);
    }

    void Team::attack(Team *other) {

        if (other == nullptr)
            throw invalid_argument("There is no other team.\n");

        if (stillAlive() == 0)
            throw runtime_error("Team is dead. GAME OVER.\n");

        if(other->stillAlive() == 0)
		    throw runtime_error("Other team  is dead. GAME OVER.");

        if (!_leader->isAlive()) //Choose new leader
            setLeader();


        Character *victim = nullptr;

        for (Character *fighter : _team) {
            if (other->stillAlive() > 0)
                victim = findClosest(other);

            else
                return;

            if (fighter != nullptr && fighter->isAlive()) {
                
                if (victim != nullptr && victim->isAlive()) {

                    if(typeid(Cowboy) == typeid(*fighter)){

                        Cowboy *attacker = dynamic_cast<Cowboy*>(fighter);

                        if(attacker->hasBoolets())
                            attacker->shoot(victim);
                        
                        else
                            attacker->reload();
                    }
                }
                
                else
                    return;

            }
        }

        for (Character *fighter : _team) {

            if (other->stillAlive() > 0)
                victim = findClosest(other);

            else
                return;

            if (fighter != nullptr && fighter->isAlive()) {
                
                if (victim != nullptr && victim->isAlive()) {

                    if(typeid(Cowboy) != typeid(*fighter)) {
                        Ninja *attacker = dynamic_cast<Ninja*>(fighter);

                        if(attacker->distance(victim) < 1)
                            attacker->slash(victim);
                        
                        else
                            attacker->move(victim);
                    }
                }
                
                else
                    return;
            }
        }
    }

    Character* Team::findClosest(const Team* other) {

        Character *closest = nullptr;
        double min_distance = numeric_limits<double>::max();

        for (Character *character : other->getTeam()) {

            if (character->isAlive() && character != nullptr) {
                double distance = _leader->distance(character);

                if (distance <= min_distance) {
                    min_distance = distance;
                    closest = character;
                }
            }
        }

        return closest;
    }

    int Team::stillAlive() const{
        int count_alive = 0;

        for (Character *fighter : _team){
            if (fighter->isAlive())
                count_alive++;
        }

        return count_alive;
    }

    const vector<Character *> &Team::getTeam() const{
        return _team;
    }

    Character *Team::getLeader() const{
        return _leader;

    }
    
    void Team::setLeader(){
        Character *next_leader = findClosest(this);
        _leader = next_leader;
    }

    void Team::print() const{
        cout << "Team Leader: " << _leader->getName() << endl;
        cout << "Member team : " << endl;
        
        for (Character *fighter : _team)
            fighter->print();
    }

}