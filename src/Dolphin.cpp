#include "Dolphin.h"

Dolphin::Dolphin(double a, double b)
{
	cenx = a;
	ceny = b;
	posx = cenx - 30;
	posy = ceny - 35;
}

void Dolphin::Texture_Img()
{
	img.loadFromFile("image\\mini\\1.1minidol.png");
}

void Dolphin::Sprite_Img()
{
	img2.setTexture(img);
	img2.setPosition(posx, posy);
}

void Dolphin::Draw(sf::RenderWindow& window){
	if(isDead == false){
		Texture_Img();
		Sprite_Img();
		window.draw(img2);
	}
}

vector<double> Dolphin::getpos()
{
	vector<double> a;
	a.push_back(cenx);
	a.push_back(ceny);
	return a;
}

sf::Sprite Dolphin::getsprite(){
	return img2;
}

vector<double> Dolphin::getcen(){
	vector<double> a;
	a.push_back(cenx);
	a.push_back(ceny);
	return a;
}

void Dolphin::Changepos(double x, double y){
	posx = x-30;
	posy = y-35;
}