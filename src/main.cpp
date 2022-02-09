// import library สำหรับ gui
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

// import library พื้นฐาน
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>

// import class ของสมาชิกแต่ละคน
#include "poom.h"
#include "meepooh.h"
#include "non.h"
#include "north.h"

int main()
{
    srand(time(0));

    // กำหนดขนาด window ความละเอียด 1920*1080 แบบเต็มจอ
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "REAIxProcom : Survive escape from atlantis", sf::Style::Fullscreen);

    // พื้นหลังน้ำ
    vector<BoardgameWater> water;
    for(double x = 127; x < (127+(63.5*14)); x += 63.5) for(double y = 63.5; y < (127+(63.5*14)); y+= 63.5) water.push_back(BoardgameWater(x,y));

    //พื้นหลังพื้นที่หนี
    vector<BoardgameEscape> escape;
    for(int x = 127; x < (127+(63.5*2)); x += 63.5) for(int y = 63.5; y < (63.5+(63.5*2)); y+= 63.5) escape.push_back(BoardgameEscape(x,y));
    for(int x = (63.5*13); x < ((63.5*13)+(63.5*2)); x += 63.5) for(int y = 63.5; y < (63.5+(63.5*2)); y+= 63.5) escape.push_back(BoardgameEscape(x,y));
    for(int x = 127; x < (127+(63.5*2)); x += 63.5) for(int y = (63.5*13); y < ((63.5*13)+(63.5*2)); y+= 63.5) escape.push_back(BoardgameEscape(x,y));
    for(int x = (63.5*13); x < ((63.5*13)+(63.5*2)); x += 63.5) for(int y = (63.5*13); y < ((63.5*13)+(63.5*2)); y+= 63.5) escape.push_back(BoardgameEscape(x,y));

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

        //พื้นหลังน้ำ
        for(int i = 0; i < int(water.size()); i++) water[i].DrawWater(window);

        for(int i = 0; i < int(escape.size()); i++) escape[i].DrawEscape(window);

        // แสดงเฟรมใหม่
        window.display();
    }

    return 0;
}