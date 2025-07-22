#include "Yahtzee.h"

void presentMenu() {
	int option; 
	do {
		printf("\nPlease select an an option (1-3) to continue!\n\n");

		printf("1.Print game rules");

		printf("\n2.Start a game of Yahtzee");

		printf("\n3.Exit\n");

		scanf("%d", &option);
		system("cls");

		switch (option)
		{
		case 1:
			printf("\nRULES: \n");
			printf("YAHTZEE is a two player game, your goal is to score the most points. \nTo play, you roll 5 6-sided dice over 13 rounds.");
			printf("During each round, you can roll up to 3 times to make a combination. \nCombinations (except for the Yahtzee Combo) CANNOT be reused ");
			printf("\n\nYou will be scored in 2 sections: the Upper Section and the Lower Section");
			printf("\nIn the upper section, you simply add up the the total of one type of dice face. If your sum is 63 or above, you get 35 BONUS points!");
			printf("\n\nIn the lower section, you will be scored based on specific combinations: \n");
			printf("1.THREE-OF-A-KIND: sum of all dice");
			printf("\n2.FOUR-OF-A-KIND: sum of all dice");
			printf("\n3.FULL HOUSE (one pair and three-of-a-kind): 25");
			printf("\n4.SMALL STRAIGHT (sequence 4 numbers): 30");
			printf("\n5.LARGE STRAIGHT (sequence 5 numbers): 40");
			printf("\n6. YAHTZEE (all 5 dice same): 50");
			printf("\n7. CHANCE (any): sum of all dice\n");

			Sleep(4000);
			printf("\n\nWhat woud you like to do now?");

			break;
		case 2:
			printf("\nLet's play!");
			break;
		case 3:
			printf("GOODBYE!");
			exit(0);
			break;

		default:

			break;
		}
	} while (option != 2);
}



int* rollDice(int dice[]) {

	printf("\nRoll your 5 dice....\n");
	system("pause");

	dice[0] = rand() % 6 + 1;
	dice[1] = rand() % 6 + 1;
	dice[2] = rand() % 6 + 1;
	dice[3] = rand() % 6 + 1;
	dice[4] = rand() % 6 + 1;

	printf("\n\nDICE 1: %d | DICE 2: %d | DICE 3: %d | DICE 4: %d | DICE 5: %d", dice[0], dice[1], dice[2], dice[3], dice[4]);

	return dice;
}

int* rerollDice(int dice[], char buffer[]) {

	char* diceToReroll = strtok(buffer, " "); //pointer to item in buffer

	while (diceToReroll != NULL) 
	{
		dice[atoi(diceToReroll) - 1] = rand() % 6 + 1;
		diceToReroll = strtok(NULL, " ");
	}

	printf("\n\nDICE 1: %d | DICE 2: %d | DICE 3: %d | DICE 4: %d | DICE 5: %d", dice[0], dice[1], dice[2], dice[3], dice[4]);
	return dice;
}

void askReroll(int rollNum, char* dice) {
	int reroll = 0;
	char rerollBuffer[100];

	while (rollNum < 3) {
		printf("\nWould you like to reroll? Max 3 rolls (1/0): ");
		scanf("%d", &reroll);
		if (reroll == 1)
		{
			printf("\nEnter the die to reroll separated by space!: ");

			getchar();
			fgets(rerollBuffer, sizeof(rerollBuffer), stdin);

			rerollDice(dice, rerollBuffer);
			rollNum++;
		}
		else {
			break;
		}
	}
}
int addScore(int dice[], int comboNum, int totalScore, int *upperSection) { //edit to separate upper section
	int score = 0;
	int faceCounts[7] = { 0 };
	countFaces(dice, faceCounts);
	switch (comboNum) {

	case 1:					//sums
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		score = sumOfFace(dice, comboNum);
		*upperSection += score;
		break;
	case 7:
		if (ofAKind(faceCounts, 3) == 1)
			score = sumAllCards(dice);
		break;
	case 8:
		if (ofAKind(faceCounts, 4) == 1)
			score = sumAllCards(dice);
		break;

	case 9: //fullhouse (one pair and a 3-of-a-kind)
		if (fullHouse(faceCounts) == 1)
			score = 25;
		break;

	case 10: //straights
		if (sequence(dice) == 4)
			score = 40;

	case 11:
		if (sequence(dice) == 5)
			score = 40;

	case 12: //yahtzee
		if (ofAKind(faceCounts, 5) == 1)
			score = sumAllCards(dice);
		break;
	case 13: //chance
		score = sumAllCards(dice);
		break;
	}
	totalScore += score;
	return totalScore;
}

int sumOfFace(int dice[], int face) 
{
	int sum = 0;
	for (int i = 0; i < 5; i++) 
	{
		if (dice[i] == face) 
		{
			sum += face;
		}
	}
	return sum;
}

int sumAllCards(int dice[]) {
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += dice[i];
	}
	return sum;
}

int sequence(int dice[]) {
	int consecutive = 1;

	for (int i = 0; i < 4; i++)
	{
		if (dice[i] == dice[i + 1] - 1) {
			consecutive++;
		}
	}
	return consecutive;
}

int* countFaces(int dice[], int faceCounts[]) {

	for (int i = 0; i < 5; i++) {
		faceCounts[dice[i]]++;  // assign a count for each face val found in deck (ex: [2] = 3)
	}
	return faceCounts;
}
int ofAKind(int faceCounts[], int num){
		for (int i = 1; i <= 6; i++) {//checks if any of the face counts in the array are equal or greater than the of a kind val 
			if (faceCounts[i] >= num) {
				return 1;  
			}
		}
		return 0;
	}

int fullHouse(int faceCounts[]) {
	int pairFound = 0;
	int threeFound = 0;
	for (int i = 1; i <= 6; i++) { 
		if (faceCounts[i] == 2) {
			pairFound = 1;
		}
		if (faceCounts[i] == 3) {
			threeFound = 1;
		}
		if (pairFound == 1 && threeFound == 1) {
			return 1;
		}
	}
	return 0;
}

int pickCombo(int combosPicked[]) {
	int comboSuccess = 0;
	int combo = 0;
	do {
		comboSuccess = 0;
		printf("\n\n>>>Please pick a combination<<<");
		printf("\n1.Sum of 1's		2. Sum of 2's		3. Sum of 3's		4. Sum of 4's		5. Sum of 5's		6. Sum of 6's");
		printf("\n7.3-of-a-kind		8. 4-of-a-kind		9. Full House		10. Small Straight		\n11. Large Straight		12. Yahtzee		13. Chance\n");
		scanf("%d", &combo);

		if (combosPicked[combo] == 1)
		{
			printf("That combo has already been picked, try again!\n");
		}
		else {
			combosPicked[combo] = 1;
			comboSuccess = 1;
		}
	} while (comboSuccess == 0);
	return combo;
}





