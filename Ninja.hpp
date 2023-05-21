#pragma once

#include "Character.hpp"

using namespace std;
namespace ariel
{
	class Ninja : public Character
	{
		private:
			int _speed;

		public:
			Ninja(const string &_name, const Point &_location, int _health, int _speed);
			void move(Character *enemy);
			void slash(Character *enemy);
			string print() const override;
	};

}