/*******************************************************************************
* Programmer: Arantxa Sierra                                               *
* Class: CptS 121; Lab Section 07                                          *
* Programming Assignment: Programming Assignment 2                                      *
* Date:  09/13/24                                   *                                                                  *
*                                                                             *
* Description: This file contains the C source code that defines the functions*
*            that perform various calculations for the user.                  *
******************************************************************************/



#include "equations.h";


double calculateNewtons2ndLaw(double mass, double acceleration) 
{
	return mass * acceleration;
}

double calculateVolumeCylinder(double radius, double height)
{
	return PI * (radius*radius) * height;
}

char performCharacterEncoding(char plaintext_character, int offset) 
{
	return offset + (plaintext_character - 'a') + 'A';
}

double calculateForce(double mass1, double mass2, double distance) 
{
	return (GRAVITY * mass1 * mass2 )/ (distance * distance);
}

double fahrenheitToCelsius(double fahrenheit)
{
	return (fahrenheit - (double)32) / ((double)9 / 5);
}

int calculateDistance(int x1, int x2, int y1, int y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double calculateGeneralEq(int z, int x, int a)
{
	return (((double)89 / (double)27)) - z * x + a / (a % 2);
}