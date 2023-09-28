#include "testPawn.h"
#include "pawn.h"
#include "board.h"
#include <cassert>

/*************************************
 * GET  Zero
 * Default position: slot zero at a1
 * +---a--b--c--d--e--f--g--h---+
 * |                            |
 * 8  56 57 58 59 60 61 62 63   8
 * 7  48 49 50 51 52 53 54 55   7
 * 6  40 41 42 43 44 45 46 47   6
 * 5  32 33 34 35 36 37 38 39   5
 * 4  24 25 26 27 28 29 30 31   4
 * 3  16 17 18 19 20 21 22 23   3
 * 2   8  9 10 11 12 13 14 15   2
 * 1  (0) 1  2  3  4  5  6  7   1
 * |                            |
 * +---a--b--c--d--e--f--g--h---+
 **************************************/

void testPawn::getBlocked()
{
	Board board;
	// Find out what r is
	board[4][3] = new Pawn(4, 3, true);
	board[3][3] = new Pawn(3, 3, false);
	// Find what to place in front
	dic moves = board[3][3].getMoves(board);
	assert(moves.length = 0);

}

void testPawn::getSimpleMove()
{
	Board board;
	board[4][1] = new Pawn(4, 1, true);
	moves = board[3][1].getMoves(board);
	assert(moves[0][0] == (4, 1, "p"));
	assert(moves[0][1] == (3, 1, " "));
}

void testPawn::getInitialMove()
{
	Board board;
	board[6][1] = new Pawn(6, 1, true);
	moves = board[1][1].getMoves(board);
	assert(moves[0][0] == (6, 1));
	assert(moves[0][1] == (5, 1));
	assert(moves[1][0] == (6, 1));
	assert(moves[1][1] == (4, 1));
	
}

void testPawn::getCapture()
{
	Board board;
	board[2][1] = new Pawn(2, 1, true);
	board[1][1] = new Pawn(1, 1, false);
	board[1][0] = new Pawn(1, 0, false);
	board[1][2] = new pawn(1, 2, false);
	moves = board[5][1].getMoves();
	assert(moves[0][0] == (2, 1));
	assert(moves[0][1] == (1, 0));
	assert(moves[1][0] == (2, 1));
	assert(moves[1][1] == (1, 2));

}

void testPawn::getEnpassant()
{
	//create board and pawns
	Board board;
	board[3][1] = new Pawn(3, 1, true);
	board[2][1] = new Pawn(2, 1, false);
	board[2][0] = new Pawn(2, 0, false);
	//move pawn forward 2
	board[2][2] = new Pawn(2, 2, false);
	//move pawn forward 2
	moves = board[3][1].getMoves();
	assert(moves == ((3,1),(2,2)),((3,1),(2,0))

}

void testPawn::getPromotion()
{
	Board board;
	board[1][1] = new Pawn(3, 1, true);
	moves = board[1][1].getMoves();
	assert(moves == ((1, 1), (1, 0));
}
