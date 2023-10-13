#include "testKing.h"


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
	Board board = Board(true);
	//white king position e5
	board.setPlace(4, 4, new King(4, 4, true));
	// EXERCISE
	set<string> move;
	move = board.getPiece(4, 4).getMoves(board);
	// VERIFY
	assert(move.find("e5d6") != move.end());
	assert(move.find("e5e6") != move.end());
	assert(move.find("e5f6") != move.end());
	assert(move.find("e5d5") != move.end());
	assert(move.find("e5f5") != move.end());
	assert(move.find("e5d4") != move.end());
	assert(move.find("e5e4") != move.end());
	assert(move.find("e5f4") != move.end());
	// TEARDOWN
}

void kingTest::read_blocked() const
{
	// SETUP
	Board board = Board(true);
	//white king position e5
	board.setPlace(4, 4, new King(4, 4, true));
	//white pawns surrounding king
	board.setPlace(5, 3, new Pawn(5, 3, true));
	board.setPlace(5, 4, new Pawn(5, 4, true));
	board.setPlace(5, 5, new Pawn(5, 5, true));
	board.setPlace(4, 5, new Pawn(4, 5, true));
	board.setPlace(4, 3, new Pawn(4, 3, true));
	board.setPlace(3, 3, new Pawn(3, 3, true));
	board.setPlace(3, 4, new Pawn(3, 4, true));
	board.setPlace(3, 5, new Pawn(3, 5, true));

	// EXERCISE
	bool has_move1 = board.getPiece(4, 4).getMoves(board).empty();
	// VERIFY
	assert(has_move1 == true);
	// TEARDOWN
}   

void kingTest::read_capture() const
{
	// SETUP
	Board board = Board(true);
	//white king position e5
	board.setPlace(4, 4, new King(4, 4, true));
	// black pawns surrounding king
	board.setPlace(5, 3, new Pawn(5, 3, false));
	board.setPlace(5, 4, new Pawn(5, 4, false));
	board.setPlace(5, 5, new Pawn(5, 5, false));
	board.setPlace(4, 5, new Pawn(4, 5, false));
	board.setPlace(4, 3, new Pawn(4, 3, false));
	board.setPlace(3, 3, new Pawn(3, 3, false));
	board.setPlace(3, 4, new Pawn(3, 4, false));
	board.setPlace(3, 5, new Pawn(3, 5, false));
	// EXERCISE
	set<string> move;
	move = board.getPiece(4, 4).getMoves(board);
	// VERIFY
	assert(move.find("e5d6p") != move.end());
	assert(move.find("e5e6p") != move.end());
	assert(move.find("e5f6p") != move.end());
	assert(move.find("e5d5p") != move.end());
	assert(move.find("e5f5p") != move.end());
	assert(move.find("e5d4p") != move.end());
	assert(move.find("e5e4p") != move.end());
	assert(move.find("e5f4p") != move.end());
	// TEARDOWN
}   

void kingTest::read_castle_king_moved() const
{
	// SETUP
	Board board = Board(true);
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
	// TEARDOWN
}   

void kingTest::read_castle_rook_moved() const
{
	// SETUP
	Board board = Board(true);
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
	board[0][0].isMove();
	//r2 position h1, made 1 move
	board[0][7] = new Rook(0, 7, true);
	board[0][7].isMove();
	// EXERCISE
	bool set_len = board[0][4].getMoves(board).length();
	bool has_move1 = board[0][4].getMoves(board).contains('e1f1');
	bool has_move2 = board[0][4].getMoves(board).contains('e1d1');
	// VERIFY
	assert(set_len == 2);
	assert(has_move1 == true);
	assert(has_move2 == true);
	// TEARDOWN
}

void kingTest::read_castle_block() const
{
	// SETUP
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
	board[0][0] = new Rook(0, 0, true);
	//r2 position h1, made 1 move
	board[0][7] = new Rook(0, 7, true);
	// EXERCISE
	bool set_len = board[0][4].getMoves(board).length();
	bool has_move1 = board[0][4].getMoves(board).contains('e1f1');
	bool has_move2 = board[0][4].getMoves(board).contains('e1d1');
	// VERIFY
	assert(set_len == 2);
	assert(has_move1 == true);
	assert(has_move2 == true);
	// TEARDOWN
}  

void kingTest::read_castle() const
{
	// SETUP
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
	bool has_move3 = board[0][4].getMoves(board).contains('e1g1c');
	bool has_move4 = board[0][4].getMoves(board).contains('e1c1C');
	// VERIFY
	assert(set_len == 4);
	assert(has_move1 == true);
	assert(has_move2 == true);
	assert(has_move3 == true);
	assert(has_move4 == true);
	// TEARDOWN
}