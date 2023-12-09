#pragma once
#include <cassert>      // for ASSERT
#include <cMath>
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
		position.setMeters(x,y);
		velocity.setDx(dx);
		velocity.setDy(dy);
	}

	Position getPosition() {
		return position;
	}
	void updatePosition(double ddx, double ddy, int t) {
		//D += (V * T) + (.5 * A * T^2)
		position.addMetersX((velocity.getDx() * t) + (.5 * ddx * (t * t)));
		position.addMetersY((velocity.getDy() * t) + (.5 * ddy * (t * t)));
		velocity.updateVelocity(ddx, ddy, t);
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
	void draw(ogstream & gout, double angleShip) {
		//Position pt;
		//ogstream gout(pt);
		gout.drawHubble(position, angleShip);
	}

	//hubble breaks into 4 pieces
	void break_apart(ogstream & gout, double angleShip) {

		double kickT = random(5000,9000);
		double angle = random(0, 360);
		double rad = angle * (pi / 180);
		double kickx = kickT * cos(rad);
		double kicky = kickT * sin(rad);
		Velocity kickOne(kickx + velocity.getDx(), kicky + velocity.getDy());
		pieces_vel[0] = kickOne;
		Position posTelescope;
		posTelescope.setPixelsX(2.0);
		posTelescope.setPixelsY(0.0);
		Position pos;
		pos.setPixelsX(position.getPixelsX() + (4 * cos(rad)));
		pos.setPixelsY(position.getPixelsY() + (4 * sin(rad)));
		gout.drawHubbleTelescope(position, angleShip, posTelescope);


		kickT = random(5000, 9000);
		angle = random(0, 360);
		rad = angle * (pi / 180);
		kickx = kickT * cos(rad);
		kicky = kickT * sin(rad);
		Velocity kickTwo(kickx + velocity.getDx(), kicky + velocity.getDy());
		pieces_vel[1] = kickTwo;

		kickT = random(5000, 9000);
		angle = random(0, 360);
		rad = angle * (pi / 180);
		kickx = kickT * cos(rad);
		kicky = kickT * sin(rad);
		Velocity kickThree(kickx + velocity.getDx(), kicky + velocity.getDy());
		pieces_vel[2] = kickThree;

		kickT = random(5000, 9000);
		angle = random(0, 360);
		rad = angle * (pi / 180);
		kickx = kickT * cos(rad);
		kicky = kickT * sin(rad);
		Velocity kickFour(kickx + velocity.getDx(), kicky + velocity.getDy());
		pieces_vel[3] = kickFour;

		

		Position posComputer;
		posComputer.setPixelsX(-10.0);
		posComputer.setPixelsY(0.0);
		gout.drawHubbleComputer(position, angleShip, posComputer);

		Position posRight;
		posRight.setPixelsX(1.0);
		posRight.setPixelsY(-8.0);
		gout.drawHubbleRight(position, angleShip, posRight);


		Position posLeft;
		posLeft.setPixelsX(1.0);
		posLeft.setPixelsY(8.0);
		gout.drawHubbleLeft(position, angleShip, posLeft);

		pieces_pos[0] = position;
		pieces_pos[1] = position;
		pieces_pos[2] = position;
		pieces_pos[3] = position;

		pieces_offset[0] = posTelescope;
		pieces_offset[1] = posComputer;
		pieces_offset[2] = posRight;
		pieces_offset[3] = posLeft;
	}

	Position pieces_pos[4];
	Position pieces_offset[4];
	Velocity pieces_vel[4];
	double pieces_angle[4];
	Position fragments_pos[9];
	Velocity fragments_vel[9];
	double fragments_angle[9];
	int fragments_expiration[9];
};

class Sputnik : public Satellite {
public:
	Sputnik() {
	}
	void draw(ogstream& gout, double angleShip) {
		gout.drawSputnik(position, angleShip);
	}

	//Sputnik breaks into 4 fragments
	void break_apart(ogstream& gout, double angleShip) {

		gout.drawFragment();
		fragments_pos[0] = position;
		fragments_pos[1] = position;
		fragments_pos[2] = position;
		fragments_pos[3] = position;

		Velocity kickOne(random(-700, 700) + velocity.getDx(), random(-700, 700) + velocity.getDy());
		fragments_vel[0] = kickOne;
		Velocity kickTwo(random(-700, 700) + velocity.getDx(), random(-700, 700) + velocity.getDy());
		fragments_vel[1] = kickTwo;
		Velocity kickThree(random(-700, 700) + velocity.getDx(), random(-700, 700) + velocity.getDy());
		fragments_vel[2] = kickThree;
		Velocity kickFour(random(-700, 700) + velocity.getDx(), random(-700, 700) + velocity.getDy());
		fragments_vel[3] = kickFour;
	}
	Position fragments_pos[4];
	Velocity fragments_vel[4];
	double fragments_angle[4];
	int fragments_expiration[4];
};

class GPS : public Satellite {
public:
	GPS() {
	}
	void draw(ogstream& gout, double angleShip) {
		gout.drawGPS(position, angleShip);
	}

	//GPS breaks into 2 fragments and 3 pieces, should the pieces break too then each one becomes 3 fragments

	Position pieces_pos[3];
	Position pieces_offset[3];
	Velocity pieces_vel[3];
	double pieces_angle[3];
	Position fragments_pos[11];
	Velocity fragments_vel[11];
	double fragments_angle[11];
	int fragments_expiration[11];
};

class Dragon : public Satellite {
public:
	Dragon() {
	}
	void draw(ogstream& gout, double angleShip) {
		gout.drawCrewDragon(position, angleShip);
	}

	//Dragon breaks into 3 pieces and 2 fragments

	Position pieces_pos[3];
	Position pieces_offset[3];
	Velocity pieces_vel[3];
	double pieces_angle[3];
	Position fragments_pos[10];
	Velocity fragments_vel[10];
	double fragments_angle[10];
	int fragments_expiration[10];
};

class Starlink : public Satellite {
public:
	Starlink() {
	}
	void draw(ogstream& gout, double angleShip) {
		gout.drawStarlink(position, angleShip);
	}
	//starlink breaks into 2 pieces and 2 fragments

	Position pieces_pos[2];
	Position pieces_offset[2];
	Velocity pieces_vel[2];
	double pieces_angle[2];
	Position fragments_pos[8];
	Velocity fragments_vel[8];
	double fragments_angle[8];
	int fragments_expiration[8];
};