#pragma once

#include <string>

using namespace std;

namespace ariel
{
	class Point {
		
		private:

			double _x;
			double _y;

		public:

			Point();
            
			Point(double p_x, double p_y);
			
			double getX() const;
			
			double getY() const;
			
			double distance(Point other) const;
			
			string print() const;
			
			static Point moveTowards(Point source, Point destination, double distance);
	
	};
}