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

class Startgame{
	sf::Texture img;
	sf::Sprite img2;
	string pic[4] = {"image\\startgame2\\T7.1second frame.png","image\\startgame2\\T7.1second frame1.png","image\\startgame2\\T7.1second frame2.png",
	"image\\startgame2\\T7.1second frame3.png"};
	public :
		int GetTimes();
		void start(sf::RenderWindow &);
};

int Startgame::GetTimes(){
	const auto now = std::chrono::system_clock::now();
	const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
	stringstream nowSs;
	nowSs << std::setfill('0') << std::setw(3) << nowMs.count();
  	return stoi(nowSs.str());
}

void Startgame::start(sf::RenderWindow &window){

	sf::RectangleShape r1;
	r1.setSize(sf::Vector2f(420,115));
	r1.setFillColor(sf::Color::Transparent);
	r1.setOutlineColor(sf::Color::White);
	r1.setOutlineThickness(10.f);
	r1.setPosition(170.f,145.f);

	sf::RectangleShape r2;
	r2.setSize(sf::Vector2f(420,115));
	r2.setFillColor(sf::Color::Transparent);
	r2.setOutlineColor(sf::Color::White);
	r2.setOutlineThickness(10.f);
	r2.setPosition(170.f,335.f);

	sf::RectangleShape r3;
	r3.setSize(sf::Vector2f(420,115));
	r3.setFillColor(sf::Color::Transparent);
	r3.setOutlineColor(sf::Color::White);
	r3.setOutlineThickness(10.f);
	r3.setPosition(170.f,545.f);

	sf::Texture sign1;
	sf::Texture sign2;
	sign1.loadFromFile("image\\startgame2\\7.1menu.png");
	sign2.loadFromFile("image\\startgame2\\7.1menu1.png");
	sf::Sprite sign11;
	sign11.setPosition(0,0);


	bool once = true;
	int num = 3;
	sf::Sprite s1,s2;

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			// server
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            	if(r1.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
					sign11.setTexture(sign1);
         		}
			}
			//cliend
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            	if(r2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
					sign11.setTexture(sign2);
         		}
			}
			//guide3ed(sf::Mouse::Left)){
            if(r3.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y))
				break;
		}

		window.clear();


		window.draw(r1);
		window.draw(r2);
		window.draw(r3);
		if (once){
			img.loadFromFile(pic[num]);
			img2.setTexture(img);
			img2.setPosition(0,0);
			once = false;
		}
		else{
			if((GetTimes()%333) == 0){
				img.loadFromFile(pic[num]);
				img2.setTexture(img);
				img2.setPosition(0,0);
				num++;
				if(num >= 4) num = 0;
			}
		}
		window.draw(img2);
		window.draw(sign11);


		window.display();
	}
}