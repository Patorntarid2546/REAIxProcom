#include "Shark.h"

Shark::Shark(double a, double b)
{
	cenx = a;
	ceny = b;
	posx = cenx - 30;
	posy = ceny - 35;
}

void Shark::Texture_Img()
{
	img.loadFromFile("image\\mini\\1.1minishark.png");
}

void Shark::Sprite_Img()
{
	img2.setTexture(img);
	img2.setPosition(posx, posy);
}

void Shark::Draw(sf::RenderWindow& window)
{
	Texture_Img();
	Sprite_Img();
	window.draw(img2);
}

vector<double> Shark::getpos()
{
	vector<double> a;
	a.push_back(cenx);
	a.push_back(ceny);
	return a;
}