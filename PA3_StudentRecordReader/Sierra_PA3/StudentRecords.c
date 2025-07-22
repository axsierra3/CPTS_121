/*******************************************************************************
* Programmer: Arantxa Sierra                                                  *
* Class: CptS 121; Lab Section 07                                             *
* Programming Assignment: Programming Assignment 3                            *
* Date:  09/17/24                                                             *                                                                 
*                                                                             *
* Description: This file contains the C source code that defines the functions *
*            that perform various calculations for processing student records  *
******************************************************************************/


#include "StudentRecords.h"

double read_double(FILE* infile) 
{
	double dRead = 0.0;

	fscanf(infile, "%lf", &dRead);

	return dRead;
}

int read_integer(FILE* infile)
{
	int iRead = 0;

	fscanf(infile, "%d", &iRead);

	return iRead;
}

double calculate_sum(double number1, double number2, double
	number3, double number4, double number5) 
{

	return number1 + number2 + number3 + number4 + number5;
}

double calculate_mean(double sum, int number) 
{
	if (number == 0) {
		return -1.0;
	}

	else {
		return sum / number;
	}
}

double calculate_deviation(double number, double mean) 
{
	return number - mean;
}


double calculate_variance(double deviation1, double deviation2, double
	deviation3, double deviation4, double deviation5, int number)  
{
	double sum = (calculate_sum(deviation1*deviation1, deviation2*deviation2, deviation3*deviation3, deviation4*deviation4, deviation5*deviation5));
	return calculate_mean(sum, number);
}


double calculate_standard_deviation(double variance) 
{
	return sqrt(variance);
}


double find_max(double number1, double number2, double number3,
	double number4, double number5)
{
	double max = number1;

	if (max < number2) {
		max = number2;
	}
	if (max < number3) {
		max = number3;
	}
	if (max < number4) {
		max = number4;
	}
	if (max < number5) {
		max = number5;
	}

	return max;
}


double find_min(double number1, double number2, double number3,
	double number4, double number5) 
{
	double min = number1;

	if (min > number2) {
		min = number2;
	}
	if (min > number3) {
		min = number3;
	}
	if (min > number4) {
		min = number4;
	}
	if (min > number5) {
		min = number5;
	}

	return min;
}


void print_double(FILE* outfile, double number) 
{
	fprintf(outfile, "% .2lf\n", number);
}

