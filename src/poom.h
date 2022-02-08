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

class Boardgame_Water{
	float x;
	float y;
	char type;
	public :
		string RandomImage();
};

string Boardgame_Water::RandomImage(){
	int a = rand()%3;
	if(a == 0) return "image\\Texture_Sea\\seawaves.png";
	else if(a == 1) return "image\\Texture_Sea\\seawaves1.png";
	else if(a == 2) return "image\\Texture_Sea\\seawaves2.png";
	else return "Boardgame_Water::RandomImage() --> Error";
}