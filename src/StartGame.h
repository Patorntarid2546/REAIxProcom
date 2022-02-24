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
	string poc[8] = {"image\\Guide\\9.guide6.png","image\\Guide\\9.guide1.png","image\\Guide\\9.guide1.png","image\\Guide\\9.guide2.png","image\\Guide\\9.guide3.png",
	"image\\Guide\\9.guide4.png","image\\Guide\\9.guide5.png","image\\Guide\\9.guide7.png"};
	vector<string> pic;
	bool bk = false;
	bool sc = false;
	bool check;
	string str = "";
	public :
		Startgame(bool);
		int GetTimes();
		void start(sf::RenderWindow &, string &, char &);
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

void Startgame::start(sf::RenderWindow &window, string &ip, char &mode){

    //ตำแหนงปุ่มหน้าแรก
	sf::CircleShape c1;
	c1.setRadius(95.f);
	c1.setFillColor(sf::Color::Transparent);
	c1.setOutlineColor(sf::Color::White);
	c1.setOutlineThickness(10.f);
    c1.setPosition(130.f,48.f);

	sf::CircleShape c2;
	c2.setRadius(40.f);
	c2.setFillColor(sf::Color::Transparent);
	c2.setOutlineColor(sf::Color::Black);
	c2.setOutlineThickness(8.f);
    c2.setPosition(1370.f,292.f);


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
	sign1.loadFromFile("image\\startgame2\\7.2menu1.png");
	sign2.loadFromFile("image\\startgame2\\7.2menu2.png");
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
    if(!amazingfont.loadFromFile("image\\Pixellettersfull-BnJ5.ttf"))
	   printf("Load ttf fail");

	sf::Text delet("delete",amazingfont,80);
	delet.setPosition(1200,500);
	delet.setFillColor(sf::Color::Black);
	delet.setOutlineColor(sf::Color::Cyan);
    delet.setOutlineThickness(8.f);

	sf::Text Enter("Enter",amazingfont,120);
	Enter.setPosition(1100,600);
	Enter.setFillColor(sf::Color::Green);
	Enter.setOutlineColor(sf::Color::Cyan);
	Enter.setOutlineThickness(8.f);

	sf::CircleShape point;
	point.setRadius(10.f);
	point.setPosition(1110,570);
	point.setFillColor(sf::Color::Black);
	point.setOutlineColor(sf::Color::Cyan);
	point.setOutlineThickness(15.f);

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

	score.push_back(sf::Text(str,amazingfont,40));
	score[10].setPosition(840,400);
	score[10].setFillColor(sf::Color::Black);
	score[10].setOutlineColor(sf::Color::Cyan);
	score[10].setOutlineThickness(2.f);

	bool once = true;
	int num = 3;
	sf::Sprite s1,s2;

	bool g = false;
	int ggg = 0;

	while (window.isOpen()){
		score[10].setString(str);
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
					sc = false;
				}
            	if(r1.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
					sign11.setTexture(sign1);
					g = false;
					sc = false;
					bk = false;
					mode = 's';
					ip = "";
				}
				//cliend
            	if(r2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
					g = false;
					sign11.setTexture(sign2);
					sc = true;
         		}

				//guide3ed(sf::Mouse::Left)){
            	if(r3.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
					cout << g << endl;
					g = true;
					img3.loadFromFile(poc[ggg]);
		    		img4.setTexture(img3);
		    		img4.setPosition(225,160);
					sc = false;
					break;
				}
				if(c2.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
					//ปิดป้าย
    				}
				if(sc){
					for(int i = 0; i < int(score.size()); i++){
						if(score[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
							str+=to_string(i);
							cout << str << endl;
						}
					}
					if(Enter.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
						bk = true;
						mode = 'c';
						ip = str;
					}
					if(delet.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
						str.erase(str.size() - 1);
					}
					if(point.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
						str+=".";
					}
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
						if(ggg > 7){
					   		ggg = 7;
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
			if(sc){
				for(int i = 0; i < int(score.size()); i++){
					window.draw(score[i]);
				}
				window.draw(Enter);
				window.draw(delet);
				window.draw(point);

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
	score[11].setString(str);
}