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
	string pic[5] = {"image\\Guide\\9.guide1.png","image\\Guide\\9.guide2.png","image\\Guide\\9.guide3.png",
	"image\\Guide\\9.guide4.png","image\\Guide\\9.guide5.png"};
	public :
		int GetTimes();
		void start(sf::RenderWindow &);
};

void Startgame::start(sf::RenderWindow &window){

	sf::CircleShape g1;
	g1.setRadius(30.f);
	g1.setFillColor(sf::Color::Transparent);
	g1.setOutlineColor(sf::Color::White);
	g1.setOutlineThickness(10.f);
	g1.setPosition(1520.f,175.f);

	sf::RectangleShape g2;
	g2.setSize(sf::Vector2f(240,95));
	g2.setFillColor(sf::Color::Transparent);
	g2.setOutlineColor(sf::Color::White);
	g2.setOutlineThickness(10.f);
	g2.setPosition(380.f,730.f);

	sf::RectangleShape g3;
	g3.setSize(sf::Vector2f(240,95));
	g3.setFillColor(sf::Color::Transparent);
	g3.setOutlineColor(sf::Color::White);
	g3.setOutlineThickness(10.f);
	g3.setPosition(1322.f,730.f);

	int num = 0;

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//click
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				if(g1.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
                    // exit
         		}
            	if(g2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
				   if(num <= 0){
					   num = 1;
				    }
					num--;
         		}
				 if(g3.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
				   if(num > 5){
					   num = 5;
				    }
					num++;
         		}
			}
		    img.loadFromFile(pic[num]);
		    img2.setTexture(img);
		    img2.setPosition(225,160);

		}

		window.clear();
		window.draw(g1);
		window.draw(g2);
		window.draw(g3);

		window.draw(img2);


		window.display();
	}
}