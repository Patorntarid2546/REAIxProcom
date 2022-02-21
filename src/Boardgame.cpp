#include "Boardgame.h"

Boardgame::Boardgame(double a, double b, string c,int d = 0, int e = 0){
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
	int b = rand()%(36);
	if(b < 8) effect = 0;
	else if (b < 16) effect = 1; // เพิ่มฉลาม
	else if (b < 20) effect = 2; // เพิ่มโลมา
	else if (b < 24) effect = 3; // ย้ายโลมา
	else if (b < 28) effect = 4; // ย้ายฉลาม
	else if (b < 34) effect = 5; // ว่างเปล่า
	else effect = 6; // ภูเขาไฟระเบิด

	if(a == 0) tile = "sand";
	else if(a == 1) tile = "solid";
	else tile = "mount";

}

vector<int> Boardgame::getqrs(){
	vector<int> a;
	a.push_back(q); a.push_back(r); a.push_back(s);
	return a;
}

vector<double> Boardgame::getpos(){
	vector<double> a;
	a.push_back(posx); a.push_back(posy);
	return a;
}

vector<double> Boardgame::getcen(){
	vector<double> a;
	a.push_back(cenx); a.push_back(ceny);
	return a;
}

sf::Sprite Boardgame::getsprite(){
	return img2;
}

string Boardgame::GetType(){
	return type;
}