#include "Battleship.h"

void welcome_screen() {

	printf("***** Welcome to Battleship! *****\n\n");
	printf("Rules of the game: \n1.This a two player game \n2.Player1 is you and Player2 is the computer\n3.Your objective is to sink all of the ships in your enemy's board first\n\n");
	printf("\n5. You will both have 5 ships each which all vary by cell size (Carrier = 5, Battlsehip = 4, Cruiser = 3, Submarine = 3, Destroyer = 2");
	printf("\n6. On every turn you will be asked for a position to target");
	printf("\nYour stats will be printed at the end!\n");

	printf("\n\nHit enter to start the game!");
	getchar();
	system("cls");
}

void initialize_game_board(char arr[10][10]) 
{ 
	for (int r = 0; r < 10; r++) {
		for (int c = 0; c < 10; c++) 
		{
			arr[r][c] = '-';
		}
	}
}

int valid_coordinate(int x, int y, char b[10][10])
{
	if (x < 0 || x > 10 || y < 0 || y > 10 || b[x][y] != '-') {
		return 0;
	}
	return 1;
}

void manualPlacement(char b[10][10]) {
	int x = 0, y = 0;

	printf("Please enter the 5 cells to place the Carrier across: \n");
	for (int i = 0; i < 5; i++) {
		do {
			printf("\nCell: ");
			scanf("%d %d", &x, &y);
		} while (!valid_coordinate(x, y, b));
		b[x][y] = 'c';
	}

	printf("Please enter the 4 cells to place the Battleship across: \n");
	for (int i = 0; i < 4; i++) {
		do {
			printf("\nCell: ");
			scanf("%d %d", &x, &y);
		} while (!valid_coordinate(x, y, b));
		b[x][y] = 'b';
	}

	printf("Please enter the 3 cells to place the Cruiser across: \n");
	for (int i = 0; i < 3; i++) {
		do {
			printf("\nCell: ");
			scanf("%d %d", &x, &y);
		} while (!valid_coordinate(x, y, b));
		b[x][y] = 'r';
	}

	printf("Please enter the 3 cells to place the Submarine across: \n");
	for (int i = 0; i < 3; i++) {
		do {
			printf("\nCell: ");
			scanf("%d %d", &x, &y);
		} while (!valid_coordinate(x, y, b));
		b[x][y] = 's';
	}

	printf("Please enter the 2 cells to place the Destroyer across: \n");
	for (int i = 0; i < 2; i++) {
		do {
			printf("\nCell: ");
			scanf("%d %d", &x, &y);
		} while (!valid_coordinate(x, y, b));
		b[x][y] = 'd';
	}
}


int randomizeDirection(int x, int y, int shipSize, char b[10][10])
{
	int direction = -1;
	int valid = 0;
	
	while (!valid) {
		direction = rand() % 4;
		valid = 1;

		for (int i = 0; i < shipSize; i++) 
		{
			if (direction == 0 && !valid_coordinate(x - i, y, b) ) {//left
				valid = 0;
				break;
			}
			else if (direction == 1 && !valid_coordinate(x, y - i, b) ) {//up
				valid = 0;
				break;
			}
			else if (direction == 2 && !valid_coordinate(x, y + i, b)) {//down
				valid = 0;
				break;
			}
			else if (direction == 3 && !valid_coordinate(x + 1, y, b)) {//right
				valid = 0;
				break;
			}
		}
	}
	
	return direction;
}

void randomPlacement(char b[10][10])
{
	int x = 0, y = 0, direction;
	//starting cords for carrier
	do {
	x = rand() % 10;
	y = rand() % 10;
 } while (!valid_coordinate(x, y, b));

	direction = randomizeDirection(x, y, 5, b);

	b[x][y] = 'c';
	if (direction == 0) {
		for (int i = 0; i < 5; i++)
		{
			b[x - i][y] = 'c';
		}
	}
	else if (direction == 1) {
		for (int i = 0; i < 5; i++)
		{
			b[x][y - i] = 'c';
		}
	}
	else if (direction == 2) {
		for (int i = 0; i < 5; i++)
		{
			b[x][y + i] = 'c';
		}
	}
			else if (direction == 3) {
		for (int i = 0; i < 5; i++)
		{
			b[x + 1][y] = 'c';
		}
	}

	//starting cords for battleship
	x = rand() % 10;
	y = rand() % 10;
	direction = randomizeDirection(x, y, 4, b);

	b[x][y] = 'b';
	if (direction == 0) {
		for (int i = 0; i < 4; i++)
		{
			b[x - i][y] = 'b';
		}
	}
	else if (direction == 1) {
		for (int i = 0; i < 4; i++)
		{
			b[x][y - i] = 'b';
		}
	}
	else if (direction == 2) {
		for (int i = 0; i < 4; i++)
		{
			b[x][y + i] = 'b';
		}
	}
	else if (direction == 3) {
		for (int i = 0; i < 4; i++)
		{
			b[x + 1][y] = 'b';
		}
	}

	//starting cords for cruiser
	x = rand() % 10;
	y = rand() % 10;
	direction = randomizeDirection(x, y, 3, b);

	b[x][y] = 'c';
	if (direction == 0) {
		for (int i = 0; i < 3; i++)
		{
			b[x - i][y] = 'r';
		}
	}
	else if (direction == 1) {
		for (int i = 0; i < 3; i++)
		{
			b[x][y - i] = 'r';
		}
	}
	else if (direction == 2) {
		for (int i = 0; i < 3; i++)
		{
			b[x][y + i] = 'r';
		}
	}
	else if (direction == 3) {
		for (int i = 0; i < 3; i++)
		{
			b[x + i][y] = 'r';
		}
	}

	//starting cords for submarine
	x = rand() % 10;
	y = rand() % 10;
	direction = randomizeDirection(x, y, 3, b);

	b[x][y] = 's';
	if (direction == 0) {
		for (int i = 0; i < 3; i++)
		{
			b[x - i][y] = 's';
		}
	}
	else if (direction == 1) {
		for (int i = 0; i < 3; i++)
		{
			b[x][y - i] = 's';
		}
	}
	else if (direction == 2) {
		for (int i = 0; i < 3; i++)
		{
			b[x][y + i] = 's';
		}
	}
	else if (direction == 3) {
		for (int i = 0; i < 3; i++)
		{
			b[x + i][y] = 's';
		}
	}
	
	//starting cords for destroyer
	x = rand() % 10;
	y = rand() % 10;
	direction = randomizeDirection(x, y, 2, b);

	b[x][y] = 'd';
	if (direction == 0) {
		for (int i = 0; i < 2; i++)
		{
			b[x - i][y] = 'd';
		}
	}
	else if (direction == 1) {
		for (int i = 0; i < 2; i++)
		{
			b[x][y - i] = 'd';
		}
	}
	else if (direction == 2) {
		for (int i = 0; i < 2; i++)
		{
			b[x][y + i] = 'd';
		}
	}
	else if (direction == 3) {
		for (int i = 0; i < 2; i++)
		{
			b[x + i][y] = 'd';
		}
	}
}

void display_board1(char b[10][10]) 
{
	printf("\nPlayer 1's Board: \n\n");
	printf("  0 1 2 3 4 5 6 7 8 9\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", i);
		for (int j = 0; j < 10; j++) {
			printf("%c ", b[i][j]); 
		}
		printf("\n");
	}
}

void display_board2(char b[10][10])
{
	printf("\nPlayer 2's Board: \n\n");
	printf("  0 1 2 3 4 5 6 7 8 9\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", i);
		for (int j = 0; j < 10; j++) {
			if (b[i][j] == 'c' || b[i][j] == 'b' || b[i][j] == 'r' || b[i][j] == 's' || b[i][j] == 'd') {
				printf("- ");
			}
			else {
				printf("%c ", b[i][j]);
			}
		}
		printf("\n");
	}
}

void takeShot(int *x, int *y, char b[10][10]) {
	do
	{
		printf("Enter the coordinate to shoot at:  ");
		scanf("%d %d", x, y);
	} while (*x < 0 || *x > 10 || *y < 0 || *y > 10 || b[*x][*y] == '*' || b[*x][*y] == 'm');
	}

void computerShot(int* x, int* y, char b[10][10])
{
	do
	{
		*x = rand() % 10;
		*y = rand() % 10;
	} while (x == '*' || x == 'm' || y == '*' || y == 'm');
}

int isHit(int *x, int *y, char b[10][10])
{
	char shipType = '\0';

	if (b[*x][*y] != '-') 
	{
		shipType = b[*x][*y];
		b[*x][*y] = '*'; //shows hit
		printf("It's a hit!\n");
		shipSunk(shipType, b);
		return 1;
	}

	else {
		printf("It's a miss!\n");
		return 0;

	}
}

int shipSunk(char shipType, char b[10][10])
{
	for (int r = 0; r < 10; r++) {
		for (int c = 0; c < 10; c++)
		{
			if (b[r][c] == shipType) {
				printf("%c ship has not been sunk yet!", shipType);
				return 0;
			}
		}
	}
	printf("%c ship was sunk!", shipType);
	return 1;
}
	//after each turn interation check for both--1 means this board lost
	int isLoser(char b[10][10]) 
	{
		for (int r = 0; r < 10; r++) {
			for (int c = 0; c < 10; c++)
			{
				if (b[r][c] != '-' && b[r][c] != '*') {
					return 0;
				}
			}
		}
		return 1;
	}

	output_stats(Stats* p1, Stats* p2, FILE *outfile) 
	{
		fprintf(outfile, "STATISTICS: \n\n");

		fprintf(outfile, "Player 1: \nHits: %d, Misses: %d, Shots: %d, Hit-To-Miss-Ration: %lf", p1->numHits, p1->numMisses, p1->totalShots, p1->totalShots, p1->hitsToMisses);
		fprintf(outfile, "Player 2: \nHits: %d, Misses: %d, Shots: %d, Hit-To-Miss-Ration: %lf", p2->numHits, p2->numMisses, p2->totalShots, p2->totalShots, p2->hitsToMisses);

		if (p1->winLoss == 1) {
			fprintf(outfile, "The winner is Player 1!");
		}
		else {
			fprintf(outfile, "The winner is Player 2!");
		}
	}



