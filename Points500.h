#pragma once
#include<vector>
#include<iostream>

#include"Point2D.h"
#include"RandomNumbers.h"

struct Circle {

	Point2D center = Point2D(0, 0);;
	float radius = 50.0;

};

class Points500 {

	Circle circle;
	std::vector<Point2D> points;
public:
	Points500();

	void printPointsWithinRange();
};