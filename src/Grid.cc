#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <codecvt>
#include <vector>
#include <stdexcept>  // std::invalid_argument
#include <math.h>

#include "Grid.hh"
#include "Text.hh"

#define BORDER_THICKNESS 2
#define X_WINDOW 800
#define Y_WINDOW 800
#define SPACE_BETWEEN_SQUARES 0

using namespace std;

Grid :: Grid(size_t nb_x, size_t nb_y, size_t square_size) {

	Square_Size = square_size;
	nb_squares_x = nb_x;
	nb_squares_y = nb_y;
	height = nb_y * square_size + (nb_y - 1) * SPACE_BETWEEN_SQUARES + BORDER_THICKNESS;
	length = nb_x * square_size + (nb_x - 1) * SPACE_BETWEEN_SQUARES + BORDER_THICKNESS;

	for (size_t i = 0; i < nb_x; ++i) {
		for (size_t j = 0; j < nb_y; ++j){
			if( (i + j) % 2 == 0 ){
				colors_array[i][j] = 1;
			}
			else{
				colors_array[i][j] = 0;
			}
		}
	}
}	

sf::RectangleShape Grid :: draw_square(sf::RenderWindow& window, const size_t x, const size_t y, const size_t size, const sf::Color& color) {

	sf::RectangleShape square;
	square.setSize(sf::Vector2f(size, size));
	square.setOutlineColor(sf::Color::Black);
	square.setFillColor(color);
	square.setOutlineThickness(BORDER_THICKNESS);
	square.setPosition(x, y);
	window.draw(square);
	return square;
}

void Grid :: display(sf::RenderWindow& window) {

	size_t x_init = (X_WINDOW - length) / 2; 
	size_t y_init = (Y_WINDOW - height) / 2;
	
	for (size_t i = 0; i < nb_squares_x; ++i) {
		for (size_t j = 0; j < nb_squares_y; ++j) {

			sf::Color color;
			switch(colors_array[i][j]){

				case 0:
					color = sf::Color{ 30 , 30 , 30 };
					break;
				case 1:
					color = sf::Color{ 230 , 230 , 230 };
					break;		
			}
			sf::RectangleShape square = draw_square(window, x_init + i * (Square_Size + SPACE_BETWEEN_SQUARES), y_init + j * (Square_Size + SPACE_BETWEEN_SQUARES), Square_Size, color);
			rectangles_array[i][j] = square;
		}	
	}
}