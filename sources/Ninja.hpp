#pragma once

#include "Character.hpp"

namespace ariel
{
	class Ninja : public Character {
		
		private:

			int _speed;

		public:

			Ninja(std::string _name, const Point &_location, int _health, int speed);

			void move(Character *enemy);

			void slash(Character *enemy);

			std::string print() const override;
	};

}