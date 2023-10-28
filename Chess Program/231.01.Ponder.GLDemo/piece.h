#pragma once
//#include "pieceType.h"
//#include "board.h"
using namespace std;
#include <set>

class Piece {
public:
    // constructor and stuff
    Piece(int r, int c, bool isWhite = true) :
        fWhite(isWhite), nMoves(0), position(r, c), lastMove(-1) {}
    Piece(const Piece& piece) { *this = piece; }
    virtual ~Piece() {}
    const Piece& operator = (const Piece& rhs);
    const Piece& operator = (const Position& rhs)
    {
        nMoves++;
        position = rhs;
        return *this;
    }

    // getters
    bool operator == (char letter) const { return getLetter() == letter; }
    bool operator != (char letter) const { return getLetter() != letter; }
    bool isWhite()                 const { return fWhite;                }
    bool isMoved()                 const { return getNMoves() != 0;       }
    int  getNMoves()                const { return nMoves;                }
    const Position& getPosition()  const { return position; }
    bool justMoved(int currentMove) const
    {
        return (currentMove - 1 == lastMove);
    }

    // setter
    void setLastMove(int currentMove) { lastMove = currentMove; }

    // virtual methods
    virtual PieceType getLetter() const = 0;
    virtual void display(ogstream* pgout) const = 0;
    virtual void getMoves(set<Move>& moves, const Board& board) const = 0;


protected:
    set <Move> getMovesSlide(const Board& board,
        const Delta deltas[],
        int numDelta) const;
    //set <Move> getMovesNoslide(const Board& board,
    //    const Delta deltas[],
    //    int numDelta) const;

    int nMoves;
    bool fWhite;
    Position position;
    int lastMove;
    PieceType letter;
//private:
//    PieceType letter;
//    bool fWhite;
//    
//    bool nMoves;
//    int lastMove;
//    string character;
};

class Space : public Piece {
public:
    //Space() : Piece(){}
    Space(int r, int c) : Piece(r, c) 
    {
        letter = SPACE;
        nMoves = 0;
        fWhite = true;
        position = Position(r, c);
        lastMove = -1;
    }
    virtual PieceType getLetter() const { return letter; }
    virtual void getMoves(set <Move>& moves, const Board& board) const {}
    virtual void diplay(ogstream* pgout) const {}
};

class Pawn : public Piece {
public:
    Pawn(int r, int c, bool color) : Piece(r, c, isWhite) 
    {
        letter = PAWN;
        nMoves = 0;
        fWhite = color;
        position = Position(r, c);
        lastMove = -1;
    }
    PieceType getLetter() const { return letter; }
    void getMoves(set <Move>& moves, const Board& board) const;

    // set<Move> getMoves(const Board& board);
    virtual void diplay(ogstream* pgout) const
    {
        pgout->drawPawn(position.getLocation(), !isWhite());
    }
private:
    void addPromotion(set <Move> & moves, Move & move) const;
};

class Rook : public Piece {
public:
    Rook(int r, int c, bool color) : Piece(r, c, isWhite) 
    { 
        letter = ROOK;
        nMoves = 0;
        fWhite = color;
        position = Position(r, c);
        lastMove = -1;
    }
    PieceType getLetter() const { return letter; }
    void getMoves(set <Move>& moves, const Board& board) const;
    virtual void diplay(ogstream* pgout) const
    {
        pgout->drawRook(position.getLocation(), !isWhite());
    }

};

class King : public Piece {
public:
    King(int r, int c, bool color) : Piece(r, c, isWhite) 
    { 
        letter = KING;
        nMoves = 0;
        fWhite = color;
        position = Position(r, c);
        lastMove = -1;
    }
    PieceType getLetter() const { return letter; }
    void getMoves(set <Move>& moves, const Board& board) const;
    virtual void diplay(ogstream* pgout) const
    {
        pgout->drawKing(position.getLocation(), !isWhite());
    }
};

class Queen : public Piece {
public:
    Queen(int r, int c, bool color) : Piece(r, c, isWhite) 
    {
        letter = QUEEN;
        nMoves = 0;
        fWhite = color;
        position = Position(r, c);
        lastMove = -1;
    }
    PieceType getLetter() const { return letter; }
    void getMoves(set <Move>& moves, const Board& board) const;
    virtual void diplay(ogstream* pgout) const
    {
        pgout->drawQueen(position.getLocation(), !isWhite());
    }
};

class Knight : public Piece {
public:
    Knight(int r, int c, bool color) : Piece(r, c, isWhite) 
    {
        letter = KNIGHT;
        nMoves = 0;
        fWhite = color;
        position = Position(r, c);
        lastMove = -1;
    }
    PieceType getLetter() const { return letter; }
    void getMoves(set <Move>& moves, const Board& board) const;
    virtual void diplay(ogstream* pgout) const
    {
        pgout->drawKnight(position.getLocation(), !isWhite());
    }
};

class Bishop : public Piece {
public:
    Bishop(int r, int c, bool color) : Piece(r, c, isWhite) 
    {
        letter = BISHOP;
        nMoves = 0;
        fWhite = color;
        position = Position(r, c);
        lastMove = -1;
    }
    PieceType getLetter() const { return letter; }
    void getMoves(set <Move>& moves, const Board& board) const;
    virtual void diplay(ogstream* pgout) const
    {
        pgout->drawBishop(position.getLocation(), !isWhite());
    }
};


//PieceType getLetter() const { return letter; }
//bool getColor() { return white; }
//Position getPos() { return position; }
//bool getMoved() { return nMove; }
//string getChar() { return character; }
//bool isWhite() const { return white; }
//void setLetter(PieceType letter);
//void setColor(bool color);
//void setPos(int r, int c);
//void setMoved(bool move) { nMove = move; }
//void setChar(string symbol);
//void isMove();
//virtual set<Move> getMoves(const Board & board); // May need a constant and look into virtual 