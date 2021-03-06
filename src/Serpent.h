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

class  Serpent{
	sf::Texture img;
	sf::Sprite img2;

	bool isDead = false;

	public:
		double posx, posy;
		double cenx ,ceny;

		Serpent(double, double);
		void Texture_Img();
		void Sprite_Img();
		void Draw(sf::RenderWindow &window);
		sf::Sprite getsprite();
		vector<double> getcen();
		void Changepos(double, double);
};