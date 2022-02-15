#include "Boardgame.h"

Boardgame::Boardgame(int a, int b, string c){
	x = a; y = b; type = c;
}

int Boardgame::GetTimes(){
	const auto now = std::chrono::system_clock::now();
	const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
	stringstream nowSs;
	nowSs << std::setfill('0') << std::setw(3) << nowMs.count();
  	return stoi(nowSs.str());
}

void Boardgame::Texture_Img(){
	string ref;
	if(type == "water"){
		ref = list_water[num];
	}
	else if(type == "forest"){
		ref = "image\\Texture_forest\\Forest.png";
	}
	else if(type == "island"){
		int a = rand()%3;
		if(a == 0){
			tile = "sand";
			ref = "image\\Texture_Sand\\sand.png";
		}
		else if(a == 1){
			tile = "solid";
			ref = "image\\Texture_Solid\\solid.png";
		}
		else if(a == 2){
			tile = "hill";
			ref = "image\\Texture_Hill\\hill.png";
		}
	}
	img.loadFromFile(ref);
}
void Boardgame::Sprite_Img(){
	img2.setTexture(img);
	img2.setPosition(x,y);
}

void Boardgame::Draw(sf::RenderWindow &window){
	if(GetTimes() == 000) num++;
	Texture_Img();
	Sprite_Img();
	window.draw(img2);
}