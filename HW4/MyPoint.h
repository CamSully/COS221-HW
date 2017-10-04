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
