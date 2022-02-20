//import library สำหรับ gui
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

// import library พื้นฐาน
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

// import class สำหรับหน้าเริ่มเกม
#include "Startgame.h"
#include "Network.h"
#include "Boardgame.h"
#include "islandrandom.h"

int main()
{
	srand(time(0));

	// หน้าต่างงเริ่มเกม
	Startgame a;
	a.start();

	// กำหนดขนาด window ความละเอียด 1920*1080 แบบเต็มจอ
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "REAIxProcom : Survive forest from atlantis", sf::Style::Fullscreen);

	int block_h = 96, block_w = 84, set_h = 0, set_w = 500;

	vector<Boardgame> water;
	vector<Boardgame> island;

	int nub , nubx;
	for(int i = 1; i <= 14; i+=2){
		int y = set_h+(i*block_h*3/4);
		if(i <= 7){
			if(i < 7){
				nub = 1-i;
				for(double j = 1-(i+5)/2; j <= 1+(i+5)/2; j++){
					int x = set_w+(j*block_w);
					water.push_back(Boardgame(x, y, "water", i-7, nub++));
				}
				y = set_h+72+(i*block_h*3/4);
				nub = -i;
				for(double l = 1-(i+5)/2; l <= 2+(i+5)/2; l++){
					int x = set_w-44+(l*block_w);
					water.push_back(Boardgame(x, y, "water", i-6, nub++));
				}
			}
			else{
				nub = 1-i;
				nubx = nub;
				for(double j = 1-(i+5)/2; j <= 1+(i+5)/2; j++){
					int x = set_w+(j*block_w);
					water.push_back(Boardgame(x, y, "water", i-7, nub++));
				}
			}
		}

		else{
			int nub2 = nubx;
			y -= 72;
			for(double l = 1-(7-(i%7)+5)/2; l <= 2+(7-(i%7)+5)/2; l++){
				int x = set_w-44+(l*block_w);
				water.push_back(Boardgame(x, y, "water", i-8, nub2++));
			}
			y += 72;
			nub2 = nubx;
			for(double j = 1-(7-(i%7)+5)/2; j <= 1+(7-(i%7)+5)/2; j++){
				int x = set_w+(j*block_w);
				water.push_back(Boardgame(x, y, "water", i-7, nub2++));
			}
		}
	}

	vector<int> effect = {};


    while (window.isOpen())
	{

		// ลูป Event
		sf::Event event;
		while (window.pollEvent(event))
		{
			// ถ้ามีการปิดหน้าต่างให้ปิดโปรแกรม
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// เคลียร์เฟรมเดิม
		window.clear();

		// พื้นหลังน้ำ
		for (int i = 0; i < int(water.size()); i++)
			water[i].Draw(window);

		// แสดงเฟรมใหม่
		window.display();
	}

	return 0;
}