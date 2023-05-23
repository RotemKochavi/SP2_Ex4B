#include "Character.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace ariel{

	Character::Character(string name, const Point &location, int health) :
	_name(name), _location(location), _health(health), _inTeam(false), _hit(0) {}

	Character::Character(const Character &other) : _name(other._name), _location(other._location), _health(other._health), _inTeam(other._inTeam), _hit(other._hit) {}

	Character::Character(Character &&other) noexcept : _name(other._name), _location(other._location), _health(other._health), _inTeam(other._inTeam), _hit(other._hit) {}

	bool Character::isAlive() const{
		return (_health > 0);
	}

	double Character::distance(const Character *other) const{
		if (other == nullptr)
				throw invalid_argument("Put character please!");
		else
			return _location.distance(other->_location);
	}

	void Character::hit(int hits){
		if (hits < 0)
			throw invalid_argument("hits < 0");
		_health -= hits;
		_hit += hits;
	}

	const string &Character::getName() const{
		return _name;
	}

	int Character::getHealth() const{
		return _health;
	}

	const Point& Character::getLocation() const{
		return _location;
	}

	void Character::setLocation(const Point &location){
		_location = location;
	}

	bool Character::getInTeam() const{
		return _inTeam;
	}
	void Character::setInTeam(bool status){
		_inTeam = status;
	}

	int Character::getHit() const{
		return _hit;
	}
	
// ********************************************************************//
	Character& Character::operator=(const Character& other) {
		if (this != &other){
			_health = other._health;
			_name = other._name;
		}

		return *this;
	}

	Character& Character::operator=(Character&& other) noexcept{
		if (this != &other){
			_health = other._health;
			_name = move(other._name);
			other._health = 0;
		}

		return *this;
	}

}