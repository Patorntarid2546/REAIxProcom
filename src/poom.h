#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include <windows.h>

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
		cout << "Error" << endl;
		return "Error";
	}
}
