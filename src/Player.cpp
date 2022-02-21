#include "Player.h"

Player::Player(char m, double a, double b){
	mode = m; cenx = a, ceny = b; posx = cenx-30; posy = ceny-35;
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