#include "TrainedNinja.hpp"

using namespace std;

namespace ariel
{
    // Trained_Ninja_Speed = 12 , Trained_Ninja_Health = 120

    TrainedNinja::TrainedNinja(string _name, const Point &_location) : Ninja(_name, _location, 120, 12) {};

}