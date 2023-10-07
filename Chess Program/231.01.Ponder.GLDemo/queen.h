#pragma once
#include "piece.h"
#include "move.h"
#include "board.h"
#include <vector>
class Queen : Piece
{
private:

public:
	Queen() { character = 'Q'; };
	Queen(bool isWhite);

	std::vector<Move> getMoves(Board board);
};