#include "pawn.h"

Pawn::Pawn(bool isWhite)
{
    if (isWhite)
        character = 'P';
    else
        character = 'p';
}

std::vector<Move> Pawn::getMoves(Board board)
{
    std::vector<Move> moves;
    Position posMove;
    if (isWhite())
        posMove = Position(getPosition().getLocation() + 8);
    else
        posMove = Position(getPosition().getLocation() - 8);

    if (posMove.isValid() && board[posMove] == SPACE)
    {
        Move newMove = Move();
        // get first possible move
        newMove.setSrc(getPosition());
        newMove.setDes(posMove);
        newMove.setWhiteMove(isWhite());
        // check for promotion
        if (posMove.getRow() == 7 || posMove.getRow() == 0)
            newMove.setPromote(QUEEN);
        moves.push_back(newMove);
        //get second possible move
    }
    if (getMoved() != true)
    {
        Move newMove;
        if (isWhite())
            posMove = Position(getPosition().getLocation() + 16);
        else
            posMove = Position(getPosition().getLocation() - 16);

        if (board[posMove] == SPACE)
        {
            newMove.setSrc(getPosition());
            newMove.setDes(posMove);
            newMove.setWhiteMove(isWhite());
            moves.push_back(newMove);
        }


    }
    // check captures

    for (int i = -1;
        i < 2;
        i + 2)
    {
        Move newMove;

        if (isWhite())
            posMove = Position(getPosition().getRow() + 1, getPosition().getCol() + i);
        else
            posMove = Position(getPosition().getRow() - 1, getPosition().getCol() + i);

        if (board[posMove].isValid() && board[posMove] != SPACE && board[posMove].isWhite() != isWhite())
        {
            newMove.setSrc(getPosition());
            newMove.setDes(posMove);
            newMove.setWhiteMove(isWhite());
            newMove.setCapture(board[posMove].getLetter());

            // check for promotion
            if (posMove.getRow() == 7 || posMove.getRow() == 0)
                newMove.setPromote(QUEEN);
            moves.push_back(newMove);
        }
    }

    // check en pessant
    for (int i = -1;
        i < 2;
        i + 2)
    {
        Move newMove;
        Position posKill;
        if (isWhite())
        {
            posMove = Position(getPosition().getRow() + 1, getPosition().getCol() + i);
            posKill = Position(getPosition().getRow(), getPosition().getCol() + i);
        }
        else
        {
            posMove = Position(getPosition().getRow() - 1, getPosition().getCol() + i);
            posKill = Position(getPosition().getRow(), getPosition().getCol() + i);
        }

        if (board[posMove].isValid() &&
            (posMove.getRow() == 3 && !isWhite() || posMove.getRow() == 4 && isWhite()) &&
            board[posMove] != SPACE &&
            board[posKill] == PAWN &&
            board[posKill].iswhite() != isWhite() &&
            board[posKill].getTotalMoves() == 1 &&
            board[posKill].justMoved(board.getCurrentMove()))

        {
            newMove.setSrc(getPosition());
            newMove.setDes(posMove);
            newMove.setWhiteMove(isWhite());
            newMove.setCapture(board[posMove].getLetter());
            newMove.setEnPassant();
            moves.push_back(newMove);


        }
    }


    return moves;
}

