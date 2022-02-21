#include "Dolphin.h"

Dolphin::Dolphin(double a, double b){
	cenx = a; ceny = b; posx = cenx-30; posy = ceny-35;
}

void Dolphin::Texture_Img(){
	img.loadFromFile("image\\mini\\1.1minidol.png");
}

void Dolphin::Sprite_Img(){
	img2.setTexture(img);
	img2.setPosition(posx,posy);
}

void Dolphin::Draw(sf::RenderWindow &window){
	Texture_Img();
	Sprite_Img();
	window.draw(img2);
}