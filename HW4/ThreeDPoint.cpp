#include <iostream>
#include <cmath>
#include "ThreeDPoint.h"
using namespace std;

ThreeDPoint::ThreeDPoint() {
	x = 0;
	y = 0;
	z = 0;
}

ThreeDPoint::ThreeDPoint(double xCoord, double yCoord, double zCoord) {
	x = xCoord;
	y = yCoord;
	z = zCoord;
}

double ThreeDPoint::getZ() {
	return z;
}

const double ThreeDPoint::distance(const ThreeDPoint& threeDPoint) {
	return sqrt(pow(threeDPoint.z - z,2) + pow(threeDPoint.y - y,2) + pow(threeDPoint.x - x,2));
}
