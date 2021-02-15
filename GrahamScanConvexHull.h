#pragma once
#include <stack>
#include<vector>
#include <algorithm>
#include"Point2D.h"

class GrahamConvex {

	std::stack<Point2D> convexHull;
	std::vector<Point2D> points;
	Point2D minYPoint = Point2D(0, 0);
	int individualAngledPoints;
	void sortByAngles();
	void removeSameAngles();
	Point2D nextToTop();
	void populateStack();

public:
	GrahamConvex(std::vector<Point2D> newPoints);
	void createHull();

};