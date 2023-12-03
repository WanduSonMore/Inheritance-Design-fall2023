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
		acceleration = 0;
	}
	Velocity(double x, double y) {
		dx = x;
		dy = y;
	}
	Velocity(double angle) {
		acceleration = 0.5;
		dx = horizontalAccel(angle);
		dy - verticalAccel(angle);
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
		return (position.getMetersY() + dy * time + (0.5 * verticalAccel(angle) * (time * time)));
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
	void setDx(double x)
	{
		dx = x;
	}
	void setDy(double y)
	{
		dy = y;
	}
	double getDx() {
		return dx;
	}
	double getDy() {
		return dy;
	}
	double getAcceleration() {
		return acceleration;
	}
	void addAcceleration(double value, double angle) {
		acceleration = acceleration + value;
		updateVelocity(horizontalAccel(angle), verticalAccel(angle), 1);
	}
	//void calculateVelocity() {

	//}
protected:
	double velocity; //  = random(-3100, 0)
	double acceleration;
	double dx;
	double dy;
	double speed;
	//double ddx;
	//double ddy;
	//double time;
	
};

