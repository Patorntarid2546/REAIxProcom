// #include "Cardevent.h"
// #include "Boardgame.h"
// #include "Dolphin.h"
// #include "Shark.h"
// #include <ctime>
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// Cardevent::Cardevent(vector<Dolphin>& dolphin, vector<Shark>& shark)
// {
// 	int number = rand() % 5;
// 	if (number == 0)
// 		Cardevent::PlusDolphin(dolphin);
// 	if (number == 1)
// 		Cardevent::PlusShark(shark);
// 	if (number == 2)
// 		Cardevent::MoveDolphin(dolphin);
// 	if (number == 3)
// 		Cardevent::MoveShark(shark);
// 	if (number == 4)
// 		Cardevent::DeleteShark(shark);
// }

// void Cardevent::PlusDolphin(vector<Dolphin>& dolphin)
// {
// 	vector<Boardgame> board;
// 	for (int i = 0; int(board.size()); i++)
// 	{
// 		if (dolphin.at(i - 1).getpos() != dolphin.at(i).getpos())
// 		{
// 			if (board.at(i).GetType() == "water")
// 			{
// 				vector<double> a = board.at(i).getpos();
// 				dolphin.push_back(Dolphin(a.at(1), a.at(2)));
// 			}
// 		}
// 	}
// }

// void Cardevent::PlusShark(vector<Shark>& shark)
// {
// 	vector<Boardgame> board;
// 	for (int i = 0; int(board.size()); i++)
// 	{
// 		if (shark.at(i - 1).getpos() != shark.at(i).getpos())
// 		{
// 			if (board.at(i).GetType() == "water")
// 			{
// 				vector<double> a = board.at(i).getpos();
// 				shark.push_back(Shark(a.at(1), a.at(2)));
// 			}
// 		}
// 	}
// }

// void Cardevent::MoveDolphin(vector<Dolphin>& dolphin)
// {
// 	vector<Boardgame> board;
// 	int nb = rand() % dolphin.size();
// 	for (int i = 0; int(board.size()); i++)
// 	{
// 		if (board.at(i).GetType() == "water" && board.at(i).getpos() != dolphin.at(i).getpos())
// 		{
// 			vector<double> a = dolphin.at(i).getpos();
// 			int old = i;
// 			dolphin.push_back(Dolphin(a.at(1), a.at(2)));
// 			dolphin.erase(dolphin.begin() + i, dolphin.begin() + i);
// 		}
// 	}
// }

// void Cardevent::MoveShark(vector<Shark>& shark)
// {
// 	vector<Boardgame> board;
// 	int nb = rand() % shark.size();
// 	for (int i = 0; int(board.size()); i++)
// 	{
// 		if (board.at(i).GetType() == "water" && board.at(i).getpos() != shark.at(i).getpos())
// 		{
// 			vector<double> a = shark.at(i).getpos();
// 			int old = i;
// 			shark.push_back(Shark(a.at(1), a.at(2)));
// 			shark.erase(shark.begin() + i, shark.begin() + i);
// 		}
// 	}
// }
// void Cardevent::DeleteShark(vector<Shark>& shark)
// {
// 	shark.pop_back();
// }