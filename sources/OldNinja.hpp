#pragma once

#include "Ninja.hpp"

using namespace std;

namespace ariel{
    class OldNinja : public Ninja{

        public:
            OldNinja(string _name, const Point &_location);
    };
}