#include "testVelocityUpdate.h"
#include "velocity.h"

void testVelocityUpdate::velocityTestOne()
{
   //setup
   Velocity velocity;

   //exercise
   velocity.updateVelocity(0, 0, 0);
   
   //verify
   assert(velocity.getDx() == 0.0);
   assert(velocity.getDy() == 0.0);
   //teardown
   //no need, variable velocity is destroyed once function ends
}

void testVelocityUpdate::velocityTestTwo()
{
   //setup
   Velocity velocity(1.2, 3.4);

   //exercise
   velocity.updateVelocity(0, 0, 0);
   
   //verify
   assert(velocity.getDx() == 0.0);
   assert(velocity.getDy() == 0.0);
   
   //teardown
   //no need, variable velocity is destroyed once function ends
}

void testVelocityUpdate::velocityTestThree()
{
   //setup
   Velocity velocity;
   
   //exercise
   velocity.updateVelocity(1.2, 3.4, 1);
   
   //verify
   assert(velocity.getDx() == 1.2);
   assert(velocity.getDy() == 3.4);
   
   //teardown
   //no need, variable velocity is destroyed once function ends
}

void testVelocityUpdate::velocityTestFour()
{
   //setup
   Velocity velocity;
   
   //exercise
   velocity.updateVelocity(1.2, 3.4, 2);
   
   //verify
   assert(velocity.getDx() == 2.4);
   assert(velocity.getDy() == 6.8);
   
   //teardown
   //no need, variable velocity is destroyed once function ends
}

void testVelocityUpdate::velocityTestFive()
{
   //setup
   Velocity velocity(4.1, 6.0);
   
   //exercise
   velocity.updateVelocity(0.5, 0.2, 3);
   
   //verify
   assert(velocity.getDx() == 5.6);
   assert(velocity.getDy() == 6.6);
   
   //teardown
   //no need, variable velocity is destroyed once function ends
}