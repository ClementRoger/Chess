#include <iostream>
#include "Queen.hh"

#define WHITE_QUEEN_PATH "../images/whiteQueen.png"
#define BLACK_QUEEN_PATH "../images/blackQueen.png"

using namespace std; 

Queen :: Queen( bool color , std::size_t square_x , std::size_t square_y ) : Piece( color , square_x , square_y ) {
    
    std::string path;

    if( color ){ //white
        path = WHITE_QUEEN_PATH;
    }
    else{
        path = BLACK_QUEEN_PATH;
    }

    image_path = path; 
}