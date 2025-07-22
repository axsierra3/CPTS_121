
//PA 9
//Name: Arantxa Sierra
//Description: This program contains a series of smaller problems 
// that could be found in interviews. These problems are solved through
// functions ulilizing concepts such as pointers, arrays, structs 
// and more.

#include "PA8.h"

int main()
{
	//tester code for #1
	char word[100] = "mulch";
	char wordToAdd[100] = "dog";

	my_str_n_cat(word, wordToAdd, 3);

	printf("%s\n", word);

	//tester code for #2

	int sortedList[6] = { 1,3,4,6,8,9 };
	int target = 8;
	int targetIndex;

	targetIndex = binary_search(sortedList, target, 6); //works for 4 and nothing else...so lets fix

	printf("\nThe item was found at index: %d\n", targetIndex);


	//tester code for #3
	char* words[] = { "Zebra", "Bank", "Apple", "Xylophone", "Appalousa", "Seltza" };

	bubble_sort(words, 6);

	for (int i = 0; i < 6; i++)
	{
		printf("%s, ", words[i]);
	}

	//tester code for #4
	char* wordToCheck = "race car";
	printf("\nPalindrome?: %d", isPalindrome(wordToCheck, 8));


	//tester code for #5
	int num = 5;

	printf("\nSum of primes: %d", sum_primes(num));


	//tester code for #6 
	char* string1 = "test string";

	char maxChar = '\0';
	int maxOccur = 0;

	Occurrences allOcc[128] = { 0 };

	maximum_occurences(string1, allOcc, &maxOccur, &maxChar);

	printf("\nMax occurences: %d, Char: %c", maxOccur, maxChar);



	//tester code for bonus
	int *startAddress;
	int maxStreak;

	int arr[4][5] = {
		{-5, 6, 0, 2, 2}, //row 1
		{2, 2, 2, 9, 3},  //row 2
		{3, 3, 2, 1, -8}, //row 3
		{7, -2, 6, 0, 4}  //row 4
	};

	max_conseutive_integers(arr, 4, 5, &startAddress, &maxStreak);

	printf("\nThe longest streak was %d, the address was %p", maxStreak, (void*)startAddress);


	return 0;
}


	