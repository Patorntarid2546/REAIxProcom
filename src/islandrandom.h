#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class islandrandom
{
	int x;
	int y;
	string type;
	sf::Texture img;

	public:
		islandrandom(int, int, string);
		void Texture_Img();
};
