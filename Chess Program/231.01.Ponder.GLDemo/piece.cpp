#include "piece.h"
#include <list>

void Piece::setLetter(PieceType newLetter)
{
	letter = newLetter;
}

void Piece::setColor(bool color)
{
	white = color;
}

void Piece::setPos(int r, int c)
{
	pos = Position(r, c);
}

void Piece::setChar(string symbol)
{
	character = symbol;
}

void Piece::isMove()
{
	moved = true;
}

set<string> Piece::getMoves(Board board)
{
	set<string> moveList;
	list<string> rowLetters;
	rowLetters.assign({ "a", "b", "c", "d", "e", "f", "g", "h" });
	PieceType pieceType = getLetter();
	Position piecePos = getPos();
	int r = piecePos.getRow();;
	int c = piecePos.getCol();
	if (pieceType == PAWN) {
		if (getMoved() == false) {
			if (board.getPiece(r + 1, c).getLetter() == SPACE) {
				if (getColor() == true && (r + 2) < 8) {
					moveList.insert(next(rowLetters.begin(), r)->c_str()
						+ to_string(c)
						+ next(rowLetters.begin(), r + 2)->c_str()
						+ to_string(c)
						+ board.getPiece(r + 2, c).getChar());
				}
				moveList.insert(next(rowLetters.begin(), r)->c_str()
					+ to_string(c)
					+ next(rowLetters.begin(), r + 1)->c_str()
					+ to_string(c)
					+ board.getPiece(r + 1, c).getChar());

			}
			if (board.getPiece(r + 1, c+1).getLetter() != SPACE)
				moveList.insert(next(rowLetters.begin(), r)->c_str()
					+ to_string(c)
					+ next(rowLetters.begin(), r + 1)->c_str()
					+ to_string(c + 1)
					+ board.getPiece(r + 1, c + 1).getChar());
			if (board.getPiece(r + 1, c - 1).getLetter() != SPACE)
				moveList.insert(next(rowLetters.begin(), r)->c_str()
					+ to_string(c)
					+ next(rowLetters.begin(), r + 1)->c_str()
					+ to_string(c - 1)
					+ board.getPiece(r + 1, c - 1).getChar());
		}
	}
	else if (pieceType == KING) {

	}
	else if (pieceType == ROOK) {

	}
	else if (pieceType == QUEEN) {

	}
	else if (pieceType == KNIGHT) {

	}
	else if (pieceType == BISHOP) {

	}
	return moveList;
}



Pawn::Pawn(int r, int c, bool color)
{
	setLetter(PAWN);
	setColor(color);
	setPos(r, c);
	setMoved(false);
	if (color == true) {
		setChar("P");
	}
	else {
		setChar("p");
	}
	
}

King::King(int r, int c, bool color)
{
	setLetter(KING);
	setColor(color);
	setPos(r, c);
	setMoved(false);
	if (color == true) {
		setChar("K");
	}
	else {
		setChar("k");
	}
}

Rook::Rook(int r, int c, bool color)
{
	
	setLetter(ROOK);
	setColor(color);
	setPos(r, c);
	setMoved(false);
	if (color == true) {
		setChar("R");
	}
	else {
		setChar("r");
	}
}

Queen::Queen(int r, int c, bool color)
{
	setLetter(QUEEN);
	setColor(color);
	setPos(r, c);
	setMoved(false);
	if (color == true) {
		setChar("Q");
	}
	else {
		setChar("q");
	}
}

Knight::Knight(int r, int c, bool color)
{
	setLetter(KNIGHT);
	setColor(color);
	setPos(r, c);
	setMoved(false);
	if (color == true) {
		setChar("N");
	}
	else {
		setChar("n");
	}
}

Bishop::Bishop(int r, int c, bool color)
{
	setLetter(BISHOP);
	setColor(color);
	setPos(r, c);
	setMoved(false);
	if (color == true) {
		setChar("B");
	}
	else {
		setChar("b");
	}
}

Space::Space(int r, int c)
{
	setLetter(SPACE);
	setColor(true);
	setPos(r, c);
	setMoved(false);
	setChar("");
}
