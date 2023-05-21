#pragma once

#include "Character.hpp"
using namespace std;
namespace ariel
{
	class Ninja : public Character
	{
		protected:
			
			int _speed;

		public:
			
			Ninja(string name, Point location, int health_points, int speed);
			void move(Character *other);
			void slash(Character *other);
			string print() const override;
	};

    class YoungNinja : public virtual Ninja{
		
        public:
			 YoungNinja(string name, Point location);
	};

	class TrainedNinja : public virtual Ninja{
		
        public:	
			 TrainedNinja(string name, Point location);
	};

	class OldNinja : public virtual Ninja{
		
        public:	
			 OldNinja(string name, Point location);
	};

}