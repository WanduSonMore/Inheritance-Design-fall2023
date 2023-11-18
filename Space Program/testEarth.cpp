#include "testEarth.h"
#include "earth.h"

void testEarth::altitudeTestOne() 
{
   //setup
   Earth earth;
   double Altitude;

   //exercise
   Altitude = earth.getAltitude(6378000.0, 0.0);

   //verify
   assert(Altitude == 0);

   //teardown
   //no need, variable Altitude is destroyed once function ends
}

void testEarth::altitudeTestTwo()
{
   //setup
   Earth earth;
   double Altitude;
   
   //exercise
   Altitude = earth.getAltitude(6379000.0, 0.0);
   //verify
   assert(Altitude == 1000);
   
   //teardown
   //no need, variable Altitude is destroyed once function ends
}

void testEarth::altitudeTestThree()
{
   //setup
   Earth earth;
   double Altitude;
   
   //exercise
   Altitude = earth.getAltitude(0.0, 6379000.0);
   
   //verify
   assert(Altitude == 1000);
   
   //teardown
   //no need, variable Altitude is destroyed once function ends
}

void testEarth::altitudeTestFour() 
{
   //setup
   Earth earth;
   double Altitude;
   
   //exercise
   Altitude = earth.getAltitude(29814450.3, 29814450.3);
   
   //verify
   assert(Altitude == 35786000.0);
   
   //teardown
   //no need, variable Altitude is destroyed once function ends
}

void testEarth::gravityTestOne() 
{
   //setup
   Earth earth;
   double Gravity;
   
   //exercise
   Gravity = earth.getGravity(0.0);
   
   //verify
   assert(closeEnough(- 9.806,Gravity, .0001) == true);

   //teardown
   //no need, variable Gravity is destroyed once function ends
}

void testEarth::gravityTestTwo()
{
   //setup
   Earth earth;
   double Gravity;
   
   //exercise
   Gravity = earth.getGravity(500000.0);
   
   //verify
   assert(closeEnough(-8.4,Gravity,.04));
   
   //teardown
   //no need, variable Gravity is destroyed once function ends
}

void testEarth::gravityTestThree()
{
   //setup
   Earth earth;
   double Gravity;
   
   //exercise
   Gravity = earth.getGravity(2000000.0);
   
   //verify
   assert(closeEnough(-5.7,Gravity,.04));
   
   //teardown
   //no need, variable Gravity is destroyed once function ends
}