#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "Dolphin.h"
#include "Shark.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cardevent
{
	int number;

public:
	vector<Dolphin>& dolphin();
	vector<Shark>& shark();

	Cardevent(int, vector<Dolphin>&, vector<Shark>&);
	void PlusDolphin(vector<Dolphin>&);
	void PlusShark(vector<Shark>&);
	void MoveDolphin(vector<Dolphin>&);
	void MoveShark(vector<Shark>&);
	void DeleteShark(vector<Shark>&);
};
