#pragma once
#include "piece.h"
#include "move.h"
#include "board.h"
#include <vector>
class Rook : Piece
{
private:

public:
	Rook() { character = 'R'; };
	Rook(bool isWhite);

	std::vector<Move> getMoves(Board board);
};