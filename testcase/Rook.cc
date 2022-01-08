#include <iostream>
#include "Rook.hh"

#define WHITE_ROOK_PATH "../images/whiteRook.png"
#define BLACK_ROOK_PATH "../images/blackRook.png"

using namespace std; 

Rook :: Rook( bool color , std::size_t square_x , std::size_t square_y ) : Piece( color , square_x , square_y ) {
    
    std::string path;

    if( color ){ //white
        path = WHITE_ROOK_PATH;
    }
    else{
        path = BLACK_ROOK_PATH;
    }

    image_path = path; 
}