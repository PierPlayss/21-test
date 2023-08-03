//SDL2
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

//C++
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <fstream>


//Headers
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "SDL2SoundEffects.h"

//Game
#include "deckHandler.h"
#include "scoreHandler.h"


using namespace std;

RenderWindow window("21", 1280, 720);
//RenderWindow gamesWindow("Games Window", 1000, 500);

const int FPS = 60;
int refreshRate = 1000 / FPS;
int frame = 0;

//Textures

SDL_Texture* bgTexture = window.loadTexture("res/gfx/lightning/bg.png");
Entity bgEntity(0, 0, 1280, 720, bgTexture);

SDL_Texture* lgTexture1 = window.loadTexture("res/gfx/lightning/gm1.png");
Entity lgEntity1(0, 415, 1280, 305, lgTexture1);

SDL_Texture* lgTexture2 = window.loadTexture("res/gfx/lightning/gm2.png");
Entity lgEntity2(0, 415, 1280, 305, lgTexture2);




int main(int argc, char* argv[]) {
	
	//Game
	//Setup
	srand(time(NULL));
	//Game Bools
	bool gameOver = false;
	bool turnOver = false;
	bool cardDraw = false;
	int turn = 0;


	//Puntajes

	int playerScores[2]{ 0,0 };
	int currentBet;

	//Cartas
	int currentCard;
	bool cartasDisponibles[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
	int cartasP[2][6] = { {-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1} };
	int totalCardsDraw = 0;
	//Cartas String
	string cartasS[2][6];

	int cardPos[2] = { 0,0 };


	//Score
	int Score[2] = { 0,0 };
	int scoreLimit = 21;


	

	//Game

	int contador2 = 1;
	int opcion;

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		cout << "IMG_init has failed. Error: " << SDL_GetError() << endl;

	if (TTF_Init() == -1) {
		cout << "TTF_init has failed. Error: " << SDL_GetError() << endl;
	}
	int mouseX, mouseY;
	int clicks = 0;
	int clickMenu = 0;


	SDL_Event event;
	SDL_Event mouseEvent{ SDL_MOUSEMOTION };

	bool gameRunning = true;
	int contador = 0;
	bool start = false;
	bool stop = false;
	bool toggleMenu = false;
	int ended = 0;

	bool RoundOver = false;
	bool reseted = false;
	int ultimajugada = 0;

	stringstream translate;
	string turnString;

	srand(time(NULL));

	resetCards(cartasDisponibles, cartasP, cartasS, cardPos, totalCardsDraw);
	resetScore(Score, turn, ultimajugada);
	SetupDeck(cartasDisponibles, cartasP, cardPos, cartasS);



	while (gameRunning)
	{

		window.RenderWindow::clear();
		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
			if (event.type == SDL_MOUSEMOTION) {

				mouseX = event.motion.x;
				mouseY = event.motion.y;
				//cout << mouseX << "," << mouseY << endl;

			}
			if (event.type == SDL_MOUSEBUTTONUP) {
				if (event.button.state == SDL_RELEASED) {

					SDL_Delay(20);
					clicks++;
					clickMenu++;
					if (clicks == 1) {
						if (toggleMenu == false) {
							if (start == false) {
								start = true;
							}
							else {
								stop = true;
							}
						}
						clicks = 0;
					}

				}
			}

			if (event.type == SDL_KEYDOWN) {
				if ((event.key.keysym.sym == SDLK_RETURN) &&
					(event.key.keysym.mod & KMOD_ALT))
				{
					window.ToggleFullscreen();
				}
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					if (toggleMenu == false) {
						toggleMenu = true;
					}
					else toggleMenu = false;
				}

			}


			if (event.type == SDL_KEYUP) {
				if (RoundOver == false){
					if (event.key.keysym.sym == SDLK_1) {

						drawCard(turn, cartasDisponibles, cardPos, totalCardsDraw, cartasP, cartasS);
						ultimajugada = 1;
						turn = TurnOver(turn);

					}
					if (event.key.keysym.sym == SDLK_2) {

						if (ultimajugada == 2) {
							RoundOver = true;
						}
						else {
							ultimajugada = 2;
						}

						turn = TurnOver(turn);

					}
				}
				else {
					if (event.key.keysym.sym == SDLK_3) {
						RoundOver = false;
						reseted = false;
						if (reseted == false) {
							resetCards(cartasDisponibles, cartasP, cartasS, cardPos, totalCardsDraw);
							resetScore(Score, turn, ultimajugada);
							SetupDeck(cartasDisponibles, cartasP, cardPos, cartasS);
							reseted = true;
						}

					}
				}
				
			}
		}



		if (stop == false) {												//game running

			window.render(bgEntity, 1);
		
			//window.backgroundColor(20, 50, 0, 255);
			//window.drawText("21", 10, 10, 255, 255, 255, 255, 40);

		
		}
		
		renderDeck(window, cartasP,cartasS, cardPos,RoundOver);
		
		
		
		if (RoundOver == false) {

			if (turn == 0)
			{
				//SDL_SetTextureAlphaMod(lgTexture1, 60);
				SDL_SetTextureBlendMode(lgTexture1, SDL_BLENDMODE_MUL);
				window.render(lgEntity1, 1);
			}
			else
			{
				//SDL_SetTextureAlphaMod(lgTexture2, 200);
				SDL_SetTextureBlendMode(lgTexture2, SDL_BLENDMODE_MUL);
				window.render(lgEntity2, 1);
			}

			translate.clear();
			turn += 1;
			translate << turn;
			translate >> turnString;
			window.textCustom(turnString.c_str(), "res/font/MicroExtendFLF.ttf", 0, 0, 255, 255, 255, 255, 40, 1, 0, 0);
			window.textCustom("1 - Pedir carta     2- Pasar turno", "res/font/MicroExtendFLF.ttf", 1, 600, 255, 255, 255, 255, 25, 1, 0, 300);
			turn -= 1;
		}
		else{
			checkWinner(window, Score,scoreLimit);
			window.textCustom("Presiona 3 para continuar", "res/font/MicroExtendFLF.ttf", 1, 600, 255, 255, 255, 255, 25, 1, 0, 300);
		}

	
		ScoreHandler(window, turn, cartasP, cardPos, RoundOver, Score, scoreLimit);
		



		window.display();

	
		Sleep(refreshRate);
		if (frame == FPS) {
			frame = 0;
		}
		else frame++;
	}

	window.cleanUp();
	SDL_Quit();
	TTF_Quit();

	return 0;
}
