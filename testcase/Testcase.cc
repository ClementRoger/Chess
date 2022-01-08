#define CATCH_CONFIG_MAIN

#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "catch.hpp"
#include "Grid.hh"
#include "Text.hh"
#include "Chess.hh"
#include "Bishop.hh"
#include "Knight.hh"
#include "Queen.hh"
#include "King.hh"
#include "Pawn.hh"
#include "Rook.hh"

#define KING 0
#define QUEEN 1
#define ROOK_LEFT 2
#define ROOK_RIGHT 3
#define KNIGHT_LEFT 4
#define KNIGHT_RIGHT 5
#define BISHOP_LEFT 6
#define BISHOP_RIGHT 7
#define PAWN1 8
	
TEST_CASE("1 : Pawn move test") {

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