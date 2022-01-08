#define CATCH_CONFIG_MAIN

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "catch.hpp"
#include "../src/Chess.hh"

#define KING 0
#define QUEEN 1
#define ROOK_LEFT 2
#define ROOK_RIGHT 3
#define KNIGHT_LEFT 4
#define KNIGHT_RIGHT 5
#define BISHOP_LEFT 6
#define BISHOP_RIGHT 7
#define PAWN1 8
	
TEST_CASE("1 : Pawn moves test") {

	Chess chess;

	sf::Vector2i v;

	for (int i = 0; i < 8; ++i){
		
		//Vertical moves
		v.x = i;
		v.y = 0;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i, WHITE ) == false );
		v.y = 1;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i, WHITE ) == false );
		v.y = 2;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i, WHITE ) == false );
		v.y = 3;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i, WHITE ) == false );
		v.y = 4;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == true );
		v.y = 5;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == true );
		v.y = 6;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i, WHITE ) == false );
		v.y = 7;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i, WHITE ) == false );

		//Cannot go diagonal if there is no opponent
		if( i > 1 ){
			v.x = i - 1; v.y = 1;
			REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == false );
		}
		if( i < 7 ){
			v.x = i + 1;
			REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == false );	
		}


		for (int j = 0; j < 2; ++j){
			
			v.x = i; v.y = j + 1;
			chess.move( v , PAWN1 + i , WHITE );

			//Check move function
			REQUIRE( chess.get_piece( PAWN1 + i , WHITE ).get_x_square() == v.x );
			REQUIRE( chess.get_piece( PAWN1 + i , WHITE ).get_y_square() == v.y );

			//Eat opponent
			if( i > 1 ){
				v.x = i - 1; v.y = j;
				REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == true );
			}
			if( i < 7 ){
				v.x = i + 1; v.y = j;
				REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == true );	
			}
			//Cannot go up as there is an opponent in front
			v.x = i; v.y = j;
			REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == false );
		}
	}	
}

TEST_CASE("2 : King moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the king cannot move
	v.x = KING_STARTING_SQUARE - 1; v.y = 7;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == false );
	v.x = KING_STARTING_SQUARE + 1; v.y = 7;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == false );
	v.x = KING_STARTING_SQUARE - 1; v.y = 6;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == false );
	v.x = KING_STARTING_SQUARE; v.y = 6;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == false );
	v.x = KING_STARTING_SQUARE + 1; v.y = 6;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == false );

	v.x = 4; v.y = 4;
	chess.move( v , KING , WHITE );
	//Check move function
	REQUIRE( chess.get_piece( KING , WHITE ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( KING , WHITE ).get_y_square() == v.y );

	//King in the middle of the chessboard, can move everywhere
	v.x = 5; v.y = 4;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == true );
	v.x = 5; v.y = 5;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == true );
	v.x = 5; v.y = 3;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == true );
	v.x = 4; v.y = 3;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == true );
	v.x = 3; v.y = 5;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == true );
	v.x = 3; v.y = 3;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == true );
	v.x = 3; v.y = 4;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == true );
	v.x = 4; v.y = 5;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == true );

	//Cannot move more than one square
	v.x = 2; v.y = 4;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == false );
	v.x = 4; v.y = 6;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == false );
	v.x = 7; v.y = 7;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == false );	
	v.x = 0; v.y = 0;
	REQUIRE( chess.is_move_legal( v , KING , WHITE ) == false );
}	

TEST_CASE("3 : Left rook moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the left rook cannot move
	for (int j = 1; j < 8; ++j){
		v.x = ROOK_STARTING_SQUARE; v.y = j;
		REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == false );
	}
	for (int i = 1; i < 8; ++i){
		v.x = i; v.y = 7;
		REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == false );	
	}
		
	v.x = 4; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == false );
	v.x = 6; v.y = 6;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == false );

	//Check move function
	v.x = 4; v.y = 4;
	chess.move( v , ROOK_LEFT , WHITE );
	REQUIRE( chess.get_piece( ROOK_LEFT , WHITE ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( ROOK_LEFT , WHITE ).get_y_square() == v.y );

	//Left Rook can move one square but not in diagonal
	v.x = 5; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == true );
	v.x = 5; v.y = 5;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == false );
	v.x = 5; v.y = 3;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == false );
	v.x = 4; v.y = 3;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == true );
	v.x = 3; v.y = 5;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == false );
	v.x = 3; v.y = 3;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == false );
	v.x = 3; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == true );
	v.x = 4; v.y = 5;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == true );

	//Left Rook can move more than one square on a colum or a row
	v.x = 0; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == true );
	v.x = 7; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == true );
	v.x = 4; v.y = 0;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == false ); //illegal, there is an ally piece
	v.x = 4; v.y = 7;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == false ); //same as above
	v.x = 7; v.y = 7;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == false );
	v.x = 6; v.y = 6;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == false );
	v.x = 3; v.y = 0;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == false );
	v.x = 4; v.y = 0;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == false ); //pawn between rook and queen
	v.x = 4; v.y = 1;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , WHITE ) == true ); //can eat pawn
}	

TEST_CASE("4 : Right rook moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the left rook cannot move
	for (int j = 1; j < 8; ++j){
		v.x = ROOK_STARTING_SQUARE + 7; v.y = j;
		REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == false );
	}
	for (int i = 0; i < 7; ++i){
		v.x = i; v.y = 7;
		REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == false );	
	}
		
	v.x = 4; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == false );
	v.x = 6; v.y = 6;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == false );

	//Check move function
	v.x = 4; v.y = 4;
	chess.move( v , ROOK_RIGHT , WHITE );
	REQUIRE( chess.get_piece( ROOK_RIGHT , WHITE ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( ROOK_RIGHT , WHITE ).get_y_square() == v.y );

	//Left Rook can move one square but not in diagonal
	v.x = 5; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == true );
	v.x = 5; v.y = 5;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == false );
	v.x = 5; v.y = 3;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == false );
	v.x = 4; v.y = 3;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == true );
	v.x = 3; v.y = 5;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == false );
	v.x = 3; v.y = 3;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == false );
	v.x = 3; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == true );
	v.x = 4; v.y = 5;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == true );

	//Left Rook can move more than one square on a colum or a row
	v.x = 0; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == true );
	v.x = 7; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == true );
	v.x = 4; v.y = 0;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == false ); //illegal, there is an ally piece
	v.x = 4; v.y = 7;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == false ); //same as above
	v.x = 7; v.y = 7;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == false );
	v.x = 6; v.y = 6;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == false );
	v.x = 3; v.y = 0;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == false );
	v.x = 4; v.y = 0;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == false ); //pawn between rook and queen
	v.x = 4; v.y = 1;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , WHITE ) == true ); //can eat pawn
}	