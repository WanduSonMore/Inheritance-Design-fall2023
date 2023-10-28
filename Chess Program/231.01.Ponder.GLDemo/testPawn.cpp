//#include "testPawn.h"
//#include <cassert>
//#include <set>
//#include <string>
//
////positions
//
////  A  B  C  D  E  F  G  H
////8 56 57 58 59 60 61 62 63
////7 48 49 50 51 52 53 54 55
////6 40 41 42 43 44 45 46 47
////5 32 33 34 35 36 37 38 39
////4 24 25 26 27 28 29 30 31
////3 16 17 18 19 20 21 22 23
////2 8  9  10 11 12 13 14 15
////1 0  1  2  3  4  5  6  7
//
//// A = 0 B = 1 C = 2 D = 3 E = 4 F = 5 G = 6 H = 7
//// The numbers will be one less than their value.
//
//void testPawn::getBlocked()
//{
//	// SETUP
//	// white pawn position d4
//	board.setPlace(3, 3, new Pawn(3, 3, true));
//	// black pawn position d5
//	board.setPlace(4, 3, new Pawn(4, 3, false));
//	// EXERCISE
//	bool no_moves = board.getPiece(3, 3).getMoves(board).empty();
//	// VERIFY
//	assert(no_moves == true);
//	// TEARDOWN
//	board.resetBlank();
//}   
//
//void testPawn::getSimpleMove()
//{
//	// SETUP
//	// white pawn position b4
//	board.setPlace(3, 1, new Pawn(3, 1, true));
//	board.getPiece(3, 1).isMove();
//	// EXERCISE
//	set<string> move;
//	move = board.getPiece(3, 1).getMoves(board);
//	// VERIFY
//	assert(move.find("b4b5") != move.end());
//	// TEARDOWN
//	board.resetBlank();
//} 
//
//void testPawn::getInitialMove()
//{
//	// SETUP
//	// white pawn position b2
//	board.setPlace(1, 1, new Pawn(1, 1, true));
//	// EXERCISE
//	set<string> move;
//	move = board.getPiece(1, 1).getMoves(board);
//	// VERIFY
//	assert(move.find("b2b3") != move.end());
//	assert(move.find("b2b4") != move.end());
//	// TEARDOWN
//	board.resetBlank();
//}   
//
//void testPawn::getCapture()
//{
//	// SETUP
//	// white pawn position b6
//	board.setPlace(5, 1, new Pawn(5, 1, true));
//	// black pawns positions a7, b7, and c7 
//	board.setPlace(6, 0, new Pawn(6, 0, false));
//	board.setPlace(6, 1, new Pawn(6, 1, false));
//	board.setPlace(6, 2, new Pawn(6, 2, false));
//	// EXERCISE
//	set<string> move;
//	move = board.getPiece(5, 1).getMoves(board);
//	// VERIFY
//	assert(move.find("b6a7p") != move.end());
//	assert(move.find("b6c7p") != move.end());
//	// TEARDOWN
//	board.resetBlank();
//}  
//
//void testPawn::getEnpassant()
//{
//	// SETUP
//	// white pawn position b5
//	board.setPlace(4, 1, new Pawn(4, 1, true));
//	// black pawns position b6
//	board.setPlace(5, 0, new Pawn(5, 0, false));
//	// black pawns positions a6 and c6, each one made 1 move
//	board.getPiece(5, 0).isMove();
//	board.setPlace(5, 2, new Pawn(5, 2, false));
//	board.getPiece(5, 2).isMove();
//	board.setPlace(5, 1, new Pawn(5, 1, false));
//	// EXERCISE
//	set<string> move;
//	move = board.getPiece(3, 1).getMoves(board);
//	// VERIFY
//	assert(move.find("b5c6E") != move.end());
//	assert(move.find("b5a6E") != move.end());
//	// TEARDOWN
//	board.resetBlank();
//}  
//
//void testPawn::getPromotion()
//{
//	// SETUP
//	// white pawn position b7
//	board.setPlace(1, 1, new Pawn(1, 1, true));
//	// EXERCISE
//	bool has_move = board.getPiece(1, 1).getMoves(board).find("b7b8Q") != board.getPiece(1, 1).getMoves(board).end();
//	// VERIFY
//	assert(has_move == true);
//	// TEARDOWN
//	board.resetBlank();
//}  
