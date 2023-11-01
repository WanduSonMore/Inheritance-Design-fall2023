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
	//Satellite() {
	///*	draw();*/
	//}
	
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
	void setPositionNew(int timer) {
		angle = earth.getAngle(position.getMetersX(), position.getMetersY());
		//cout << angle;
		/*velocity.testMove(position);*/
		//if (position.getMetersX()) {
		//	position.addMetersX(1);
		//	position.addPixelsX(1);
		//}
		//position.addMetersX(1);
		//position.addPixelsX(1);
		//position.addMetersY(1);
		//position.addPixelsY(1);
		//position.addMetersX(velocity.horizontalAccel(angle));
		//position.addPixelsX(velocity.horizontalAccel(angle));
		//position.addMetersY(velocity.verticalAccel(angle));
		//position.addPixelsY(velocity.verticalAccel(angle));
		//position.addMetersX(velocity.distanceFormulaX(position, angle, timer));
		//position.addPixelsX(velocity.distanceFormulaX(position, angle, timer));
		//position.addMetersY(velocity.distanceFormulaY(position, angle, timer));
		//position.addPixelsY(velocity.distanceFormulaY(position, angle, timer));
	}
	//void rotate(double change) {
	//	angleShip += change;
	//}
	virtual void draw(ogstream & gout, double angleShip) {}
protected:
	Position position;
	Velocity velocity;
	Earth earth;
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

