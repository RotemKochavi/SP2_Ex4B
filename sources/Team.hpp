#include <vector>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"

namespace ariel {
    class Team {
    private:
        Character* leader;
        std::vector<Character*> warriors;
    public:
        Team(Character* character);
        Team(const Team& other);
        Team(Team&& other) noexcept;
        ~Team();

        void add(Character* warrior);
        void attack(Team* enemies);
        int stillAlive();
        void print();

        Team& operator=(const Team& other);
        Team& operator=(Team&& other) noexcept;
    };
}