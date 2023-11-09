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
	Satellite(double x, double y, double dx, double dy) {
		position.setMetersX(x);
		position.setPixelsX(x);
		position.setMetersY(y);
		position.setPixelsY(y);
		Velocity velocity1(dx, dy);
		velocity = velocity1;
	/*	draw();*/
	}
	
	void setPosition(Position ptUpperRight)
	{
		position.setPixelsX(ptUpperRight.getPixelsX() * random(-0.3, 0.3));
		position.setPixelsY(ptUpperRight.getPixelsY() * random(-0.3, 0.3));
		//position.setPixelsX(ptUpperRight.getPixelsX() * 0);
		//position.setPixelsY(ptUpperRight.getPixelsX() * 0);


	}
	Position getPosition() {
		return position;
	}
	void updatePosition(double x, double y, int t) {

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
	void draw(ogstream & gout, double angleShip) {
		//Position pt;
		//ogstream gout(pt);
		gout.drawHubble(position, angleShip);
	}
};

