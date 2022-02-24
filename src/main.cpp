//import library สำหรับ gui
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

// import library พื้นฐาน
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

// import class สำหรับหน้าเริ่มเกม
#include "Startgame.h"
#include "Network.h"
#include "Boardgame.h"
#include "islandrandom.h"
#include "player.h"
#include "Dolphin.h"
#include "Shark.h"
#include "Serpent.h"
#include "Dice.h"
#include "Checkscore.h"

int main()
{
	srand(time(0));

    string poc[8] = {"image\\Guide\\9.guide6.png","image\\Guide\\9.guide1.png","image\\Guide\\9.guide1.png","image\\Guide\\9.guide2.png","image\\Guide\\9.guide3.png",
	"image\\Guide\\9.guide4.png","image\\Guide\\9.guide5.png","image\\Guide\\9.guide7.png"};

	// กำหนดขนาด window ความละเอียด 1920*1080 แบบเต็มจอ
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "REAIxProcom : Survive forest from atlantis"); //,

	char mode = 'c';
	string my_ipp;

	Startgame B(false);
	B.start(window, my_ipp, mode);


	Startgame a(true);
	a.start(window, my_ipp, mode);



	Network network;
	network.connect(mode,"");

	sf::Texture bg1;
	sf::Sprite bg;
	bg1.loadFromFile("image\\Startgame\\6.ingame (1).jpg");
	bg.setTexture(bg1);
	bg.setPosition(0,0);

	sf::RectangleShape frame;
	frame.setSize(sf::Vector2f(305.f,305.f));
	frame.setPosition(1472,129);
	frame.setFillColor(sf::Color::White);
	frame.setOutlineColor(sf::Color::Black);
	frame.setOutlineThickness(5.f);

	// ขนาด block 6 เหลี่ยม
	int block_h = 96, block_w = 84, set_h = -10, set_w = 600;

	// วางบล็อคน้ำ 6 เหลี่ยม
	vector<Boardgame> board;
	int nub , nubx;
	for(int i = 1; i <= 14; i+=2){
		int y = set_h+(i*block_h*3/4);
		if(i <= 7){
			if(i < 7){
				nub = 1-i;
				for(double j = 1-(i+5)/2; j <= 1+(i+5)/2; j++){
					int x = set_w+(j*block_w);
					board.push_back(Boardgame(x, y, "water", i-7, nub++));
				}
				y = set_h+72+(i*block_h*3/4);
				nub = -i;
				for(double l = 1-(i+5)/2; l <= 2+(i+5)/2; l++){
					int x = set_w-44+(l*block_w);
					board.push_back(Boardgame(x, y, "water", i-6, nub++));
				}
			}
			else{
				nub = 1-i;
				nubx = nub;
				for(double j = 1-(i+5)/2; j <= 1+(i+5)/2; j++){
					int x = set_w+(j*block_w);
					board.push_back(Boardgame(x, y, "water", i-7, nub++));
				}
			}
		}

		else{
			int nub2 = nubx;
			y -= 72;
			for(double l = 1-(7-(i%7)+5)/2; l <= 2+(7-(i%7)+5)/2; l++){
				int x = set_w-44+(l*block_w);
				board.push_back(Boardgame(x, y, "water", i-8, nub2++));
			}
			y += 72;
			nub2 = nubx;
			for(double j = 1-(7-(i%7)+5)/2; j <= 1+(7-(i%7)+5)/2; j++){
				int x = set_w+(j*block_w);
				board.push_back(Boardgame(x, y, "water", i-7, nub2++));
			}
		}
	}

	// วางบล็อคเกาะ 6 เหลี่ยม
	if (mode == 's'){
		int z = board.size();
		for (int i = 0; i < z; i++){
			vector<int> a = (board.at(i)).getqrs();
			double dis = (abs(a.at(0)) + abs(a.at(1)) + abs(a.at(2)))/2;
			if(dis <= 3 && dis > 0){
				(board.at(i)).ChangeType("");
				network.senttext((board.at(i)).GetTile());
			}
		}
	}
	else{
		int z = board.size();
		for (int i = 0; i < z; i++){
			vector<int> a = (board.at(i)).getqrs();
			double dis = (abs(a.at(0)) + abs(a.at(1)) + abs(a.at(2)))/2;
			if(dis <= 3 && dis > 0){
				string a = network.recievedtext();
				(board.at(i)).ChangeType(a);
			}
		}
	}

	// วางบล็อคป่า 6 เหลี่ยม
	vector<int> secc = {0,7,15,24,34,45};
	nub = -6;
	for (int j = 5; j >= 4; j--){
		for (int i = 1; i < j; i++){
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)))).getpos()).at(0) - 84*i,
				((board.at(secc.at(2*(5-j)))).getpos()).at(1), "forest", nub, ((board.at(secc.at(2*(5-j)))).getqrs()).at(0)-i));
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)+1))).getpos()).at(0) - 84*i,
				((board.at(secc.at(2*(5-j)+1))).getpos()).at(1), "forest", nub+1, ((board.at(secc.at(2*(5-j)+1))).getqrs()).at(0)-i));
		}
		nub+=2;
	}
	secc = {120,112,103,93,82,70};
	nub = 6;
	for (int j = 5; j >= 4; j--){
		for (int i = 1; i < j; i++){
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)))).getpos()).at(0) - 84*i,
				((board.at(secc.at(2*(5-j)))).getpos()).at(1), "forest", nub, ((board.at(secc.at(2*(5-j)))).getqrs()).at(0)-i));
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)+1))).getpos()).at(0) - 84*i,
				((board.at(secc.at(2*(5-j)+1))).getpos()).at(1), "forest", nub-1, ((board.at(secc.at(2*(5-j)+1))).getqrs()).at(0)-i));
		}
		nub-=2;
	}
	secc = {6,14,23,33,44,56};
	nub = -6;
	for (int j = 5; j >= 4; j--){
		for (int i = 1; i < j; i++){
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)))).getpos()).at(0) + 84*i,
				((board.at(secc.at(2*(5-j)))).getpos()).at(1), "forest", nub, ((board.at(secc.at(2*(5-j)))).getqrs()).at(0)+i));
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)+1))).getpos()).at(0) + 84*i,
				((board.at(secc.at(2*(5-j)+1))).getpos()).at(1), "forest", nub+1, ((board.at(secc.at(2*(5-j)+1))).getqrs()).at(0)+i));
		}
		nub+=2;
	}
	secc = {126,119,111,102,92,81,70};
	nub = 6;
	for (int j = 5; j >= 4; j--){
		for (int i = 1; i < j; i++){
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)))).getpos()).at(0) + 84*i,
			((board.at(secc.at(2*(5-j)))).getpos()).at(1), "forest", nub, ((board.at(secc.at(2*(5-j)))).getqrs()).at(0)+i));
			board.push_back(Boardgame(((board.at(secc.at(2*(5-j)+1))).getpos()).at(0) + 84*i,
			((board.at(secc.at(2*(5-j)+1))).getpos()).at(1), "forest", nub-1, ((board.at(secc.at(2*(5-j)+1))).getqrs()).at(0)+i));
		}
		nub-=2;
	}

	vector<Player> Splayer;
	vector<Player> Cplayer;


	// vector<Checkscore> check;
	// vector<int> chec;
	// for (int j = 0;j <= 17;j++){
	// 	for(int i = 0; int(board.size()); i++){
	// 		vector<double> posplayer = Cplayer.at(j).getpos();
	// 		vector<double> posboard = board.at(i).getpos();
	// 		string type = board.at(i).GetType();
	// 		chec = check.at(0).checkpos(posplayer,posboard,type);
	// 	}

	// }


	for(int i = 0; i < 18; i++){
		Splayer.push_back(Player(mode, ((board[168]).getcen()).at(0)+48, ((board[69]).getcen()).at(1)));
	}

	char Emode;
	if(mode == 's') Emode = 'c';
	else Emode = 's';
	for(int i = 0; i < 18; i++){
		Cplayer.push_back(Player(Emode, ((board[168]).getcen()).at(0)+48, ((board[69]).getcen()).at(1)));
	}

	vector<Dolphin> dolphin;
	vector<Shark> shark;
	vector<Serpent> serpent;
	if (mode == 's'){
		while (true){
			nub = rand()%board.size();
			if (((board.at(nub)).GetType() == "water") && ((board.at(nub)).haveall == 0)){
				dolphin.push_back(Dolphin(((board.at(nub)).getcen()).at(0), ((board.at(nub)).getcen()).at(1)));
				(board.at(nub)).havedol++;
				string str = to_string(nub);
				network.senttext(str);
				break;
			}
		}

		while (true){
			nub = rand()%board.size();
			if (((board.at(nub)).GetType() == "water") && ((board.at(nub)).haveall == 0)){
				shark.push_back(Shark(((board.at(nub)).getcen()).at(0), ((board.at(nub)).getcen()).at(1)));
				(board.at(nub)).haveshark++;
				string str = to_string(nub);
				network.senttext(str);
				break;
			}
		}

		serpent.push_back(Serpent(((board.at(15)).getcen()).at(0), ((board.at(15)).getcen()).at(1)));
		(board.at(15)).haveser++;
		serpent.push_back(Serpent(((board.at(103)).getcen()).at(0), ((board.at(103)).getcen()).at(1)));
		(board.at(103)).haveser++;
		serpent.push_back(Serpent(((board.at(23)).getcen()).at(0), ((board.at(23)).getcen()).at(1)));
		(board.at(23)).haveser++;
		serpent.push_back(Serpent(((board.at(111)).getcen()).at(0), ((board.at(111)).getcen()).at(1)));
		(board.at(111)).haveser++;
	}
	else{

		while (true){
			nub = network.recieveddouble();
			if (((board.at(nub)).GetType() == "water") && ((board.at(nub)).haveall == 0)){
				dolphin.push_back(Dolphin(((board.at(nub)).getcen()).at(0), ((board.at(nub)).getcen()).at(1)));
				(board.at(nub)).havedol++;
				break;
			}
		}

		while (true){
			nub = network.recieveddouble();
			if (((board.at(nub)).GetType() == "water") && ((board.at(nub)).haveall == 0)){
				shark.push_back(Shark(((board.at(nub)).getcen()).at(0), ((board.at(nub)).getcen()).at(1)));
				(board.at(nub)).haveshark++;
				break;
			}
		}

		serpent.push_back(Serpent(((board.at(15)).getcen()).at(0), ((board.at(15)).getcen()).at(1)));
		(board.at(15)).haveser++;
		serpent.push_back(Serpent(((board.at(103)).getcen()).at(0), ((board.at(103)).getcen()).at(1)));
		(board.at(103)).haveser++;
		serpent.push_back(Serpent(((board.at(23)).getcen()).at(0), ((board.at(23)).getcen()).at(1)));
		(board.at(23)).haveser++;
		serpent.push_back(Serpent(((board.at(111)).getcen()).at(0), ((board.at(111)).getcen()).at(1)));
		(board.at(111)).haveser++;
	}

	vector<Dice> dice;
	dice.push_back(Dice(576.0,156.0,1));
	dice.push_back(Dice(576.0,156.0,2));
	dice.push_back(Dice(576.0,156.0,3));

	//score ระบบคะแนน
	sf::Font amazingfont;
    if(!amazingfont.loadFromFile("image\\ShortBaby-Mg2w.ttf"))
	   printf("Load ttf fail");

	sf::Text Score("Score",amazingfont,80);
	Score.setPosition(1480,950);
	Score.setFillColor(sf::Color::Black);
	Score.setOutlineColor(sf::Color::Cyan);
	Score.setOutlineThickness(8.f);

	//guide exit ในเกม
	sf::Texture guide;
	guide.loadFromFile("image\\startgame2\\8.guide.png");
	sf::Sprite guider;
    guider.setTexture(guide);
	guider.setPosition(1870,600);

	sf::Texture exit;
	exit.loadFromFile("image\\startgame2\\8.leave.png");
    sf::Sprite exiter;
	exiter.setTexture(exit);
	exiter.setPosition(1870,200);

	int num_sand = 0, num_solid = 0, num_mount = 0;
	for(int i = 0; i < int(board.size()); i++){
		if(board[i].GetTile() == "sand") num_sand++;
		else if(board[i].GetTile() == "solid") num_solid++;
		else if(board[i].GetTile() == "mount") num_mount++;
	}

	cout << num_sand << " " << num_solid << " " << num_mount << endl;

	bool turn;
	bool isclick = false;
	int Pwhich = 0;
	if(mode == 's') turn = true;
	else turn = false;
	int check = 0;
	bool bk = false;

	while (window.isOpen()){
		sf::Event event;
		if(bk){
			break;
		}
		if(turn){
			while (window.pollEvent(event)){
				//ปุ่ม guide and exit
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				    /*if(guider.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
					(ลอกจาก startgame);
				    }*/
					if(exiter.getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
					window.close();
				    }
				}
				// ถ้ามีการปิดหน้าต่างให้ปิดโปรแกรม
				if (event.type == sf::Event::Closed)
					window.close();
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
					if(isclick == false){
						for(int i = 0; i < int(Splayer.size()); i++){
							if(Splayer.at(i).getsprite().getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
								isclick = true;
								Pwhich = i;
								break;
							}
						}
					}
					else{
						for(int i = 0; i < int(board.size()); i++){
							if((board.at(i).getsprite().getGlobalBounds()).contains(Splayer.at(Pwhich).getcen().at(0), Splayer.at(Pwhich).getcen().at(1))){
								if(board.at(i).haveplayer == 0){
									if(board.at(i).GetType() == "island"){
										isclick = false;
										turn = false;
										network.sentpos(Pwhich, Splayer.at(Pwhich).posx, Splayer.at(Pwhich).posy);
										network.senttext("pass");
										board[i].haveplayer++;
										board[i].index_player = Pwhich;
										Splayer[Pwhich].index_board = i;
										break;
									}
								}
							}
						}
					}

				}
				if (event.type == sf::Event::MouseMoved){
					if(isclick){
						float x = event.mouseMove.x;
						float y = event.mouseMove.y;
						Splayer[Pwhich].Changepos(x,y);
						// network.senttext("con");
						// network.senttext(to_string(Pwhich));
						// network.senttext(to_string(x));
						// network.senttext(to_string(y));
					}
				}
			}

		}
		else{
			string text = network.recievedtext();
			if(text == "pass") turn = true;
			else if(text == "pos"){
				double po = stof(network.recievedtext());
				double x = stof(network.recievedtext());
				double y = stof(network.recievedtext());
				Cplayer[po].Changepos(x,y);
				Cplayer[po].Draw(window);
				for(int i = 0; i < int(board.size()); i++){
					if((board.at(i).getsprite().getGlobalBounds()).contains(Cplayer.at(po).getcen().at(0), Cplayer.at(po).getcen().at(1))){
						cout << "ok0" << endl;
						board[i].haveplayer++;
						board[i].index_player = po;
						Cplayer[po].index_board = i;
						check++;
						if(check == 1){
							network.senttext("break");
							bk = true;
						}
					}
				}
			}
			else if(text == "con"){
				double po = stof(network.recievedtext());
				double x = stof(network.recievedtext());
				double y = stof(network.recievedtext());
				Cplayer[po].Changepos(x,y);
			}
			if(text == "break") bk = true;
		}
		// เคลียร์เฟรมเดิม
		window.clear();

		window.draw(bg);

		// พื้นที่
		for (int i = 0; i < int(board.size()); i++) board[i].Draw(window);

		// Enplayer
		for (int i = 0; i < int(Cplayer.size()); i++) Cplayer[i].Draw(window);

		// player
		for (int i = 0; i < int(Splayer.size()); i++) Splayer[i].Draw(window);

		// Dolphin
		for (int i = 0; i < int(dolphin.size()); i++) dolphin[i].Draw(window);

		// Shark
		for (int i = 0; i < int(shark.size()); i++) shark[i].Draw(window);

		// Serpent
		for (int i = 0; i < int(serpent.size()); i++) serpent[i].Draw(window);

		// แสดงเฟรมใหม่
        window.draw(frame);
		window.draw(guider);
		window.draw(Score);
		window.draw(exiter);

		window.display();
	}

	if(mode == 's') turn = true;
	else turn = false;
	isclick = false;
	Pwhich = 0;
	int Bwhich;
	// bool phase_one = false;
	bool phase_two = false;
	bool phase_three = false;
	bool phase_four = true;
	bool phase_four_once = true;

	int hav = 0;

	int ranran = rand()%3;

	cout << "Start" << endl;

	//ห้ามลบ เอาไว้เคลียร์แคช
	if(mode == 's') cout << network.recievedtext() << endl;

	while (window.isOpen()){
		// cout << phase_three << endl;
		sf::Event event;
		if(turn){
			// ลูป Event
			while (window.pollEvent(event)){
				// ถ้ามีการปิดหน้าต่างให้ปิดโปรแกรม
				if (event.type == sf::Event::Closed)
					window.close();
				if(phase_two){
					if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
						if(isclick == false){
							for(int i = 0; i < int(Splayer.size()); i++){
								if(Splayer.at(i).getsprite().getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
									for(int j = 0; j < int(board.size()); j++){
										if((board.at(j).getsprite().getGlobalBounds()).contains(Splayer.at(i).getcen().at(0), Splayer.at(i).getcen().at(1))){
											Bwhich = j;
											break;
										}
									}
									isclick = true;
									Pwhich = i;
									board[i].haveplayer--;
									board[i].index_player = 999;
									break;
								}
							}
						}
						else{
							hav = 0;
							for(int i = 0; i < int(board.size()); i++){
								if((board.at(i).getsprite().getGlobalBounds()).contains(Splayer.at(Pwhich).getcen().at(0), Splayer.at(Pwhich).getcen().at(1))){
									int distance = board[i] + board[Bwhich];
									if(board[Bwhich].GetType() == "island"){
										if(board[i].GetType() == "water"){
											for(int j = 0; j < int(board.size()); j++){
												if((board[j].GetType() == "water")&& (j!=i)){
													if(board[i] + board[j] <= 1){
														hav++;
													}
												}
											}
											if(hav < 6){
												if(distance <= 3){
													isclick = false;
													phase_two = false;
													phase_three = true;
													network.sentpos(Pwhich, Splayer.at(Pwhich).posx, Splayer.at(Pwhich).posy);
													cout << "sent" << endl;
													board[i].haveplayer++;
													board[i].index_player = Pwhich;
													Splayer[Pwhich].index_board = i;
													break;
												}
											}
										}
										else{
											if(distance <= 3){
												isclick = false;
												phase_two = false;
												phase_three = true;
												network.sentpos(Pwhich, Splayer.at(Pwhich).posx, Splayer.at(Pwhich).posy);
												cout << "sent" << endl;
												board[i].haveplayer++;
												board[i].index_player = Pwhich;
												Splayer[Pwhich].index_board = i;
												}
										}
										break;
									}
									else{
										if(distance <= 1){
											isclick = false;
											phase_two = false;
											phase_three = true;
											network.sentpos(Pwhich, Splayer.at(Pwhich).posx, Splayer.at(Pwhich).posy);
											board[i].haveplayer++;
											board[i].index_player = Pwhich;
											Splayer[Pwhich].index_board = i;
											break;
										}
									}
								}
							}
						}
					}
					if (event.type == sf::Event::MouseMoved){
						if(isclick){
							float x = event.mouseMove.x;
							float y = event.mouseMove.y;
							Splayer[Pwhich].Changepos(x,y);
							// network.senttext("con");
							// network.senttext(to_string(Pwhich));
							// network.senttext(to_string(x));
							// network.senttext(to_string(y));
						}
					}
				}
				else if(phase_three){
					if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

						for(int i = 0; i < int(board.size()); i++){
							if(board.at(i).getsprite().getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
								if(board[i].GetType() == "island"){
									if(num_sand > 0){
										if(board[i].GetTile() == "sand"){
											board[i].alive = false;
											num_sand--;
											board[i].Delete();
											turn = false;
											network.senttext("delete");
											network.senttext(to_string(i));
											network.senttext("sand");
											network.senttext("pass");
											phase_three = false;
											phase_four = true;
											ranran = rand()%3;
										}
									}
									else if(num_solid > 0){
										if(board[i].GetTile() == "solid"){
											board[i].alive = false;
											num_solid--;
											board[i].Delete();
											turn = false;
											network.senttext("delete");
											network.senttext(to_string(i));
											network.senttext("solid");
											network.senttext("pass");
											phase_three = false;
											phase_four = true;
											ranran = rand()%3;
										}
									}
									else if(num_mount > 0){
										if(board[i].GetTile() == "mount"){
											board[i].alive = false;
											num_mount--;
											board[i].Delete();
											turn = false;
											network.senttext("delete");
											network.senttext(to_string(i));
											network.senttext("mount");
											network.senttext("pass");
											phase_three = false;
											phase_four = true;
											ranran = rand()%3;
										}
									}
									isclick = false;
								}
							}
						}
					}
				}
				else if(phase_four){
					if(ranran == 0){
						if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
							for(int i = 0; i < int(serpent.size()) ;i++){
								if(serpent.at(i).getsprite().getGlobalBounds().contains(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y)){
									if(isclick == false){
										Pwhich = i;
										for(int j = 0; j < int(board.size()); j++){
											if((board.at(j).getsprite().getGlobalBounds()).contains(serpent.at(i).getcen().at(0), serpent.at(i).getcen().at(1))){
												Bwhich = j;
												isclick = true;
												phase_four_once = false;
												break;
											}
										}
									}
									else{
										isclick = false;
									}
								}
							}
						}
						if (event.type == sf::Event::MouseMoved){
							if(isclick){
								float x = event.mouseMove.x;
								float y = event.mouseMove.y;
								serpent[Pwhich].Changepos(x,y);
							}
						}
					}
				}
			}
		}
		else{
			string text = network.recievedtext();
			if(text == "pass"){
				turn = true;
			}
			else if(text == "pos"){
				double po = stof(network.recievedtext());
				double x = stof(network.recievedtext());
				double y = stof(network.recievedtext());
				Cplayer[po].Changepos(x,y);
				Cplayer[po].Draw(window);
				for(int i = 0; i < int(board.size()); i++){
					if((board.at(i).getsprite().getGlobalBounds()).contains(Cplayer.at(po).getcen().at(0), Cplayer.at(po).getcen().at(1))){
						board[i].haveplayer++;
						board[i].index_player = po;
						Cplayer[po].index_board = i;
					}
				}
			}
			else if(text == "con"){
				double po = stof(network.recievedtext());
				double x = stof(network.recievedtext());
				double y = stof(network.recievedtext());
				Cplayer[po].Changepos(x,y);
			}
			else if(text == "delete"){
				int po = stoi(network.recievedtext());
				board[po].alive = false;
				board[po].Delete();
				text = network.recievedtext();
				if(text == "sand") num_sand--;
				else if(text == "solid") num_solid--;
				else if(text == "mount") num_mount--;
			}
		}

		// เคลียร์เฟรมเดิม
		window.clear();

		window.draw(bg);

		// พื้นที่
		for (int i = 0; i < int(board.size()); i++) board[i].Draw(window);

		// Enplayer
		for (int i = 0; i < int(Cplayer.size()); i++) Cplayer[i].Draw(window);

		// player
		for (int i = 0; i < int(Splayer.size()); i++) Splayer[i].Draw(window);

		// Dolphin
		for (int i = 0; i < int(dolphin.size()); i++) dolphin[i].Draw(window);

		// Shark
		for (int i = 0; i < int(shark.size()); i++) shark[i].Draw(window);

		// Serpent
		for (int i = 0; i < int(serpent.size()); i++) serpent[i].Draw(window);

		// แสดงเฟรมใหม่
		window.draw(frame);
		window.draw(guider);
		window.draw(Score);
		window.draw(exiter);

		if(phase_four_once){
			dice[ranran].Draw(window);
		}


		window.display();

	}

	return 0;
}