#pragma once

class testEarth
{
public:
   //run is a function that simply calls and runs through every test function
   void run() 
   {
      altitudeTestOne();
      altitudeTestTwo();
      altitudeTestThree();
      altitudeTestFour();
      
      gravityTestOne();
      gravityTestTwo();
      gravityTestThree();
   }

   //Altitude tests
   //altitude test one finds the altitude of an object 6378000x 0y meters from the earths center
   void altitudeTestOne();
   //altitude test two finds the altitude of an object 6379000x 0y meters from the earths center
   void altitudeTestTwo();
   //altitude test three finds the altitude of an object 0x 6379000y meters from the earths center
   void altitudeTestThree();
   //altitude test four finds the altitude of an object 29814450.3x 29814450.3y meters from the earths center
   void altitudeTestFour();
   
   //gravity tests
   //gravity test one finds the amount of gravity affecting an object at an altitude of 0
   void gravityTestOne();
   //gravity test one finds the amount of gravity affecting an object at an altitude of 500000
   void gravityTestTwo();
   //gravity test one finds the amount of gravity affecting an object at an altitude of 2000000
   void gravityTestThree();
};