#pragma once
#include "piece.h"
#include "move.h"
#include "board.h"
#include <vector>
class Pawn : Piece
{
private:

public:
	Pawn() { character = 'P'; };
	Pawn(bool isWhite);

	std::vector<Move> getMoves(Board board);
};


