#include "GrahamScanConvexHull.h"
#include"Points500.h"

int main() {

	// 500 Points and distance to a circle
	Points500 fiveHundret;
	fiveHundret.printPointsWithinRange();




	///////////////////convecHull
	std::vector<Point2D> temp = { Point2D(2.0,5.0),Point2D(2.0,1.0), Point2D(3.0,4.0),
		Point2D(5.0,2.0), Point2D(6.0,5.0), Point2D(7.0,1.0),Point2D(5.0,4.0), Point2D(7.0,6.0) };

	GrahamConvex convexHull(temp);
	convexHull.createHull();


}