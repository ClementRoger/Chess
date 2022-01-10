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
	
TEST_CASE("1 : White pawn moves test") {

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
			v.x = i - 1; v.y = 6;
			REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == false );
		}
		if( i < 7 ){
			v.x = i + 1;
			REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == false );	
		}

		for (int j = 1; j < 3; ++j){
			
			v.x = i; v.y = j;
			chess.move( v , PAWN1 + i , WHITE );

			//Check move function
			REQUIRE( chess.get_piece( PAWN1 + i , WHITE ).get_x_square() == v.x );
			REQUIRE( chess.get_piece( PAWN1 + i , WHITE ).get_y_square() == v.y );

			//Eat opponent
			if( i > 1 ){
				v.x = i - 1; v.y = j - 1;
				REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == true );
			}
			if( i < 7 ){
				v.x = i + 1; v.y = j - 1;
				REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == true );	
			}
			//Cannot go up as there is an opponent in front
			v.x = i; v.y = j - 1;
			REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == false );

			//Cannot go down
			v.x = i; v.y = j + 1;
			REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == false );

			//Cannot go left nor right
			if( i < 7 ){
				v.x = i + 1; v.y = j;
				REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == false );
			}
			if( i > 1 ){
				v.x = i - 1; v.y = j;
				REQUIRE( chess.is_move_legal( v , PAWN1 + i , WHITE ) == false );
			}				
		
		}
	}	
}

TEST_CASE("2 : Black pawn moves test") {

	Chess chess;

	sf::Vector2i v;

	for (int i = 0; i < 8; ++i){
		
		//Vertical moves
		v.x = i;
		v.y = 0;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i, BLACK ) == false );
		v.y = 1;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i, BLACK ) == false );
		v.y = 2;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i, BLACK ) == true );
		v.y = 3;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i, BLACK ) == true );
		v.y = 4;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i , BLACK ) == false );
		v.y = 5;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i , BLACK ) == false );
		v.y = 6;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i, BLACK ) == false );
		v.y = 7;
		REQUIRE( chess.is_move_legal( v , PAWN1 + i, BLACK ) == false );

		//Cannot go diagonal if there is no opponent
		if( i > 1 ){
			v.x = i - 1; v.y = 2;
			REQUIRE( chess.is_move_legal( v , PAWN1 + i , BLACK ) == false );
		}
		if( i < 7 ){
			v.x = i + 1;
			REQUIRE( chess.is_move_legal( v , PAWN1 + i , BLACK ) == false );	
		}

		for (int j = 5; j < 7; ++j){
			
			v.x = i; v.y = j;
			chess.move( v , PAWN1 + i , BLACK );

			//Check move function
			REQUIRE( chess.get_piece( PAWN1 + i , BLACK ).get_x_square() == v.x );
			REQUIRE( chess.get_piece( PAWN1 + i , BLACK ).get_y_square() == v.y );

			//Eat opponent
			if( i > 1 ){
				v.x = i - 1; v.y = j + 1;
				REQUIRE( chess.is_move_legal( v , PAWN1 + i , BLACK ) == true );
			}
			if( i < 7 ){
				v.x = i + 1; v.y = j + 1;
				REQUIRE( chess.is_move_legal( v , PAWN1 + i , BLACK ) == true );	
			}
			//Cannot go up as there is an opponent in front
			v.x = i; v.y = j + 1;
			REQUIRE( chess.is_move_legal( v , PAWN1 + i , BLACK ) == false );

			//Cannot go down
			v.x = i; v.y = j - 1;
			REQUIRE( chess.is_move_legal( v , PAWN1 + i , BLACK ) == false );

			//Cannot go left nor right
			if( i < 7 ){
				v.x = i + 1; v.y = j;
				REQUIRE( chess.is_move_legal( v , PAWN1 + i , BLACK ) == false );
			}
			if( i > 1 ){
				v.x = i - 1; v.y = j;
				REQUIRE( chess.is_move_legal( v , PAWN1 + i , BLACK ) == false );
			}				
		
		}
	}	
}

TEST_CASE("3 : White king moves test") {

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

TEST_CASE("4 : Black king moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the king cannot move
	v.x = KING_STARTING_SQUARE - 1; v.y = 0;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == false );
	v.x = KING_STARTING_SQUARE + 1;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == false );
	v.x = KING_STARTING_SQUARE - 1; v.y = 1;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == false );
	v.x = KING_STARTING_SQUARE; v.y = 1;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == false );
	v.x = KING_STARTING_SQUARE + 1; v.y = 1;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == false );

	v.x = 4; v.y = 4;
	chess.move( v , KING , BLACK );
	//Check move function
	REQUIRE( chess.get_piece( KING , BLACK ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( KING , BLACK ).get_y_square() == v.y );

	//King in the middle of the chessboard, can move everywhere
	v.x = 5; v.y = 4;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == true );
	v.x = 5; v.y = 5;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == true );
	v.x = 5; v.y = 3;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == true );
	v.x = 4; v.y = 3;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == true );
	v.x = 3; v.y = 5;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == true );
	v.x = 3; v.y = 3;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == true );
	v.x = 3; v.y = 4;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == true );
	v.x = 4; v.y = 5;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == true );

	//Cannot move more than one square
	v.x = 2; v.y = 4;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == false );
	v.x = 4; v.y = 6;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == false );
	v.x = 7; v.y = 7;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == false );	
	v.x = 0; v.y = 0;
	REQUIRE( chess.is_move_legal( v , KING , BLACK ) == false );
}	

TEST_CASE("5 : White left rook moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the rook cannot move
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

	//Rook can move one square but not in diagonal
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

	//Rook can move more than one square on a colum or a row
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

TEST_CASE("6 : White right rook moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the rook cannot move
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

	//Rook can move one square but not in diagonal
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

	//Rook can move more than one square on a colum or a row
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

TEST_CASE("7 : Black left rook moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the rook cannot move
	for (int j = 1; j < 8; ++j){
		v.x = ROOK_STARTING_SQUARE; v.y = j;
		REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == false );
	}
	for (int i = 1; i < 8; ++i){
		v.x = i; v.y = 0;
		REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == false );	
	}
		
	v.x = 4; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == false );
	v.x = 6; v.y = 6;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == false );

	//Check move function
	v.x = 4; v.y = 4;
	chess.move( v , ROOK_LEFT , BLACK );
	REQUIRE( chess.get_piece( ROOK_LEFT , BLACK ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( ROOK_LEFT , BLACK ).get_y_square() == v.y );

	//Rook can move one square but not in diagonal
	v.x = 5; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == true );
	v.x = 5; v.y = 5;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == false );
	v.x = 5; v.y = 3;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == false );
	v.x = 4; v.y = 3;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == true );
	v.x = 3; v.y = 5;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == false );
	v.x = 3; v.y = 3;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == false );
	v.x = 3; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == true );
	v.x = 4; v.y = 5;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == true );

	//Rook can move more than one square on a colum or a row
	v.x = 0; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == true );
	v.x = 7; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == true );
	v.x = 4; v.y = 0;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == false ); //illegal, there is an ally piece
	v.x = 4; v.y = 7;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == false ); //same as above
	v.x = 7; v.y = 7;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == false );
	v.x = 6; v.y = 6;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == false );
	v.x = 3; v.y = 0;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == false );
	v.x = 4; v.y = 0;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == false ); //pawn between rook and queen
	v.x = 4; v.y = 6;
	REQUIRE( chess.is_move_legal( v , ROOK_LEFT , BLACK ) == true ); //can eat pawn
}	

TEST_CASE("8 : Black right rook moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the rook cannot move
	for (int j = 1; j < 8; ++j){
		v.x = ROOK_STARTING_SQUARE + 7; v.y = j;
		REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == false );
	}
	for (int i = 0; i < 7; ++i){
		v.x = i; v.y = 0;
		REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == false );	
	}
		
	v.x = 4; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == false );
	v.x = 6; v.y = 6;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == false );

	//Check move function
	v.x = 4; v.y = 4;
	chess.move( v , ROOK_RIGHT , BLACK );
	REQUIRE( chess.get_piece( ROOK_RIGHT , BLACK ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( ROOK_RIGHT , BLACK ).get_y_square() == v.y );

	//Rook can move one square but not in diagonal
	v.x = 5; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == true );
	v.x = 5; v.y = 5;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == false );
	v.x = 5; v.y = 3;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == false );
	v.x = 4; v.y = 3;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == true );
	v.x = 3; v.y = 5;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == false );
	v.x = 3; v.y = 3;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == false );
	v.x = 3; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == true );
	v.x = 4; v.y = 5;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == true );

	//Rook can move more than one square on a colum or a row
	v.x = 0; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == true );
	v.x = 7; v.y = 4;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == true );
	v.x = 4; v.y = 0;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == false ); //illegal, there is an ally piece
	v.x = 4; v.y = 7;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == false ); //same as above
	v.x = 7; v.y = 7;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == false );
	v.x = 6; v.y = 6;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == false );
	v.x = 3; v.y = 0;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == false );
	v.x = 4; v.y = 0;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == false ); //pawn between rook and queen
	v.x = 4; v.y = 6;
	REQUIRE( chess.is_move_legal( v , ROOK_RIGHT , BLACK ) == true ); //can eat pawn
}

TEST_CASE("9 : White left bishop moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the bishop cannot move
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			v.x = i; v.y = j;
			REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == false );
		}
	}

	//Check move function
	v.x = 3; v.y = 4;
	chess.move( v , BISHOP_LEFT , WHITE );
	REQUIRE( chess.get_piece( BISHOP_LEFT , WHITE ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( BISHOP_LEFT , WHITE ).get_y_square() == v.y );

	//Bishop can move in diagonal
	v.x = 2; v.y = 3;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == true );
	v.x = 1; v.y = 2;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == true );
	v.x = 0; v.y = 1;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == true ); //eat pawn
	v.x = 4; v.y = 3;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == true );
	v.x = 5; v.y = 2;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == true );
	v.x = 6; v.y = 1;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == true ); //eat pawn
	v.x = 7; v.y = 0;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == false ); //pawn between bishop and rook
	v.x = 2; v.y = 5;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == true );
	v.x = 1; v.y = 6;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == false ); //ally piece
	v.x = 0; v.y = 7;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == false ); //ally piece
	v.x = 4; v.y = 5;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == true );
	v.x = 5; v.y = 6;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == false ); //ally piece
	v.x = 6; v.y = 7;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == false ); //ally piece


	//Bishop cannot move in a row or a column
	for (int i = 0; i < 8; ++i){
		v.x = i; v.y = 4;
		REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == false );
	}
	for (int j = 0; j < 8; ++j){
		v.x = 3; v.y = j;
		REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , WHITE ) == false );
	}	
}	

TEST_CASE("10 : White right bishop moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the bishop cannot move
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			v.x = i; v.y = j;
			REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == false );
		}
	}

	//Check move function
	v.x = 4; v.y = 4;
	chess.move( v , BISHOP_RIGHT , WHITE );
	REQUIRE( chess.get_piece( BISHOP_RIGHT , WHITE ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( BISHOP_RIGHT , WHITE ).get_y_square() == v.y );

	//Bishop can move in diagonal
	v.x = 3; v.y = 3;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == true );
	v.x = 2; v.y = 2;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == true );
	v.x = 1; v.y = 1;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == true ); //eat pawn
	v.x = 0; v.y = 0;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == false ); //pawn between bishop and rook
	v.x = 5; v.y = 3;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == true );
	v.x = 6; v.y = 2;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == true );
	v.x = 7; v.y = 1;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == true ); //eat pawn
	v.x = 3; v.y = 5;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == true );
	v.x = 2; v.y = 6;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == false ); //ally piece
	v.x = 1; v.y = 7;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == false ); //ally piece
	v.x = 5; v.y = 5;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == true );
	v.x = 6; v.y = 6;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == false ); //ally piece
	v.x = 7; v.y = 7;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == false ); //ally piece


	//Bishop cannot move in a row or a column
	for (int i = 0; i < 8; ++i){
		v.x = i; v.y = 4;
		REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == false );
	}
	for (int j = 0; j < 8; ++j){
		v.x = 4; v.y = j;
		REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , WHITE ) == false );
	}	
}

TEST_CASE("11 : Black left bishop moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the bishop cannot move
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			v.x = i; v.y = j;
			REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == false );
		}
	}

	//Check move function
	v.x = 3; v.y = 4;
	chess.move( v , BISHOP_LEFT , BLACK );
	REQUIRE( chess.get_piece( BISHOP_LEFT , BLACK ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( BISHOP_LEFT , BLACK ).get_y_square() == v.y );

	//Bishop can move in diagonal
	v.x = 2; v.y = 3;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == true );
	v.x = 1; v.y = 2;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == true );
	v.x = 0; v.y = 1;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == false ); //ally piece
	v.x = 4; v.y = 3;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == true );
	v.x = 5; v.y = 2;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == true );
	v.x = 6; v.y = 1;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == false ); //ally piece
	v.x = 7; v.y = 0;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == false ); //ally piece
	v.x = 2; v.y = 5;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == true );
	v.x = 1; v.y = 6;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == true ); //eat pawn
	v.x = 0; v.y = 7;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == false ); //pawn between rook and bishop
	v.x = 4; v.y = 5;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == true );
	v.x = 5; v.y = 6;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == true ); //eat pawn
	v.x = 6; v.y = 7;
	REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == false ); //pawn between rook and bishop


	//Bishop cannot move in a row or a column
	for (int i = 0; i < 8; ++i){
		v.x = i; v.y = 4;
		REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == false );
	}
	for (int j = 0; j < 8; ++j){
		v.x = 3; v.y = j;
		REQUIRE( chess.is_move_legal( v , BISHOP_LEFT , BLACK ) == false );
	}	
}	

TEST_CASE("12 : Black right bishop moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the bishop cannot move
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			v.x = i; v.y = j;
			REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == false );
		}
	}

	//Check move function
	v.x = 4; v.y = 4;
	chess.move( v , BISHOP_RIGHT , BLACK );
	REQUIRE( chess.get_piece( BISHOP_RIGHT , BLACK ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( BISHOP_RIGHT , BLACK ).get_y_square() == v.y );

	//Bishop can move in diagonal
	v.x = 3; v.y = 3;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == true );
	v.x = 2; v.y = 2;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == true );
	v.x = 1; v.y = 1;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == false ); //ally piece
	v.x = 0; v.y = 0;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == false ); //ally piece
	v.x = 5; v.y = 3;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == true );
	v.x = 6; v.y = 2;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == true );
	v.x = 7; v.y = 1;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == false ); //ally piece
	v.x = 3; v.y = 5;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == true );
	v.x = 2; v.y = 6;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == true ); //eat pawn
	v.x = 1; v.y = 7;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == false ); //pawn between bishop and rook
	v.x = 5; v.y = 5;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == true );
	v.x = 6; v.y = 6;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == true ); //eat pawn
	v.x = 7; v.y = 7;
	REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == false ); //pawn between bishop and rook


	//Bishop cannot move in a row or a column
	for (int i = 0; i < 8; ++i){
		v.x = i; v.y = 4;
		REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == false );
	}
	for (int j = 0; j < 8; ++j){
		v.x = 4; v.y = j;
		REQUIRE( chess.is_move_legal( v , BISHOP_RIGHT , BLACK ) == false );
	}	
}

TEST_CASE("13 : White left knight moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the knight only has two moves
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			v.x = i; v.y = j;
			if( (i == 0 && j == 5) || (i == 2 && j == 5) ){	
				REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , WHITE ) == true );
			}
			else{
				REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , WHITE ) == false );	
			}	
		}
	}

	//Check move function
	v.x = 4; v.y = 4;
	chess.move( v , KNIGHT_LEFT , WHITE );
	REQUIRE( chess.get_piece( KNIGHT_LEFT , WHITE ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( KNIGHT_LEFT , WHITE ).get_y_square() == v.y );

	//Knight can move in L
	v.x = 3; v.y = 2;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , WHITE ) == true );
	v.x = 5; v.y = 2;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , WHITE ) == true );
	v.x = 6; v.y = 3;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , WHITE ) == true );
	v.x = 6; v.y = 5;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , WHITE ) == true );
	v.x = 5; v.y = 6;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , WHITE ) == false ); //ally piece
	v.x = 3; v.y = 6;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , WHITE ) == false ); //ally piece
	v.x = 2; v.y = 5;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , WHITE ) == true );
	v.x = 2; v.y = 3;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , WHITE ) == true );

	//Knight cannot move in a row or a column
	for (int i = 0; i < 8; ++i){
		v.x = i; v.y = 4;
		REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , WHITE ) == false );
	}
	for (int j = 0; j < 8; ++j){
		v.x = 4; v.y = j;
		REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , WHITE ) == false );
	}

	//Check move function
	v.x = 4; v.y = 3;
	chess.move( v , KNIGHT_LEFT , WHITE );
	REQUIRE( chess.get_piece( KNIGHT_LEFT , WHITE ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( KNIGHT_LEFT , WHITE ).get_y_square() == v.y );
	
	v.x = 3; v.y = 1;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , WHITE ) == true ); //eat
	v.x = 5; v.y = 1;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , WHITE ) == true ); //eat		
}

TEST_CASE("14 : White right knight moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the knight only has two moves
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			v.x = i; v.y = j;
			if( (i == 5 && j == 5) || (i == 7 && j == 5) ){	
				REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , WHITE ) == true );
			}
			else{
				REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , WHITE ) == false );	
			}	
		}
	}

	//Check move function
	v.x = 4; v.y = 4;
	chess.move( v , KNIGHT_RIGHT , WHITE );
	REQUIRE( chess.get_piece( KNIGHT_RIGHT , WHITE ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( KNIGHT_RIGHT , WHITE ).get_y_square() == v.y );

	//Knight can move in L
	v.x = 3; v.y = 2;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , WHITE ) == true );
	v.x = 5; v.y = 2;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , WHITE ) == true );
	v.x = 6; v.y = 3;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , WHITE ) == true );
	v.x = 6; v.y = 5;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , WHITE ) == true );
	v.x = 5; v.y = 6;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , WHITE ) == false ); //ally piece
	v.x = 3; v.y = 6;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , WHITE ) == false ); //ally piece
	v.x = 2; v.y = 5;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , WHITE ) == true );
	v.x = 2; v.y = 3;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , WHITE ) == true );

	//Knight cannot move in a row or a column
	for (int i = 0; i < 8; ++i){
		v.x = i; v.y = 4;
		REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , WHITE ) == false );
	}
	for (int j = 0; j < 8; ++j){
		v.x = 4; v.y = j;
		REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , WHITE ) == false );
	}

	//Check move function
	v.x = 4; v.y = 3;
	chess.move( v , KNIGHT_RIGHT , WHITE );
	REQUIRE( chess.get_piece( KNIGHT_RIGHT , WHITE ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( KNIGHT_RIGHT , WHITE ).get_y_square() == v.y );
	
	v.x = 3; v.y = 1;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , WHITE ) == true ); //eat
	v.x = 5; v.y = 1;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , WHITE ) == true ); //eat		
}

TEST_CASE("15 : Black left knight moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the knight only has two moves
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			v.x = i; v.y = j;
			if( (i == 0 && j == 2) || (i == 2 && j == 2) ){	
				REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , BLACK ) == true );
			}
			else{
				REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , BLACK ) == false );	
			}	
		}
	}

	//Check move function
	v.x = 3; v.y = 3;
	chess.move( v , KNIGHT_LEFT , BLACK );
	REQUIRE( chess.get_piece( KNIGHT_LEFT , BLACK ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( KNIGHT_LEFT , BLACK ).get_y_square() == v.y );

	//Knight can move in L
	v.x = 2; v.y = 1;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , BLACK ) == false ); //ally piece
	v.x = 5; v.y = 1;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , BLACK ) == false ); //ally piece
	v.x = 5; v.y = 2;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , BLACK ) == true );
	v.x = 5; v.y = 4;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , BLACK ) == true );
	v.x = 4; v.y = 5;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , BLACK ) == true );
	v.x = 2; v.y = 5;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , BLACK ) == true ); 
	v.x = 1; v.y = 4;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , BLACK ) == true );
	v.x = 1; v.y = 2;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , BLACK ) == true );

	//Knight cannot move in a row or a column
	for (int i = 0; i < 8; ++i){
		v.x = i; v.y = 3;
		REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , BLACK ) == false );
	}
	for (int j = 0; j < 8; ++j){
		v.x = 3; v.y = j;
		REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , BLACK ) == false );
	}

	//Check move function
	v.x = 4; v.y = 4;
	chess.move( v , KNIGHT_LEFT , BLACK );
	REQUIRE( chess.get_piece( KNIGHT_LEFT , BLACK ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( KNIGHT_LEFT , BLACK ).get_y_square() == v.y );
	
	v.x = 3; v.y = 6;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , BLACK ) == true ); //eat
	v.x = 5; v.y = 6;
	REQUIRE( chess.is_move_legal( v , KNIGHT_LEFT , BLACK ) == true ); //eat		
}

TEST_CASE("16 : Black right knight moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the knight only has two moves
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			v.x = i; v.y = j;
			if( (i == 5 && j == 2) || (i == 7 && j == 2) ){	
				REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , BLACK ) == true );
			}
			else{
				REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , BLACK ) == false );	
			}	
		}
	}

	//Check move function
	v.x = 3; v.y = 3;
	chess.move( v , KNIGHT_RIGHT , BLACK );
	REQUIRE( chess.get_piece( KNIGHT_RIGHT , BLACK ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( KNIGHT_RIGHT , BLACK ).get_y_square() == v.y );

	//Knight can move in L
	v.x = 2; v.y = 1;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , BLACK ) == false ); //ally piece
	v.x = 5; v.y = 1;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , BLACK ) == false ); //ally piece
	v.x = 5; v.y = 2;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , BLACK ) == true );
	v.x = 5; v.y = 4;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , BLACK ) == true );
	v.x = 4; v.y = 5;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , BLACK ) == true );
	v.x = 2; v.y = 5;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , BLACK ) == true ); 
	v.x = 1; v.y = 4;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , BLACK ) == true );
	v.x = 1; v.y = 2;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , BLACK ) == true );

	//Knight cannot move in a row or a column
	for (int i = 0; i < 8; ++i){
		v.x = i; v.y = 3;
		REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , BLACK ) == false );
	}
	for (int j = 0; j < 8; ++j){
		v.x = 3; v.y = j;
		REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , BLACK ) == false );
	}

	//Check move function
	v.x = 4; v.y = 4;
	chess.move( v , KNIGHT_RIGHT , BLACK );
	REQUIRE( chess.get_piece( KNIGHT_RIGHT , BLACK ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( KNIGHT_RIGHT , BLACK ).get_y_square() == v.y );
	
	v.x = 3; v.y = 6;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , BLACK ) == true ); //eat
	v.x = 5; v.y = 6;
	REQUIRE( chess.is_move_legal( v , KNIGHT_RIGHT , BLACK ) == true ); //eat		
}

TEST_CASE("17 : White queen moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the queen doesn't have any move
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			v.x = i; v.y = j;
			REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false );	
		}
	}

	//Check move function
	v.x = 3; v.y = 3;
	chess.move( v , QUEEN , WHITE );
	REQUIRE( chess.get_piece( QUEEN , WHITE ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( QUEEN , WHITE ).get_y_square() == v.y );

	//Queen can move in a row or a column
	for (int i = 0; i < 8; ++i){
		v.x = i; v.y = 3;
		REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == true );
	}
	for (int j = 0; j < 8; ++j){
		v.x = 3; v.y = j;
		if( j == 7 || j == 6 ){	
			REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false ); //ally piece
		}
		else if( j == 0 ){
			REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false ); //pawn between the queen and the destination	
		}
		else{
			REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == true );	
		}
	}

	//Queen can move in diagonal
	for (int i = 0; i < 8; ++i){
		v.x = i; v.y = i;

		if( i == 0 ){ //pawn between the queen and the destination
			REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false );	
		}
		else if( i == 6 || i == 7 ){ //ally piece
			REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false );
		}
		else{
			REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == true );
		}
	}

	for (int i = 0; i < 7; ++i){
		v.x = i; v.y = 6 - i;

		if( i == 6 ){ //pawn between the queen and the destination
			REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false );	
		}
		else if( i == 0 ){ //ally piece
			REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false );
		}
		else{
			REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == true );
		}
	}

	//Queen cannot move as a knight
	v.x = 2; v.y = 1;
	REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false );
	v.x = 5; v.y = 1;
	REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false );
	v.x = 5; v.y = 2;
	REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false );
	v.x = 5; v.y = 4;
	REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false );
	v.x = 4; v.y = 5;
	REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false );
	v.x = 2; v.y = 5;
	REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false ); 
	v.x = 1; v.y = 4;
	REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false );
	v.x = 1; v.y = 2;
	REQUIRE( chess.is_move_legal( v , QUEEN , WHITE ) == false );
}

TEST_CASE("18 : Black queen moves test") {

	Chess chess;
	sf::Vector2i v;

	//Beginning of the game, the queen doesn't have any move
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			v.x = i; v.y = j;
			REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == false );	
		}
	}

	//Check move function
	v.x = 3; v.y = 3;
	chess.move( v , QUEEN , BLACK );
	REQUIRE( chess.get_piece( QUEEN , BLACK ).get_x_square() == v.x );
	REQUIRE( chess.get_piece( QUEEN , BLACK ).get_y_square() == v.y );

	//Queen can move in a row or a column
	for (int i = 0; i < 8; ++i){
		v.x = i; v.y = 3;
		REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == true );
	}
	for (int j = 0; j < 8; ++j){
		v.x = 3; v.y = j;
		if( j == 1 || j == 0 ){	
			REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == false ); //ally piece
		}
		else if( j == 7 ){
			REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == false ); //pawn between the queen and the destination	
		}
		else{
			REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == true );	
		}
	}

	//Queen can move in diagonal
	for (int i = 0; i < 8; ++i){
		v.x = i; v.y = i;

		if( i == 7 ){ //pawn between the queen and the destination
			REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == false );	
		}
		else if( i == 0 || i == 1 ){ //ally piece
			REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == false );
		}
		else{
			REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == true );
		}
	}

	for (int i = 0; i < 7; ++i){
		v.x = i; v.y = 6 - i;

		if( i == 6 || i == 5 ){ //ally piece
			REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == false );
		}
		else{
			REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == true );
		}
	}

	//Queen cannot move as a knight
	v.x = 2; v.y = 1;
	REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == false );
	v.x = 5; v.y = 1;
	REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == false );
	v.x = 5; v.y = 2;
	REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == false );
	v.x = 5; v.y = 4;
	REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == false );
	v.x = 4; v.y = 5;
	REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == false );
	v.x = 2; v.y = 5;
	REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == false ); 
	v.x = 1; v.y = 4;
	REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == false );
	v.x = 1; v.y = 2;
	REQUIRE( chess.is_move_legal( v , QUEEN , BLACK ) == false );
}