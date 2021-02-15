#include"Points500.h"

Points500::Points500() {
	for (size_t i = 0; i < 500; i++) {
		points.push_back(Point2D(RandomNumbers::getInstance().generateRandomNumber(1.0, 200.0),
			RandomNumbers::getInstance().generateRandomNumber(1.0, 200.0)));
	}
}

void Points500::printPointsWithinRange() {

	for (size_t i = 0; i < 500; i++) {
		if (points[i].distanceToPoint(circle.center) <= pow(circle.radius, 2)) {
			std::cout << "Point X = " << points[i].getX() << " and Y = " << points[i].getY() << std::endl;
		}
	}

}