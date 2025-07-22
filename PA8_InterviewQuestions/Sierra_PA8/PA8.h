#ifndef PA_8
#define PA_8

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct occurrences
{
	int num_occurrences;
	double frequency;
	char c;
} Occurrences;

//takes a destination string and a source string, and appends the source string to destination 
// for n chacters using pointer arithmetic
char* my_str_n_cat(char* destination, char* source, int n);

//takes an array of sorted integers and finds a target value by identifying the middle of the list,
//cheking if the integer is in the lower or higher half, and continues to split and search
//until it is found, returns 1 if found 0 if not
int binary_search(int sortedInts[], int target, int size);

//takes an array of strings and sorts them alphabetially by performing a bubble sort where words are swapped
//repeatedly in the array until there are no words left unsorted
void bubble_sort(char* arr[], int numStrings);

//reursive function checks if two words are the same backwards by calling itself until all characters at the 
// that correspond to eachother are compared using pointer arithmetic
int isPalindrome(char* word, int length);

//recursive function returns the sum of all of the prime integers from 0 to n (the inputted number) 
//until all of the in-between numbers have been checked
int sum_primes(unsigned int n);

//takes a string and determines what character is repeated the most, and how many repitions of that character 
//there were, this is achieved with an Occurences struct
void maximum_occurences(char* string, Occurrences occur[], int* maxOccur, char* maxChar);

//Bonus: takes a 2D array and determines what the longest streak of the same number is, and the address
// of the first number in that streak is
void max_conseutive_integers(int arr[][5], int rows, int cols, int** startAddress, int* maxStreak);

#endif

#pragma once
