#pragma once
#include "piece.h"
#include "move.h"
#include "board.h"
#include <vector>
class Knight : Piece
{
private:

public:
	Knight() { character = 'N'; };
	Knight(bool isWhite);

	std::vector<Move> getMoves(Board board);
};