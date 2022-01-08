#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Image{

	public :
		Image (sf::RenderWindow& window, const size_t x, const size_t y, const size_t width, size_t height, std::string path);
		void display (sf::RenderWindow& window);
		std::size_t get_x() {return x_image;}
		std::size_t get_y() {return y_image;}
		std::size_t get_width() {return width_image;}
		std::size_t get_height() {return height_image;}

	private :
		std::size_t x_image;
		std::size_t y_image;
		std::size_t width_image;
		std::size_t height_image;
		std::string path_image;
};			