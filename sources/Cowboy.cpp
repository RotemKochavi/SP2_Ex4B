#include <iostream>
#include <string>
#include "Character.hpp"
#include "Cowboy.hpp"

using namespace std;

namespace ariel
{
	Cowboy::Cowboy(const string &_name, const Point &_location) : Character(_name, _location, 110), _bulletsCount(6) {}

	void Cowboy::shoot(Character *enemy){

		if (enemy == nullptr)
			throw invalid_argument("There is no other character\n");

		else if (enemy == this)
			throw runtime_error("Cannot shoot yourself\n");

		else if (!isAlive())
			throw runtime_error("You're dead. Cannot shoot\n");

		else if (!enemy->isAlive())
			throw runtime_error("The character is allready dead\n");
		

		else if (_bulletsCount > 0) {
            enemy->hit(10);
            _bulletsCount -= 1;
        }

		else
			cout << "Run out of bullets\n" << endl;
	}

	bool Cowboy::hasBoolets() const{
		return (_bulletsCount > 0);
	}

	void Cowboy::reload(){
		if (!isAlive())
            throw runtime_error("You're dead. can't reload.\n");
        _bulletsCount = 6;
	}

	int Cowboy::getBulletsCount() const{
        return _bulletsCount;
    }

	string Cowboy::print() const{
		if (isAlive())
			return "Cowboy name: " + getName() + 
					" --- Cowboy health: " + to_string(getHealth()) +
					" --- Cowboy location: " + getLocation().print();

		return "Cowboy name: " + getName() + 
				" --- Cowboy location: " + getLocation().print();
	}

}