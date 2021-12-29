#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <codecvt>

#include "Grid.hh"
#include "Text.hh"
#include "Chess.hh"

#define X_WINDOW 800
#define Y_WINDOW 800
#define SQUARE_SIZE 75
#define CHESSBOARD_SIZE_X 8
#define CHESSBOARD_SIZE_Y 8
#define LATEX_FONT "../fonts/cmunss.ttf"
#define CHARACTER_SIZE 30
#define BOLD true
#define NON_ITALIC false
#define NON_UNDERLINED false
#define NO_ROTATION 0
#define HALF_REVOLUTION_ROTATION 180
#define NO_ROTATION 0

Chess :: Chess(){

	play_again = false;
    win = false;
    difficulty = false;
}

std::wstring Chess :: string_to_wstring(const std::string& Str) {

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> conv;
    return conv.from_bytes(Str);
}

void Chess :: display_coordinates(sf::RenderWindow &window , Grid grid){

	sf::Color color = sf::Color{ 3 , 34 , 76 };

	for (int i = 0; i < CHESSBOARD_SIZE_X; ++i){ //Letters of the bottom of the chessboard
        char letter = 'A' + i;
        Text text( window , string_to_wstring( std::string(1 , letter) ) , grid.get_rectangle( i , CHESSBOARD_SIZE_Y - 1 ).getPosition().x + SQUARE_SIZE / 2 , grid.get_rectangle( i , CHESSBOARD_SIZE_Y - 1 ).getPosition().y + 1.5 * SQUARE_SIZE , CHARACTER_SIZE , color , LATEX_FONT , BOLD , NON_ITALIC , NON_UNDERLINED , NO_ROTATION );
        text.display(window);
    }

	for (int i = 0; i < CHESSBOARD_SIZE_X; ++i){ //Letters of the top of the chessboard
        char letter = 'A' + i;
        Text text( window , string_to_wstring( std::string(1 , letter) ) , grid.get_rectangle( i , 0 ).getPosition().x + SQUARE_SIZE / 2 , grid.get_rectangle( i , 0 ).getPosition().y - SQUARE_SIZE / 2, CHARACTER_SIZE , color , LATEX_FONT , BOLD , NON_ITALIC , NON_UNDERLINED , HALF_REVOLUTION_ROTATION );
        text.display(window);
    }

    for (int i = 0; i < CHESSBOARD_SIZE_Y; ++i){ //Digits of the left side of the chessboard
     	Text text( window , string_to_wstring( std::to_string(CHESSBOARD_SIZE_Y - i) ) , grid.get_rectangle( 0 , i ).getPosition().x - SQUARE_SIZE / 2 , grid.get_rectangle( 0 , i ).getPosition().y + SQUARE_SIZE / 2, CHARACTER_SIZE , color , LATEX_FONT , BOLD , NON_ITALIC , NON_UNDERLINED , NO_ROTATION );
        text.display(window);  	
    }
    
    for (int i = 0; i < CHESSBOARD_SIZE_Y; ++i){ //Digits of the right side of the chessboard
     	Text text( window , string_to_wstring( std::to_string(CHESSBOARD_SIZE_Y - i) ) , grid.get_rectangle( CHESSBOARD_SIZE_Y - 1 , i ).getPosition().x + 1.5 * SQUARE_SIZE , grid.get_rectangle( CHESSBOARD_SIZE_Y - 1 , i ).getPosition().y + SQUARE_SIZE / 2, CHARACTER_SIZE , color , LATEX_FONT , BOLD , NON_ITALIC , NON_UNDERLINED , HALF_REVOLUTION_ROTATION );
        text.display(window);  	
    }
} 

void Chess :: run(){

	sf::RenderWindow window(sf::VideoMode(X_WINDOW, Y_WINDOW), "Chess");
	Grid grid( CHESSBOARD_SIZE_X , CHESSBOARD_SIZE_Y , SQUARE_SIZE);

	while( window.isOpen() ){

		sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed){
                window.close();                
            } 
        }
        window.clear(sf::Color::White);
		grid.display(window);
		display_coordinates(window , grid);
		window.display();
	}
} 