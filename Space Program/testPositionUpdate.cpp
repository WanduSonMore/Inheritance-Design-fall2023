#include "testPositionUpdate.h"
#include "position.h"
#include "satellite.h"

void testPositionUpdate::positionTestOne()
{
   //setup
   Satellite satellite(11.1, 22.2, 0, 0);
   
   //exercise
   satellite.updatePosition(0, 0, 1);
   
   //verify
   assert(satellite.getPosition().getMetersX() == 11.2);
   assert(satellite.getPosition().getMetersY() == 22.2);
   
   //teardown
   //no need, variable satellite is destroyed once function ends
}

void testPositionUpdate::positionTestTwo()
{
   //setup
   Satellite satellite(11.1, 22.2, 0.5, 0.4);
      
   //exercise
   satellite.updatePosition(0, 0, 1);
      
   //verify
   assert(satellite.getPosition().getMetersX() == 11.6);
   assert(satellite.getPosition().getMetersY() == 22.6);
      
   //teardown
   //no need, variable satellite is destroyed once function ends
}

void testPositionUpdate::positionTestThree()
{
   //setup
   Satellite satellite(11.1, 22.2, 0.5, 0.4);
      
   //exercise
   satellite.updatePosition(0, 0, 2);
      
   //verify
   assert(satellite.getPosition().getMetersX() == 12.1);
   assert(satellite.getPosition().getMetersY() == 23.0);
      
   //teardown
   //no need, variable satellite is destroyed once function ends
}

void testPositionUpdate::positionTestFour()
{
   //setup
   Satellite satellite(11.1, 22.2, 0, 0);
      
   //exercise
   satellite.updatePosition(0.2, 0.3, 1);
      
   //verify
   assert(satellite.getPosition().getMetersX() == 11.2);
   assert(satellite.getPosition().getMetersY() == 22.35);
      
   //teardown
   //no need, variable satellite is destroyed once function ends
}

void testPositionUpdate::positionTestFive()
{
   //setup
   Satellite satellite(11.1, 22.2, 0, 0);
      
   //exercise
   satellite.updatePosition(0.2, 0.3, 2);
      
   //verify
   assert(satellite.getPosition().getMetersX() == 11.5);
   assert(satellite.getPosition().getMetersY() == 22.8);
      
   //teardown
   //no need, variable satellite is destroyed once function ends
}

void testPositionUpdate::positionTestSix()
{
   //setup
   Satellite satellite(11.1, 22.2, 1, 2);
      
   //exercise
   satellite.updatePosition(0.2, 0.3, 2);
      
   //verify
   assert(satellite.getPosition().getMetersX() == 13.5);
   assert(satellite.getPosition().getMetersY() == 26.8);
      
   //teardown
   //no need, variable satellite is destroyed once function ends
}