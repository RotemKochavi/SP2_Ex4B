#include "Point.hpp"
#include <iostream>

#include <cmath>

using namespace std;
using namespace ariel;

Point::Point() : _x(0.0), _y(0.0) {}

Point::Point(double p_x, double p_y) : _x(p_x), _y(p_y) {}

double Point::getX() const{
    return _x;
}

double Point::getY() const{
	return _y;
}

double Point::distance(Point other) const{
	return sqrt(pow(_x - other._x, 2) + pow(_y - other._y, 2));
}

string Point::print() const{
	return "(" + to_string(_x) + " , " + to_string(_y) + ")";
}

Point Point::moveTowards(Point source, Point destination, double distance){
		if (distance < 0)
            throw invalid_argument("The dinstance is negative!");
        
		if (distance == 0)
            return source;

        else if (distance >= source.distance(destination))
            return destination;

    	double dis = source.distance(destination);
        return Point((source.getX() + (distance * (destination.getX() - source.getX()) / dis)), (source.getY() + (distance * (destination.getY() - source.getY()) / dis)));
        
}