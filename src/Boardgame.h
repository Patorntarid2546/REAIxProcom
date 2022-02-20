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
	double posx, posy;
	double cenx = posx+42, ceny = posy+48;
	double q, r, s;
	string tile = "", type;

	sf::Texture img;
	sf::Sprite img2;

	public:
		Boardgame(double, double, string, int, int);
		void Texture_Img();
		void Sprite_Img();
		void Draw(sf::RenderWindow &window);

		void ChangeType();
};


