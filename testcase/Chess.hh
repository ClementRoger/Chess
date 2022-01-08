#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Grid.hh"
#include "Piece.hh"

#define X_WINDOW 800
#define Y_WINDOW 800
#define SQUARE_SIZE 75
#define CHESSBOARD_SIZE_X 8
#define CHESSBOARD_SIZE_Y 8

#define LATEX_FONT "../fonts/cmunss.ttf"
#define CHARACTER_SIZE 30
#define BOLD true
#define NON_ITALIC false
#define NON_UNDERLINED false
#define NO_ROTATION 0
#define HALF_REVOLUTION_ROTATION 180
#define NO_ROTATION 0

#define WHITE 1
#define BLACK 0

#define ROOK_STARTING_SQUARE 0
#define KNIGHT_STARTING_SQUARE 1
#define BISHOP_STARTING_SQUARE 2
#define QUEEN_STARTING_SQUARE 3
#define KING_STARTING_SQUARE 4

#define KING 0
#define QUEEN 1
#define ROOK_LEFT 2
#define ROOK_RIGHT 3
#define KNIGHT_LEFT 4
#define KNIGHT_RIGHT 5
#define BISHOP_LEFT 6
#define BISHOP_RIGHT 7

class Chess{

	public:

		Chess();
		void run();
		std::wstring string_to_wstring(const std::string& Str);
		void display_coordinates(sf::RenderWindow &window , Grid grid);
		void create_pieces( std::vector<Piece> &vec , bool color );
		bool is_move_legal( sf::Vector2i &square_clicked , int piece , bool color );
		int get_piece_index_from_square( std::vector<Piece> &vec , sf::Vector2i &square_clicked );
		bool is_rook_move_legal( size_t piece_x , size_t piece_y , size_t destination_x , size_t destination_y );

		int is_square_taken( size_t i , size_t j ){ return squares_taken[i][j]; }
		
		void move( sf::Vector2i &square_clicked , int piece , bool color ){
			
			if( color ){
				WhitePieces[piece].move( square_clicked );
			}
			else{
				BlackPieces[piece].move(square_clicked);
			}	
		}

		Piece get_piece( size_t n , bool color ){
			if( color ){
				return WhitePieces[n];
			}
			else{
				return BlackPieces[n];
			}
		}

	private:	

		bool play_again;
		bool win;
		bool difficulty; //True if easy, false if difficult
		bool player_color; //True if white, false if black
		int squares_taken[8][8]; //1 if white piece on it, 0 if black piece on it, -1 if no piece
		std::vector<Piece> BlackPieces;
		std::vector<Piece> WhitePieces;
};