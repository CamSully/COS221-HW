/* COS 221 - Cameron Sullivan - HW4
* ThreeDPoint class: create an object that represents a point in 3D space.
* Includes a function to calculate the distance between two 3D points.
*/

#include <iostream>
#include <cmath>
#include "ThreeDPoint.h"
using namespace std;

// No-arg constructor: create a point at the origin.
ThreeDPoint::ThreeDPoint() {
	x = 0;
	y = 0;
	z = 0;
}

// 3-arg constructor: create a point at the specified coordinates.
ThreeDPoint::ThreeDPoint(double xCoord, double yCoord, double zCoord) {
	x = xCoord;
	y = yCoord;
	z = zCoord;
}

// Getter function for the z-coordinate.
double ThreeDPoint::getZ() {
	return z;
}

// Distance function: returns the distance between the current point and a specified point.
const double ThreeDPoint::distance(const ThreeDPoint& threeDPoint) {
	return sqrt(pow(threeDPoint.z - z,2) + pow(threeDPoint.y - y,2) + pow(threeDPoint.x - x,2));
}
