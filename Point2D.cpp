#include"Point2D.h"

Point2D::Point2D(float coordX, float coordY) {

	x = coordX;
	y = coordY;

}


float Point2D::distanceToPoint(Point2D point) {

	float distance;

	distance = pow(x - point.x, 2.0) + pow(y - point.y, 2.0);

	return distance;

}



int Point2D::orientation(Point2D pointP, Point2D pointQ) {//return 0 for colinear, 1 for clockwise, 2 for counter Clockwise


	int orient = (pointP.y - y) * (pointQ.x - pointP.x) -
		(pointP.x - x) * (pointQ.y - pointP.y);

	if (orient == 0) return 0;
	return (orient > 0) ? 1 : 2;


}

bool Point2D::compareX(Point2D pointQ) {
	return x < pointQ.x;
}
bool Point2D::compareY(Point2D pointQ) {
	return y < pointQ.y;

}


float Point2D::getX() { return x; }
float Point2D::getY() { return y; }


