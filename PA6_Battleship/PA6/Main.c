#include "Battleship.h"


int main() {
	Stats p1Stats = { 0 };
	Stats p2Stats = { 0 };

	int choice = 0;
	int x = 0, y = 0;
	int playerOrder;
	int hasLost = 0, hitVal = -1;
	srand(time(NULL));
	
	//setting up
	welcome_screen();

	//initializing boards to all -
	char p1_board[10][10];
	char p2_board[10][10];

	//opening log file
	FILE *logFile = fopen("battleship.log", "r");

	initialize_game_board(p1_board);
	initialize_game_board(p2_board);

	//placement
	printf("Would you like to manually place your ships(1) or randomly generate placements(2)?: \n");
	scanf("%d", &choice);

	if (choice == 1)
		manualPlacement(p1_board);
	else if (choice == 2)
		randomPlacement(p1_board);

		randomPlacement(p2_board);
		printf("Both boards have been generated!\n\n");

		display_board1(p1_board);

		printf("Deciding what player will go first. . .");
		Sleep(4000);
		playerOrder = rand() % 2 + 1;
		printf("Player %d goes first!", playerOrder);
		Sleep(4000);
		do {
			if (playerOrder == 1) {
				display_board1(p1_board);
				display_board2(p2_board);

				takeShot(&x, &y, p2_board);
				Sleep(4);
				hitVal = isHit(&x, &y, p2_board);
				if (hitVal) {
					p1Stats.numHits++;
				}
				else {
					p1Stats.numMisses++;
				}

				playerOrder = 2;
				hasLost = isLoser(p2_board);
				if (hasLost == 1) {
					p1Stats.winLoss = 0;
					p2Stats.winLoss = 1;
				}
				Sleep(4000);
			}


			if (playerOrder == 2) {
				display_board1(p1_board);
				display_board2(p2_board);

				computerShot(&x, &y, p1_board);
				printf("Computer is shooting......: ");
				hitVal = isHit(&x, &y, p1_board);
				if (hitVal) {
					p2Stats.numHits++;
				}
				else {
					p2Stats.numMisses++;
				}

				playerOrder = 1;
				hasLost = isLoser(p1_board);
				if (hasLost == 1) {
					p2Stats.winLoss = 0;
					p1Stats.winLoss = 1;
				}
				Sleep(4000);
			}

			Sleep(4000);
				system("cls");
		} while (hasLost != 1);

		p1Stats.hitsToMisses = p1Stats.numHits / p1Stats.numMisses;
		p2Stats.hitsToMisses = p2Stats.numHits / p2Stats.numMisses;
		output_stats(p1Stats, p2Stats, logFile);
		fclose(logFile);
	return 0;
}