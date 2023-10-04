#include "testPawn.h"
#include "pawn.h"
#include "board.h"
#include <cassert>
#include <set>
#include <string>

//positions

//  A  B  C  D  E  F  G  H
//8 56 57 58 59 60 61 62 63
//7 48 49 50 51 52 53 54 55
//6 40 41 42 43 44 45 46 47
//5 32 33 34 35 36 37 38 39
//4 24 25 26 27 28 29 30 31
//3 16 17 18 19 20 21 22 23
//2 8  9  10 11 12 13 14 15
//1 0  1  2  3  4  5  6  7

// A = 0 B = 1 C = 2 D = 3 E = 4 F = 5 G = 6 H = 7
// The numbers will be one less than their value.

void testPawn::getBlocked()
{
	// SETUP
	Board board;
	// white pawn position d4
	board[3][3] = new Pawn(3, 3, true);
	// black pawn position d5
	board[4][3] = new Pawn(4, 3, false);
	// EXERCISE
	bool no_moves = board[3][3].getMoves(board).empty();
	// VERIFY
	assert(no_moves == true);
}   // TEARDOWN

void testPawn::getSimpleMove()
{
	// SETUP
	Board board;
	// white pawn position b4
	board[3][1] = new Pawn(3, 1, true);
	// EXERCISE
	bool has_move = board[3][1].getMoves(board).contains('b4b5');
	// VERIFY
	assert(has_move == true);
}   // TEARDOWN

void testPawn::getInitialMove()
{
	// SETUP
	Board board;
	// white pawn position b2
	board[1][1] = new Pawn(1, 1, true);
	// EXERCISE
	bool has_move = board[1][1].getMoves(board).contains('b2b3');
	bool has_move2 = board[1][1].getMoves(board).contains('b2b4');
	// VERIFY
	assert(has_move == true);
	assert(has_move2 == true);
}   // TEARDOWN

void testPawn::getCapture()
{
	// SETUP
	Board board;
	// white pawn position b6
	board[5][1] = new Pawn(5, 1, true);
	// black pawns positions a7, b7, and c7 
	board[6][0] = new Pawn(6, 0, false);
	board[6][1] = new Pawn(6, 1, false);
	board[6][2] = new pawn(6, 2, false);
	// EXERCISE
	bool has_move = board[5][1].getMoves().contains('b6a7p');
	bool has_move2 = board[5][1].getMoves().contains('b6c7p');
	// VERIFY
	assert(has_move == true);
	assert(has_move2 == true);
}   // TEARDOWN

void testPawn::getEnpassant()
{
	// SETUP
	Board board;
	// white pawn position b5
	board[4][1] = new Pawn(4, 1, true);
	// black pawns position b6
	board[5][0] = new Pawn(5, 0, false);
	// black pawns positions a6 and c6, each one made 1 move
	board[5][0].isMove();
	board[5][2] = new Pawn(5, 2, false);
	board[5][2].isMove();
	board[5][1] = new Pawn(5, 1, false);
	// EXERCISE
	bool has_move = board[3][1].getMoves().contains('b5c6E');
	bool has_move2 = board[3][1].getMoves().contains('b5a6E');
	// VERIFY
	assert(has_move == true);
	assert(has_move2 == true);
}   // TEARDOWN

void testPawn::getPromotion()
{
	// SETUP
	Board board;
	// white pawn position b7
	board[1][1] = new Pawn(3, 1, true);
	// EXERCISE
	bool has_move = board[1][1].getMoves().contains('b7b8Q');
	// VERIFY
	assert(has_move == true);
}   // TEARDOWN
