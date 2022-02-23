#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "Boardgame.h"
#include "Dolphin.h"
#include "Shark.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cardevent
{
public:
	vector<Dolphin>& dolphin();
	vector<Shark>& shark();

	Cardevent(vector<Dolphin>& dolphin, vector<Shark>& shark);
	void PlusDolphin(vector<Dolphin>&);
	void PlusShark(vector<Shark>&);
	void MoveDolphin(vector<Dolphin>&);
	void MoveShark(vector<Shark>&);
	void DeleteShark(vector<Shark>&);
};
