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

class Chess{

	public:

		Chess();
		void run();
		std::wstring string_to_wstring(const std::string& Str);
		void display_coordinates(sf::RenderWindow &window , Grid grid);
		void create_pieces( std::vector<Piece> &vec , bool color );

	private:	

		bool play_again;
		bool win;
		bool difficulty; //True if easy, false if difficult
};