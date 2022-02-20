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
#include <list>
#include <algorithm>

// import class สำหรับหน้าเริ่มเกม
#include "Startgame.h"
#include "Network.h"
#include "Boardgame.h"
#include "islandrandom.h"

int main()
{
	srand(time(0));

	sf::Vector2f mousepos;

	// หน้าต่างงเริ่มเกม
	// Startgame a;
	// a.start();

	// กำหนดขนาด window ความละเอียด 1920*1080 แบบเต็มจอ
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "REAIxProcom : Survive forest from atlantis");

	int block_h = 96, block_w = 84, set_h = 0, set_w = 650;

	vector<Boardgame> board;

	int nub , nubx;
	for(int i = 1; i <= 14; i+=2){
		int y = set_h+(i*block_h*3/4);
		if(i <= 7){
			if(i < 7){
				nub = 1-i;
				for(double j = 1-(i+5)/2; j <= 1+(i+5)/2; j++){
					int x = set_w+(j*block_w);
					board.push_back(Boardgame(x, y, "water", i-7, nub++));
				}
				y = set_h+72+(i*block_h*3/4);
				nub = -i;
				for(double l = 1-(i+5)/2; l <= 2+(i+5)/2; l++){
					int x = set_w-44+(l*block_w);
					board.push_back(Boardgame(x, y, "water", i-6, nub++));
				}
			}
			else{
				nub = 1-i;
				nubx = nub;
				for(double j = 1-(i+5)/2; j <= 1+(i+5)/2; j++){
					int x = set_w+(j*block_w);
					board.push_back(Boardgame(x, y, "water", i-7, nub++));
				}
			}
		}

		else{
			int nub2 = nubx;
			y -= 72;
			for(double l = 1-(7-(i%7)+5)/2; l <= 2+(7-(i%7)+5)/2; l++){
				int x = set_w-44+(l*block_w);
				board.push_back(Boardgame(x, y, "water", i-8, nub2++));
			}
			y += 72;
			nub2 = nubx;
			for(double j = 1-(7-(i%7)+5)/2; j <= 1+(7-(i%7)+5)/2; j++){
				int x = set_w+(j*block_w);
				board.push_back(Boardgame(x, y, "water", i-7, nub2++));
			}
		}
	}

	int z = board.size();
	for (int i = 0; i < z; i++){
		vector<int> a = (board.at(i)).getqrs();
		double dis = (abs(a.at(0)) + abs(a.at(1)) + abs(a.at(2)))/2;
		if(dis <= 3 && dis > 0) (board.at(i)).ChangeType();
	}

	// for (int i = 1; i < 5; i++){
	// 	board.push_back(Boardgame(((board.at(0)).getpos()).at(0) - 84*i, ((board.at(0)).getpos()).at(1), "forest", -6, 0-i));
	// 	board.push_back(Boardgame(((board.at(7)).getpos()).at(0) - 84*i, ((board.at(7)).getpos()).at(1), "forest", -5, -1-i));
	// }

	vector<int> secc = {0,7,15,24,34,45};
	nub = -6;
	for (int j = 5; j >= 4; j--){
		for (int i = 1; i < j; i++){
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)))).getpos()).at(0) - 84*i,
				((board.at(secc.at(2*(5-j)))).getpos()).at(1), "forest", nub, ((board.at(secc.at(2*(5-j)))).getqrs()).at(0)-i));
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)+1))).getpos()).at(0) - 84*i,
				((board.at(secc.at(2*(5-j)+1))).getpos()).at(1), "forest", nub+1, ((board.at(secc.at(2*(5-j)+1))).getqrs()).at(0)-i));
		}
		nub+=2;
	}
	secc = {120,112,103,93,82,70};
	nub = 6;
	for (int j = 5; j >= 4; j--){
		for (int i = 1; i < j; i++){
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)))).getpos()).at(0) - 84*i,
				((board.at(secc.at(2*(5-j)))).getpos()).at(1), "forest", nub, ((board.at(secc.at(2*(5-j)))).getqrs()).at(0)-i));
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)+1))).getpos()).at(0) - 84*i,
				((board.at(secc.at(2*(5-j)+1))).getpos()).at(1), "forest", nub-1, ((board.at(secc.at(2*(5-j)+1))).getqrs()).at(0)-i));
		}
		nub-=2;
	}
	secc = {6,14,23,33,44,56};
	nub = -6;
	for (int j = 5; j >= 4; j--){
		for (int i = 1; i < j; i++){
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)))).getpos()).at(0) + 84*i,
				((board.at(secc.at(2*(5-j)))).getpos()).at(1), "forest", nub, ((board.at(secc.at(2*(5-j)))).getqrs()).at(0)+i));
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)+1))).getpos()).at(0) + 84*i,
				((board.at(secc.at(2*(5-j)+1))).getpos()).at(1), "forest", nub+1, ((board.at(secc.at(2*(5-j)+1))).getqrs()).at(0)+i));
		}
		nub+=2;
	}
	secc = {126,119,111,102,92,81,70};
	nub = 6;
	for (int j = 5; j >= 4; j--){
		for (int i = 1; i < j; i++){
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)))).getpos()).at(0) + 84*i,
			((board.at(secc.at(2*(5-j)))).getpos()).at(1), "forest", nub, ((board.at(secc.at(2*(5-j)))).getqrs()).at(0)+i));
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)+1))).getpos()).at(0) + 84*i,
			((board.at(secc.at(2*(5-j)+1))).getpos()).at(1), "forest", nub-1, ((board.at(secc.at(2*(5-j)+1))).getqrs()).at(0)+i));
		}
		nub-=2;
	}


	while (window.isOpen())
	{

		// ลูป Event
		sf::Event event;
		while (window.pollEvent(event))
		{
			// ถ้ามีการปิดหน้าต่างให้ปิดโปรแกรม
			if (event.type == sf::Event::Closed)
				window.close();

			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

				sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

				z = board.size();
				for (int i = 0; i < z; i++){
					sf::FloatRect bounds = ((board.at(i)).getsprite()).getGlobalBounds();
    				if (bounds.contains(mouse))
    				{
        				vector<int> test = ((board.at(i)).getqrs());
						cout << test.at(0) << " " << test.at(1) << " " << test.at(2) << endl;
    				}
				}

			}
		}

		// เคลียร์เฟรมเดิม
		window.clear();

		// พื้นหลังน้ำ
		for (int i = 0; i < int(board.size()); i++)
			board[i].Draw(window);

		// แสดงเฟรมใหม่
		window.display();
	}

	return 0;
}