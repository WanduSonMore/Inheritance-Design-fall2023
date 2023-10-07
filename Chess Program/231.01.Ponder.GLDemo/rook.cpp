#include "rook.h"
using namespace std;

Rook::Rook(bool isWhite)
{
    if (isWhite)
        character = 'R';
    else
        character = 'r';
}

std::vector<Move> Rook::getMoves(Board board)
{
    std::vector<Move> moves;
    std::vector<Move> moves;
    Position posMove;
    Position posMove2;
    Position posMove3;
    Position posMove4;
    Position posMove5;
    Position posMove6;
    Position posMove7;
    Position posMove8;
    Position posMove9;
    Position posMove10;
    Position posMove11;
    Position posMove12;
    Position posMove13;
    Position posMove14;
    Position posMove15;
    Position posMove16;
    Move newMove = Move();
    Move newMove2 = Move();
    Move newMove3 = Move();
    Move newMove4 = Move();
    Move newMove5 = Move();
    Move newMove6 = Move();
    Move newMove7 = Move();
    Move newMove8 = Move();
    Move newMove9 = Move();
    Move newMove10 = Move();
    Move newMove11 = Move();
    Move newMove12 = Move();
    Move newMove13 = Move();
    Move newMove14 = Move();
    Move newMove15 = Move();
    Move newMove16 = Move();
    int row = getPosition().getRow();
    int col = getPosition().getCol();
    int x1 = 0 - row;
    int y1 = 0 - col;
    int x2 = 1 - row;
    int y2 = 1 - col;
    int x3 = 2 - row;
    int y3 = 2 - col;
    int x4 = 3 - row;
    int y4 = 3 - col;
    int x5 = 4 - row;
    int y5 = 4 - col;
    int x6 = 5 - row;
    int y6 = 5 - col;
    int x7 = 6 - row;
    int y7 = 6 - col;
    int x8 = 7 - row;
    int y8 = 7 - col;
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow() + x1, getPosition().getCol()).isValid() && x1 != 0) {
        //if the statement is successful then it sets the posMove
        posMove = Position(getPosition().getRow() + x1, getPosition().getCol());
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove] = " ") {
            newMove.setSrc(getPosition());
            newMove.setDes(posMove);
            newMove.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove1] != " " && board[posMove1].isWhite() != isWhite()) {
            newMove.setSrc(getPosition());
            newMove.setDes(posMove);
            newMove.setWhiteMove(isWhite());
            newMove.setCapture(board[posMove1].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow() + x2, getPosition().getCol()).isValid() && x2 != 0) {
        //if the statement is successful then it sets the posMove
        posMove2 = Position(getPosition().getRow() + x2, getPosition().getCol());
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove2] = " ") {
            newMove2.setSrc(getPosition());
            newMove2.setDes(posMove);
            newMove2.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove2] != " " && board[posMove2].isWhite() != isWhite()) {
            newMove2.setSrc(getPosition());
            newMove2.setDes(posMove);
            newMove2.setWhiteMove(isWhite());
            newMove2.setCapture(board[posMove2].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow() + x3, getPosition().getCol()).isValid() && x3 != 0) {
        //if the statement is successful then it sets the posMove
        posMove3 = Position(getPosition().getRow() + x3, getPosition().getCol());
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove3] = " ") {
            newMove3.setSrc(getPosition());
            newMove3.setDes(posMove);
            newMove3.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove3] != " " && board[posMove3].isWhite() != isWhite()) {
            newMove3.setSrc(getPosition());
            newMove3.setDes(posMove);
            newMove3.setWhiteMove(isWhite());
            newMove3.setCapture(board[posMove3].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow() + x4, getPosition().getCol()).isValid() && x4 != 0) {
        //if the statement is successful then it sets the posMove
        posMove4 = Position(getPosition().getRow() + x4, getPosition().getCol());
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove4] = " ") {
            newMove4.setSrc(getPosition());
            newMove4.setDes(posMove);
            newMove4.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove4] != " " && board[posMove4].isWhite() != isWhite()) {
            newMove4.setSrc(getPosition());
            newMove4.setDes(posMove);
            newMove4.setWhiteMove(isWhite());
            newMove4.setCapture(board[posMove4].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow() + x5, getPosition().getCol()).isValid() && x5 != 0) {
        //if the statement is successful then it sets the posMove
        posMove5 = Position(getPosition().getRow() + x5, getPosition().getCol());
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove5] = " ") {
            newMove5.setSrc(getPosition());
            newMove5.setDes(posMove);
            newMove5.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove5] != " " && board[posMove5].isWhite() != isWhite()) {
            newMove5.setSrc(getPosition());
            newMove5.setDes(posMove);
            newMove5.setWhiteMove(isWhite());
            newMove5.setCapture(board[posMove5].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow() + x6, getPosition().getCol()).isValid() && x6 != 0) {
        //if the statement is successful then it sets the posMove
        posMove6 = Position(getPosition().getRow() + x6, getPosition().getCol());
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove6] = " ") {
            newMove6.setSrc(getPosition());
            newMove6.setDes(posMove);
            newMove6.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove6] != " " && board[posMove6].isWhite() != isWhite()) {
            newMove6.setSrc(getPosition());
            newMove6.setDes(posMove);
            newMove6.setWhiteMove(isWhite());
            newMove6.setCapture(board[posMove6].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow() + x7, getPosition().getCol()).isValid() && x7 != 0) {
        //if the statement is successful then it sets the posMove
        posMove7 = Position(getPosition().getRow() + x7, getPosition().getCol());
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove7] = " ") {
            newMove7.setSrc(getPosition());
            newMove7.setDes(posMove);
            newMove7.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove7] != " " && board[posMove7].isWhite() != isWhite()) {
            newMove7.setSrc(getPosition());
            newMove7.setDes(posMove);
            newMove7.setWhiteMove(isWhite());
            newMove7.setCapture(board[posMove7].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow() + x8, getPosition().getCol()).isValid() && x8 != 0) {
        //if the statement is successful then it sets the posMove
        posMove8 = Position(getPosition().getRow() + x8, getPosition().getCol());
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove8] = " ") {
            newMove8.setSrc(getPosition());
            newMove8.setDes(posMove);
            newMove8.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove8] != " " && board[posMove8].isWhite() != isWhite()) {
            newMove8.setSrc(getPosition());
            newMove8.setDes(posMove);
            newMove8.setWhiteMove(isWhite());
            newMove8.setCapture(board[posMove8].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow(), getPosition().getCol() + y1).isValid() && y1 != 0) {
        //if the statement is successful then it sets the posMove
        posMove9 = Position(getPosition().getRow(), getPosition().getCol() + y1);
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove9] = " ") {
            newMove9.setSrc(getPosition());
            newMove9.setDes(posMove);
            newMove9.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove9] != " " && board[posMove9].isWhite() != isWhite()) {
            newMove9.setSrc(getPosition());
            newMove9.setDes(posMove);
            newMove9.setWhiteMove(isWhite());
            newMove9.setCapture(board[posMove9].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow(), getPosition().getCol() + y2).isValid() && y2 != 0) {
        //if the statement is successful then it sets the posMove
        posMove10 = Position(getPosition().getRow(), getPosition().getCol() + y2);
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove10] = " ") {
            newMove10.setSrc(getPosition());
            newMove10.setDes(posMove);
            newMove10.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove10] != " " && board[posMove10].isWhite() != isWhite()) {
            newMove10.setSrc(getPosition());
            newMove10.setDes(posMove);
            newMove10.setWhiteMove(isWhite());
            newMove10.setCapture(board[posMove10].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow(), getPosition().getCol() + y3).isValid() && y3 != 0) {
        //if the statement is successful then it sets the posMove
        posMove11 = Position(getPosition().getRow(), getPosition().getCol() + y3);
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove11] = " ") {
            newMove11.setSrc(getPosition());
            newMove11.setDes(posMove);
            newMove11.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove11] != " " && board[posMove11].isWhite() != isWhite()) {
            newMove11.setSrc(getPosition());
            newMove11.setDes(posMove);
            newMove11.setWhiteMove(isWhite());
            newMove11.setCapture(board[posMove11].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow(), getPosition().getCol() + y4).isValid() && y4 != 0) {
        //if the statement is successful then it sets the posMove
        posMove12 = Position(getPosition().getRow(), getPosition().getCol() + y4);
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove12] = " ") {
            newMove12.setSrc(getPosition());
            newMove12.setDes(posMove);
            newMove12.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove12] != " " && board[posMove12].isWhite() != isWhite()) {
            newMove12.setSrc(getPosition());
            newMove12.setDes(posMove);
            newMove12.setWhiteMove(isWhite());
            newMove12.setCapture(board[posMove12].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow(), getPosition().getCol() + y5).isValid() && y5 != 0) {
        //if the statement is successful then it sets the posMove
        posMove13 = Position(getPosition().getRow(), getPosition().getCol() + y5);
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove13] = " ") {
            newMove13.setSrc(getPosition());
            newMove13.setDes(posMove);
            newMove13.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove13] != " " && board[posMove13].isWhite() != isWhite()) {
            newMove13.setSrc(getPosition());
            newMove13.setDes(posMove);
            newMove13.setWhiteMove(isWhite());
            newMove13.setCapture(board[posMove13].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow(), getPosition().getCol() + y6).isValid() && y6 != 0) {
        //if the statement is successful then it sets the posMove
        posMove14 = Position(getPosition().getRow(), getPosition().getCol() + y6);
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove14] = " ") {
            newMove14.setSrc(getPosition());
            newMove14.setDes(posMove);
            newMove14.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove14] != " " && board[posMove14].isWhite() != isWhite()) {
            newMove14.setSrc(getPosition());
            newMove14.setDes(posMove);
            newMove14.setWhiteMove(isWhite());
            newMove14.setCapture(board[posMove14].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow(), getPosition().getCol() + y7).isValid() && y7 != 0) {
        //if the statement is successful then it sets the posMove
        posMove15 = Position(getPosition().getRow(), getPosition().getCol() + y7);
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove15] = " ") {
            newMove15.setSrc(getPosition());
            newMove15.setDes(posMove);
            newMove15.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if (board[posMove15] != " " && board[posMove15].isWhite() != isWhite()) {
            newMove15.setSrc(getPosition());
            newMove15.setDes(posMove);
            newMove15.setWhiteMove(isWhite());
            newMove15.setCapture(board[posMove15].getLetter());
        }
    }
    //Tests if the first Possible Move is valid and if it's the same position as the rook
    if (Position(getPosition().getRow(), getPosition().getCol() + y8).isValid() && y8 != 0) {
        //if the statement is successful then it sets the posMove
        posMove16 = Position(getPosition().getRow(), getPosition().getCol() + y8);
        //tests if the new spot is open, if it is then it sets a newMove
        if (board[posMove16] = " ") {
            newMove16.setSrc(getPosition());
            newMove16.setDes(posMove);
            newMove16.setWhiteMove(isWhite());
        }
        //If the previous if statement doesn't work then this tests if the spot isn't open and if the piece in the spot 
        //is of the opposite color. If its all true it sets the newMove with capture
        else if(board[posMove16] != " " && board[posMove16].isWhite() != isWhite()) {
            newMove16.setSrc(getPosition());
            newMove16.setDes(posMove);
            newMove16.setWhiteMove(isWhite());
            newMove16.setCapture(board[posMove16].getLetter());
        }
    }
    return moves;
}