#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Piece.hh"

class King : public Piece{

    public:

        King( bool color , std::size_t square_x , std::size_t square_y );

};