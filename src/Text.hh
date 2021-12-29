#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Text{

	public :
		Text (sf::RenderWindow& window, const std::wstring text, const size_t x, const size_t y, const size_t character_size, const sf::Color& color, const std::string font, const bool bold, const bool italic, const bool underlined, const float rotation);		
		void display (sf::RenderWindow& window);
		std::size_t get_x() {return x_text;}
		std::size_t get_y() {return y_text;}

	private :
		std::size_t x_text;
		std::size_t y_text;
		std::size_t Character_Size;
		sf::Color Text_color;
		std::string font_path;
		std::wstring Texte;
		bool Bold;
		bool Italic;
		bool Underlined;
		float Rotation;
};			