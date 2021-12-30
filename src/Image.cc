#include <iostream>
#include "Image.hh"

using namespace std; 

Image :: Image (sf::RenderWindow& window, const size_t x, const size_t y, const size_t width, size_t height, string path) {
  
	x_image = x;
	y_image = y;
	width_image = width;
	height_image = height;
	path_image = path;
}

void Image :: display(sf::RenderWindow& window) {

	sf::Texture texture;
	sf::Sprite image;

    if (!texture.loadFromFile(path_image)){ 
        cout << "Erreur de chargement de l'image : " << path_image << endl;
    }

    texture.setSmooth(true);
    image.setTexture(texture);
    float SCALE_X = (float)width_image / (float)image.getTexture()->getSize().x;
    float SCALE_Y = (float)height_image / (float)image.getTexture()->getSize().y;
    image.setScale(SCALE_X, SCALE_Y);
    image.setPosition(x_image - width_image/2 , y_image - height_image/2);
    window.draw(image);
}    
