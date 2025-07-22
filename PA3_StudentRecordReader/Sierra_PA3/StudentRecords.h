/*******************************************************************************
* Programmer: Arantxa Sierra                                               *
* Class: CptS 121; Lab Section 07                                          *
* Programming Assignment: Programming Assignment 2                         *
* Date:  09/17/24                                                          *
*                                                                          *
* Description: This header file defines the function prototypes that the compiler    *
*              uses to recognize function calls. Also includes libraries, guard code, and defines constants.                              *
******************************************************************************/



// guard code
#ifndef STUDENTRECORDS_H
#define STUDENTRECORDS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>

/*************************************************************
* Function: read_double()
* Date Created: 9/16/24
* Date Last Modified:  9/16/24
* Description: This function takes an input file and reads then stores the
* next double value from it.
* Input parameters: FILE* infile
* Returns: double dRead
* Preconditions: The file should not be null        
* Postconditions: The double value that was read from the file is returned.
*************************************************************/
double read_double(FILE* infile);

/*************************************************************
* Function: read_integer()
* Date Created: 9/16/24
* Date Last Modified:  9/16/24
* Description: This function takes an input file and reads then stores the
* next integer value from it.
* Input parameters: FILE* infile
* Returns: int iRead
* Preconditions: The file should not be null
* Postconditions: The integer value that was read from the file is returned.
*************************************************************/
int read_integer(FILE* infile);


/*************************************************************
* Function: calculate_sum()
* Date Created: 9/16/24
* Date Last Modified: 9/16/24
* Description: This function takes 5 double values representing
* 5 different numbers.The function then adds these values 
* to compute the sum.
* Input parameters: double number1, double number2, double
*	number3, double number4, double number5
* Returns: The double representing the sum.
* Preconditions: The values should not be null, and should be numeric.               *
* Postconditions: The result of the addition is returned as a double.
*************************************************************/
double calculate_sum(double number1, double number2, double
	number3, double number4, double number5);


/*************************************************************
* Function: calculate_mean()
* Date Created: 9/16/24
* Date Last Modified: 9/16/24
* Description: This function takes a double value and an int
* representing a sum and the number of values in the sum.
* Input parameters: double sum, int number
* Returns: The double representing the mean.
* Preconditions: The values should not be null, and should be numeric.               *
* Postconditions: The result of the mean is returned as a double.
*************************************************************/
double calculate_mean(double sum, int number);

/*************************************************************
* Function: calculate_deviation()
* Date Created: 9/16/24
* Date Last Modified: 9/16/24
* Description: This function takes a double number and a double
* mean and calculates the deviation from the mean through subtraction.
* Input parameters: double number, double mean
* Returns: The double representing the deviation.
* Preconditions: The values should not be null, and should be numeric.               *
* Postconditions: The result of the deviation is returned as a double.
*************************************************************/
double calculate_deviation(double number, double mean);


/*************************************************************
* Function: calculate_variance()
* Date Created: 9/16/24
* Date Last Modified: 9/16/24
* Description: This function takes 5 double values representing
* 5 different deviation values and 1 int value representing the number 
* of values. It calculates the variance by finding the sum of the deviations squared
* and finding the mean through function calls. 
* Input parameters: double deviation1, double deviation2, double
*	deviation3, double deviation4, double deviation5
* Returns: The double representing the variance.
* Preconditions: The values should not be null, and should be numeric.               *
* Postconditions: The result of the variance is returned as a double.
*************************************************************/
double calculate_variance(double deviation1, double deviation2, double
	deviation3, double deviation4, double deviation5, int number);

/*************************************************************
* Function: calculate_standard_deviation()
* Date Created: 9/16/24
* Date Last Modified: 9/16/24
* Description: This function takes a double value representing the variance 
* and calculates the standard variation by passing it through the square root function.
* Input parameters: double vairance
* Returns: The double representing the standard deviation.
* Preconditions: The value should not be null, and should be numeric.               *
* Postconditions: The result of the standard deviation is returned as a double.
*************************************************************/
double calculate_standard_deviation(double variance);


/*************************************************************
* Function: find_max()
* Date Created: 9/16/24
* Date Last Modified: 9/16/24
* Description: This function takes 5 double values representing
* 5 different numbers.The function then uses conditional statements 
* to determine what the highest number in the set is.
* Input parameters: double number1, double number2, double
*	number3, double number4, double number5
* Returns: double max
* Preconditions: The values should not be null, and should be numeric.               *
* Postconditions: The max is returned as a double.
*************************************************************/
double find_max(double number1, double number2, double number3,
	double number4, double number5);

/*************************************************************
* Function: find_min()
* Date Created: 9/16/24
* Date Last Modified: 9/16/24
* Description: This function takes 5 double values representing
* 5 different numbers.The function then uses conditional statements
* to determine what the lowest number in the set is.
* Input parameters: double number1, double number2, double
*	number3, double number4, double number5
* Returns: double min
* Preconditions: The values should not be null, and should be numeric.               *
* Postconditions: The min is returned as a double.
*************************************************************/
double find_min(double number1, double number2, double number3,
	double number4, double number5);

/*************************************************************
* Function: print_double()
* Date Created: 9/16/24
* Date Last Modified:  9/16/24
* Description: This function takes an output file and a floating point
* number then writes that number to the file.
* Input parameters: FILE* outfile, double number
* Returns: void
* Preconditions: The inputs should not be null
* Postconditions: The number is printed in the output file.
*************************************************************/
void print_double(FILE* outfile, double number);

#endif // guard code end

#pragma once
