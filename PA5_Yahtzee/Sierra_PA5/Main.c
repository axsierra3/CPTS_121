//PA 5
//Name: Arantxa Sierra
//Description: This program is a two player text-based Yahtzee game that loops until
//the players decide to exit. The program takes user input for dice rolling 
// and combination picking purpposes. At the end of the game a winner is chosen based
//on the scoring perfromed during gameplay.

#include "Yahtzee.h"

int main() {
	int option = 0;
	int gameOver = 0;
	int diceArr[4] = { 0 }, combosPickedP1[13] = { 0 }, combosPickedP2[13] = { 0 };
	int rollNum = 0, roundNum = 0, combo = 0;
	int totalScoreP1, totalScoreP2, upperScore1, upperScore2;

	srand(time(NULL));

	while (1) 
	{
		totalScoreP1 = 0, totalScoreP2 = 0, upperScore1 = 0, upperScore2 = 0;

		printf("\n~~~WELCOME TO YAHTZEE~~~");
		presentMenu();

		for (int i = 0; i < 13; i++) {//game loop

			roundNum++;
			printf("\nROUND %d", roundNum);

			//PLAYER 1
			printf("\n--PLAYER 1--");

			rollDice(diceArr);
			rollNum++;
			askReroll(rollNum, diceArr);
			combo = pickCombo(combosPickedP1);
			totalScoreP1 = addScore(diceArr, combo, totalScoreP1, &upperScore1);
			printf("\nPlayer 1 current score: %d points", totalScoreP1);
			Sleep(4000);
			system("cls");
			rollNum = 0;

			//player 2
			printf("\n--PLAYER 2--");

			rollDice(diceArr);
			rollNum++;
			askReroll(rollNum, diceArr);
			combo = pickCombo(combosPickedP2);
			totalScoreP2 = addScore(diceArr, combo, totalScoreP2, &upperScore2);
			printf("\nPlayer 2 current score: %d points", totalScoreP2);
			Sleep(4000);
			system("cls");
			rollNum = 0;
		}
		if (upperScore1 >= 63) {
			totalScoreP1 += 35;
		}
		if (upperScore2 >= 63) {
			totalScoreP2 += 35;
		}
		int winner = 2;
		if (upperScore1 > upperScore2) {
			winner = 1;
		}

		printf("\n\n*****SCORES*****");
		printf("\nPlayer 1: %d", totalScoreP1);
		printf("\nPlayer 2: %d", totalScoreP2);
		printf("\nThe WINNER is Player %d!!!", winner);
		Sleep(5000);
	}
		return 0;
	}

