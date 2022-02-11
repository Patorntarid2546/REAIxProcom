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

// import class ของสมาชิกแต่ละคน
#include "meepooh.h"
#include "non.h"
#include "north.h"
#include "poom.h"

	int main()
{
	srand(time(0));

	// กำหนดขนาด window ความละเอียด 1920*1080 แบบเต็มจอ
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "REAIxProcom : Survive forest from atlantis", sf::Style::Fullscreen);

	// พื้นหลังน้ำ
	vector<Boardgame> water;
	for (double x = 128; x < (128 + (64 * 15)); x += 64)
		for (double y = 64; y < (128 + (64 * 14)); y += 64)
			water.push_back(Boardgame(x, y, "water"));

	// พื้นหลังป่า
	vector<Boardgame> forest;
	for (int x = 128; x <= (128 + (64 * 2)); x += 64)
		for (int y = 64; y <= (64 + (64 * 2)); y += 64)
			forest.push_back(Boardgame(x, y, "forest"));
	for (int x = (64 * 14); x <= ((64 * 14) + (64 * 2)); x += 64)
		for (int y = 64; y <= (64 + (64 * 2)); y += 64)
			forest.push_back(Boardgame(x, y, "forest"));
	for (int x = 128; x <= (128 + (64 * 2)); x += 64)
		for (int y = (64 * 13); y <= ((64 * 13) + (64 * 2)); y += 64)
			forest.push_back(Boardgame(x, y, "forest"));
	for (int x = (64 * 14); x <= ((64 * 14) + (64 * 2)); x += 64)
		for (int y = (64 * 13); y <= ((64 * 13) + (64 * 2)); y += 64)
			forest.push_back(Boardgame(x, y, "forest"));

	// พื้นเกาะ
	//vector<random> island;
	//int islandsize = rand() % 3;
	//for (int x = 64 * 9; x >= 64 * 5; x -= 64)
	//{
	//for (int y = 64 * 8; y >= 64 * 4; x -= 64)
	//	island.push_back(random(x, y);
	//}
	// ลูปตัวเกม
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

		// พื้นหลังป่า
		for (int i = 0; i < int(forest.size()); i++)
			forest[i].Draw(window);

		// แสดงเฟรมใหม่
		window.display();
	}

	return 0;
}