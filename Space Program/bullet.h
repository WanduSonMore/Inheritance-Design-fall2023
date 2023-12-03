#pragma once
#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "velocity.h"
#include "earth.h"
class Bullet
{
public:
	Bullet(double a, Position p) {
		angle = a;
		position = p;
		Velocity v(a);
		velocity = v;
	}
	void updatePosition() {
		position.addPixelsX(velocity.getDx());
		position.addPixelsY(velocity.getDy());
	}
	void draw(ogstream& gout) {
		gout.drawProjectile(position);
	}
protected:
	double angle;
	Position position;
	Velocity velocity;
};

