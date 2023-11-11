#pragma once
#include<iostream>
#include<cmath>
#include<cassert>
#include "position.h"
using namespace std;

class Velocity
{
public:
	Velocity() {
		dx = 0.0;
		dy = 0.0;
	}
	Velocity(double x, double y) {
		dx = x;
		dy = y;
	}
	double horizontalAccel(double angle) {
		return acceleration * sin(angle);
	}
	double verticalAccel(double angle) {
		return acceleration * cos(angle);
	}
	double distanceFormulaX(Position position, double angle, int time) {
		return (position.getMetersX() + dx * time + (0.5 * horizontalAccel(angle) * (time * time )));
	}
	double distanceFormulaY(Position position, double angle, int time) {
		return (position.getMetersY() + dx * time + (0.5 * verticalAccel(angle) * (time * time)));
	}
	void distanceFormulaSpeed(Position position, double angle, int time) {
		speed = speed + velocity * time + (0.5 * acceleration * (time * time));
	}
	void constantAccelCal(double angle, int time) {
		dx = dx + horizontalAccel(angle) * time;
		dy = dy + verticalAccel(angle) * time;
		velocity = velocity + acceleration * time;
	}
	void testMove(Position position) {
		
	}
	void updateVelocity(double x, double y, int t) {
		dx = dx + (x * t);
		dy = dy + (y * t);
	}
	double getDx() {
		return dx;
	}
	double getDy() {
		return dy;
	}
	//void calculateVelocity() {

	//}
protected:
	double velocity; //  = random(-3100, 0)
	double acceleration;
	double dx;
	double dy;
	//double ddx;
	//double ddy;
	//double time;
	double speed;
};

