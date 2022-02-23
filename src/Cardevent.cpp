#include "Cardevent.h"
#include "Boardgame.h"
#include "Dolphin.h"
#include "Shark.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Cardevent::Cardevent(int NO, vector<Dolphin>& dolphin, vector<Shark>& shark)
{
	number = NO;
	if (number == 0)
		Cardevent::PlusDolphin(dolphin);
	if (number == 1)
		Cardevent::PlusShark(shark);
	if (number == 2)
		Cardevent::MoveDolphin(dolphin);
	if (number == 3)
		Cardevent::MoveShark(shark);
	if (number == 4)
		Cardevent::DeleteShark(shark);
}

void Cardevent::PlusDolphin(vector<Dolphin>& dolphin)
{
	int index = rand() % 127;
	int posx = dolphin.at(index).posx;
	int posy = dolphin.at(index).posy;
	dolphin.push_back(Dolphin(posx, posy));
}

void Cardevent::PlusShark(vector<Shark>& shark)
{
	int index = rand() % 127;
	int posx = shark.at(index).posx;
	int posy = shark.at(index).posy;
	shark.push_back(Shark(posx, posy));
}

void Cardevent::MoveDolphin(vector<Dolphin>& dolphin)
{
}

void Cardevent::MoveShark(vector<Shark>& shark)
{
}

void Cardevent::DeleteShark(vector<Shark>& shark)
{
	shark.pop_back();
}