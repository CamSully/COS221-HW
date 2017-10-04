#include <iostream>
#include "MyPoint.h"	// MyPoint declarations.
#include <cmath>	// For square root.
using namespace std;

// No-arg constructor: create a point at the origin.
MyPoint::MyPoint() {
	x = 0;
	y = 0;
}

// 2-arg constructor: create a point with the specified coordinates.
MyPoint::MyPoint(double xCoord, double yCoord) {
	x = xCoord;
	y = yCoord;
}

// Functions to return x coord and y coord values.
double MyPoint::getX() {
	return x;
}

double MyPoint::getY() {
	return y;
}

// Distance function: returns the distance between the current point and a specified point.
double MyPoint::distance(MyPoint otherPoint) {
	return sqrt(pow((otherPoint.y - y), 2) + pow((otherPoint.x - x), 2));
}
