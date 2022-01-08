#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <codecvt>
#include <cstdlib>

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
    player_color = WHITE;

    create_pieces( BlackPieces , BLACK );
    create_pieces( WhitePieces , WHITE );

    for (int i = 0; i < CHESSBOARD_SIZE_X; ++i){

        squares_taken[i][0] = 0; //Black pieces
        squares_taken[i][1] = 0;
        squares_taken[i][6] = 1; //White pieces
        squares_taken[i][7] = 1;

        for (int j = 2; j < 6; ++j){
            squares_taken[i][j] = -1; //no piece
        }
    }
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

int Chess :: get_piece_index_from_square( std::vector<Piece> &vec , sf::Vector2i &square_clicked ){

    for (int i = 0; i < 2 * CHESSBOARD_SIZE_X; ++i){   
        if( (int)vec[i].get_x_square() == square_clicked.x && (int)vec[i].get_y_square() == square_clicked.y ){
            return i;
        }
    }
    return -1;            
}

bool Chess :: is_rook_move_legal( size_t piece_x , size_t piece_y , size_t destination_x , size_t destination_y ){

    if( piece_x == destination_x){
        int mul = 1;
        if( destination_y < piece_y ){
            mul = -1;
        }
            
        for (int j = 1; j < abs(destination_y - piece_y); ++j){
            if( squares_taken[piece_x][piece_y + mul * j] != -1 ){
                return false;
            }        
        }
        return true;
            
    }
    else if( piece_y == destination_y ){
        int mul = 1;
        if( destination_x < piece_x ){
            mul = -1;
        }
            
        for (int i = 1; i < abs(destination_x - piece_x); ++i){
            if( squares_taken[piece_x + mul * i][piece_y] != -1 ){
                return false;
            }           
        }
        return true;        
    }
    else{
        return false;
    }

    return false; //Avoid warning
}

bool Chess :: is_move_legal( sf::Vector2i &square_clicked , int piece , bool piece_color ){

    size_t destination_x = (size_t) square_clicked.x;
    size_t destination_y = (size_t) square_clicked.y;
    size_t piece_x , piece_y;

    if( squares_taken[destination_x][destination_y] != -1 && squares_taken[destination_x][destination_y] == piece_color ){ //If an ally piece is on the destination square
        return false;
    }

    if( piece_color ){
        piece_x = WhitePieces[piece].get_x_square();
        piece_y = WhitePieces[piece].get_y_square(); 
    }
    else{
        piece_x = BlackPieces[piece].get_x_square();
        piece_y = BlackPieces[piece].get_y_square();    
    }

    if( piece == KING ){
        if( abs( destination_x - piece_x ) > 1 || abs( destination_y - piece_y ) > 1 ){
            return false;
        }
    }
    else if( piece == QUEEN ){

    }
    else if( piece == ROOK_LEFT || piece == ROOK_RIGHT ){
        
        return  is_rook_move_legal( piece_x , piece_y , destination_x , destination_y );
    }
    else if( piece == KNIGHT_LEFT || piece == KNIGHT_RIGHT ){

    }
    else if( piece == BISHOP_LEFT || piece == BISHOP_RIGHT ) {

    }
    else{ //pawn

        if( piece_color ){

            if( abs( piece_x - destination_x ) == 1 && destination_y == (piece_y - 1) && squares_taken[destination_x][destination_y] == 0 ){
                return true; //eat
            }
            else if( piece_x == destination_x ){
                if( squares_taken[destination_x][destination_y] == -1 ){
                    if( piece_y == 6 ){
                        if( destination_y == 5 || (destination_y == 4 && squares_taken[destination_x][5] == -1) ){
                            return true;
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        if( piece_y - destination_y == 1 ){
                            return true;
                        }
                        else{
                            return false;
                        }
                    }    
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            //blacks, to do
        }
    }
    return true;
}

void Chess :: run(){

	sf::RenderWindow window(sf::VideoMode(X_WINDOW, Y_WINDOW), "Chess");
	Grid grid( CHESSBOARD_SIZE_X , CHESSBOARD_SIZE_Y , SQUARE_SIZE);
    
    bool first_click_done = false;
    int piece;
    sf::Vector2i square_clicked;

	while( window.isOpen() ){

		sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed){
                window.close();                
            }

            if (event.type == sf::Event::MouseButtonPressed){

                if( !first_click_done ){
                    
                    int x = sf::Mouse::getPosition(window).x;
                    int y = sf::Mouse::getPosition(window).y;
                    square_clicked = grid.get_square_from_coordinates( x , y );

                    if( player_color ){
                        piece = get_piece_index_from_square( WhitePieces , square_clicked );
                    }
                    else{     
                        piece = get_piece_index_from_square( BlackPieces , square_clicked );
                    }

                    if( piece != -1 ){ //if click is on a piece and that the piece is of the right color
                        first_click_done = true;
                    }
                }
                else{
                    int x = sf::Mouse::getPosition(window).x;
                    int y = sf::Mouse::getPosition(window).y;
                    square_clicked = grid.get_square_from_coordinates( x , y );

                    if( square_clicked.x != -1 && square_clicked.y != -1 ){
                        if( is_move_legal( square_clicked , piece , player_color ) ){
                            if( player_color ){
                                x = (int) WhitePieces[piece].get_x_square();
                                y = (int) WhitePieces[piece].get_y_square();
                                WhitePieces[piece].move(square_clicked);
                            }
                            else{
                                x = (int) BlackPieces[piece].get_x_square();
                                y = (int) BlackPieces[piece].get_y_square();                            
                                BlackPieces[piece].move(square_clicked);          
                            }
                            squares_taken[square_clicked.x][square_clicked.y] = player_color;
                            squares_taken[x][y] = -1;
                        }
                    }    
                    first_click_done = false;
                }    
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