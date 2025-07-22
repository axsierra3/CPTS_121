#include "PA8.h"

char* my_str_n_cat(char* destination, char* source, int n) //passing in pointers to first char in array
{
	//index version
	
	//int destLength = 0;

	//while (destination[destLength] != '\0') { //finding how many letters in destination w/out strlen
	//	destLength++;
	//}
	//int i = 0;
	//for (; source[i] != '\0' && i < n; i++) 
	//{
	//	destination[destLength + i] = source[i];
	//}

	//destination[destLength + i] = '\0';

	while (*destination != '\0') //while that value being pointed to is not null, keep moving the pointer up
	{
		destination++;
	}

	while(*source != '\0' && n > 0)
	{
		*destination = *source; //that last val of destination is now that part of source

		destination++; //increment 
		source++;      //both
		n--;
	}
	*destination = '\0';

	return destination;
}


int binary_search(int sortedInts[], int target, int size) 
{
	int left = 0;
	int right = size - 1;
	int mid;
	int targetIndex = -1;

	int found = 0;

	while (!found && left <= right) 
	{
		mid = ((left + right) / 2);

		if (target == sortedInts[mid]) 
		{
			found = 1;
			targetIndex = mid;
		}
		else if (target < sortedInts[mid]) 
		{
			right = mid - 1;
		}
		else if (target > sortedInts[mid])
		{
			left = mid + 1;
		}
	}
	return targetIndex;
}

//sorting from low to high
void bubble_sort(char* arr[], int numStrings)
{
	int unsortedIndex = numStrings - 1; //if 3 words, index of unsorted = 2
	int currIndex;

	while (unsortedIndex > 1) //while still an element unsorted
	{
		currIndex = 1; //setting to 2nd element in list

		while (currIndex <= unsortedIndex)
		{
			if (strcmp(arr[currIndex], arr[currIndex - 1]) < 1) //if string at curr is less than the one before it, swap them (note: strcmp takes pointers, so no dereferencing)
			{
				char* temp;
				//pointer to string at currIndex stored in temp 
				temp = arr[currIndex];
				arr[currIndex] = arr[currIndex - 1]; //pointer at currIndex is now the pointer to the string before it
				arr[currIndex - 1] = temp;    //pointer that pointed is now the ptr to currIndex

			}
			currIndex++;
		}
		unsortedIndex--;
	}
}

	int isPalindrome(char* word, int length)
	{
		char* endPtr = word; //points to start of word, ptrs are equal to eachother
		endPtr += (length - 1); //endPtr  is now pointing to last index

		//base case (single char or odd lettered word)
		if (length <= 1) 
		{
			return 1;
		}

		// skip spaces at the start
		while (*word == ' ')
		{
			word++;
			length--;
		}
		// skip spaces at the end
		while (*endPtr == ' ')
		{
			endPtr--;
			length--;
		}

		//recursive case
		   if (*word == *endPtr) //if they're the same chars call this funct again to keep checking
			{
				return isPalindrome(++word, length - 2); //move start and end closer (length - 2 bc two chars are consumed each call)
			}											//note: remember to put 2nd return
			
		return 0;
	}

	//REFERENCE: code is altered from StackOverflow for how to check for a prime number 
	int is_prime(int num)
	{
		if (num <= 1)
		{
			return 0;
		}
		if (num % 2 == 0 && num > 2)
		{
			return 0;
		}
		for (int i = 3; i < num / 2; i += 2)
		{
			if (num % i == 0)
				return 0;
		}
		return 1;
	}

	//unsigned ints cant be negative 
	int sum_primes(unsigned int n) 
	{

		//base case 
		if (n < 2) 
		{
			return 0; 
		}

		//recursive case 
		else if (is_prime(n)) //checks if prime, if it is, add that prime number then call again
		{                                                             //if n drops below 2 it just adds 0 and stops calling more
			return n + sum_primes(n - 1); 
		}
		else //if number isn't prime dont add anything anything
		{
			return sum_primes(n - 1);
		}
	}



	void maximum_occurences(char* string, Occurrences occur[], int* maxOccur, char* maxChar)
	{
		//array for ascii that keeps tracks of how many of each aplhanumeric ascii
		int ascii[128] = { 0 };
		/*char unique[] = { 0 };*/
		int numChars = 0;

		//convert each char in the string to its ascii and put it into corresponding 
		for (int i = 0; string[i] != '\0'; i++)
		{
			ascii[(int)string[i]] += 1;
			numChars++;
		}
		
		int uniqueChars = 0;;
		//go thru all of ascii array
		for (int i = 0; i < 121; i++)
		{
			if (ascii[i] != 0) //if theres an amt logged for that ascii, make it the next entry in occurences array
			{
				occur[uniqueChars].c = (char)i; //will be used to access char for that occurence 
				occur[uniqueChars].num_occurrences = ascii[i];
				occur[uniqueChars].frequency = ascii[i] / numChars;	//occurences div by total 

				uniqueChars++;
			}
		}

		//finding max num and char
		*maxOccur = occur[0].num_occurrences;
		*maxChar = occur[0].c;

		for (int i = 1; i < uniqueChars; i++) 
		{
			if (occur[i].num_occurrences > *maxOccur) 
			{
				*maxOccur = occur[i].num_occurrences;
				*maxChar = occur[i].c;
			}
		}
	}

	void max_conseutive_integers(int arr[][5], int rows, int cols, int** maxStartAddress, int* maxStreak)
	{
		int currStreak = 1;
		int max = 0;
		int* startAddress = &arr[0][0];

		//find the longest streak to store indirectly in 2nd pointer

		int prev = arr[0][0];
		//2D arrarys are layed out in a flat sequence in memory, you don't need separate loops bc you're not printing by row or anything
		for (int i = 1; i < rows * cols; i++)
		{

			if (arr[0][i] == prev) {
				currStreak++;
			}
			else {
				currStreak = 1;
				startAddress = &arr[0][i];
			}

			if (currStreak > *maxStreak)
			{
				*maxStartAddress = startAddress;
				*maxStreak = currStreak;
				max = prev;
			}
			prev = arr[0][i];
		}
	}

