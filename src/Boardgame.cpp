#include "Boardgame.h"

Boardgame::Boardgame(double a, double b, string c,int d, int e){
	posx = a; posy = b; type = c; r = d; q = e; s = -1*(q+r);
}

void Boardgame::Texture_Img(){
	string ref;
	if(type == "water"){
		ref = "image\\hexa\\4.1seawave.png";
		tile = "water";
	}
	else if(type == "forest"){
		ref = "image\\hexa\\4.1forest.png";
		tile = "forest";
	}
	else if(type == "island"){
		if(tile == "sand"){
			ref = "image\\hexa\\4.1sand.png";
		}
		else if(tile == "solid"){
			ref = "image\\hexa\\4.1soild.png";
		}
		else if(tile == "mount"){
			ref = "image\\hexa\\4.1mountion.png";
		}
	}
	img.loadFromFile(ref);
}
void Boardgame::Sprite_Img(){
	img2.setTexture(img);
	img2.setPosition(posx,posy);
}

void Boardgame::Draw(sf::RenderWindow &window){
	Texture_Img();
	Sprite_Img();
	window.draw(img2);
}

void Boardgame::ChangeType(){
	type = "island";
	int a = rand()%3;
	if(a == 0) tile = "sand";
	else if(a == 1) tile = "solid";
	else tile = "mount";
}