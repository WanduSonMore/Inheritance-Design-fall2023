#include "testKing.h"
#include "king.h"
#include "pawn.h"
#include "rook.h"
#include "board.h"
#include <cassert>

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


void kingTest::read_free() const
{
	// SETUP
	Board board;
	//white king position e5
	board[4][4] = new King(4, 4, true);
	// EXERCISE
	bool set_len = board[4][4].getMoves(board).length();
	bool has_move1 = board[4][4].getMoves(board).contains('e5d6');
	bool has_move2 = board[4][4].getMoves(board).contains('e5e6');
	bool has_move3 = board[4][4].getMoves(board).contains('e5f6');
	bool has_move4 = board[4][4].getMoves(board).contains('e5d5');
	bool has_move5 = board[4][4].getMoves(board).contains('e5f5');
	bool has_move6 = board[4][4].getMoves(board).contains('e5d4');
	bool has_move7 = board[4][4].getMoves(board).contains('e5e4');
	bool has_move8 = board[4][4].getMoves(board).contains('e5f4');
	// VERIFY
	assert(set_len == 8)
	assert(has_move1 == true);
	assert(has_move2 == true);
	assert(has_move3 == true);
	assert(has_move4 == true);
	assert(has_move5 == true);
	assert(has_move6 == true);
	assert(has_move7 == true);
	assert(has_move8 == true);
}

void kingTest::read_blocked() const
{
	// SETUP
	Board board;
	//white king position e5
	board[4][4] = new King(4, 4, true);
	//white pawns surrounding king
	board[5][3] = new Pawn(5, 3, true);
	board[5][4] = new Pawn(5, 4, true);
	board[5][5] = new Pawn(5, 5, true);
	board[4][5] = new Pawn(4, 5, true);
	board[4][3] = new Pawn(4, 3, true);
	board[3][3] = new Pawn(3, 3, true);
	board[3][4] = new Pawn(3, 4, true);
	board[3][5] = new Pawn(3, 5, true);
	// EXERCISE
	bool has_move1 = board[4][4].getMoves(board).empty();
	// VERIFY
	assert(has_move1 == true);
}   // TEARDOWN

void kingTest::read_capture() const
{
	// SETUP
	Board board;
	//white king position e5
	board[4][4] = new King(4, 4, true);
	// black pawns surrounding king
	board[5][3] = new Pawn(5, 3, false);
	board[5][4] = new Pawn(5, 4, false);
	board[5][5] = new Pawn(5, 5, false);
	board[4][5] = new Pawn(4, 5, false);
	board[4][3] = new Pawn(4, 3, false);
	board[3][3] = new Pawn(3, 3, false);
	board[3][4] = new Pawn(3, 4, false);
	board[3][5] = new Pawn(3, 5, false);
	// EXERCISE
	bool set_len = board[4][4].getMoves(board).length();
	bool has_move1 = board[4][4].getMoves(board).contains('e5d6p');
	bool has_move2 = board[4][4].getMoves(board).contains('e5e6p');
	bool has_move3 = board[4][4].getMoves(board).contains('e5f6p');
	bool has_move4 = board[4][4].getMoves(board).contains('e5d5p');
	bool has_move5 = board[4][4].getMoves(board).contains('e5f5p');
	bool has_move6 = board[4][4].getMoves(board).contains('e5d4p');
	bool has_move7 = board[4][4].getMoves(board).contains('e5e4p');
	bool has_move8 = board[4][4].getMoves(board).contains('e5f4p');
	// VERIFY
	assert(set_len == 8)
	assert(has_move1 == true);
	assert(has_move2 == true);
	assert(has_move3 == true);
	assert(has_move4 == true);
	assert(has_move5 == true);
	assert(has_move6 == true);
	assert(has_move7 == true);
	assert(has_move8 == true);
}   // TEARDOWN

void kingTest::read_castle_king_moved() const
{
	// SETUP
	Board board;
	//white king position e1, made 1 move
	board[0][4] = new King(0, 4, true);
	board[0][4].isMove();
	//w1 position d2
	board[1][3] = new Pawn(1, 4, true);
	//w2 position e2
	board[1][4] = new Pawn(1, 4, true);
	//w3 position f2
	board[1][4] = new Pawn(1, 4, true);
	//r1 position a1
	board[0][0] = new Rook(0, 0, true);
	//r2 position h1
	board[0][7] = new Rook(0, 7, true);
	// EXERCISE
	bool set_len = board[0][4].getMoves(board).length();
	bool has_move1 = board[0][4].getMoves(board).contains('e1f1');
	bool has_move2 = board[0][4].getMoves(board).contains('e1d1');
	// VERIFY
	assert(set_len == 2);
	assert(has_move1 == true);
	assert(has_move2 == true);
}   // TEARDOWN

void kingTest::read_castle_rook_moved() const
{
	// SETUP
	//white king position e1
	Board board;
	board[0][4] = new King(0, 4, true);
	//w1 position d2
	board[1][3] = new Pawn(1, 4, true);
	//w2 position e2
	board[1][4] = new Pawn(1, 4, true);
	//w3 position f2
	board[1][4] = new Pawn(1, 4, true);
	//r1 position a1, made 1 move
	board[0][0] = new Rook(0, 0, true, 1);
	board[0][0].isMove();
	//r2 position h1, made 1 move
	board[0][7] = new Rook(0, 7, true, 1);
	board[0][7].isMove();
	// EXERCISE
	bool set_len = board[0][4].getMoves(board).length();
	bool has_move1 = board[0][4].getMoves(board).contains('e1f1');
	bool has_move2 = board[0][4].getMoves(board).contains('e1d1');
	// VERIFY
	assert(set_len == 2);
	assert(has_move1 == true);
	assert(has_move2 == true);
}   // TEARDOWN

void kingTest::read_castle_block() const
{
	// SETUP
	Board board;
	//white king position e1
	board[0][4] = new King(0, 4, true);
	//w1 position d2
	board[1][3] = new Pawn(1, 4, true);
	//w2 position e2
	board[1][4] = new Pawn(1, 4, true);
	//w3 position f2
	board[1][4] = new Pawn(1, 4, true);
	//w4 position b1
	board[0][1] = new Pawn(0, 1, true);
	//w5 position g1
	board[0][6] = new Pawn(0, 6, true);
	//r1 position a1, made 1 move
	board[0][0] = new Rook(0, 0, true, 1);
	//r2 position h1, made 1 move
	board[0][7] = new Rook(0, 7, true, 1);
	// EXERCISE
	bool set_len = board[0][4].getMoves(board).length();
	bool has_move1 = board[0][4].getMoves(board).contains('e1f1');
	bool has_move2 = board[0][4].getMoves(board).contains('e1d1');
	// VERIFY
	assert(set_len == 2);
	assert(has_move1 == true);
	assert(has_move2 == true);
}   // TEARDOWN

void kingTest::read_castle() const
{
	// SETUP
	Board board;
	//white king position e1
	board[0][4] = new King(0, 4, true);
	//w1 position d2
	board[1][3] = new Pawn(1, 4, true);
	//w2 position e2
	board[1][4] = new Pawn(1, 4, true);
	//w3 position f2
	board[1][4] = new Pawn(1, 4, true);
	//r1 position a1, made 1 move
	board[0][0] = new Rook(0, 0, true);
	//r2 position h1, made 1 move
	board[0][7] = new Rook(0, 7, true);
	// EXERCISE
	bool set_len = board[0][4].getMoves(board).length();
	bool has_move1 = board[0][4].getMoves(board).contains('e1f1');
	bool has_move2 = board[0][4].getMoves(board).contains('e1d1');
	bool has_move3 = board[0][4].getMoves(board).contains('E1g1c');
	bool has_move4 = board[0][4].getMoves(board).contains('e1c1C');
	// VERIFY
	assert(set_len == 4);
	assert(has_move1 == true);
	assert(has_move2 == true);
	assert(has_move3 == true);
	assert(has_move4 == true);
}   // TEARDOWN