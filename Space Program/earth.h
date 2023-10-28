#pragma once

#include <cassert>		// for ASSERT
#include <cmath>
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"
#include "math.h"

#define pi 3.1415926535898
#define g 9.80665
#define r 6,378,000

class Earth
{
public:
	//This is the only setter as all other functions find a variable that must be stored in each individual satellite.
	float setRotationSpeed(float td)
	{
		//R = -(2 pi / framerate) x (td / secondsDay)
		//R rotation of earth in one frame
		//framerate number of frames per second = 30
		//td is time dilation, how much faster time passes in the simulator than in the real world
		//secondsDay is number of seconds it takes for earth to make full rotation
		//secondsDay = 60
		float rotation;
		rotation = -((2 * pi) / 30) * (td / 60);
	}

	float GetGravityMag(float h)
	{
		//Gh = G (r / (r + h))^2
		//Gh is the magnitude of gravity
		//G is gravity - 9.80665 m/s^2
		//r is the radius of the earth - 6,378,000
		//h is the height of a satellite above the earth
		float gravityMag;
		gravityMag = g * pow((r / (r + h)), 2);
		return gravityMag;
	}

	float getHeightAboveEarth(float x, float y)
	{
		float height;
		float X2;
		float Y2;
		X2 = pow(x, 2);
		Y2 = pow(y, 2);
		height = sqrt(X2 + Y2) - r;
		return height;
	}

	float getAngle(float x, float y) 
	{
		//d = atan(Ex - Sx, Ey - Sy)
		//d is direction or angle
		//Ex and Ey are the earths x and y position
		//Sx and Sy are the satellites x and y position
		//Sx and Sy are going to be the x and y variables given to the func when called
		float angle;
		angle = atan2(position.getMetersX() - x, position.getMetersY() - y);
		return angle;
	}

	float Rad2Deg(float radians) {
		// simple formula that turns radians to degrees by multiplying the radians by 180/pi
		float degree = radians * (180 / pi);
		return degree;
	}

protected:
	Position position;
	float rotation;
};