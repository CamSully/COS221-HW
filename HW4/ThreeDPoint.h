// Inclusion guards to prevent duplicate inclusions (necessary for inheritance).
#ifndef ThreeDPoint_H
#define ThreeDPoint__H

#include "MyPoint.h"

class ThreeDPoint: public MyPoint {
public:
	double z;

	ThreeDPoint();

	ThreeDPoint(double, double, double);

	double getZ();

	const double distance(const ThreeDPoint&);
};

#endif
