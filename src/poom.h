#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <string>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <chrono>
#include <sys/time.h>

using namespace std;

class Network{
	sf::TcpSocket socket;
	sf::TcpListener listenner;
	public :
		sf::IpAddress my_ip = sf::IpAddress::getLocalAddress();

		void connect(char, string);
		void senttext(string);
		string recievedtext();
		void showip();
};

void Network::connect(char mode, string ip_s){
	if(mode == 's'){
		listenner.listen(2000);
		listenner.accept(socket);
		cout << "Connect Success!!!" << endl;
	}
	else if(mode == 'c'){
		socket.connect(ip_s, 2000);
		cout << "Connect Success!!!" << endl;
	}
}

void Network::senttext(string text){
	socket.send(text.c_str(), text.length()+1);
}

string Network::recievedtext(){
	string text;
	char buffer[2000];
	size_t recieved;
	socket.receive(buffer, sizeof(buffer), recieved);
	if(recieved > 0){
		text = buffer;
		return text;
	}
	else{
		return "Network::recievedtext() --> Error";
	}
}

//--------------------------------------------------------------------------------------------------------------------//

class Boardgame{
	int x;
	int y;
	int num = 0;

	string list_water[3] = {"image\\Texture_Sea\\seawaves.png","image\\Texture_Sea\\seawaves1.png", "image\\Texture_Sea\\seawaves2.png"};

	string type;
	string tile;

	sf::Texture img;
	sf::Sprite img2;
	void Texture_Img();
	void Sprite_Img();
	int GetTimes();

	public :
		Boardgame(int,int,string);
		void Draw(sf::RenderWindow &);

};

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

//--------------------------------------------------------------------------------------------------------------------//

