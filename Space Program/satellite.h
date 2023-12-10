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

	void kick()
	{
		kickT = random(5000, 9000);
		kickAngle = random(0, 360);
		kickRad = kickAngle * (pi / 180);
		kickx = kickT * cos(kickRad);
		kicky = kickT * sin(kickRad);
	}

	void create_piece(int index, int radius, double offx, double offy)
	{
		kick();
		Velocity kickvel(kickx + velocity.getDx(), kicky + velocity.getDy());
		pieces_vel[index] = kickvel;
		Position offset;
		offset.setPixelsX(offx);
		offset.setPixelsY(offy);
		Position pos;
		pos.setPixelsX(position.getPixelsX() + (radius * cos(kickRad)));
		pos.setPixelsY(position.getPixelsY() + (radius * sin(kickRad)));
		pieces_pos[index] = pos;
		pieces_angle[index] = kickAngle;
		pieces_offset[index] = offset;
	}

	void create_fragment(int index, Position parent_pos, Velocity parent_vel)
	{
		kick();
		Velocity kickOne(kickx + parent_vel.getDx(), kicky + parent_vel.getDy());
		fragments_vel[index] = kickOne;
		Position pos;
		pos.setPixelsX(parent_pos.getPixelsX() + (4 * cos(kickRad)));
		pos.setPixelsY(parent_pos.getPixelsY() + (4 * sin(kickRad)));
		fragments_pos[index] = pos;
		fragments_angle[index] = kickAngle;
		fragments_expiration[index] = random(50,100);
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
	double kickT;
	double kickAngle;
	double kickRad;
	double kickx;
	double kicky;


	Position pieces_pos[4];
	Position pieces_offset[4];
	Velocity pieces_vel[4];
	double pieces_angle[4];

	Position fragments_pos[11];
	Velocity fragments_vel[11];
	double fragments_angle[11];
	int fragments_expiration[11];

	bool broken = false;
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

		create_piece(0, 10, 2.0, 0.0);
		gout.drawHubbleTelescope(pieces_pos[0], pieces_angle[0], pieces_offset[0]);

		create_piece(1, 7, -10.0, 0.0);
		gout.drawHubbleComputer(pieces_pos[1], pieces_angle[1], pieces_offset[1]);

		create_piece(2, 8, 1.0, -8.0);
		gout.drawHubbleRight(pieces_pos[2], pieces_angle[2], pieces_offset[2]);

		create_piece(3, 8, 1.0, 8.0);
		gout.drawHubbleLeft(pieces_pos[3], pieces_angle[3], pieces_offset[3]);

		broken = true;
	}

	void break_pieces(ogstream& gout, int index) {
		int num = 0;
		for (Position i : fragments_pos) {
			num += 1;
		}
		create_fragment(num, pieces_pos[num], pieces_vel[num]);
		gout.drawFragment(fragments_pos[num], fragments_angle[num]);
		num += 1;

		create_fragment(num, pieces_pos[num], pieces_vel[num]);
		gout.drawFragment(fragments_pos[num], fragments_angle[num]);
		num += 1;

		if (index == 0)
			create_fragment(num, pieces_pos[num], pieces_vel[num]);
			gout.drawFragment(fragments_pos[num], fragments_angle[num]);

		pieces_pos[index].setMeters(100000000000,-100000000000);
	}
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

		create_fragment(0, position, velocity);
		gout.drawFragment(fragments_pos[0], fragments_angle[0]);

		create_fragment(1, position, velocity);
		gout.drawFragment(fragments_pos[1], fragments_angle[1]);

		create_fragment(2, position, velocity);
		gout.drawFragment(fragments_pos[2], fragments_angle[2]);

		create_fragment(3, position, velocity);
		gout.drawFragment(fragments_pos[3], fragments_angle[3]);
	}
};

class GPS : public Satellite {
public:
	GPS() {
	}
	void draw(ogstream& gout, double angleShip) {
		gout.drawGPS(position, angleShip);
	}

	//GPS breaks into 2 fragments and 3 pieces, should the pieces break too then each one becomes 3 fragments
	void break_apart(ogstream& gout, double angleShip) {

		create_piece(0, 7, 0.0, 0.0);
		gout.drawGPSCenter(pieces_pos[0], pieces_angle[0]);

		create_piece(1, 8, 0.0, 12.0);
		gout.drawGPSRight(pieces_pos[1], pieces_angle[1], pieces_offset[1]);

		create_piece(2, 8, 0.0, -12.0);
		gout.drawGPSLeft(pieces_pos[2], pieces_angle[2], pieces_offset[2]);

		create_fragment(0, position, velocity);
		gout.drawFragment(fragments_pos[0], fragments_angle[0]);

		create_fragment(1, position, velocity);
		gout.drawFragment(fragments_pos[1], fragments_angle[1]);
	}

	void break_pieces(ogstream& gout, int index) {
		int num = 0;
		for (Position i : fragments_pos) {
			num += 1;
		}
		create_fragment(num, pieces_pos[num], pieces_vel[num]);
		gout.drawFragment(fragments_pos[num], fragments_angle[num]);
		num += 1;

		create_fragment(num, pieces_pos[num], pieces_vel[num]);
		gout.drawFragment(fragments_pos[num], fragments_angle[num]);
		num += 1;


		create_fragment(num, pieces_pos[num], pieces_vel[num]);
		gout.drawFragment(fragments_pos[num], fragments_angle[num]);

		pieces_pos[index].setMeters(100000000000, -100000000000);
	}
};

class Dragon : public Satellite {
public:
	Dragon() {
	}
	void draw(ogstream& gout, double angleShip) {
		gout.drawCrewDragon(position, angleShip);
	}

	//Dragon breaks into 3 pieces and 2 fragments
	void break_apart(ogstream& gout, double angleShip)
	{
		create_piece(0, 6, 0.0, 0.0);
		gout.drawCrewDragonCenter(pieces_pos[0], pieces_angle[0]);

		create_piece(1, 6, -1.0, 11.0);
		gout.drawCrewDragonRight(pieces_pos[1], pieces_angle[1], pieces_offset[1]);

		create_piece(2, 6, -1.0, -11.0);
		gout.drawCrewDragonRight(pieces_pos[2], pieces_angle[2], pieces_offset[2]);

		create_fragment(0, position, velocity);
		gout.drawFragment(fragments_pos[0], fragments_angle[0]);

		create_fragment(1, position, velocity);
		gout.drawFragment(fragments_pos[1], fragments_angle[1]);
	}

	void break_pieces(ogstream& gout, int index) {
		int num = 0;
		for (Position i : fragments_pos) {
			num += 1;
		}
		create_fragment(num, pieces_pos[num], pieces_vel[num]);
		gout.drawFragment(fragments_pos[num], fragments_angle[num]);
		num += 1;

		create_fragment(num, pieces_pos[num], pieces_vel[num]);
		gout.drawFragment(fragments_pos[num], fragments_angle[num]);
		num += 1;

		if (index == 0)
			create_fragment(num, pieces_pos[num], pieces_vel[num]);
			gout.drawFragment(fragments_pos[num], fragments_angle[num]);
			num += 1;

			create_fragment(num, pieces_pos[num], pieces_vel[num]);
			gout.drawFragment(fragments_pos[num], fragments_angle[num]);

		pieces_pos[index].setMeters(100000000000, -100000000000);
	}
};

class Starlink : public Satellite {
public:
	Starlink() {
	}
	void draw(ogstream& gout, double angleShip) {
		gout.drawStarlink(position, angleShip);
	}
	//starlink breaks into 2 pieces and 2 fragments
	void break_apart(ogstream& gout, double angleShip) 
	{
		create_piece(0,2,-1.0,0.0);
		gout.drawStarlinkBody(pieces_pos[0], pieces_angle[0], pieces_offset[0]);

		create_piece(1, 4, 8.0, -2.0);
		gout.drawStarlinkArray(pieces_pos[1], pieces_angle[1], pieces_offset[1]);

		create_fragment(0, position, velocity);
		gout.drawFragment(fragments_pos[0], fragments_angle[0]);

		create_fragment(1, position, velocity);
		gout.drawFragment(fragments_pos[1], fragments_angle[1]);
	}

	void break_pieces(ogstream& gout, int index) {
		int num = 0;
		for (Position i : fragments_pos) {
			num += 1;
		}
		create_fragment(num, pieces_pos[num], pieces_vel[num]);
		gout.drawFragment(fragments_pos[num], fragments_angle[num]);
		num += 1;

		create_fragment(num, pieces_pos[num], pieces_vel[num]);
		gout.drawFragment(fragments_pos[num], fragments_angle[num]);
		num += 1;

		create_fragment(num, pieces_pos[num], pieces_vel[num]);
		gout.drawFragment(fragments_pos[num], fragments_angle[num]);

		pieces_pos[index].setMeters(100000000000, -100000000000);
	}
};