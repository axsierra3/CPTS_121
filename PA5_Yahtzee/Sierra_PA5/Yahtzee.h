// guard code
#ifndef YAHTZEE_H
#define YAHTZEE_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>
#include <time.h>
#include <windows.h> 

//prints menu options, takes user input, and either prints reles, starts game or exits
void presentMenu();
//takes an array of dice and randomizes their face values
int* rollDice(int dice[]);
//separates user input for which dice to reroll and randomizes those dice in the array accordingly
int* rerollDice(int dice[], char buffer[]);
//asks user if they would like to reroll up to a maximum of 3 times, and asks for which dice to reroll
void askReroll(int rollNum, char* dice);
//calculates score for that round by checking the combo that was chosen, and adds to the total score and upper card
int addScore(int dice[], int comboNum, int totalScore, int* upperSection);
//sums all the card faces of the face number entered
int sumOfFace(int dice[], int face);
//sums all card faces
int sumAllCards(int dice[]);
//counts how many ascending die there are
int sequence(int dice[]);
//counts how many of each face are present in the array of cards
int* countFaces(int dice[], int faceCounts[]);
//checks if any of the face amounts are valid for one of the of-a-kind combos
int ofAKind(int faceCounts[], int num);
//checks for full house (pair and 3 of a kind) through flags
int fullHouse(int faceCounts[]);
//asks the user to pick a combo and checks  if it has been used yet
int pickCombo(int combosPicked[]);


#endif // guard code end


#pragma once
