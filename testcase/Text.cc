#include <iostream>
#include "Text.hh"

using namespace std; 

#define TEXT_WIDTH 50

Text :: Text (sf::RenderWindow& window, const wstring text, const size_t x, const size_t y, const size_t character_size, const sf::Color& color, const string font, const bool bold, const bool italic, const bool underlined, const float rotation) {
  	
	Texte = text;
	x_text = x;
	y_text = y;
	Character_Size = character_size;
	Text_color = color;
	font_path = font;
	Bold = bold;
	Italic = italic;
	Underlined = underlined;
	Rotation = rotation; 
}

void Text :: display(sf::RenderWindow& window) {

	sf::Font font;
	if (! font.loadFromFile(font_path) ){
        cout << "Error ! Cannot find font" << endl;
    }
	sf::Text T(Texte,font, TEXT_WIDTH);
	T.setCharacterSize(Character_Size);
    T.setFillColor(Text_color);
    T.setRotation(Rotation);
    T.setPosition(x_text - T.getGlobalBounds().width / 2 - T.getGlobalBounds().left , y_text - T.getGlobalBounds().height / 2 - T.getGlobalBounds().top);

    if(Bold) {
    	T.setStyle(sf::Text::Bold);
    }
    if(Italic){
    	T.setStyle(sf::Text::Italic);
    }
    if(Underlined){
    	T.setStyle(sf::Text::Underlined);
    }
    window.draw(T);
}    