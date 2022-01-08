#include <iostream>
#include "Pawn.hh"

#define WHITE_PAWN_PATH "../images/whitePawn.png"
#define BLACK_PAWN_PATH "../images/blackPawn.png"

using namespace std; 

Pawn :: Pawn( bool color , std::size_t square_x , std::size_t square_y ) : Piece( color , square_x , square_y ) {
    
    std::string path;

    if( color ){ //white
        path = WHITE_PAWN_PATH;
    }
    else{
        path = BLACK_PAWN_PATH;
    }

    image_path = path; 
}