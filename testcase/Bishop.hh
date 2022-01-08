#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Piece.hh"

class Bishop : public Piece{

	public:

		Bishop( bool color , std::size_t square_x , std::size_t square_y );

};