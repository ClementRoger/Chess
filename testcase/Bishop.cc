#include <iostream>
#include "Bishop.hh"

#define WHITE_BISHOP_PATH "../images/whiteBishop.png"
#define BLACK_BISHOP_PATH "../images/blackBishop.png"

using namespace std; 

Bishop :: Bishop( bool color , std::size_t square_x , std::size_t square_y ) : Piece( color , square_x , square_y ) {
    
    std::string path;

    if( color ){ //white
        path = WHITE_BISHOP_PATH;
    }
    else{
        path = BLACK_BISHOP_PATH;
    }

    image_path = path; 
}