
//PA 5
//Name: Arantxa Sierra
//Description: This program is a text-based Poker game that loops until
//the user decides to exit. The user plays against the computer, "the dealer".
// The program takes user input for menu purposes, and for card replacing purposes.
// In each round, the entire deck of cards is reshuffled and the player and 
// the computer are both given hands of 5. Cards can be changed in the hand.
// Both hands are evaluated to decide on a winner, and the player can chose to start
// a new round.

#include "Poker.h"


int main(void)
{
	int choice = 3;
	int deckPtr = 1; //declare as an int then later pass it in as a pointer

	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };



	srand((unsigned)time(NULL)); /* seed random-number generator */



	printf("\nWELCOME TO POKER!");

	Hand playerHand;
	Hand computerHand;
	do {
		/* initalize deck array */
		int deck[4][13] = { 0 };
		shuffle(deck);

		printf("\nWould you like to 1. View the game rules 2. Play the game 3. Exit\n\n");
		scanf("%d", &choice);

		if (choice == 1) {
			displayRules();
		}
		else if (choice == 3) {
			break;
		}
		
		
		printf("\nDealing your hand: \n");
		deal(deck, &playerHand, 5, &deckPtr);
		printHand(face, suit, &playerHand); 

		int repNum = 0;
		int cardToReplace = 0;
		int repChoice = 0;
		//replacing
		do {
			printf("\n\nWould you like to replace any cards? Max 3 (1/0) : \n");
			scanf("%d", &repChoice);
			if (repChoice == 1)
			{
				printf("Enter the card to replace ( 1 - 5): \n");
				scanf("%d", &cardToReplace);

				replaceCard(deck, &playerHand, &deckPtr, cardToReplace);
				printf("Updated Deck: \n");
				printHand(face, suit, &playerHand);

				repNum++;
			}
		} while (repNum < 3 && repChoice != 0);

		printf("\nDealing computer's hand: \n"); //
		deal(deck, &computerHand, 5, &deckPtr);
		
		printHand(face, suit, &computerHand);

		checkWinner(&playerHand, &computerHand);

	} while (choice != 3);

	return 0;
}
