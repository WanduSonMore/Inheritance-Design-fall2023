#pragma once
#include "position.h"
#include "move.h"
#include "board.h"
#include <vector>
class Piece
{
private:
	int moves = 0;
	Position pos;
public:
	std::vector<Move> getMovesSlide(Board board, std::vector<Position> delta);
	bool isWhite();
	bool justMoved(Move currentMove);
	// getters
	Position getPosition();
	int getTotalMoves();

	// setters
	void setMoved();
	char character;




};
