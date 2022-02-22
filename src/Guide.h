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

class Guide{
	sf::Texture img;
	sf::Sprite img2;
	string pic[4] = {"image\\startgame2\\T7.1second frame.png","image\\startgame2\\T7.1second frame1.png","image\\startgame2\\T7.1second frame2.png",
	"image\\startgame2\\T7.1second frame3.png"};
	public :
		void startG(sf::RenderWindow &);
};
void Guide::startG(sf::RenderWindow &window){
