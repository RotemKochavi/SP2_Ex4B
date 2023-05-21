#include "Point.hpp"
#include "Ninja.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"

#include <vector>

namespace ariel
{
    class Team2
    {
    private:
        Character *leader;
        std::vector<Character *> warriors2;

    public:
        Team2(const Team2 &other);
        Team2(Team2&& other) noexcept;
        Team2(Character *leader);
        ~Team2();
        
        void add(Character *warrior2);
        void attack(Team2 &enemy);
        int stillAlive() const;
        void print() const;

        Team2 &operator=(const Team2 &other);
        Team2& operator=(Team2&& other) noexcept;
    };
}