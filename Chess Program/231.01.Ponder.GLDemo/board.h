#pragma once
#include "piece.h"
#include "move.h"
#include "position.h"
#include "uiDraw.h"
#include <list>

class Board
{
private:
	std::list<Piece> board[64];
	int currentMove;
	ogstream gout;

public:
	Board();
	//Board(ogstream gout, reset);
	int calculateLocation(int r, int c);
	int getCurrentMove() { return currentMove; }
	bool whiteTurn();
	void display(Position posHover, Position posSelect);
	Piece get(Position pos);
	void free();
	void reset();
	void resetBlank();
	void move(Move move);
	void assign(Piece piece);
	void swap(Position pos1, Position pos2);
	void assertBoard();
};

