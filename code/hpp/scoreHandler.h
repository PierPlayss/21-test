#pragma once
#include <iostream>
#include<stdlib.h>
#include<time.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"

using namespace std;

void resetScore(int score[],int &turn, int &ultimajugada);

void ScoreHandler(RenderWindow window, int turn, int cartasP[][6], int cardPos[], bool roundOver, int Score[],int scoreLimit);

void checkWinner(RenderWindow window, int Score[],int scoreLimit);