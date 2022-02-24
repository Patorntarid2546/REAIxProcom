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

class Dice{
	sf::Texture img;
	sf::Sprite img2;

	public:
		double posx, posy;
		int num;

		Dice(double, double, int);
		void Texture_Img();
		void Sprite_Img();
		void Draw(sf::RenderWindow &window);
};