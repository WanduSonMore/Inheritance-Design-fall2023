#pragma once

#include <cassert>		// for ASSERT
#include <cmath>
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"
#include "math.h"

#define pi 3.1415926535898
#define g 9.80665
#define r 6378000

class Earth
{
public:
	//This is the only setter as all other functions find a variable that must be stored in each individual satellite.
	double setRotationSpeed(double td)
	{
		//R = -(2 pi / framerate) x (td / secondsDay)
		//R rotation of earth in one frame
		//framerate number of frames per second = 30
		//td is time dilation, how much faster time passes in the simulator than in the real world
		//secondsDay is number of seconds it takes for earth to make full rotation
		//secondsDay = 60
		double rotation;
		rotation = -((2 * pi) / 30) * (td / 60);
		return rotation;
	}

	double getGravity(double h)
	{
		//Gh = G (r / (r + h))^2
		//Gh is the magnitude of gravity
		//G is gravity - 9.80665 m/s^2
		//r is the radius of the earth - 6,378,000
		//h is the height of a satellite above the earth
		double gravityMag;
		gravityMag = g * ((r / (r + h)) * (r / (r + h)));//pow((r / (r + h)), 2);
		gravityMag = floor(gravityMag * 1000);//9.806649999
		gravityMag = gravityMag / 1000;
		return -gravityMag;
	}

	double getAltitude(double x, double y)
	{
		double height;
		double X2;
		double Y2;
		X2 = x * x;
		Y2 = y * y;
		//X2 = pow(x, 2);
		//Y2 = pow(y, 2);
		height = sqrt(X2 + Y2) - r;
		return round(height);
	}

	double getAngle(int x, int y) 
	{
		//d = atan(Ex - Sx, Ey - Sy)
		//d is direction or angle
		//Ex and Ey are the earths x and y position
		//Sx and Sy are the satellites x and y position
		//Sx and Sy are going to be the x and y variables given to the func when called
		double angle;
		angle = atan2(position.getMetersX() - x, position.getMetersY() - y);

		return angle;
	}

	double Rad2Deg(double radians) {
		// simple formula that turns radians to degrees by multiplying the radians by 180/pi
		double degree = radians * (180 / pi);
		return degree;
	}

	double Deg2Rad(double degrees) {
		return degrees * (pi / 180);
	}


protected:
	Position position;
	double rotation;
};