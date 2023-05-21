#pragma once

#include "Character.hpp"

namespace ariel
{
	class Cowboy : public Character
	{
		private:
			
			int _bulletsCount;

		public:
		
			Cowboy(const string &name, const Point &location);
			void shoot(Character *enemy);
			bool hasBullets() const;
			void reload();
			int getBulletsCount() const;
			string print() const override;
	};
}