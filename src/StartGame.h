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

class Startgame{
	sf::Texture img;
	sf::Sprite img2;
	string pic[4] = {"image\\Startgame\\6.start game1.png","image\\Startgame\\6.start game2.png","image\\Startgame\\6.start game3.png", "image\\Startgame\\6.start game4.png"};
	public :
		int GetTimes();
		void start();
};

int Startgame::GetTimes(){
	const auto now = std::chrono::system_clock::now();
	const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
	stringstream nowSs;
	nowSs << std::setfill('0') << std::setw(3) << nowMs.count();
  	return stoi(nowSs.str());
}

void Startgame::start(){
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "REAIxProcom : Survive forest from atlantis", sf::Style::Fullscreen);

	sf::CircleShape c1;
	c1.setRadius(95.f);
	c1.setFillColor(sf::Color::Transparent);
	c1.setOutlineColor(sf::Color::White);
	c1.setOutlineThickness(10.f);
    c1.setPosition(130.f,48.f);

	int num = 3;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(c1.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))
			window.close();
		}
		window.clear();
		if((GetTimes()%333) == 0){
			img.loadFromFile(pic[num]);
			img2.setTexture(img);
			img2.setPosition(0,0);
			num++;
			if(num >= 4) num = 1;
		}

		window.draw(img2);

		window.display();
	}
}

//--------------------------------------------------------------------------------------------------------------------//