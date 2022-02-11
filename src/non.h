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
islandrandom::islandrandom(int A, int B, string C)
{
	x = A;
	y = B;
	type = C;
}
void islandrandom::Texture_Img()
{
	int N = rand() % 3;
	string pic;
	if (N == 0)
	{
		type = "sand";
		pic = "image\\Texture_Sand\\sand.png";
	}
	else if (N == 1)
	{
		type = "solid";
		pic = "image\\Texture_Solid\\solid.png";
	}
	else if (N == 2)
	{
		type = "hill";
		pic = "image\\Texture_Hill\\hill.png";
	}
	img.loadFromFile(pic);
}