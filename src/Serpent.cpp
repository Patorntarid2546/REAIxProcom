#include "Serpent.h"

Serpent::Serpent(double a, double b){
	cenx = a; ceny = b; posx = cenx-30; posy = ceny-35;
}

void Serpent::Texture_Img(){
	img.loadFromFile("image\\mini\\1.1miniseaserphen.png");
}

void Serpent::Sprite_Img(){
	img2.setTexture(img);
	img2.setPosition(posx,posy);
}

void Serpent::Draw(sf::RenderWindow &window){
	Texture_Img();
	Sprite_Img();
	window.draw(img2);
}