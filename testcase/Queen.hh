#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Piece.hh"

class Queen : public Piece{

    public:

        Queen( bool color , std::size_t square_x , std::size_t square_y );

};