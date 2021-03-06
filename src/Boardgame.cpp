#include "Boardgame.h"

Boardgame::Boardgame(double a, double b, string c,int d = 0, int e = 0){
	posx = a; posy = b; type = c; r = d; q = e; s = -1*(q+r);
}

void Boardgame::Texture_Img(){
	string ref;
	if(type == "water"){
		ref = "image\\hexa\\4.1seawave.png";
		tile = "";
	}
	else if(type == "forest"){
		ref = "image\\hexa\\4.1forest.png";
		tile = "";
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

void Boardgame::ChangeType(string z = ""){
	type = "island";
	int a = rand()%3;
	int b = rand()%(36);
	if(b < 8) effect = '0';
	else if (b < 16) effect = '1'; // เพิ่มฉลาม
	else if (b < 20) effect = '2'; // เพิ่มโลมา
	else if (b < 24) effect = '3'; // ย้ายโลมา
	else if (b < 28) effect = '4'; // ย้ายฉลาม
	else if (b < 34) effect = '5'; // ว่างเปล่า
	else effect = 6; // ภูเขาไฟระเบิด
	if(z == ""){
		if(a == 0) tile = "sand";
		else if(a == 1) tile = "solid";
		else tile = "mount";
	}
	else{
		tile = z;
	}
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
	a.push_back(posx+42); a.push_back(posy+48);
	return a;
}

sf::Sprite Boardgame::getsprite(){
	return img2;
}

string Boardgame::GetType(){
	return type;
}

string Boardgame::GetTile(){
	return tile;
}

string Boardgame::GetEffect(){
	return effect;
}

void Boardgame::ChangeEffect(string a){
	effect = a;
}

int Boardgame::operator+(const Boardgame &B){
	int qq = abs(q - B.q);
	int rr = abs(r - B.r);
	int ss = abs(s - B.s);
	return (qq+rr+ss)/2;
}

void Boardgame::Delete(){
	tile = "";
	type = "water";
}