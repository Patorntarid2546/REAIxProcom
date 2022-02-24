#include "dice.h"

Dice::Dice(double a, double b, int c){
	posx = a; posy = b; num = c;
}

void Dice::Texture_Img(){
	if(num == 1) img.loadFromFile("image\\Dice\\diceface1.jpg");
	else if(num == 2) img.loadFromFile("image\\Dice\\diceface2.jpg");
	else if(num == 3) img.loadFromFile("image\\Dice\\diceface3.jpg");
}

void Dice::Sprite_Img(){
	img2.setTexture(img);
	img2.setPosition(posx,posy);
}

void Dice::Draw(sf::RenderWindow &window){
	Texture_Img();
	Sprite_Img();
	window.draw(img2);
}