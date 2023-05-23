#include "TrainedNinja.hpp"

using namespace std;
namespace ariel{

    // Trained_Ninja_Speed = 12;
    // Trained_Ninja_Health = 120;


    TrainedNinja::TrainedNinja(string name, const Point &location) :
    Ninja(name, location, 120, 12) {};

}