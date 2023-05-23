// #include <iostream>
// #include "SmartTeam.hpp"

// using namespace std;
// using namespace ariel;

// SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

// void SmartTeam::attack(Team *other){

//     if (other == nullptr)
//             throw invalid_argument("There is no other team.\n");

//         if (stillAlive() == 0)
//             throw runtime_error("Team is dead. GAME OVER.\n");

//         if(other->stillAlive() == 0)
// 		    throw runtime_error("Other team  is dead. GAME OVER.");

//         if (!_leader->isAlive()){ //Choose new leader

//             Character *newLeader = nullptr;
//             double min_dis = numeric_limits<double>::max();

//             for (auto fighter : _team) {
//                 if (fighter->isAlive() && fighter != _leader) {
//                     double distance = _leader->getLocation().distance(fighter->getLocation());
                    
//                     if (distance <= min_dis) {
//                         min_dis = distance;
//                         newLeader = fighter;
//                     }
//                 }
//             }

//             _leader = newLeader;
//         }

//         Character *victim = nullptr;

//         if (other->stillAlive() > 0)
//             victim = findClosestVictim(other->_team, _leader->getLocation());
//         else
//             return;

//         for (auto fighter : _team) {
//             if (fighter != nullptr && fighter->isAlive()) {
                
//                 if (victim != nullptr && victim->isAlive()) {
//                     fighter->attack(victim);
//                     victim->print();
//                 }
                
//                 else
//                 {
//                     victim = findClosestVictim(other->_team, _leader->getLocation());
//                     if (victim != nullptr && victim->isAlive()) {
//                         fighter->attack(victim);
//                         victim->print();
//                     }
//                 }
//             }
//         }
//     }


// void SmartTeam::print() const {

//     for (Character *character : *this->getTeam())
//         cout << character->print() << endl;
// }