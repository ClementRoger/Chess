#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Grid{

	public:

		Grid(size_t nb_x, size_t nb_y, size_t square_size);
		sf::RectangleShape draw_square(sf::RenderWindow& window, const size_t x, const size_t y, const size_t size, const sf::Color& color);
		void display(sf::RenderWindow& window);

		sf::RectangleShape get_rectangle( size_t i , size_t j ){ return rectangles_array[i][j]; }

	private:	

		size_t Square_Size;
		size_t height;
		size_t length;
		size_t nb_squares_x;
		size_t nb_squares_y;
		sf::RectangleShape rectangles_array[8][8];
		int colors_array[8][8];
};		