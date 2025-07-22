// guard code
#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

//struct to keep data
typedef struct stats {
	int numHits;
	int numMisses;
	int totalShots;
	double hitsToMisses;
	int winLoss;

}Stats;

//prints welcome and rules
void welcome_screen();

//starts blank game board
void initialize_game_board(char arr[10][10]);

//checks to see if the coordinate is useable in game (not out of bounds or taken)
int valid_coordinate(int x, int y, char b[10][10]);

//prompts user to specifically pick battleship coordinates
void manualPlacement(char b[10][10]);

//randomly picks what direction the battleships will lay for use in random placement
int randomizeDirection(int x, int y, int shipSize, char b[10][10]);

//randomly places the battleships on the board
void randomPlacement(char b[10][10]);

//prompts user to pick a coordinate to shoot at
void takeShot(int* x, int* y, char b[10][10]);

//randomizes a shot for the computer player to take
void computerShot(int* x, int* y, char b[10][10]);

//determines if a shot at a specified coordinate was successful
int isHit(int* x, int* y, char b[10][10]);

//determines if entire ship has been sunk 
int shipSunk(char shipType, char b[10][10]);

//determines if that player has lost based on their board
int isLoser(char b[10][10]);

//prints statistics into output log file
output_stats(Stats s1, Stats s2, FILE * f);



#endif // guard code end

#pragma once