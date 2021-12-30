#include <iostream>

#include "Piece.hh"
#include "Chess.hh"

using namespace std; 

Piece :: Piece( bool Color , std::size_t Square_x , std::size_t Square_y ) {
    
    color = Color;
    square_x = Square_x;
    square_y = Square_y;
	is_alive = true;
}

void Piece :: display( sf::RenderWindow &window , Grid grid ){

    std::size_t x = grid.get_rectangle( square_x , square_y ).getPosition().x + SQUARE_SIZE / 2;
    std::size_t y = grid.get_rectangle( square_x , square_y ).getPosition().y + SQUARE_SIZE / 2;

    Image piece( window , x , y , WIDTH , HEIGHT , image_path );
    piece.display( window );
}