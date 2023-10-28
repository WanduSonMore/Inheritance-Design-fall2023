#include "piece.h"
#include "board.h"
#include "move.h"
#include "uiDraw.h"
#include <cassert>


void Pawn::getMoves(set<Move>& moves, const Board& board) const
{
	Position posMove(getPosition(), isWhite() ? ADD_R : SUB_R);

	if (posMove.isValid() && board[posMove] == ' ')
	{
		Move move;
		move.setSrc(getPosition());
		move.setDes(posMove);
		move.setWhiteMove(isWhite());

		if (posMove.getRow() == (isWhite() ? 7 : 0)) {
			addPromotion(moves, move);
		}
		else {
			moves.insert(move);
		}

	}

	if (!isMoved())
	{
		assert(position.getRow() == (isWhite() ? 1 : 6));
		Position posMove(isWhite() ? 3 : 4, getPosition().getCol());
		Position posCheck(isWhite() ? 2 : 5, getPosition().getCol());

		if (board[posMove] == ' ' && board[posCheck] == ' ') {
			Move move;
			move.setSrc(getPosition());
			move.setDes(posMove);
			move.setWhiteMove(isWhite());
			moves.insert(move);
		}
	}

	const int cDelta[] = { 1, -1 };
	for (int i = 0; i < 2; i++)
	{
		Position posMove(position.getRow() + (isWhite() ? 1 : -1),
			position.getCol() + cDelta[i]);
		if (posMove.isValid() &&
			board[posMove] != ' ' &&
			board[posMove].isWhite() != isWhite())
		{
			Move move;
			move.setSrc(getPosition());
			move.setDes(posMove);
			move.setWhiteMove(isWhite());
			move.setCapture(board[posMove].getLetter());

			if (posMove.getRow() == (isWhite() ? 7 : 0))
			{
				addPromotion(moves, move);
			}
			else {
				moves.insert(move);
			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		Position povMove(position.getRow() + (isWhite() ? 1 : -1),
			position.getCol() + cDelta[i]);
		Position povKill(position.getRow(),
			position.getCol() + cDelta[i]);

		if (posMove.isValid() &&
			position.getRow() == (isWhite() ? 4 : 3) &&
			board[posMove] == ' ' &&
			board[povKill] == 'p' &&
			board[povKill].isWhite() != isWhite() &&
			board[povKill].getNMoves() == 1 &&
			board[povKill].justMoved(board.getCurrentMove()))
		{
			Move move;
			move.setSrc(getPosition());
			move.setDes(posMove);
			move.setWhiteMove(isWhite());
			move.setCapture(board[posMove].getLetter());
			move.setEnPassant();
			moves.insert(move);
		}

	}

}

void Pawn::addPromotion(set<Move>& moves, Move& move) const
{
	move.setPromote(QUEEN);
	moves.insert(move);
}

void Bishop::getMoves(set<Move>& moves, const Board& board) const
{
	const Delta delta[4] =
	{
		 {-1,  1}, {1,  1},
		 {-1, -1}, {1, -1}
	};

	moves = getMovesSlide(board, delta, sizeof(delta[0]));
}


void Rook::getMoves(set<Move>& moves, const Board& board) const
{
	const Delta delta[4] =
	{
				  {0,  1},
		 {-1, 0},         {1, 0},
				  {0, -1}
	};


	moves = getMovesSlide(board, delta, sizeof(delta[0]));

}

void King::getMoves(set<Move>& moves, const Board& board) const
{
	const Delta delta[8] =
	{
		 {-1,  1}, {0,  1}, {1,  1},
		 {-1,  0},          {1,  0},
		 {-1, -1}, {0, -1}, {1, -1}
	};
	moves = getMovesSlide(board, delta, sizeof(delta[0]));
}

void Queen::getMoves(set<Move>& moves, const Board& board) const
{
	const Delta delta[] =
	{
		 {-1,  1}, {0,  1}, {1,  1},
		 {-1,  0},          {1,  0},
		 {-1, -1}, {0, -1}, {1, -1}
	};


	moves = getMovesSlide(board, delta, sizeof(delta[0]));
}

void Knight::getMoves(set<Move>& moves, const Board& board) const
{
	const Delta delta[] =
	{
			   {-1,  2}, { 1,  2},
	  {-2,  1},                    { 2,  1},
	  {-2, -1},                    { 2, -1},
			   {-1, -2}, { 1, -2}
	};

	moves = getMovesSlide(board, delta, sizeof(delta[0]));
}

const Piece& Piece::operator=(const Piece& rhs)
{
	// TODO: insert return statement here
}

set<Move> Piece::getMovesSlide(const Board& board, const Delta deltas[], int numDelta) const
{
	set<Move> moves;
	
	//Position checkPos(position);
	//bool blocked = false;
	PieceType type = getLetter();
	int row = getPosition().getRow();  // current location row
	int col = getPosition().getCol();  // current location column
	int r;                   // the row we are checking
	int c;                   // the column we are checking
	bool amWhite = isWhite();

	for (int i = 0; i < numDelta; i++)
	{
		// Has move here so it resets everytime it loops
		Move move;
		r = row + deltas[i].dRow;
		c = col + deltas[i].dCol;
		if (type == KNIGHT) {
			// Checks to see if the knight is white and space it can move to is a SPACE or a black piece.
			if (amWhite && (board[r * 8 + c].getLetter() == SPACE || !board[r * 8 + c].isWhite())) {
				move.setSrc(getPosition());
				move.setDes(board[r * 8 + c].getPosition());
				if (board[r * 8 + c].getLetter() != SPACE) {
					move.setCapture(board[r * 8 + c].getLetter());
				}
				moves.insert(move);
			}
			// Checks to see if the knight is black and the space it can move to is a SPACE or a white piece.
			else if (!amWhite && (board[r * 8 + c].getLetter() == SPACE || board[r * 8 + c].isWhite())) {
				move.setSrc(getPosition());
				move.setDes(board[r * 8 + c].getPosition());
				if (board[r * 8 + c].getLetter() != SPACE) {
					move.setCapture(board[r * 8 + c].getLetter());
				}
				moves.insert(move);
			}
		}

		else if (type == KING) {
			// Checks to see if the king is white and space it can move to is a SPACE or a black piece.
			if (amWhite && board[r * 8 + c].getLetter() == SPACE || !board[r * 8 + c].isWhite()) {  
				move.setSrc(getPosition());
				move.setDes(board[r * 8 + c].getPosition());
				if (board[r * 8 + c].getLetter() != SPACE) {
					move.setCapture(board[r * 8 + c].getLetter());
				}
				moves.insert(move);
				// Check to see if king can castle
				if (nMoves == 0 && (i == 3|| i == 4)){ 
					// Checks to see if castling on the king's side is available.
					if (board[0].getNMoves() < 0 
						&& board[0].getLetter() == ROOK 
						&& board[1].getLetter() == SPACE
						&& board[2].getLetter() == SPACE) 
					{
						move.setSrc(getPosition());
						move.setDes(board[1].getPosition());
						move.setCastle(true);
						moves.insert(move);
					}
					// Checks to see if castling on the queen's side is available.
					else if (board[7].getNMoves() < 0
						&& board[7].getLetter() == ROOK
						&& board[4].getLetter() == SPACE
						&& board[5].getLetter() == SPACE
						&& board[6].getLetter() == SPACE)
					{
						move.setSrc(getPosition());
						move.setDes(board[5].getPosition());
						move.setCastle(false);
						moves.insert(move);
					}
				}
			}
			// Checks to see if the king is black and the space it can move to is a SPACE or a white piece.
			else if (!amWhite && board[r * 8 + c].getLetter() == SPACE || board[r * 8 + c].isWhite()) {
				move.setSrc(getPosition());
				move.setDes(board[r * 8 + c].getPosition());
				if (board[r * 8 + c].getLetter() != SPACE) {
					move.setCapture(board[r * 8 + c].getLetter());
				}
				moves.insert(move);
				// Check to see if king can castle
				if (nMoves == 0 && (i == 3 || i == 4)) {
					// Checks to see if castling on the king's side is available.
					if (board[56].getNMoves() < 0
						&& board[56].getLetter() == ROOK
						&& board[57].getLetter() == SPACE
						&& board[58].getLetter() == SPACE)
					{
						move.setSrc(getPosition());
						move.setDes(board[57].getPosition());
						move.setCastle(true);
						moves.insert(move);
					}
					// Checks to see if castling on the queen's side is available.
					else if (board[63].getNMoves() < 0
						&& board[63].getLetter() == ROOK
						&& board[60].getLetter() == SPACE
						&& board[61].getLetter() == SPACE
						&& board[62].getLetter() == SPACE)
					{
						move.setSrc(getPosition());
						move.setDes(board[61].getPosition());
						move.setCastle(false);
						moves.insert(move);
					}
				}
			}
		}

		else if (type == QUEEN) {
			// This goes through all the spaces available and adds them to the moves set until it finds a place that has a piece in the way.
			while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
				board[r * 8 + c].getLetter() == SPACE)
			{
				move.setSrc(getPosition());
				move.setDes(board[r * 8 + c].getPosition());
				moves.insert(move);
				r += deltas[i].dRow;
				c += deltas[i].dCol;
			}
			// This helps to prevent adding duplicates to the set
			if (r >= 0 && r < 8 && c >= 0 && c < 8) {
				// Checks see if the queen is white and if the place it is looking at has a black or white piece.
				if (amWhite && !board[r * 8 + c].isWhite()) {
					move.setSrc(getPosition());
					move.setDes(board[r * 8 + c].getPosition());
					if (board[r * 8 + c].getLetter() != SPACE) {
						move.setCapture(board[r * 8 + c].getLetter());
					}
					moves.insert(move);
				}
				// Checks see if the queen is black and if the place it is looking at has a black or white piece.
				else if (!amWhite && board[r * 8 + c].isWhite()) {
					move.setSrc(getPosition());
					move.setDes(board[r * 8 + c].getPosition());
					if (board[r * 8 + c].getLetter() != SPACE) {
						move.setCapture(board[r * 8 + c].getLetter());
					}
					moves.insert(move);
				}
			}
		}
		else if (type == ROOK) {
			// This goes through all the spaces available and adds them to the moves set until it finds a place that has a piece in the way.
			while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
				board[r * 8 + c].getLetter() == SPACE)
			{
				move.setSrc(getPosition());
				move.setDes(board[r * 8 + c].getPosition());
				moves.insert(move);
				r += deltas[i].dRow;
				c += deltas[i].dCol;
			}
			// This helps to prevent adding duplicates to the set
			if (r >= 0 && r < 8 && c >= 0 && c < 8) {
				// Checks see if the rook is white and if the place it is looking at has a black or white piece.
				if (amWhite && !board[r * 8 + c].isWhite()) {
					move.setSrc(getPosition());
					move.setDes(board[r * 8 + c].getPosition());
					if (board[r * 8 + c].getLetter() != SPACE) {
						move.setCapture(board[r * 8 + c].getLetter());
					}
					moves.insert(move);
				}
				// Checks see if the rook is black and if the place it is looking at has a black or white piece.
				else if (!amWhite && board[r * 8 + c].isWhite()) {
					move.setSrc(getPosition());
					move.setDes(board[r * 8 + c].getPosition());
					if (board[r * 8 + c].getLetter() != SPACE) {
						move.setCapture(board[r * 8 + c].getLetter());
					}
					moves.insert(move);
				}
			}
		}
		else if (type == BISHOP) {
			// This goes through all the spaces available and adds them to the moves set until it finds a place that has a piece in the way.
			while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
				board[r * 8 + c].getLetter() == SPACE)
			{
				move.setSrc(getPosition());
				move.setDes(board[r * 8 + c].getPosition());
				moves.insert(move);
				r += deltas[i].dRow;
				c += deltas[i].dCol;
			}
			// This helps to prevent adding duplicates to the set
			if (r >= 0 && r < 8 && c >= 0 && c < 8) {
				// Checks see if the bishop is white and if the place it is looking at has a black or white piece.
				if (amWhite && !board[r * 8 + c].isWhite()) {
					move.setSrc(getPosition());
					move.setDes(board[r * 8 + c].getPosition());
					if (board[r * 8 + c].getLetter() != SPACE) {
						move.setCapture(board[r * 8 + c].getLetter());
					}
					moves.insert(move);
				}
				// Checks see if the bishop is black and if the place it is looking at has a black or white piece.
				else if (!amWhite && board[r * 8 + c].isWhite()) {
					move.setSrc(getPosition());
					move.setDes(board[r * 8 + c].getPosition());
					if (board[r * 8 + c].getLetter() != SPACE) {
						move.setCapture(board[r * 8 + c].getLetter());
					}
					moves.insert(move);
				}
			}
		}
	}
	

}

//set<Move> Piece::getMovesNoslide(const Board& board, const Delta deltas[], int numDelta) const
//{
//	return set<Move>();
//}


//void Piece::setLetter(PieceType newLetter)
//{
//	letter = newLetter;
//}
//
//void Piece::setColor(bool color)
//{
//	white = color;
//}
//
//void Piece::setPos(int r, int c)
//{
//	pos = Position(r, c);
//}
//
//void Piece::setChar(string symbol)
//{
//	character = symbol;
//}
//
//void Piece::isMove()
//{
//	nMove = true;
//}

//set<Move> Piece::getMoves(Board & board) //need and to call by referance.
//{
//	set<Move> moveList;
//	//list<string> rowLetters;
//	//rowLetters.assign({ "a", "b", "c", "d", "e", "f", "g", "h" });
//	//PieceType pieceType = getLetter();
//	//Position piecePos = getPos();
//	//int r = piecePos.getRow();
//	//int c = piecePos.getCol();
//	if (pieceType == PAWN) {
//		if (getMoved() == false) {
//			if (board.getPiece(r + 1, c).getLetter() == SPACE) {
//				if (getColor() == true && (r + 2) < 8) {
//					moveList.insert(next(rowLetters.begin(), r)->c_str()
//						+ to_string(c)
//						+ next(rowLetters.begin(), r + 2)->c_str()
//						+ to_string(c)
//						+ board.getPiece(r + 2, c).getChar());
//				}
//				moveList.insert(next(rowLetters.begin(), r)->c_str()
//					+ to_string(c)
//					+ next(rowLetters.begin(), r + 1)->c_str()
//					+ to_string(c)
//					+ board.getPiece(r + 1, c).getChar());
//			}
//			if (board.getPiece(r + 1, c+1).getLetter() != SPACE)
//				moveList.insert(next(rowLetters.begin(), r)->c_str()
//					+ to_string(c)
//					+ next(rowLetters.begin(), r + 1)->c_str()
//					+ to_string(c + 1)
//					+ board.getPiece(r + 1, c + 1).getChar());
//			if (board.getPiece(r + 1, c - 1).getLetter() != SPACE)
//				moveList.insert(next(rowLetters.begin(), r)->c_str()
//					+ to_string(c)
//					+ next(rowLetters.begin(), r + 1)->c_str()
//					+ to_string(c - 1)
//					+ board.getPiece(r + 1, c - 1).getChar());
//		}
//	}
//	else if (pieceType == KING) {
//
//	}
//	else if (pieceType == ROOK) {
//
//	}
//	else if (pieceType == QUEEN) {
//
//	}
//	else if (pieceType == KNIGHT) {
//
//	}
//	else if (pieceType == BISHOP) {
//
//	}
//	return moveList;
//}



//Pawn::Pawn(int r, int c, bool color)
//{
//	setLetter(PAWN);
//	setColor(color);
//	setPos(r, c);
//	setMoved(false);
//	if (color == true) {
//		setChar("P");
//	}
//	else {
//		setChar("p");
//	}
//	
//}

//set<Move> Pawn::getMoves(const Board& board)
//{
//	return set<Move>();
//}

//King::King(int r, int c, bool color)
//{
//	setLetter(KING);
//	setColor(color);
//	setPos(r, c);
//	setMoved(false);
//	if (color == true) {
//		setChar("K");
//	}
//	else {
//		setChar("k");
//	}
//}

//set<Move> King::getMoves(const Board& board)
//{
//	return set<Move>();
//}

//Rook::Rook(int r, int c, bool color)
//{
//	
//	setLetter(ROOK);
//	setColor(color);
//	setPos(r, c);
//	setMoved(false);
//	if (color == true) {
//		setChar("R");
//	}
//	else {
//		setChar("r");
//	}
//}

//set<Move> Rook::getMoves(const Board& board)
//{
//	return set<Move>();
//}
//
//Queen::Queen(int r, int c, bool color)
//{
//	setLetter(QUEEN);
//	setColor(color);
//	setPos(r, c);
//	setMoved(false);
//	if (color == true) {
//		setChar("Q");
//	}
//	else {
//		setChar("q");
//	}
//}
//
//set<Move> Queen::getMoves(const Board& board)
//{
//	return set<Move>();
//}
//
//Knight::Knight(int r, int c, bool color)
//{
//	setLetter(KNIGHT);
//	setColor(color);
//	setPos(r, c);
//	setMoved(false);
//	if (color == true) {
//		setChar("N");
//	}
//	else {
//		setChar("n");
//	}
//}
//
//set<Move> Knight::getMoves(const Board& board)
//{
//	return set<Move>();
//}
//
//Bishop::Bishop(int r, int c, bool color)
//{
//	setLetter(BISHOP);
//	setColor(color);
//	setPos(r, c);
//	setMoved(false);
//	if (color == true) {
//		setChar("B");
//	}
//	else {
//		setChar("b");
//	}
//}
//
//set<Move> Bishop::getMoves(const Board& board)
//{
//	return set<Move>();
//}
//
//Space::Space(int r, int c)
//{
//	setLetter(SPACE);
//	setColor(true);
//	setPos(r, c);
//	setMoved(false);
//	setChar("");
//}
//