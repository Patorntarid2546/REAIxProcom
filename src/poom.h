#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <string>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>

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
	int z;
	string type;
	string tile;

	sf::Texture img;
	sf::Sprite img2;
	void Texture_Img();
	void Sprite_Img();

	public :
		Boardgame(int,int,string);
		void Draw(sf::RenderWindow &);

};

Boardgame::Boardgame(int a, int b, string c){
	x = a; y = b; type = c;
}

void Boardgame::Texture_Img(){
	string ref;
	if(type == "water"){
		int a = rand()%3;
		if(a == 0) ref = "image\\Texture_Sea\\seawaves.png";
		else if(a == 1) ref = "image\\Texture_Sea\\seawaves1.png";
		else if(a == 2) ref = "image\\Texture_Sea\\seawaves2.png";
		else ref =  "Boardgame::Texture_Img() --> Error";
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
	Texture_Img();
	Sprite_Img();
	window.draw(img2);
}
