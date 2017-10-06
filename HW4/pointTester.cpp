#include <iostream>
#include "MyPoint.h"
#include "ThreeDPoint.h"
using namespace std;

void printThreeDPoint(ThreeDPoint);

int main() {

	cout << "COS 221 - Cameron Sullivan - HW4 Output" << endl;

	// Create two 3D points.
	ThreeDPoint tdPoint1;
	ThreeDPoint tdPoint2(10, 30, 25.5);

	cout << "point1: ";
	printThreeDPoint(tdPoint1);
	cout << "point2: ";
	printThreeDPoint(tdPoint2);

	// Calculate and print the distance between the two points.
	cout << "Distance between point1 and point2: " << tdPoint1.distance(tdPoint2) << endl;

	return 0;
}

// Print the coordinates of a point.
void printThreeDPoint(ThreeDPoint point) {
	cout << "(" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")" << endl;
}
