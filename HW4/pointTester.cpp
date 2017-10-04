#include <iostream>
#include "MyPoint.h"
#include "ThreeDPoint.h"
using namespace std;

void printThreeDPoint(ThreeDPoint);

int main() {

/*	MyPoint point1(0,0);
*	MyPoint point2(10,30.5);
*
*	cout << "point1- x: " << point1.getX() << "   y: " << point1.getY() << endl;
*	cout << "point2- x: " << point2.getX() << "   y: " << point2.getY() << endl;
*
*	cout << "Distance between: " << point1.distance(point2) << endl;
*/

	ThreeDPoint tdPoint1(0, 0, 0);
	ThreeDPoint tdPoint2(10, 30, 25.5);

	cout << "point1: ";
	printThreeDPoint(tdPoint1);
	cout << "point2: ";
	printThreeDPoint(tdPoint2);

	cout << "Distance between point1 and point2: " << tdPoint1.distance(tdPoint2) << endl;

	return 0;
}

void printThreeDPoint(ThreeDPoint point) {
	cout << "(" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")" << endl;
}
