#pragma once
//#include "piece.h"
#include <set>
#include "uiDraw.h"
#include "move.h"
#include "position.h"
using namespace std;
class Piece;
class Board
{
private:
	Piece * board[8][8];
	int currentMove;
	ogstream gout;
public:
	//piece& operator[](const Position& pos); // Declaration
	Board(ogstream* pgout, bool noreset = false)// : pgout(pgout)
	{
		if (!noreset) {
			reset(false); // Add a semicolon here
		}
	}
	int getCurrentMove() const { return currentMove; }
	bool whiteTurn()     const { return getCurrentMove() % 2 == 1; }
	void display(const Position& posHover, const Position& posSelect) const;
	const Piece& operator [](const Position& pos) const
	{
		return *board[pos.getRow()][pos.getCol()];
	}
	Piece& get(Position pos);
	// setters
	//void free();
	void reset(bool fFree = true);
	void move(const Move& move);
	//void reverseMove(const Move& move);
	void operator -= (const Position& pos);
	//void operator -= (const Move& move);
	void remove(const Position& pos);
	//const Piece* operator = (Piece* pRhs);
	Piece& operator [](const Position& pos)
	{
		return *board[pos.getRow()][pos.getCol()];
	}
	void swap(const Position& pos1, const Position& pos2);

};

