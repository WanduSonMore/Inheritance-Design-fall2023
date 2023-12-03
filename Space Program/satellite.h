#pragma once
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "velocity.h"
#include "earth.h"
class Satellite
{
public: 
	Satellite() {
	}
	Satellite(double x, double y, double dx, double dy) {
		position.setMetersX(x);
		position.setPixelsX(x);
		position.setMetersY(y);
		position.setPixelsY(y);
		double metersx = position.getMetersX();
		double metersy = position.getMetersY();
		Velocity velocity1(dx, dy);
		velocity = velocity1;
	/*	draw();*/
	}
	Satellite(Position ptUpperRight) {
		position.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
		position.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
	}
	
	void setPosition(Position ptUpperRight)
	{
		position.setPixelsX(ptUpperRight.getPixelsX() * random(-0.3, 0.3));
		position.setPixelsY(ptUpperRight.getPixelsY() * random(-0.3, 0.3));
		//position.setPixelsX(ptUpperRight.getPixelsX() * 0);
		//position.setPixelsY(ptUpperRight.getPixelsX() * 0);


	}

	void set(double x, double y, double dx, double dy)
	{
		position.setMetersX(x);
		position.setMetersY(y);
		velocity.setDx(dx);
		velocity.setDy(dy);
	}

	Position getPosition() {
		return position;
	}
	void updatePosition(double x, double y, int t) {
		//D += (V * T) + (.5 * A * T^2)
		position.addMetersX((velocity.getDx() * t) + (.5 * x * (t * t)));
		position.addMetersY((velocity.getDy() * t) + (.5 * y * (t * t)));
		velocity.updateVelocity(x, y, t);
	}
	void setPositionNew(int timer) {
		angle = earth.getAngle(position.getMetersX(), position.getMetersY());
	}
	//void rotate(double change) {
	//	angleShip += change;
	//}
	virtual void draw(ogstream & gout, double angleShip) {}
protected:
	Position position;
	Velocity velocity;
	Earth earth; // remove and move to demo
	unsigned char phaseStar;
	double angle = 0;
	//double angleShip;
	double angleEarth;
};

class Hubble : public Satellite {
public:
	Hubble() {
	}
	void setAll(Position ptUpperRight) {
		position.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
		position.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
	}
	void draw(ogstream & gout, double angleShip) {
		//Position pt;
		//ogstream gout(pt);
		gout.drawHubble(position, angleShip);
	}
};

