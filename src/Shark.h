#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <sys/time.h>
#include <vector>
#include <windows.h>

using namespace std;

class Shark
{
	sf::Texture img;
	sf::Sprite img2;

	bool isDead = false;

public:
	double posx, posy;
	double cenx = posx + 30, ceny = posy + 35;

	Shark(double, double);
	void Texture_Img();
	void Sprite_Img();
	void Draw(sf::RenderWindow& window);
	vector<double> getpos();
	sf::Sprite getsprite();
	vector<double> getcen();
	void Changepos(double, double);
};