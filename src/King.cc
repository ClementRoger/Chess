#include <iostream>
#include "King.hh"

#define WHITE_KING_PATH "../images/whiteKing.png"
#define BLACK_KING_PATH "../images/blackKing.png"

using namespace std; 

King :: King( bool color , std::size_t square_x , std::size_t square_y ) : Piece( color , square_x , square_y ) {
    
    std::string path;

    if( color ){ //white
        path = WHITE_KING_PATH;
    }
    else{
        path = BLACK_KING_PATH;
    }

    image_path = path; 
}