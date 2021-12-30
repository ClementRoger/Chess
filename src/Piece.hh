#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Image.hh"
#include "Grid.hh"

#define WIDTH 65
#define HEIGHT 65

class Piece{

	public:

		Piece( bool color , std::size_t square_x , std::size_t square_y );
		void display( sf::RenderWindow &window , Grid grid );
		void set_x( size_t x ){ square_x = x; }
		void set_y( size_t y ){ square_y = y; }

	private:	

		bool color; //True if white, false if black
	
	protected:

		std::string image_path;
		size_t square_x;
		size_t square_y;	
		bool is_alive;
};;