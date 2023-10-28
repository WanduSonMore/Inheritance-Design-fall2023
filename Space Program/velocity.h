#pragma once
#include<iostream>
#include<cmath>
#include "position.h"
using namespace std;

class Velocity
{
public:
	double horizontalAccel() {
		return acceleration * sin(angle);
	}
	double verticalAccel() {
		return acceleration * cos(angle);
	}
	void distanceFormula(Position position) {
		position.addMetersX(position.getMetersX() + dx * time + (0.5 * horizontalAccel() * pow(time, 2)));
		position.addMetersY(position.getMetersY() + dx * time + (0.5 * verticalAccel() * pow(time, 2)));
		speed = speed + velocity * time + (0.5 * acceleration * time * time);
	}
	void constantAccelCal() {
		dx = dx + horizontalAccel() * time;
		dy = dy + verticalAccel() * time;
		velocity = velocity + acceleration * time;
	}
	void testMove(Position position) {
		
	}
	//void calculateVelocity() {

	//}
protected:
	double velocity;
	double acceleration;
	double dx;
	double dy;
	double angle;
	//double ddx;
	//double ddy;
	double time;
	double speed;
};

