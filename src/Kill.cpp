#include "Kill.h"

void Kill::CheckKill(vector<Boardgame> & board, vector<Shark> & shark, vector<Dolphin> & dolphin, vector<Player> & Splayer, vector<Player> & Cplayer, vector<Serpent> &serpent){
	for(int i = 0; i < int(board.size()); i++){
		if((board[i].haveser > 0) && (board[i].haveshark > 0)){
			for(int j = 0; j < int(serpent.size()); j++){
				for(int k = 0; k < int(shark.size()); k++){
					if(shark.at(k).getsprite().getGlobalBounds().intersects(serpent.at(j).getsprite().getGlobalBounds())){
						cout << "Delete Shark" << endl;
						shark.erase(shark.begin()+k);
						board[i].haveshark--;
					}
				}
			}
		}
		if((board[i].haveser > 0) && (board[i].havedol > 0)){
			for(int j = 0; j < int(serpent.size()); j++){
				for(int k = 0; k < int(dolphin.size()); k++){
					if(dolphin.at(k).getsprite().getGlobalBounds().intersects(serpent.at(j).getsprite().getGlobalBounds())){
						cout << "Delete Dolphine" << endl;
						dolphin.erase(dolphin.begin()+k);
						board[i].havedol--;
					}
				}
			}
		}
		if((board[i].haveser > 0) && (board[i].haveplayer > 0)){
			for(int j = 0; j < int(serpent.size()); j++){
				for(int k = 0; k < int(Splayer.size()); k++){
					if(Splayer.at(k).getsprite().getGlobalBounds().intersects(serpent.at(j).getsprite().getGlobalBounds())){
						cout << "Delete Player" << endl;
						Splayer.erase(Splayer.begin()+k);
						board[i].haveplayer--;
					}
				}
				for(int k = 0; k < int(Splayer.size()); k++){
					if(Cplayer.at(k).getsprite().getGlobalBounds().intersects(serpent.at(j).getsprite().getGlobalBounds())){
						cout << "Delete Player" << endl;
						Cplayer.erase(Cplayer.begin()+k);
						board[i].haveplayer--;
					}
				}
			}
		}
		if((board[i].haveshark > 0) && (board[i].haveplayer > 0) &&(board[i].havedol > 0) ){
			for(int j = 0; j < int(shark.size()); j++){
				for(int k = 0; k < int(dolphin.size()); k++){
					if(dolphin.at(k).getsprite().getGlobalBounds().intersects(shark.at(j).getsprite().getGlobalBounds())){
						cout << "Delete Dolphine" << endl;
						dolphin.erase(dolphin.begin()+k);
						board[i].havedol--;
					}
				}
			}
		}
		else if((board[i].haveshark > 0) && (board[i].haveplayer > 0)){
			for(int j = 0; j < int(shark.size()); j++){
				for(int k = 0; k < int(Splayer.size()); k++){
					if(Splayer.at(k).getsprite().getGlobalBounds().intersects(shark.at(j).getsprite().getGlobalBounds())){
						cout << "Delete Player" << endl;
						Splayer.erase(Splayer.begin()+k);
						board[i].haveplayer--;
					}
				}
				for(int k = 0; k < int(Splayer.size()); k++){
					if(Cplayer.at(k).getsprite().getGlobalBounds().intersects(shark.at(j).getsprite().getGlobalBounds())){
						cout << "Delete Player" << endl;
						Cplayer.erase(Cplayer.begin()+k);
						board[i].haveplayer--;
					}
				}
			}
		}
		else if((board[i].haveshark > 0) && (board[i].havedol > 0)){
			for(int j = 0; j < int(shark.size()); j++){
				for(int k = 0; k < int(dolphin.size()); k++){
					if(dolphin.at(k).getsprite().getGlobalBounds().intersects(shark.at(j).getsprite().getGlobalBounds())){
						cout << "Delete Dolphine" << endl;
						dolphin.erase(dolphin.begin()+k);
						board[i].havedol--;
					}
				}
			}
		}
	}
}