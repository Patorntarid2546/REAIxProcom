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

class  Dolphin{
	sf::Texture img;
	sf::Sprite img2;

	bool isDead = false;

	public:
		double posx, posy;
		double cenx = posx+30, ceny = posy+35;

		Dolphin(double, double);
		void Texture_Img();
		void Sprite_Img();
		void Draw(sf::RenderWindow &window);

};