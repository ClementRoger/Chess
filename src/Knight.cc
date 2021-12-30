#include <iostream>
#include "Knight.hh"

#define WHITE_KNIGHT_PATH "../images/whiteKnight.png"
#define BLACK_KNIGHT_PATH "../images/blackKnight.png"

using namespace std; 

Knight :: Knight( bool color , std::size_t square_x , std::size_t square_y ) : Piece( color , square_x , square_y ) {
    
    std::string path;

    if( color ){ //white
        path = WHITE_KNIGHT_PATH;
    }
    else{
        path = BLACK_KNIGHT_PATH;
    }

    image_path = path; 
}