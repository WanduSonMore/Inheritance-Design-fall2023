#pragma once

class testVelocityUpdate
{
public:
   //run is a function that simply calls and runs through every test function
   void run()
   {
      velocityTestOne();
      velocityTestTwo();
      velocityTestThree();
      velocityTestFour();
      velocityTestFive();
   }
   //velocity test one takes a velocity of 0x 0y and adds 0x 0y acceleration for 0 seconds
   void velocityTestOne();

   //velocity test two takes a velocity of 1.2x 3.4y and adds 0x 0y acceleration for 0 seconds
   void velocityTestTwo();

   //velocity test three takes a velocity of 0x 0y and adds 1.2x 3.4y acceleration for 1 seconds
   void velocityTestThree();

   //velocity test four takes a velocity of 0x 0y and adds 1.2x 3.4y acceleration for 2 seconds
   void velocityTestFour();

   //velocity test five takes a velocity of 4.1x 6.0y and adds .5x .2y acceleration for 3 seconds
   void velocityTestFive();
};
