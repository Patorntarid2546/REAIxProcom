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

sf::Sprite Serpent::getsprite(){
	return img2;
}

vector<double> Serpent::getcen(){
	vector<double> a;
	a.push_back(cenx);
	a.push_back(ceny);
	return a;
}

void Serpent::Changepos(double x, double y){
	posx = x-30;
	posy = y-35;
}