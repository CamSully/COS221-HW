/* COS 221 - Cameron Sullivan - HW4
* ThreeDPoint class: create an object that represents a point in 3D space.
* Includes a function to calculate the distance between two 3D points.
*/

#include <iostream>
#include <cmath>
#include "ThreeDPoint.h"
using namespace std;

// No-arg constructor: create a point at the origin.
// Note that this constructor automatically calls MyPoint's no-arg constructor, so I don't have to initialize x and y.
ThreeDPoint::ThreeDPoint() {
	z = 0;
}

// 3-arg constructor: create a point at the specified coordinates. 
// Note that this constructor inherits the two-arg constructor from MyPoint, so I can just pass xCoord and yCoord to the MyPoint constructor.
ThreeDPoint::ThreeDPoint(double xCoord, double yCoord, double zCoord) : MyPoint(xCoord, yCoord) {
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
