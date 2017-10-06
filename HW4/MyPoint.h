/* COS 221 - Cameron Sullivan - HW5
* MyPoint header: declarations for the MyPoint class.
*/

// Inclusion guard (necessary for the inheritance of this project).
#ifndef MyPoint_H
#define MyPoint_H

class MyPoint {
public:
	double x;
	double y;

	MyPoint();

	MyPoint(double, double);

	double getX();
	double getY();

	double distance(MyPoint);
};

#endif
