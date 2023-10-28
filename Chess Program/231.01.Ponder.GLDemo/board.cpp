#include "board.h"
#include "position.h"
#include <wincrypt.h>

void Board::display(const Position& posHover, const Position& posSelect) const
{
	gout.drawBoard();

}

Piece& Board::get(Position pos)
{
	int row = pos.getRow();
	int col = pos.getCol();

	return *board[row][col];
}

void Board::reset(bool why)
{
	if (!why)
	{
		for (int r = 2; r < 6; r++) {
			for (int c = 0; c < 8; c++) {
				board[r][c] = new Space(r, c);
			}
		}
		for (int c = 0; c < 8; c++) {
			board[1][c] = new Pawn(1, c, true);
			board[6][c] = new Pawn(6, c, false);
		}
		board[0][0] = new Rook(0, 0, true);
		board[0][1] = new Knight(0, 1, true);
		board[0][2] = new Bishop(0, 2, true);
		board[0][3] = new Queen(0, 3, true);
		board[0][4] = new King(0, 4, true);
		board[0][5] = new Bishop(0, 5, true);
		board[0][6] = new Knight(0, 6, true);
		board[0][7] = new Rook(0, 7, true);

		board[7][0] = new Rook(7, 0, false);
		board[7][1] = new Knight(7, 1, false);
		board[7][2] = new Bishop(7, 2, false);
		board[7][3] = new Queen(7, 3, false);
		board[7][4] = new King(7, 4, false);
		board[7][5] = new Bishop(7, 5, false);
		board[7][6] = new Knight(7, 6, false);
		board[7][7] = new Rook(7, 7, false);
	}
}
void Board::move(const Move& move)
{
}
void Board::operator-=(const Position& pos)
{
	board[pos.getRow()][pos.getRow()] = new Space(r, c);
}
void Board::remove(const Position& pos)
{
}
void Board::swap(const Position& pos1, const Position& pos2)
{
	(board[pos1.getRow()][pos1.getCol()], board[pos2.getRow()][pos2.getCol()]) = (board[pos2.getRow()][pos2.getCol()], board[pos1.getRow()][pos1.getCol()]);

}


//void Board::resetBlank()
//{
//	for (int r = 0; r < 8; r++) {
//		for (int c = 0; c < 8; c++) {
//			board[r][c] = new Space(r, c);
//		}
//	}
//}

//set<string> Board::getMoves(Board board)
//{
//	return set<string>();
//}
