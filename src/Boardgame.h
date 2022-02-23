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
#include <cmath>



using namespace std;

class Boardgame{
	double posx, posy;
	int q, r, s;
	string tile = "", type;

	sf::Texture img;
	sf::Sprite img2;

	public:
		string effect;
		Boardgame(double, double, string, int, int);
		void Texture_Img();
		void Sprite_Img();
		void Draw(sf::RenderWindow &window);

		int havedol = 0, haveshark = 0, haveplayer = 0, haveser = 0, haveall = haveshark+haveplayer+haveshark;
		int index_player;

		void ChangeType(string);
		vector <int> getqrs();
		vector <double> getpos();
		vector <double> getcen();
		sf::Sprite getsprite();
		string GetType();
		string GetTile();
		string GetEffect();
		void ChangeEffect(string);
		int operator+(const Boardgame &);
};


