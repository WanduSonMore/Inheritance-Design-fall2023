#pragma once
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "velocity.h"
#include "earth.h"
class Spaceship
{
public:
	Spaceship() {
		angle = 0;
	}
	void setAll(Position ptUpperRight, double posX, double posY) {
		position.setPixelsX(posX);
		position.setPixelsY(posY);
	}
	void draw(ogstream& gout, const Interface* pUI) {
		//Position pt;
		//ogstream gout(pt);
		gout.drawShip(position,angle, pUI->isSpace());
	}
	void addAngle(double value) {
		angle = angle + value;
	}
	void addVelocity(double value) {
		//if (velocity.getAcceleration() < 2 && velocity.getAcceleration() > -2)
		velocity.addAcceleration(value, angle);
	}
	void updatePosition() {
		position.addPixelsX(velocity.getDx());
		position.addPixelsY(velocity.getDy());
	}
	double getAngle() {
		return angle;
	}
	Position getPosition() {
		return position;
	}
protected:
	double angle;
	Position position;
	Velocity velocity;
};

