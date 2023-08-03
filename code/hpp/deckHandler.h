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

int TurnOver(int turn);

void resetCards(bool cartasDisponibles[], int cartasP[][6],string cartasS[][6], int cardPos[], int totalCardsDraw);

void SetupDeck(bool cartasDisponibles[], int cartasP[][6], int cardPos[],string cartasS[][6]);

void renderDeck(RenderWindow window, int cartasP[][6], string cartasS[][6],int cardPos[],bool roundOver);

void drawCard(int turn, bool cartasDisponibles[], int cardPos[], int &totalCardsDraw, int cartasP[][6],string cartasS[][6]);

