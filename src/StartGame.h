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
	sf::Texture img3;
	sf::Sprite img4;
	string poc[5] = {"image\\Guide\\9.guide1.png","image\\Guide\\9.guide2.png","image\\Guide\\9.guide3.png",
	"image\\Guide\\9.guide4.png","image\\Guide\\9.guide5.png"};
	vector<string> pic;
	bool bk = false;
	bool check;
	public :
		Startgame(bool);
		int GetTimes();
		void start(sf::RenderWindow &);
};

Startgame::Startgame(bool a){
	check = a;
	if(a){
		string pcc[4] = {"image\\startgame2\\7.second frame1remake.jpg","image\\startgame2\\7.second frame2remake.jpg","image\\startgame2\\7.second frame3remake.jpg","image\\startgame2\\7.second frame4remake.jpg"};
		for(int i = 0; i < 4; i++){
			pic.push_back(pcc[i]);
		}
	}
	else{
		string pcc[4] = {"image\\Startgame\\6.start game1.png","image\\Startgame\\6.start game2.png","image\\Startgame\\6.start game3.png","image\\Startgame\\6.start game4.png"};
		for(int i = 0; i < 4; i++){
			pic.push_back(pcc[i]);
		}
	}
}

int Startgame::GetTimes(){
	const auto now = std::chrono::system_clock::now();
	const auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
	stringstream nowSs;
	nowSs << std::setfill('0') << std::setw(3) << nowMs.count();
  	return stoi(nowSs.str());
}

void Startgame::start(sf::RenderWindow &window){

    //ตำแหนงปุ่มหน้าแรก
	sf::CircleShape c1;
	c1.setRadius(95.f);
	c1.setFillColor(sf::Color::Transparent);
	c1.setOutlineColor(sf::Color::White);
	c1.setOutlineThickness(10.f);
    c1.setPosition(130.f,48.f);


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

	sf::Font amazingfont;
    if(!amazingfont.loadFromFile("image\\ShortBaby-Mg2w.ttf"))
	   printf("Load ttf fail");

	vector<sf::Text> score;
	for(int i = 0; i < 5; i++){
		score.push_back(sf::Text(to_string(i),amazingfont,80));
		score[i].setPosition(500+(i+1)*100,500);
		score[i].setFillColor(sf::Color::Black);
		score[i].setOutlineColor(sf::Color::Cyan);
		score[i].setOutlineThickness(8.f);
	}
	for(int i = 5; i < 10; i++){
		score.push_back(sf::Text(to_string(i),amazingfont,80));
		score[i].setPosition(500+(i-5+1)*100,600);
		score[i].setFillColor(sf::Color::Black);
		score[i].setOutlineColor(sf::Color::Cyan);
		score[i].setOutlineThickness(8.f);
	}

	bool once = true;
	int num = 3;
	sf::Sprite s1,s2;

	bool g = false;
	int ggg = 0;

	while (window.isOpen()){
		if(bk) break;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			// server
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				//Decktop game
				if(c1.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
					bk = true;
				}
            	if(r1.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
					sign11.setTexture(sign1);
					g = false;
				}
				//cliend
            	if(r2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
					g = false;
					sign11.setTexture(sign2);
         		}

				//guide3ed(sf::Mouse::Left)){
            	if(r3.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
					cout << g << endl;
					g = true;
					img3.loadFromFile(poc[ggg]);
		    		img4.setTexture(img3);
		    		img4.setPosition(225,160);
					break;
				}

				if (g){
					if(g1.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
                    	g = false;
    				}
            		if(g2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
						ggg--;
				   		if(ggg < 0){
					   		ggg = 0;
				    	}
					}
				 	if(g3.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
						ggg++;
						if(ggg > 4){
					   		ggg = 4;
				    	}
         			}
					img3.loadFromFile(poc[ggg]);
				}
			}
		}
		window.clear();

		if(check){
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

			if (g){
				window.draw(g1);
				window.draw(g2);
				window.draw(g3);

				window.draw(img4);
			}
			for(int i = 0; i < int(score.size()); i++){
				window.draw(score[i]);
			}

		}
		else{
			window.draw(c1);
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
		}


		window.display();
	}
}