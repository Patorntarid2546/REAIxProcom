#include "dice.h"

Dice::Dice(double a, double b, int c){
	posx = a; posy = b; num = c;
}

void Dice::Texture_Img(){
	if(num == 1) img.loadFromFile("image\\Dice\\5.dice face11.png");
	else if(num == 2) img.loadFromFile("image\\Dice\\5.dice face12.png");
	else if(num == 3) img.loadFromFile("image\\Dice\\5.dice face13.png");
}

void Dice::Sprite_Img(){
	img2.setTexture(img);
	img2.setPosition(0,0);
}

void Dice::Draw(sf::RenderWindow &window){
	Texture_Img();
	Sprite_Img();
	window.draw(img2);
}