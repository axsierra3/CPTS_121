#include "Poker.h"

/* shuffle cards in deck */

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}


void deal(const int wDeck[][13], Hand* h, int cardsToDeal, int *deckPtr)
{
	Card currCard;
	int row = 0;    /* row number */
	int column = 0; /*column number */

	/* deal each of the (5) cards */
	for (int i = (1 + *deckPtr); i <= (cardsToDeal + *deckPtr); i++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == i)
				{
					currCard.faceIndex = column;
					currCard.suitIndex = row;
					h->cardArr[i - 1 - *deckPtr] = currCard;
				}
			}
		}
	}
	*deckPtr += cardsToDeal;

}

void printHand(const char* wFace[], const char* wSuit[], Hand* h) 
{
	for (int i = 0; i < 5; i++)
	{
		printf("%5s of %-8s", wFace[h->cardArr[i].faceIndex], wSuit[h->cardArr[i].suitIndex]);
	}
}

Card getCard(const int wDeck[][13], int* deckPtr)
{
	Card currCard;
	currCard.faceIndex = 0;
	currCard.suitIndex = 0;
	(*deckPtr)++;

	/* loop through rows of wDeck */
	for (int row = 0; row <= 3; row++)
	{
		/* loop through columns of wDeck for current row */
		for (int column = 0; column <= 12; column++)
		{
			/* if slot contains current card, display card */
			if (wDeck[row][column] == *deckPtr)
			{
				currCard.faceIndex = column;
				currCard.suitIndex = row;
				
				return currCard;
			}
		}
	}

	
}

void replaceCard(const int wDeck[][13], Hand* h, int *deckPtr, int cardToReplace)
{
	h->cardArr[cardToReplace - 1] = getCard(wDeck, deckPtr);
}


void displayRules() 
{
	printf("\n---RULES---\n\n");

	printf("1.You and the computer will be dealt 5 cards each ");
	printf("\n2. You are allowed to replace up to 3 of your cards to get a better hand");
	printf("\n3. Your goal is to get higher category hands (ex: straights, flush, fullhouse)");
	printf("\n4. Once you have your hand, both hands will be evaluated and a winner will be chosen! (you or the computer)");
	printf("\n5. A winner will be chosen every round, play until you wish to exit!\n");
}

void countFaces(Hand* hand1, int faceCt[13]) 
{
	for (int card = 0; card < 5; card++)
	{
		faceCt[hand1->cardArr[card].faceIndex]++; //look at each card and increment that face freq
	}
}

void countSuits(Hand* hand1, int suitCt[4])
{
	for (int card = 0; card < 5; card++)
	{
		suitCt[hand1->cardArr[card].suitIndex]++; //look at each card and increment that suit freq
	}
}


int containsPair(Hand* hand1) 
{
	int faceCt[13] = { 0 };

	countFaces(hand1, faceCt);


	for (int currFace = 0; currFace < 13; currFace++)
	{
		if (faceCt[currFace] == 2)
		{
			return 1;
		}
	}
	return 0;
}



int containsTwoPairs(Hand* hand1) 
{
	int pairCt = 0;
	int faceCt[13] = { 0 };

	countFaces(hand1, faceCt);


	for (int face = 0; face < 13; face++)
	{
		if (faceCt[face] == 2)
		{
			pairCt++;
		}
	}
	if (pairCt == 2) {
		return 1;
	}
	return 0;
}

int contains3OfKind(Hand* hand1) {

	int faceCt[13] = { 0 };

	countFaces(hand1, faceCt);


	for (int face = 0; face < 13; face++)
	{
		if (faceCt[face] == 3)
		{
			return 1;
		}
	}
	return 0;

}


int contains4OfKind(Hand* hand1) {

	int faceCt[13] = { 0 };

	countFaces(hand1, faceCt);


	for (int face = 0; face < 13; face++)
	{
		if (faceCt[face] == 4)
		{
			return 1;
		}
	}
	return 0;
	
}


int containsFullHouse(Hand* hand1) {  //3 of a kind and 2 and a pair 

	if (contains3OfKind(hand1) && containsPair(hand1)) 
	{
		return 1;
	}
	return 0;
}


int containsFlush(Hand* hand1) 
{
	int suitCt[13] = { 0 };

	countSuits(hand1, suitCt);


	for (int currSuit = 0; currSuit < 4; currSuit++)
	{
		if (suitCt[currSuit] == 5)
		{
			return 1;
		}
	}
	return 0;
}

int containsStraight(Hand* hand1)
{
	int faceCt[13];
	countFaces(hand1, faceCt);

	for (int i = 0; i <= 8; i++) //up to 8 because there are 13 faces
	{
		if (faceCt[i] == 1 && faceCt[i + 1] == 1 && faceCt[i + 2] == 1 && faceCt[i + 3] == 1 && faceCt[i + 4] == 1) //one of each consec
		{
			return 1;  
		}
	}
	return 0;
}

int checkHighestCombo(Hand* hand1) 
{
	if (containsStraight(hand1)) {
		return 10;
	}
	if (containsFlush(hand1)) {
		return 9;
	}
	if (containsFullHouse(hand1)) {
		return 8;
	}
	if (contains4OfKind(hand1)) {
		return 7;
	}
	if (contains3OfKind(hand1)) {
		return 6;
	}
	if (containsTwoPairs(hand1)) {
		return 5;
	}
	if (containsPair(hand1)) {
		return 4;
	}
	return 0;
}

void checkDealerHand(const int wDeck[][13], Hand* hand2, int* deckPtr)
{
	if(!containsStraight(hand2) && !containsFlush(hand2) && !containsFullHouse(hand2) 
		&& !contains4OfKind(hand2) && !contains3OfKind(hand2) && !containsTwoPairs(hand2)
			&& !containsPair(hand2)) 
	{
		replaceCard(wDeck, &hand2, &deckPtr, 1);
		replaceCard(wDeck, &hand2, &deckPtr, 2);
		replaceCard(wDeck, &hand2, &deckPtr, 3);

	}
}

void checkWinner(Hand* hand1, Hand* hand2)
{
	int player1Score = checkHighestCombo(hand1);
	int player2Score = checkHighestCombo(hand2);

	if (player1Score > player2Score) 
	{
		printf("\n\nPlayer 1 is the winner!\nYOU WON\n\n");
	}
	else {
		printf("\n\nPlayer 2 is the winner!\nYOU LOST\n\n");
	}
}



