#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <string>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <chrono>
#include <sys/time.h>

#include "Boardgame.h"
#include "Shark.h"
#include "Dolphin.h"
#include "Player.h"
#include "Serpent.h"

class Kill{
	bool a = false;
	public:
		void CheckKill(vector<Boardgame> &, vector<Shark> &, vector<Dolphin> &, vector<Player> &, vector<Player> &, vector<Serpent> &);
};