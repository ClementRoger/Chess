#pragma once 
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Grid.hh"

class Chess{

	public:

		Chess();
		void run();
		std::wstring string_to_wstring(const std::string& Str);
		void display_coordinates(sf::RenderWindow &window , Grid grid);

	private:	

		bool play_again;
		bool win;
		bool difficulty; //True if easy, false if difficult
};