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


