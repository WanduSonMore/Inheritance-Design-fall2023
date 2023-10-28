#pragma once
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "velocity.h"
class Satellite
{
public: 
	//Satellite() {
	///*	draw();*/
	//}
	
	void setPosition(Position ptUpperRight)
	{
		position.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
		position.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
	}
	Position getPosition() {
		return position;
	}
	void setPosition() {
		/*velocity.testMove(position);*/
		position.addMetersX(1);
		position.addPixelsX(1);
	}
	//void rotate(double change) {
	//	angleShip += change;
	//}
	virtual void draw(ogstream & gout, double angleShip) {}
protected:
	Position position;
	Velocity velocity;
	unsigned char phaseStar;
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

