/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for draw*
#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include "testMove.h"
#include "testPosition.h"
using namespace std;

//void callBack(Interface* pUI, void* p)
//{
//    getselectposi
//
//    // the first step is to cast the void pointer into a game object. This
//    // is the first step of every single callback function in OpenGL. 
//    char* board = (char*)p;
//
//    // move 
//    if (move(board, pUI->getPreviousPosition(), pUI->getSelectPosition()))
//        pUI->clearSelectPosition();
//    else
//        possible = getPossibleMoves(board, pUI->getSelectPosition());
//
//    // if we clicked on a blank spot, then it is not selected
//    if (pUI->getSelectPosition() != -1 && board[pUI->getSelectPosition()] == ' ')
//        pUI->clearSelectPosition();
//
//    // draw the board
//    draw(board, *pUI, possible);
//
//}

int main(){

	ogstream gout;
   //PositionTest t;
   //t.run();
   //MoveTest k;
   //k.run();
	gout.drawBoard();
   return 0;
}
