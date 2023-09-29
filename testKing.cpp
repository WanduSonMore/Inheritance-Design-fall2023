#include "testKing.h"
#include "king.h"
#include "pawn.h"
#include "rook.h"
#include "board.h"
#include <cassert>

//positions

//  A  B  C  D  E  F  G  H
//7 56 57 58 59 60 61 62 63
//6 48 49 50 51 52 53 54 55
//5 40 41 42 43 44 45 46 47
//4 32 33 34 35 36 37 38 39
//3 24 25 26 27 28 29 30 31
//2 16 17 18 19 20 21 22 23
//1 8  9  10 11 12 13 14 15
//0 0  1  2  3  4  5  6  7

// A = 0 B = 1 C = 2 D = 3 E = 4 F = 5 G = 6 H = 7
// positions of x and y switch in the program
// f1 will turn into [0][5] as row comes first in dictionaries  

// A1 = [0] [0] | B1 = [0] [1] | C1 = [0] [2] | D1 = [0] [3] | E1 = [0] [4] | F1 = [0] [5] | G1 = [0] [6] | H1 = [0] [7] 
// A2 = [1] [0] | B2 = [1] [1] | C2 = [1] [2] | D2 = [1] [3] | E2 = [1] [4] | F2 = [1] [5] | G2 = [1] [6] | H2 = [1] [7] 
// A3 = [2] [0] | B3 = [2] [1] | C3 = [2] [2] | D3 = [2] [3] | E3 = [2] [4] | F3 = [2] [5] | G3 = [2] [6] | H3 = [2] [7] 
// A4 = [3] [0] | B4 = [3] [1] | C4 = [3] [2] | D4 = [3] [3] | E4 = [3] [4] | F4 = [3] [5] | G4 = [3] [6] | H4 = [3] [7] 
// A5 = [4] [0] | B5 = [4] [1] | C5 = [4] [2] | D5 = [4] [3] | E5 = [4] [4] | F5 = [4] [5] | G5 = [4] [6] | H5 = [4] [7] 
// A6 = [5] [0] | B6 = [5] [1] | C6 = [5] [2] | D6 = [5] [3] | E6 = [5] [4] | F6 = [5] [5] | G6 = [5] [6] | H6 = [5] [7] 
// A7 = [6] [0] | B7 = [6] [1] | C7 = [6] [2] | D7 = [6] [3] | E7 = [6] [4] | F7 = [6] [5] | G7 = [6] [6] | H7 = [6] [7] 
// A8 = [7] [0] | B8 = [7] [1] | C8 = [7] [2] | D8 = [7] [3] | E8 = [7] [4] | F8 = [7] [5] | G8 = [7] [6] | H8 = [7] [7] 


void kingTest::read_free() const
{
	Board board;
	//white king position E5 (E = 4, and 5 becomes 4)
	board[4][4] = new King(4, 4, true);

	moves = board[4][4].getMoves(board);

	assert(moves.length == 8);
	assert(moves[0][1] == [5][3]); //D6
	assert(moves[1][0] == [4][4]);
	assert(moves[1][1] == [5][4]); //E6
	assert(moves[2][0] == [4][4]);
	assert(moves[2][1] == [5][5]); //F6
	assert(moves[3][0] == [4][4]);
	assert(moves[3][1] == [4][5]); //F5
	assert(moves[4][0] == [4][4]);
	assert(moves[4][1] == [4][3]); //D5
	assert(moves[5][0] == [4][4]);
	assert(moves[5][1] == [3][3]); //D4
	assert(moves[6][0] == [4][4]); 
	assert(moves[6][1] == [3][4]); //E4
	assert(moves[7][0] == [4][4]);
	assert(moves[7][1] == [3][5]); //F4
}

void kingTest::read_blocked() const
{
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

	moves = board[4][4].getMoves(board)

	assert(moves.length == 0);
}

void kingTest::read_capture() const
{
	//white king position e5
	board[4][4] = new King(4, 4, true);

	//black pawns surrounding king
	board[5][3] = new Pawn(5, 3, false);
	board[5][4] = new Pawn(5, 4, false);
	board[5][5] = new Pawn(5, 5, false);
	board[4][5] = new Pawn(4, 5, false);
	board[4][3] = new Pawn(4, 3, false);
	board[3][3] = new Pawn(3, 3, false);
	board[3][4] = new Pawn(3, 4, false);
	board[3][5] = new Pawn(3, 5, false);

	moves = board[4][4].getMoves(board)

	assert(moves.length == 8);
	assert(moves[0][1] == [5][3]); //D6
	assert(moves[1][0] == [4][4]);
	assert(moves[1][1] == [5][4]); //E6
	assert(moves[2][0] == [4][4]);
	assert(moves[2][1] == [5][5]); //F6
	assert(moves[3][0] == [4][4]);
	assert(moves[3][1] == [4][5]); //F5
	assert(moves[4][0] == [4][4]);
	assert(moves[4][1] == [4][3]); //D5
	assert(moves[5][0] == [4][4]);
	assert(moves[5][1] == [3][3]); //D4
	assert(moves[6][0] == [4][4]);
	assert(moves[6][1] == [3][4]); //E4
	assert(moves[7][0] == [4][4]);
	assert(moves[7][1] == [3][5]); //F4
}

void kingTest::read_castle_king_moved() const
{
	//white king position e1, made 1 move
	board[0][4] = new King(0, 4, true, 1);
	
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

	moves = board[0][4].getMoves(board);

	assert(moves.length == 2);
	assert(moves[0][1] == [0][3]);
	assert(moves[1][0] == [0][4]);
	assert(moves[1][1] == [0][5]);
}

void kingTest::read_castle_rook_moved() const
{
	//white king position e1
	board[0][4] = new King(0, 4, true);

	//w1 position d2
	board[1][3] = new Pawn(1, 4, true);
	//w2 position e2
	board[1][4] = new Pawn(1, 4, true);
	//w3 position f2
	board[1][4] = new Pawn(1, 4, true);
	//r1 position a1, made 1 move
	board[0][0] = new Rook(0, 0, true, 1);
	//r2 position h1, made 1 move
	board[0][7] = new Rook(0, 7, true, 1);

	moves = board[0][4].getMoves(board);

	assert(moves.length == 2);
	assert(moves[0][1] == [0][3]);
	assert(moves[1][0] == [0][4]);
	assert(moves[1][1] == [0][5]);
}

void kingTest::read_castle_block() const
{
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

	moves = board[0][4].getMoves(board);

	assert(moves.length == 2);
	assert(moves[0][1] == [0][3]);
	assert(moves[1][0] == [0][4]);
	assert(moves[1][1] == [0][5]);
}

void kingTest::read_castle() const
{
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

	moves = board[0][4].getMoves(board);

	assert(moves.length == 4);
	assert(moves[0][1] == [0][3]);
	assert(moves[1][0] == [0][4]);
	assert(moves[1][1] == [0][5]);
	assert(moves[2][0] == [0][4]);
	assert(moves[2][1] == [0][6]);
	assert(moves[3][0] == [0][4]);
	assert(moves[3][1] == [0][2])
}