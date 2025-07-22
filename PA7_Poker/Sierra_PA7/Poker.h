// guard code
#ifndef POKER_H
#define POKER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct card {
	int faceIndex;
	int suitIndex;

} Card;

//holds 5 cards (a hand)
typedef struct hand {
	Card cardArr[5];

} Hand;

//assigns each of the 52 spots in the array with a random card nuumber
void shuffle(int wDeck[][13]); 

//takes the shuffled deck, and assigns a chosen number of cards into the player's hand
//uses a pointer to keep track of the "top" of the card deck
void deal(const int wDeck[][13], Hand* h, int cardsToDeal, int* deckPtr);

//prints the card hand onto the screen using a for loop
void printHand(const char* wFace[], const char* wSuit[], Hand* h);

//returns the card at the top of the deck using the incremented deck pointer
Card getCard(const int wDeck[][13], int* deckPtr);

//uses the getCard function to assign the card that the user wants to replace with the next card
void replaceCard(const int wDeck[][13], Hand* h, int* deckPtr, int cardToReplace);

//prints the poker rules to the screen
void displayRules();

//goes through every card in the given hand, counts how many of each face there is, and assigns
//that number to the appropriate index in the array
void countFaces(Hand* hand1, int faceCt[13]);

//goes through every card in the given hand, counts how many of each suit there is, and assigns
//that number to the appropriate index in the array
void countSuits(Hand* hand1, int suitCt[4]);

//loops through the array of face occurences and checks to see if any show up twice, returns 1 if a pair is
//found and 0 if it is not
int containsPair(Hand* hand1);

//a counter keeps track of how many pairs are found, if two pairs are found 1 is returned
int containsTwoPairs(Hand* hand1);

//loops through the array of face occurences to check if any face appears 3 times
int contains3OfKind(Hand* hand1);

//loops through the array of face occurences to check if any face appears 4 times
int contains4OfKind(Hand* hand1);

//passes the hand into the previously defined containsPair and contains3OfKind to check
//if both conditions are fulfilled
int containsFullHouse(Hand* hand1); //3 of a kind and 2 and a pair

//loops through the array of face occurences to check if any face appears 5 times
int containsFlush(Hand* hand1); //5 of same suit

//loops through the first 8 faces in the face occurence array and checks if there is one of
//each subsequent face by adding to i in the brackets
int containsStraight(Hand* hand1); //5 cards of consecutive face vals

//uses the previously defined functions (containsPair, containsTwoPairs, contains3OfKind,
// contains4OfKind, containsFullHouse, containsFlush, and containsStraight) to check
// them in order of precedence, and returns the highest numerical value, if no combination
//is found it returns 0
int checkHighestCombo(Hand* hand1);

//checks if the computer's hand has a combination, if it doesn't, the program calls
//replaceCard to replace 3 of the dealer's cards
void checkDealerHand(const int wDeck[][13], Hand* hand2, int* deckPtr);

//calls checkHighestCombo to compare two hands, the hand that returns the higher value
//belongs to the winner, the program then prints the winner to the screen
void checkWinner(Hand* hand1, Hand* hand2);


#endif // guard code end

#pragma once
