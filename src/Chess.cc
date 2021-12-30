#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <codecvt>

#include "Grid.hh"
#include "Text.hh"
#include "Chess.hh"
#include "Bishop.hh"
#include "Knight.hh"
#include "Queen.hh"
#include "King.hh"
#include "Pawn.hh"
#include "Rook.hh"

Chess :: Chess(){

	play_again = false;
    win = false;
    difficulty = false;
}

std::wstring Chess :: string_to_wstring(const std::string& Str) {

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
    return conv.from_bytes(Str);
}

void Chess :: display_coordinates(sf::RenderWindow &window , Grid grid){

	sf::Color color = sf::Color{ 3 , 34 , 160 }; //Dark blue

	for (int i = 0; i < CHESSBOARD_SIZE_X; ++i){ //Letters of the bottom of the chessboard
        char letter = 'A' + i;
        Text text( window , string_to_wstring( std::string(1 , letter) ) , grid.get_rectangle( i , CHESSBOARD_SIZE_Y - 1 ).getPosition().x + SQUARE_SIZE / 2 , grid.get_rectangle( i , CHESSBOARD_SIZE_Y - 1 ).getPosition().y + 1.5 * SQUARE_SIZE , CHARACTER_SIZE , color , LATEX_FONT , BOLD , NON_ITALIC , NON_UNDERLINED , NO_ROTATION );
        text.display(window);
    }

	for (int i = 0; i < CHESSBOARD_SIZE_X; ++i){ //Letters of the top of the chessboard
        char letter = 'A' + i;
        Text text( window , string_to_wstring( std::string(1 , letter) ) , grid.get_rectangle( i , 0 ).getPosition().x + SQUARE_SIZE / 2 , grid.get_rectangle( i , 0 ).getPosition().y - SQUARE_SIZE / 2, CHARACTER_SIZE , color , LATEX_FONT , BOLD , NON_ITALIC , NON_UNDERLINED , HALF_REVOLUTION_ROTATION );
        text.display(window);
    }

    for (int i = 0; i < CHESSBOARD_SIZE_Y; ++i){ //Digits of the left side of the chessboard
     	Text text( window , string_to_wstring( std::to_string(CHESSBOARD_SIZE_Y - i) ) , grid.get_rectangle( 0 , i ).getPosition().x - SQUARE_SIZE / 2 , grid.get_rectangle( 0 , i ).getPosition().y + SQUARE_SIZE / 2, CHARACTER_SIZE , color , LATEX_FONT , BOLD , NON_ITALIC , NON_UNDERLINED , NO_ROTATION );
        text.display(window);  	
    }
    
    for (int i = 0; i < CHESSBOARD_SIZE_Y; ++i){ //Digits of the right side of the chessboard
     	Text text( window , string_to_wstring( std::to_string(CHESSBOARD_SIZE_Y - i) ) , grid.get_rectangle( CHESSBOARD_SIZE_Y - 1 , i ).getPosition().x + 1.5 * SQUARE_SIZE , grid.get_rectangle( CHESSBOARD_SIZE_Y - 1 , i ).getPosition().y + SQUARE_SIZE / 2, CHARACTER_SIZE , color , LATEX_FONT , BOLD , NON_ITALIC , NON_UNDERLINED , HALF_REVOLUTION_ROTATION );
        text.display(window);  	
    }
} 

void Chess :: create_pieces( std::vector<Piece> &vec , bool color ){

    std::size_t j_pawns;
    int delta;

    if( color == WHITE ){
        j_pawns = 6; //white pawns are on the fifth row
        delta = 1;
    }
    else{
        j_pawns = 1;  //black pawns are on the second row
        delta = -1;
    }

    King king( color , KING_STARTING_SQUARE , j_pawns + delta );
    vec.push_back( king );
    Queen queen( color , QUEEN_STARTING_SQUARE , j_pawns + delta );
    vec.push_back( queen );
    Rook rook_left( color , ROOK_STARTING_SQUARE , j_pawns + delta );
    vec.push_back( rook_left );
    Rook rook_right( color , CHESSBOARD_SIZE_X - ROOK_STARTING_SQUARE - 1 , j_pawns + delta );
    vec.push_back( rook_right );
    Knight knight_left( color , KNIGHT_STARTING_SQUARE , j_pawns + delta );
    vec.push_back( knight_left );
    Knight knight_right( color , CHESSBOARD_SIZE_X - KNIGHT_STARTING_SQUARE - 1 , j_pawns + delta );
    vec.push_back( knight_right );
    Bishop bishop_left( color , BISHOP_STARTING_SQUARE , j_pawns + delta );
    vec.push_back( bishop_left );
    Bishop bishop_right( color , CHESSBOARD_SIZE_X - BISHOP_STARTING_SQUARE - 1 , j_pawns + delta );
    vec.push_back( bishop_right );

    for (int i = 0; i < CHESSBOARD_SIZE_X; ++i){
        Pawn pawn( color , i , j_pawns );
        vec.push_back( pawn );
    }
}

void Chess :: run(){

	sf::RenderWindow window(sf::VideoMode(X_WINDOW, Y_WINDOW), "Chess");
	Grid grid( CHESSBOARD_SIZE_X , CHESSBOARD_SIZE_Y , SQUARE_SIZE);

    std::vector<Piece> BlackPieces;
    create_pieces( BlackPieces , BLACK );
    std::vector<Piece> WhitePieces;
    create_pieces( WhitePieces , WHITE );

	while( window.isOpen() ){

		sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed){
                window.close();                
            } 
        }
        window.clear(sf::Color::White);
		grid.display(window);
		display_coordinates(window , grid);
        
        for( Piece p : BlackPieces ){
            p.display(window , grid);
        }
        for( Piece p : WhitePieces ){
            p.display(window , grid);
        }    
		
        window.display();
	}
} 