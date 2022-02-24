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

class Player{
	sf::Texture img;
	sf::Sprite img2;



	char mode;

	public:
		bool isDead = false;
		double posx, posy;
		int index_board;

		Player(char, double, double);
		void Texture_Img();
		void Sprite_Img();
		void Draw(sf::RenderWindow &window);
		sf::Sprite getsprite();
		void Changepos(double, double);
		vector<double> getcen();
		vector<double> getpos();
};


/*int Player::Score(){
	bool kon = true;
    if(kon){
		if(แหน่งคน == ตำแหน่งภาพป่า){
			isDead = true;
		}
	}
	if(isDead){
		score
	}
}*/