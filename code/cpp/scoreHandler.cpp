#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <sstream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


#include "deckHandler.h"
#include "scoreHandler.h"

void resetScore(int score[], int &turn,int &ultimajugada) {

	score[0] = 0;
	score[1] = 0;

	turn = 0;

	ultimajugada = 0;


}


void checkWinner(RenderWindow window,int playerScores[],int scoreLimit) {
	if (playerScores[0] > scoreLimit or playerScores[1] > scoreLimit) {
		if (playerScores[0] > scoreLimit) {
			window.textCustom("Gana el jugador 2", "res/font/MicroExtendFLF.ttf", 0, 0, 255, 255, 255, 255, 40, 1, 0, 0);
			//cout << "Gana el jugador 2" << endl;
		}
		if (playerScores[1] > scoreLimit) {
			window.textCustom("Gana el jugador 1", "res/font/MicroExtendFLF.ttf", 0, 0, 255, 255, 255, 255, 40, 1, 0, 0);
			//cout << "Gana el jugador 1" << endl;
		}
	}
	else {
		if (playerScores[0] > playerScores[1]) {
			window.textCustom("Gana el jugador 1", "res/font/MicroExtendFLF.ttf", 0, 0, 255, 255, 255, 255, 40, 1, 0, 0);
			//cout << "Gana el jugador 1" << endl;
		}
		else {
			window.textCustom("Gana el jugador 2", "res/font/MicroExtendFLF.ttf", 0, 0, 255, 255, 255, 255, 40, 1, 0, 0);
			//cout << "Gana el jugador 2" << endl;
		}

	}
}


void ScoreHandler(RenderWindow window, int turn, int cartasP[][6], int cardPos[], bool roundOver, int Score[],int scoreLimit) {
	int secretScore = 0;
	stringstream translate;
	string ScoreString[2];
	string secret = "? + ";
	string scoreLimitString;
	string character = "/";
	
	int posx = 1000, posy;

	translate.clear();
	translate << scoreLimit;
	translate >> scoreLimitString;
	scoreLimitString = character + scoreLimitString;


	for (int i = 0; i < 2; i++) {
		Score[i] = 0;
		for (int j = 0; j < cardPos[i]; j++) {
			Score[i] += cartasP[i][j];
		}
	}

	for (int z = 0; z < 2; z++) {
		posy = 10 + (450 * z);
		translate.clear();
		if (roundOver == false and z == 0) {
			secretScore = Score[z] - cartasP[0][0];
			translate << secretScore;
			translate >> ScoreString[z];
			ScoreString[z] = secret + ScoreString[z]+scoreLimitString;
		}
		else {
			translate << Score[z];
			translate >> ScoreString[z];
			ScoreString[z] = ScoreString[z] + scoreLimitString;
		}
		window.drawText(ScoreString[z].c_str(), posx, posy, 255, 255, 255, 255, 40);

	}




}