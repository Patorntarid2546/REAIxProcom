#include "Player.h"

Player::Player(char m, double a, double b){
	mode = m; posx = a-30; posy = b-35;
}

void Player::Texture_Img(){
	string ref;
	if(mode == 's') ref = "image\\mini\\1.1minivillager1.png";
	else ref = "image\\mini\\1.1minivillager2.png";
	img.loadFromFile(ref);
}

void Player::Sprite_Img(){
	img2.setTexture(img);
	img2.setPosition(posx,posy);
}

void Player::Draw(sf::RenderWindow &window){
	Texture_Img();
	Sprite_Img();
	window.draw(img2);
}

sf::Sprite Player::getsprite(){
	return img2;
}

void Player::Changepos(double a, double b){
	posx = a-30;
	posy = b-35;
}

vector<double> Player::getcen(){
	vector<double> a;
	a.push_back(posx+30);
	a.push_back(posy+35);
	return a;
}

vector<double> Player::getpos(){
	vector<double> a;
	a.push_back(posx);
	a.push_back(posy);
	return a;
}