#include "knight.h"

Knight::Knight(bool isWhite)
{
    if (isWhite)
        character = 'N';
    else
        character = 'n';
}

std::vector<Move> Knight::getMoves(Board board)
{
    std::vector<Move> moves;
    Position posMove;
    Position posMove2;
    Position posMove3;
    Position posMove4;
    Position posMove5;
    Position posMove6;
    Position posMove7;
    Position posMove8;
    Move newMove = Move();
    Move newMove2 = Move();
    Move newMove3 = Move();
    Move newMove4 = Move();
    Move newMove5 = Move();
    Move newMove6 = Move();
    Move newMove7 = Move();
    Move newMove8 = Move();
    //Knights move forward or backward 2 spaces and to the left or right by 1
    //alternatively they can move to the left or right by 2 spaces then forward or backward 1
    if (Position(getPosition().getRow() + 2, getPosition().getCol() + 1).isValid())
        posMove = Position(getPosition().getRow() + 2, getPosition().getCol() + 1);
        // get first possible move
        newMove.setSrc(getPosition());
        newMove.setDes(posMove);
        newMove.setWhiteMove(isWhite());
        //checks for capture
        if (board[posMove] != ' ' && board[posMove].isWhite() != isWhite()) {
            newMove.setCapture(board[posMove].getLetter());
        }
    if (Position(getPosition().getRow() + 2, getPosition().getCol() - 1).isValid())
        posMove2 = Position(getPosition().getRow() + 2, getPosition().getCol() - 1);
        // get second possible move
        newMove2.setSrc(getPosition());
        newMove2.setDes(posMove);
        newMove2.setWhiteMove(isWhite());
        if (board[posMove2] != ' ' && board[posMove2].isWhite() != isWhite()) {
            newMove2.setCapture(board[posMove2].getLetter());
        }
    if (Position(getPosition().getRow() + 1, getPosition().getCol() + 2).isValid())
        posMove3 = Position(getPosition().getRow() + 1, getPosition().getCol() + 2);
        // get first possible move
        newMove3.setSrc(getPosition());
        newMove3.setDes(posMove);
        newMove3.setWhiteMove(isWhite());
        if (board[posMove3] != ' ' && board[posMove3].isWhite() != isWhite()) {
            newMove3.setCapture(board[posMove3].getLetter());
        }
    if (Position(getPosition().getRow() + 1, getPosition().getCol() - 2).isValid())
        posMove4 = Position(getPosition().getRow() + 1, getPosition().getCol() - 2);
        // get first possible move
        newMove4.setSrc(getPosition());
        newMove4.setDes(posMove);
        newMove4.setWhiteMove(isWhite());
        if (board[posMove4] != ' ' && board[posMove4].isWhite() != isWhite()) {
            newMove4.setCapture(board[posMove4].getLetter());
        }
    if (Position(getPosition().getRow() - 1, getPosition().getCol() + 2).isValid())
        posMove5 = Position(getPosition().getRow() - 1, getPosition().getCol() + 2);
        // get first possible move
        newMove5.setSrc(getPosition());
        newMove5.setDes(posMove);
        newMove5.setWhiteMove(isWhite());
        if (board[posMove5] != ' ' && board[posMove5].isWhite() != isWhite()) {
            newMove5.setCapture(board[posMove5].getLetter());
        }
    if (Position(getPosition().getRow() - 1, getPosition().getCol() - 2).isValid())
        posMove6 = Position(getPosition().getRow() - 1, getPosition().getCol() - 2);
        // get first possible move
        newMove6.setSrc(getPosition());
        newMove6.setDes(posMove);
        newMove6.setWhiteMove(isWhite());
        if (board[posMove6] != ' ' && board[posMove6].isWhite() != isWhite()) {
            newMove6.setCapture(board[posMove6].getLetter());
        }
    if (Position(getPosition().getRow() - 2, getPosition().getCol() + 1).isValid())
        posMove7 = Position(getPosition().getRow() - 2, getPosition().getCol() + 1);
        // get first possible move
        newMove7.setSrc(getPosition());
        newMove7.setDes(posMove);
        newMove7.setWhiteMove(isWhite());
        if (board[posMove7] != ' ' && board[posMove7].isWhite() != isWhite()) {
            newMove7.setCapture(board[posMove7].getLetter());
        }
    if (Position(getPosition().getRow() - 2, getPosition().getCol() - 1).isValid())
        posMove8 = Position(getPosition().getRow() - 2, getPosition().getCol() - 1);
        // get first possible move
        newMove8.setSrc(getPosition());
        newMove8.setDes(posMove);
        newMove8.setWhiteMove(isWhite());
        if (board[posMove8] != ' ' && board[posMove8].isWhite() != isWhite()) {
            newMove8.setCapture(board[posMove8].getLetter());
        }
    return moves;
}