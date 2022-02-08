#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include<vector>

#include "poom.h"
#include "meepooh.h"
#include "non.h"
#include "north.h"

int main()
{
    srand(time(0));

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "REAIxProcom : Survive escape from atlantis", sf::Style::Fullscreen);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();



        window.display();
    }

    return 0;
}