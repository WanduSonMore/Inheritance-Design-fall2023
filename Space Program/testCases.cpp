#include "testCases.h"
#include "earth.h"
#include "velocity.h"
#include "satellite.h"

void testCases::testAltitude()
{
	Earth earth;
	assert(earth.getAltitude(6378000.0, 0.0) == 0 );
	assert(earth.getAltitude(6379000.0, 0.0) == 1000);
	assert(earth.getAltitude(0.0, 6379000.0) == 1000);
	assert(earth.getAltitude(29814450.3, 29814450.3) == 35786000.0);
}

void testCases::testGravity()
{
	Earth earth;
	assert(earth.getGravity(6378000.0) == -9.806);
	assert(earth.getGravity(6378000.0 + 500000.0) == -8.4);
	assert(earth.getGravity(6378000.0 + 2000000.0) == -5.7);
}

void testCases::testUpdateVelocity()
{
	Velocity velocity1;
	Velocity velocity2(1.2, 3.4);
	Velocity velocity3(0, 0);
	Velocity velocity4(0, 0);
	Velocity velocity5(4.1, 6.0);

	velocity1.updateVelocity(0, 0, 0);
	assert(velocity1.getDx() == 0.0);
	assert(velocity1.getDy() == 0.0);

	velocity2.updateVelocity(0, 0, 0);
	assert(velocity2.getDx() == 0.0);
	assert(velocity2.getDy() == 0.0);

	velocity3.updateVelocity(1.2, 3.4, 1);
	assert(velocity3.getDx() == 1.2);
	assert(velocity3.getDy() == 3.4);

	velocity4.updateVelocity(1.2, 3.4, 2);
	assert(velocity4.getDx() == 2.4);
	assert(velocity4.getDy() == 6.8);

	velocity5.updateVelocity(0.5, 0.2, 3);
	assert(velocity5.getDx() == 5.6);
	assert(velocity5.getDy() == 6.6);
}

void testCases::testUpdatePosition()
{
	Satellite satellite1(11.1, 22.2, 0, 0);
	Satellite satellite2(11.1, 22.2, 0.5, 0.4);
	Satellite satellite3(11.1, 22.2, 0.5, 0.4);
	Satellite satellite4(11.1, 22.2, 0, 0);
	Satellite satellite5(11.1, 22.2, 0, 0);
	Satellite satellite6(11.1, 22.2, 1, 2);

	satellite1.updatePosition(0, 0, 1);
	assert(satellite1.getPosition().getMetersX() == 11.2);
	assert(satellite1.getPosition().getMetersY() == 22.2);

	satellite2.updatePosition(0, 0, 1);
	assert(satellite2.getPosition().getMetersX() == 11.6);
	assert(satellite2.getPosition().getMetersY() == 22.6);

	satellite3.updatePosition(0, 0, 2);
	assert(satellite3.getPosition().getMetersX() == 12.1);
	assert(satellite3.getPosition().getMetersY() == 23.0);

	satellite4.updatePosition(0.2, 0.3, 1);
	assert(satellite4.getPosition().getMetersX() == 11.2);
	assert(satellite4.getPosition().getMetersY() == 22.35);

	satellite5.updatePosition(0.2, 0.3, 2);
	assert(satellite5.getPosition().getMetersX() == 11.5);
	assert(satellite5.getPosition().getMetersY() == 22.8);

	satellite6.updatePosition(0.2, 0.3, 2);
	assert(satellite6.getPosition().getMetersX() == 13.5);
	assert(satellite6.getPosition().getMetersY() == 26.8);
}



