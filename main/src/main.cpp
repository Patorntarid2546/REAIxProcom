#include "poom.h"
#include "meepooh.h"
#include "non.h"
#include "north.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include <windows.h>


int main()
{
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