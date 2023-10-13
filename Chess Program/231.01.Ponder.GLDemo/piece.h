#pragma once
#include "position.h"
#include "pieceType.h"
#include "board.h"
using namespace std;
#include <set>


class Piece {
private:
    PieceType letter;
    bool white;
    Position pos;
    bool moved;
    string character;
public:
    PieceType getLetter() const { return letter; }
    bool getColor() { return white; }
    Position getPos() { return pos; }
    bool getMoved() { return moved; }
    string getChar() { return character; }
    bool isWhite() const { return white; }
    void setLetter(PieceType letter);
    void setColor(bool color);
    void setPos(int r, int c);
    void setMoved(bool move) { moved = move; }
    void setChar(string symbol);
    void isMove();
    set<string> getMoves(Board board);
};

class Pawn : public Piece {
public:
    Pawn(int r, int c, bool color);
};

class King : public Piece {
public:
    King(int r, int c, bool color);
};

class Rook : public Piece {
public:
    Rook(int r, int c, bool color);
};

class Queen : public Piece {
public:
    Queen(int r, int c, bool color);
};

class Knight : public Piece {
public:
    Knight(int r, int c, bool color);
};

class Bishop : public Piece {
public:
    Bishop(int r, int c, bool color);
};

class Space : public Piece {
public:
    Space(int r, int c);
};