#pragma once

#include "Character.hpp"

namespace ariel
{
	class Cowboy : public Character {
		
		private:
			
			int _bulletsCount;

		public:
		
			Cowboy(const string &_name, const Point &_location);
			void shoot(Character *enemy);
			bool hasBoolets() const;
			void reload();
			int getBulletsCount() const;
			string print() const override;
	};
}