#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "Boardgame.h"
#include "Dolphin.h"
#include "Network.h"
#include "Shark.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cardevent
{
public:
	void Start(bool, vector<Dolphin>& dolphin, vector<Shark>& shark, vector<Boardgame>&, Network&, sf::RenderWindow& window);
	int PlusDolphin(vector<Dolphin>&, vector<Boardgame>&);
	int PlusShark(vector<Shark>&, vector<Boardgame>&);
	int DeleteDolphin(vector<Dolphin>&);
	int DeleteShark(vector<Shark>&);
	void END(sf::RenderWindow&);
};
