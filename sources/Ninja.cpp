#include <iostream>
#include <string>
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;
using namespace ariel;

Ninja::Ninja(const string &_name, const Point &_location, int _health, int _speed) : Character(_name, _location, _health), _speed(_speed) {}

void Ninja::move(Character *enemy){
	if (enemy == nullptr)
		throw invalid_argument("There is no other character.\n");

	else if (enemy == this)
		throw invalid_argument("Cannot move to yourself.\n");

	else if (!isAlive())
		throw runtime_error("You're dead. Cannot move.\n");

	Point new_location = Point::moveTowards(getLocation(), enemy->getLocation(), _speed);

	setLocation(new_location);
}

void Ninja::slash(Character *enemy){
	if (enemy == nullptr)
		throw invalid_argument("There is no other character.\n");

	else if (enemy == this)
		throw runtime_error("Cannot slash yourself.\n");

	else if (!isAlive())
		throw runtime_error("You're dead. Cannot slash.\n");

	else if (!enemy->isAlive())
		throw runtime_error("The enemy is allready dead.\n");


 	if (getLocation().distance(enemy->getLocation()) <= 1)
    	enemy->hit(40);

    else
        cout << "Slash faild. Too far to slash the enemy.\n" << endl;
    
}

string Ninja::print() const{
	if (isAlive())
		return "Ninja name: " + getName() + 
			" --- Ninja health: " + to_string(getHealth()) +
			" --- Ninja location: " + getLocation().print();

	return "Ninja name: " + getName() + 
			" --- Ninja location: " + getLocation().print();
}
