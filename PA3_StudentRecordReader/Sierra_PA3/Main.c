/*******************************************************************************
* Programmer: Arantxa Sierra                                                   *
* Class: CptS 121; Lab Section 07                                              *
* Programming Assignment: Programming Assignment 2                             *
* Date:  09/73/24
*                                                                              *
* Description: This program opens a student recordfile for reading then parses 
* it to find ID, GPA, class standing, and age values. These values are stored
* in variables. These variables are passed to mathematical functions that 
* perform calucations to find sums, means, deviation, standard deviation,
* and variance. The program also finds the minimum and max of a set of numbers.
* The result of the calculations are printed to a new file. 
*                                                                             
******************************************************************************/



#include "StudentRecords.h"

int main() 
{
	int id1, id2, id3, id4, id5;
	double gpa1, gpa2, gpa3, gpa4, gpa5;
	int stand1, stand2, stand3, stand4, stand5;
	double age1, age2, age3, age4, age5;

	FILE* inputStream =fopen("input.dat", "r");

	FILE* outputStream = fopen("output.dat", "w");

	//rec 1
	id1 = read_integer(inputStream);
	gpa1 = read_double(inputStream);
	stand1 = read_integer(inputStream);
	age1 = read_double(inputStream);


	//rec 2
	id2 = read_integer(inputStream);
	gpa2 = read_double(inputStream);
	stand2 = read_integer(inputStream);
	age2 = read_double(inputStream);


	//rec 3
	id3 = read_integer(inputStream);
	gpa3 = read_double(inputStream);
	stand3 = read_integer(inputStream);
	age3 = read_double(inputStream);


	//rec 4
	id4 = read_integer(inputStream);
	gpa4 = read_double(inputStream);
	stand4 = read_integer(inputStream);
	age4 = read_double(inputStream);


	//rec 5
	id5 = read_integer(inputStream);
	gpa5 = read_double(inputStream);
	stand5 = read_integer(inputStream);
	age5 = read_double(inputStream);

	/*double GPAsum = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);*/


	print_double(outputStream, calculate_mean(calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5), 5));
	double GPAmean = calculate_mean(calculate_sum(stand1, stand2, stand3, stand4, stand5), 5);
	print_double(outputStream, GPAmean);
	print_double(outputStream, calculate_mean(calculate_sum(age1, age2, age3, age4, age5), 5));

	double dev1 = calculate_deviation(gpa1, GPAmean);
	double dev2 = calculate_deviation(gpa2, GPAmean);
	double dev3 = calculate_deviation(gpa3, GPAmean);
	double dev4 = calculate_deviation(gpa4, GPAmean);
	double dev5 = calculate_deviation(gpa5, GPAmean);

	double GPAvariance = calculate_variance(dev1, dev2, dev3, dev4, dev5, 5);
	print_double(outputStream, calculate_standard_deviation(GPAvariance));

	print_double(outputStream, find_min(gpa1, gpa2, gpa3, gpa4, gpa5));
	print_double(outputStream, find_max(gpa1, gpa2, gpa3, gpa4, gpa5));

	fclose(inputStream);
	fclose(outputStream);

}
