#pragma once
#include "board.h"
#include "piece.h"
class testPawn
{
public:
	void run()
	{
		getBlocked();
		getSimpleMove();
		getInitialMove();
		getCapture();
		getEnpassant();
		getPromotion();
	}
private:
	Board board = Board(true);
	void getBlocked();
	void getSimpleMove();
	void getInitialMove();
	void getCapture();
	void getEnpassant();
	void getPromotion();
};

