#include "testCases.h"
#include "earth.h"
#include "velocity.h"
#include "satellite.h"

void testCases::testEarth()
{
   //setup
   Earth earth;
   double Altitude[4];
   double Gravity[3];
   
   //exercise
   Altitude[0] = earth.getAltitude(6378000.0, 0.0);
   Altitude[1] = earth.getAltitude(6379000.0, 0.0);
   Altitude[2] = earth.getAltitude(0.0, 6379000.0);
   Altitude[3] = earth.getAltitude(29814450.3, 29814450.3);
   Gravity[0] = earth.getGravity(0.0);
   Gravity[1] = earth.getGravity(500000.0);
   Gravity[2] = earth.getGravity(2000000.0);
   
   //verify
   assert(Altitude[0] == 0);
   assert(Altitude[1] == 1000);
   assert(Altitude[2] == 1000);
   assert(Altitude[3] == 35786000.0);
   assert(Gravity[0] == -9.806);
   assert(Gravity[1] == -8.4);
   assert(Gravity[2] == -5.7);
   
   delete Altitude;
   delete Gravity;
}

void testCases::testUpdateVelocity()
{
   //setup
   Velocity velocity1;
   Velocity velocity2(1.2, 3.4);
   Velocity velocity3;
   Velocity velocity4;
   Velocity velocity5(4.1, 6.0);
   double Dx[5];
   double Dy[5];
   
   //exercise pt.1 add acceleration
   velocity1.updateVelocity(0, 0, 0);
   velocity2.updateVelocity(0, 0, 0);
   velocity3.updateVelocity(1.2, 3.4, 1);
   velocity4.updateVelocity(1.2, 3.4, 2);
   velocity5.updateVelocity(0.5, 0.2, 3);
   
   //exercise pt.2 get new velocity after acceleration
   Dx[0] = velocity1.getDx();
   Dy[0] = velocity1.getDy();
   Dx[1] = velocity2.getDx();
   Dy[1] = velocity2.getDy();
   Dx[2] = velocity3.getDx();
   Dy[2] = velocity3.getDy();
   Dx[3] = velocity4.getDx();
   Dy[3] = velocity4.getDy();
   Dx[4] = velocity5.getDx();
   Dy[4] = velocity5.getDy();
   
   //verify
   assert(Dx[0] == 0.0);
   assert(Dy[0] == 0.0);
   assert(Dx[1] == 0.0);
   assert(Dy[1] == 0.0);
   assert(Dx[2] == 1.2);
   assert(Dy[2] == 3.4);
   assert(Dx[3] == 2.4);
   assert(Dy[3] == 6.8);
   assert(Dx[4] == 5.6);
   assert(Dy[4] == 6.6);
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



