#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <windows.h>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <chrono>
#include <sys/time.h>
#include <string>
#include <iostream>

using namespace std;

class Network{
	sf::TcpSocket socket;
	sf::TcpListener listenner;
	sf::IpAddress my_ip = sf::IpAddress::getLocalAddress();
	sf::Packet  packet;
	public :
		void connect(char, string);
		void disconnect();
		void senttext(string);
		string recievedtext();
		double recieveddouble();
		string showip();
		bool dis;
};
