#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <sstream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


#include "deckHandler.h"

using namespace std;

int TurnOver(int turn) {
	if (turn == 0) {
		return 1;
	}
	else
	{
		return 0;
	}

	
}

void resetCards(bool cartasDisponibles[], int cartasP[][6], string cartasS[][6], int cardPos[], int totalCardsDraw) {
	totalCardsDraw = 0;
	stringstream translate;

	for (int i = 0; i < 11; i++) {
		cartasDisponibles[i] = 0;
	}
	for (int z = 0; z < 2; z++) {
		for (int j = 0; j < 6; j++) {
			cartasP[z][j] = -1;
			translate.clear();
			translate << cartasP[z][j];
			translate >> cartasS[z][j];
		}
	}
	for (int y = 0; y < 2; y++) {
		cardPos[y] = 0;
	}
}



void SetupDeck(bool cartasDisponibles[], int cartasP[][6], int cardPos[],string cartasS[][6]) {
	bool cardDraw = false;
	int turn = 0, contador = 1, currentCard;
	bool setup = false;
	stringstream translate;

	while (setup == false) {

		if (contador == 4) {
			setup = true;
		}

		while (cardDraw == false) {
			currentCard = rand() % 11;

			if (cartasDisponibles[currentCard] == false) {
				cartasDisponibles[currentCard] = true;
				cardDraw = true;
				cartasP[turn][cardPos[turn]] = currentCard + 1;
				translate.clear();
				translate << cartasP[turn][cardPos[turn]];
				translate >> cartasS[turn][cardPos[turn]]; // Convierte a string
				cardPos[turn]++;
				

			}
		}



		cardDraw = false;

		if (turn == 0) {
			turn = 1;
		}
		else
		{
			turn = 0;
		}
	
		

		contador++;
	}



}

void renderDeck(RenderWindow window,int cartasP[][6], string cartasS[][6], int cardPos[],bool roundOver) {
	//Textures
	SDL_Texture* secretCard = window.loadTexture("res/gfx/cards/secret.png");
	SDL_Texture* psecretCard = window.loadTexture("res/gfx/cards/perspective-cards/psecret.png");
	Entity psecretE(401, 590, 170, 114, psecretCard);
	SDL_Texture* tachado = window.loadTexture("res/gfx/cards/tachado.png");

	int posx = 0, posy = 0;
	float tam = 1;
	int cardw = 180, cardh = 251;

	//window.render(secretE, 1);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < cardPos[i]; j++) {
			
			//window.textCustom(cartasS[i][j].c_str(), "res/font/HelpMe.ttf", 10 + (200 * j), 10 + (500 * i), 255, 255, 255, 255, 40, 0, 0, 0);
			posx = 10 + (200 * j);
			posy = 10 + (450 * i);
			if (roundOver==false and j== 0) {
				Entity secretE(posx, posy, cardw, cardh, secretCard);
				window.render(secretE, tam);
				if (i == 1) {
					Entity tachadoE(posx, posy, cardw, cardh, tachado);
					window.render(tachadoE, tam);
					if (cartasP[i][j] <= 10) {
						window.drawText(cartasS[i][j].c_str(), (cardw / 2) - 10, posy + 20, 255, 255, 255, 255, 40);
					}
					else {
						window.drawText(cartasS[i][j].c_str(), (cardw / 2) - 20, posy + 20, 255, 255, 255, 255, 40);
					}
					
				}
				

			}
			else {
				if (cartasP[i][j] == 1) {
					SDL_Texture* card1 = window.loadTexture("res/gfx/cards/1.png");
					Entity c1(posx, posy, 180, 251, card1);
					window.render(c1, 1);
					SDL_DestroyTexture(card1);
					
				}
				if (cartasP[i][j] == 2) {
					SDL_Texture* card2 = window.loadTexture("res/gfx/cards/2.png");
					Entity c2(posx, posy, 180, 251, card2);
					window.render(c2, 1);
					SDL_DestroyTexture(card2);
				
				}
				if (cartasP[i][j] == 3) {
					SDL_Texture* card3 = window.loadTexture("res/gfx/cards/3.png");
					Entity c3(posx, posy, 180, 251, card3);
					window.render(c3, 1);
					SDL_DestroyTexture(card3);
				}
				if (cartasP[i][j] == 4) {
					SDL_Texture* card4 = window.loadTexture("res/gfx/cards/4.png");
					Entity c4(posx, posy, 180, 251, card4);
					window.render(c4, 1);
					SDL_DestroyTexture(card4);
				}
				if (cartasP[i][j] == 5) {
					SDL_Texture* card5 = window.loadTexture("res/gfx/cards/5.png");
					Entity c5(posx, posy, 180, 251, card5);
					window.render(c5, 1);
					SDL_DestroyTexture(card5);
				}
				if (cartasP[i][j] == 6) {
					SDL_Texture* card6 = window.loadTexture("res/gfx/cards/6.png");
					Entity c6(posx, posy, 180, 251, card6);
					window.render(c6, 1);
					SDL_DestroyTexture(card6);
				}
				if (cartasP[i][j] == 7) {
					SDL_Texture* card7 = window.loadTexture("res/gfx/cards/7.png");
					Entity c7(posx, posy, 180, 251, card7);
					window.render(c7, 1);
					SDL_DestroyTexture(card7);
				}
				if (cartasP[i][j] == 8) {

					SDL_Texture* card8 = window.loadTexture("res/gfx/cards/8.png");
					Entity c8(posx, posy, 180, 251, card8);
					window.render(c8, 1);
					SDL_DestroyTexture(card8);
				}
				if (cartasP[i][j] == 9) {
					SDL_Texture* card9 = window.loadTexture("res/gfx/cards/9.png");
					Entity c9(posx, posy, 180, 251, card9);
					window.render(c9, 1);
					SDL_DestroyTexture(card9);
				}
				if (cartasP[i][j] == 10) {
					SDL_Texture* card10 = window.loadTexture("res/gfx/cards/10.png");
					Entity c10(posx, posy, 180, 251, card10);
					window.render(c10, 1);
					SDL_DestroyTexture(card10);
				}
				if (cartasP[i][j] == 11) {
					SDL_Texture* card11 = window.loadTexture("res/gfx/cards/11.png");
					Entity c11(posx, posy, 180, 251, card11);
					window.render(c11, 1);
					SDL_DestroyTexture(card11);
					
				}
				
			}
			
		}
	}

	
	SDL_DestroyTexture(secretCard);
	SDL_DestroyTexture(tachado);
	SDL_DestroyTexture(psecretCard);
	
}

void drawCard(int turn, bool cartasDisponibles[], int cardPos[],int &totalCardsDraw, int cartasP[][6],string cartasS[][6]) {
	bool cardDraw = false;
	int currentCard;
	stringstream translate;

	while (cardDraw == false) {
		currentCard = rand() % 11;
		if (totalCardsDraw == 7 or cardPos[turn]==6) {
			cardDraw = true;
		
		}
		if (cartasDisponibles[currentCard] == false and cardDraw==false) {
			cartasDisponibles[currentCard] = true;
			cardDraw = true;
			cartasP[turn][cardPos[turn]] = currentCard + 1;
			translate.clear();
			translate << cartasP[turn][cardPos[turn]];
			translate >> cartasS[turn][cardPos[turn]]; // Convierte a string
			cardPos[turn]++;
			totalCardsDraw++;

		}
	}
	cout << totalCardsDraw << endl;
}

/*
int main(int argc, char* argv[]) {
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
	int cartasP[2][5] = { {-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1} };

	int cardPos[2] = { 0,0 };


	//Game

	int contador = 1;
	int opcion;
	int ultimajugada;
	//setupGame

	Setup(cartasDisponibles, cartasP, cardPos);


	while (gameOver == false) {
		system("cls");
		cout << "Mesa: " << endl;
		cout << "P1: " << endl;
		for (int i = 0; i < cardPos[0]; i++) {
			cout << cartasP[0][i] << " ";
		}
		cout << endl << endl << "P2: " << endl;
		for (int i = 0; i < cardPos[1]; i++) {
			cout << cartasP[1][i] << " ";

		}
		cout << endl << endl << "Turno del jugador " << turn + 1 << ":" << endl;
		cout << "Que deseas hacer?" << endl << endl;
		cout << "1- Pedir carta." << endl;
		cout << "2- Pasar." << endl;

		cin >> opcion;
		if (opcion == 1) {
			drawCard(turn, cartasDisponibles, cardPos, cartasP);
			ultimajugada = 1;
		}
		if (opcion == 2) {
			if (ultimajugada == 2) {
				gameOver = true;
				system("cls");
				if (playerScores[0] > 21 or playerScores[1] > 21) {
					if (playerScores[0] > 21) {
						cout << "Gana el jugador 2" << endl;
						cout << playerScores[0] << endl;
						cout << playerScores[1] << endl;

					}
					if (playerScores[1] > 21) {
						cout << "Gana el jugador 1" << endl;
						cout << playerScores[0] << endl;
						cout << playerScores[1] << endl;
					}
					gameOver = true;
				}
				else {
					if (playerScores[0] > playerScores[1]) {
						cout << "Gana el jugador 1" << endl;
						cout << playerScores[0] << endl;
						cout << playerScores[1] << endl;
					}
					else {
						cout << "Gana el jugador 2" << endl;
						cout << playerScores[0] << endl;
						cout << playerScores[1] << endl;
					}

				}
			}
			else {
				ultimajugada = 2;
			}
		}




		if (turn == 0) {
			turn = 1;
		}
		else
		{
			turn = 0;
		}


	}




	return 0;
}

*/