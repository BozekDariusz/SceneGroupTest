#include"GrahamScanConvexHull.h"


void GrahamConvex::sortByAngles() {

	std::sort(points.begin() + 1, points.end(), [this](Point2D pointP, Point2D pointQ) {


		int orientation = minYPoint.orientation(pointP, pointQ);

		if (orientation == 0)
			return (minYPoint.distanceToPoint(pointQ) < minYPoint.distanceToPoint(pointP));

		return (orientation != 2);

		});

}

void GrahamConvex::removeSameAngles() {

	individualAngledPoints = 1; //minYPoint is first individual

	for (int i = 1; i < points.size(); i++)
	{
		//maybe check distance
		int angleStart = i;
		while (i < points.size() - 1 && minYPoint.orientation(points[i], points[i + 1]) == 0)

			i++;
		int angleEnd = i;

		std::vector<Point2D>::iterator result = std::min_element(points.begin() + angleStart, points.begin() + angleEnd, [this](Point2D pointP, Point2D pointQ)
			{return minYPoint.distanceToPoint(pointP) > minYPoint.distanceToPoint(pointQ); });


		points[individualAngledPoints] = points[std::distance(points.begin(), result)];
		individualAngledPoints++;
	}

}
Point2D GrahamConvex::nextToTop() {

	Point2D temp = convexHull.top();
	convexHull.pop();
	Point2D result = convexHull.top();
	convexHull.push(temp);

	return result;
}
void GrahamConvex::populateStack() {

	convexHull.push(points[0]);
	convexHull.push(points[1]);


	for (int i = 2; i < individualAngledPoints; i++)
	{

		while (convexHull.size() > 1 && nextToTop().orientation(convexHull.top(), points[i]) == 2)
			convexHull.pop();
		convexHull.push(points[i]);
	}

}


GrahamConvex::GrahamConvex(std::vector<Point2D> newPoints) {

	points = newPoints;

}

void GrahamConvex::createHull() {

	std::vector<Point2D>::iterator result = std::min_element(points.begin(), points.end(), [](Point2D pointP, Point2D pointQ)
		{return pointP.compareY(pointQ); });



	std::swap(points[std::distance(points.begin(), result)], points[0]);
	minYPoint = points[0];

	sortByAngles();

	removeSameAngles();

	if (individualAngledPoints < 3) return; // cant create Convex hull with less than 3 points

	populateStack();

}



