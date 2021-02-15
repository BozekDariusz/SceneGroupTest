#pragma once
#include <math.h>  


class Point2D {


	float x, y;


public:

	Point2D(float coordX, float coordY);

	float distanceToPoint(Point2D point);
	int orientation(Point2D pointP, Point2D pointQ);
	bool compareY(Point2D pointQ);
	bool compareX(Point2D pointQ);
	float getX();
	float getY();
};