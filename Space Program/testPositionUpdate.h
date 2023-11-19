#pragma once

class testPositionUpdate
{
private:
    bool closeEnough(double value, double test, double tolerance) const
    {
        double difference = value - test;
        return (difference >= -tolerance) && (difference <= tolerance);
    }

public:
   //run is a function that simply calls and runs through every test function
   void run()
   {
      positionTestOne();
      positionTestTwo();
      positionTestThree();
      positionTestFour();
      positionTestFive();
      positionTestSix();
   }
   //position test one takes a satellite at position 11.1x 22.2y with a velocity of 0x 0y adds an acceleration of 0x 0y for 1 seconds 
   void positionTestOne();
   //position test two takes a satellite at position 11.1x 22.2y with a velocity of 0.5x 0.4y adds an acceleration of 0x 0y for 1 seconds
   void positionTestTwo();
   //position test three takes a satellite at position 11.1x 22.2y with a velocity of 0.5x 0.4y adds an acceleration of 0x 0y for 2 seconds
   void positionTestThree();
   //position test four takes a satellite at position 11.1x 22.2y with a velocity of 0x 0y adds an acceleration of 0.2x 0.3y for 1 seconds
   void positionTestFour();
   //position test five takes a satellite at position 11.1x 22.2y with a velocity of 0x 0y adds an acceleration of 0.2x 0.3y for 2 seconds
   void positionTestFive();
   //position test six takes a satellite at position 11.1x 22.2y with a velocity of 1x 2y adds an acceleration of 0.2x 0.3y for 2 seconds
   void positionTestSix();
};
