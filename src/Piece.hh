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
		void move( sf::Vector2i& pos );
		
		size_t get_x_square(){ return square_x; }
		size_t get_y_square(){ return square_y; }
		bool get_color(){ return color; }

	private:	

		bool color; //True if white, false if black
	
	protected:

		std::string image_path;
		size_t square_x;
		size_t square_y;	
		bool is_alive;
};;