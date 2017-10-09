/* COS 221 - Cameron Sullivan - HW4
* ThreeDPoint header: declarataions for the ThreeDPoint class.
*/

// Inclusion guard (necessary for inheritance).
#ifndef ThreeDPoint_H
#define ThreeDPoint__H

#include "MyPoint.h"

// ThreeDPoint extends MyPoint.
class ThreeDPoint: public MyPoint {
// Make the member variable private to prevent user edits.
private:
	double z;	

public:

	ThreeDPoint();

	ThreeDPoint(double, double, double);

	double getZ();

	const double distance(const ThreeDPoint&);
};

#endif
