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

class BoardgameWater{
	int x;
	int y;

	sf::Texture img;
	sf::Sprite img2;
	void Texture_Img();
	void Sprite_Img();

	public :
		BoardgameWater(int,int);
		void DrawWater(sf::RenderWindow &);

};

BoardgameWater::BoardgameWater(int a, int b){
	x = a; y = b;
}

void BoardgameWater::Texture_Img(){
	string ref;
	int a = rand()%3;
	if(a == 0) ref = "image\\Texture_Sea\\seawaves.png";
	else if(a == 1) ref = "image\\Texture_Sea\\seawaves1.png";
	else if(a == 2) ref = "image\\Texture_Sea\\seawaves2.png";
	else ref =  "BoardgameWater::Texture_Img() --> Error";
	img.loadFromFile(ref);
}
void BoardgameWater::Sprite_Img(){
	img2.setTexture(img);
	img2.setPosition(x,y);
}

void BoardgameWater::DrawWater(sf::RenderWindow &window){
	Texture_Img();
	Sprite_Img();
	window.draw(img2);
}

