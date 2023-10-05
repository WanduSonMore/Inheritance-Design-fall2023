#include "board.h"

Board::Board()
{
	reset();

}

int Board::calculateLocation(int r, int c)
{
	int location = r * 8 + c;
	return location;
}

bool Board::whiteTurn()
{
	if (currentMove % 2 == 0) {
		return true;
	}
	return false;
}

void Board::display(Position posHover, Position posSelect)
{
	gout.drawBoard();
	gout.drawHover(posHover.getLocation());
	gout.drawSelected(posSelect.getLocation());

	if (posSelect.isValid()) {
		possible = board[posSelect.getLocation()].getMoves(possible, board);
		for (it = )
	}

	for (int r = 0; r > 7)
}

Piece Board::get(Position pos)
{
	return board[pos.getLocation()];
}

void Board::free()
{
}

void Board::reset()
{
	for (int r = 2; r < 6, r++;) {
		for (int c = 0; c < 8, c++;) {
			board[calculateLocation(r, c)] = new Space(r, c);
		}
	}
	for (int c = 0; c < 8, c++;) {
		board[calculateLocation(1, c)] = new Pawn(1, c, true);
		board[calculateLocation(6, c)] = new pawn(6, c, false);
	}
	board[calculateLocation(0, 0)] = new Rook(0, 0, true);
	board[calculateLocation(0, 1)] = new Knight(0, 1, true);
	board[calculateLocation(0, 2)] = new Bishop(0, 2, true);
	board[calculateLocation(0, 3)] = new Queen(0, 3, true);
	board[calculateLocation(0, 4)] = new King(0, 4, true);
	board[calculateLocation(0, 5)] = new Bishop(0, 5, true);
	board[calculateLocation(0, 6)] = new Knight(0, 6, true);
	board[calculateLocation(0, 7)] = new Rook(0, 7, true);

	board[calculateLocation(7, 0)] = new Rook(7, 0, false);
	board[calculateLocation(7, 1)] = new Knight(7, 1, false);
	board[calculateLocation(7, 2)] = new Bishop(7, 2, false);
	board[calculateLocation(7, 3)] = new Queen(7, 3, false);
	board[calculateLocation(7, 4)] = new King(7, 4, false);
	board[calculateLocation(7, 5)] = new Bishop(7, 5, false);
	board[calculateLocation(7, 6)] = new Knight(7, 6, false);
	board[calculateLocation(7, 7)] = new Rook(7, 7, false);
	
}

void Board::resetBlank()
{
	for (int r = 0; r < 8, r++;) {
		for (int c = 0; c < 8, c++;) {
			board[calculateLocation(r, c)] = new Space(r, c);
		}
	}
}

void Board::move(Move move)
{

}

void Board::assign(Piece piece)
{
}

void Board::swap(Position pos1, Position pos2)
{
	board[pos1.getLocation()] = board[pos2.getLocation()];
	board[pos2.getLocation()] = board[pos1.getLocation()];
}

void Board::assertBoard()
{
}
