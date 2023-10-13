#pragma once
#include "piece.h"
#include <set>
using namespace std;
class Board
{
private:
	Piece* board[8][8];
public:
	//piece& operator[](const Position& pos); // Declaration
	Board(bool isClear);
	const Piece& operator[](const Position& pos) const;
	/*const Piece& operator=(const int r, const int c) const;*/
	void setPlace(int r, int c, Piece* newPiece);
	Piece getPiece(int r, int c);
	void reset();
	void resetBlank();

};

