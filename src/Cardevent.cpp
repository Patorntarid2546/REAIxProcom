#include "Cardevent.h"
#include "Boardgame.h"
#include "Dolphin.h"
#include "Network.h"
#include "Shark.h"
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Cardevent::Start(bool toggle, vector<Dolphin>& dolphin, vector<Shark>& shark, vector<Boardgame>& board, Network& network, sf::RenderWindow& window)
{
	if (toggle == 1)
	{
		int number = rand() % 100;
		if (number <= 24)
		{
			network.senttext("PlusDol");
			network.senttext(to_string(Cardevent::PlusDolphin(dolphin, board)));
		}
		else if (number <= 48)
		{
			network.senttext("PlusShark");
			network.senttext(to_string(Cardevent::PlusShark(shark, board)));
		}
		else if (number <= 72)
		{
			network.senttext("DeleteDol");
			network.senttext(to_string(Cardevent::DeleteDolphin(dolphin)));
		}
		else if (number <= 96)
		{
			network.senttext("DeleteShark");
			network.senttext(to_string(Cardevent::DeleteShark(shark)));
		}
		else
			Cardevent::END(window);
	}
}

int Cardevent::PlusDolphin(vector<Dolphin>& dolphin, vector<Boardgame>& board)
{
	vector<int> a;
	for (int i = 0; i < int(board.size()); i++)
	{
		if (board[i].GetType() == "water")
		{
			a.push_back(i);
		}
	}
	int b = rand() % int(a.size());
	dolphin.push_back(Dolphin(board[b].getcen().at(0), board[b].getcen().at(0)));
	return b;
}

int Cardevent::PlusShark(vector<Shark>& shark, vector<Boardgame>& board)
{
	vector<int> a;
	for (int i = 0; i < int(board.size()); i++)
	{
		if (board[i].GetType() == "water")
		{
			a.push_back(i);
		}
	}
	int b = rand() % int(a.size());
	shark.push_back(Shark(board[b].getcen().at(0), board[b].getcen().at(0)));
	return b;
}

int Cardevent::DeleteDolphin(vector<Dolphin>& dolphin)
{
	if (int(dolphin.size()) > 1)
	{
		int b = rand() % int(dolphin.size());
		dolphin.erase(dolphin.begin() + b);
		return b;
	}
	return 0;
}

int Cardevent::DeleteShark(vector<Shark>& shark)
{
	if (int(shark.size()) > 1)
	{
		int b = rand() % int(shark.size());
		shark.erase(shark.begin() + b);
		return b;
	}
	return 0;
}

void Cardevent::END(sf::RenderWindow& window)
{
	sf::Texture image;
	sf::Sprite image2;
	image.loadFromFile("image\\Card\\End_Game.png");
	image2.setTexture(image);
	image2.setPosition(0, 0);
	window.draw(image2);
	sf::Font amazingfont1;
	if (!amazingfont1.loadFromFile("image\\ShortBaby-Mg2w.ttf"))
		printf("Load ttf fail");

	if (C > S)
	{
		sf::Text Player1("Player1 WIN", amazingfont1, 150);
		Player1.setPosition(590, 800);
		Player1.setFillColor(sf::Color::Black);
		Player1.setOutlineColor(sf::Color::White);
		Player1.setOutlineThickness(5.f);
	}

	if (S > C)
	{
		sf::Text Player2("Player2 WIN", amazingfont1, 150);
		Player2.setPosition(590, 800);
		Player2.setFillColor(sf::Color::Black);
		Player2.setOutlineColor(sf::Color::White);
		Player2.setOutlineThickness(5.f);
	}

	if (S == C)
	{
		sf::Text draw("DRAW", amazingfont1, 150);
		draw.setPosition(590, 800);
		draw.setFillColor(sf::Color::Black);
		draw.setOutlineColor(sf::Color::White);
		draw.setOutlineThickness(5.f);
	}
}