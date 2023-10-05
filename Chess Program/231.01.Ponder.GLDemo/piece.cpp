#include "piece.h"



std::vector<Move> Piece::getMovesSlide(Board board, std::vector<Position> delta)
{
    std::vector<Move> moves;
    for (int i = 0;
        i < delta.size();
        i++)
    {
        Position posMove = delta[i];

        while (posMove.isValid() && board[posMove] == SPACE)
        {
            Move newMove = Move();
            newMove.setSrc(pos);
            newMove.setDes(posMove);
            newMove.setWhiteMove(isWhite());
            moves.push_back(newMove);
        }
        if (posMove.isValid() && (board[posMove].isWhite() != isWhite() || board[posMove] == SPACE))
        {
            Move newMove = Move();
            newMove.setSrc(pos);
            newMove.setDes(posMove);
            newMove.setWhiteMove(isWhite());
            if (board[posMove] != SPACE)\
                newMove.setCapture(board[posMove].getLetter);
            moves.push_back(newMove);

        }
    }
    return moves;
}

bool Piece::isWhite()
{
    if (islower(character))
        return true;
    else
        return false;
}

bool Piece::justMoved(Move currentMove)
{
    return true;
}


Position Piece::getPosition()
{
    return pos;
}

int Piece::getTotalMoves()
{
    return moves;
}

void Piece::setMoved()
{
    moves += 1;
}
