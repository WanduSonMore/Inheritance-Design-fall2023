/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include <list>
#include <vector>
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "satellite.h"
#include "earth.h"
#include "spaceship.h"
#include "bullet.h"
#include "testCases.h"
#include "testEarth.h"
#include "testPositionUpdate.h"
#include "testVelocityUpdate.h"
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
       hubble.set(0.0, -42164000.0, 3100.0, 0.0);
       ptHub = &hubble;
       sats[0] = &hubble;

       sputnik.set(-36515095.13, 21082000.0, 2050.0, 2684.68);
       ptSput = &sputnik;
       sats[1] = &sputnik;

       dragon.set(0.0, 8000000.0, -7900.0, 0.0);
       ptDrag = &dragon;
       sats[2] = &dragon;

       starlink.set(0.0, -13020000.0, 5800.0, 0.0);
       ptStarL = &starlink;
       sats[3] = &starlink;

       gps1.set(0.0, 26560000.0, -3880.0, 0.0);
       ptG1 = &gps1;
       sats[4] = &gps1;

       gps2.set(23001634.72, 13280000.0, -1940.00, 3360.18);
       ptG2 = &gps2;
       sats[5] = &gps2;
       
       gps3.set(23001634.72, -13280000.0, 1940.00, 3360.18);
       ptG3 = &gps3;
       sats[6] = &gps3;
       
       gps4.set(0.0, -26560000.0, 3880.0, 0.0);
       ptG4 = &gps4;
       sats[7] = &gps4;
       
       gps5.set(-23001634.72, -13280000.0, 1940.00, -3360.18);
       ptG5 = &gps5;
       sats[8] = &gps5;
       
       gps6.set(-23001634.72, 13280000.0, -1940.00, -3360.18);
       ptG6 = &gps6;
       sats[9] = &gps6;
      //ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      spaceship.setAll(ptUpperRight,-450,450);
      //ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptGPS.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptGPS.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      starSize = random(180, 220);
      for (int i = 0; i < starSize; i++) {
          stars[i].setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
          stars[i].setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
          phaseStars[i] = random(0, 256);
      }
      angleShip = 0.0;
      angleEarth = 0.0;
   }
   //Hubble hubble;

   // Draw All
   void drawAll(ogstream& gout, const Interface* pUI) {
       for (Satellite* i : sats) {
           i->draw(gout, angleShip);
       }
       //hubble.draw(gout, angleShip);
       spaceship.draw(gout, pUI);
       for (Bullet* obj : bullets) {
           obj->draw(gout);
       }

       // draw a series of star
       for (int i = 0; i < starSize; i++) {
           phaseStars[i] += 1;
           gout.drawStar(stars[i], phaseStars[i]);
       }
   }
   void updateBullets() {
       //if (bullets.empty() != true)
        for (Bullet* obj : bullets) {
            obj->updatePosition();
        }
   }

   void addBullet() {
       Bullet bullet(spaceship.getAngle(), spaceship.getPosition());
       bullets.push_back(&bullet);
   }

   void createBullet() {

   }
   Satellite* sats[10];
   Position stars[220];
   Hubble hubble;
   Satellite* ptHub;
   Sputnik sputnik;
   Satellite* ptSput;
   Dragon dragon;
   Satellite* ptDrag;
   Starlink starlink;
   Satellite* ptStarL;
   GPS gps1;
   Satellite* ptG1;
   GPS gps2;
   Satellite* ptG2;
   GPS gps3;
   Satellite* ptG3;
   GPS gps4;
   Satellite* ptG4;
   GPS gps5;
   Satellite* ptG5;
   GPS gps6;
   Satellite* ptG6;
   Spaceship spaceship;
   list<Bullet*> bullets;
   //Position ptHubble;
   Position ptSputnik;
   Position ptStarlink;
   Position ptCrewDragon;
   //Position ptShip;
   Position ptGPS;
   Position ptStar;
   Position ptUpperRight;

   unsigned char phaseStars[220];
   int starSize;

   double angleShip;
   double angleEarth;
   int timer = 0;
   int count = 0;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // accept input
   //

   // move by a little
   if (pUI->isUp())
       pDemo->spaceship.addVelocity(0.01);
   //   pDemo->ptShip.addPixelsY(1.0);
   if (pUI->isDown())
       pDemo->spaceship.addVelocity(-0.01);
   //   pDemo->ptShip.addPixelsY(-1.0);
   if (pUI->isLeft())
       pDemo->spaceship.addAngle(-0.1);
   //   pDemo->ptShip.addPixelsX(-1.0);
   if (pUI->isRight())
       pDemo->spaceship.addAngle(0.1);
   if (pUI->isSpace())
       pDemo->addBullet();
   //   pDemo->ptShip.addPixelsX(1.0);
   pDemo->spaceship.updatePosition();
   pDemo->updateBullets();
   //if (pDemo->timer < 1) {

   //}
   pDemo->timer += 1;
   //cout << pDemo->timer;
   //if (pDemo->timer < 1000000)
   //pDemo->hubble.setPositionNew(1);



   //
   // perform all the game logic
   //

   // rotate the earth
   pDemo->angleEarth += 0.01;
   pDemo->angleShip += 0.02;
   //pDemo->hubble.rotate(0.02);
   //pDemo->phaseStar++;

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);

   // draw satellites
   gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
   pDemo->drawAll(gout, pUI);
   //gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
   gout.drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
   gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
   //gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
   gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);

   // draw parts
   //pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
   //gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
   //pt.setPixelsX(pDemo->hubble.getPosition().getPixelsX() + 20);
   //pt.setPixelsY(pDemo->hubble.getPosition().getPixelsY() + 20);
   //pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
   //gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
   //gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
   //gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set

   // draw fragments
   //pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
   //gout.drawFragment(pt, pDemo->angleShip);
   //pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
   //gout.drawFragment(pt, pDemo->angleShip);

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 ); // 128km equals 1 pixel 
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,"Demo",ptUpperRight); // name on the window

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);
   //testCases tests;
   //tests.testEarth();
   //tests.testUpdatePosition();
   //tests.testUpdateVelocity();
   testEarth earth;
   testPositionUpdate PositionUpdate;
   testVelocityUpdate VelocityUpdate;
   earth.run();
   PositionUpdate.run();
   VelocityUpdate.run();
   return 0;
}
