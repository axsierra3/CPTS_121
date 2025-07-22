/*******************************************************************************
* Programmer: Arantxa Sierra                                                   *
* Class: CptS 121; Lab Section 07                                              *
* Programming Assignment: Programming Assignment 2                             *
* Date:  09/13/24                                                                
*                                                                              *
* Description: This program prompts users for input values and stores the      *
*              input in their respective variables. These variables are passed*
*              to mathemical functions that perform calculations for Newton's,
*              law, volume, character encoding, force, farenheit conversions,
*              and the general equation. Results are printed on the screen.   *

*                                                                                 *                           
******************************************************************************/


#include "equations.h";

int main() {
	double mass = 0;
	double acceleration = 0;

	printf("Please enter the mass and acceleration (both floating-point values) for use in Newton's Second Law: ");
	scanf("%lf", &mass); //& is used because you want to modify the value (passing by reference)(also scanf needs a pointer)
	scanf("%lf", &acceleration);

	double result = calculateNewtons2ndLaw(mass, acceleration);

	printf("Newton's Second Law: force = mass * acceleration = %lf * %lf = %.2lf", mass, acceleration, result);


	double rad = 0;
	double height = 0;

	printf("\n\nPlease enter the radius and height (both floating-point values) for use in volume of a cylinder equation: ");
	scanf("%lf", &rad);
	scanf("%lf", &height);

	result = calculateVolumeCylinder(rad, height);

	printf("\nVolume of a cylinder: PI * radius^2 = 3.141592 * %lf * %lf = %.2lf", rad, height, result);


	char plainChar = NULL;
	int offset = 0;

	printf("\n\nPlease enter the character and offset (char and int) for use in character encoding: ");
	scanf(" %c", &plainChar);
	scanf("%d", &offset);

	char encoded = performCharacterEncoding(plainChar, offset);

	printf("\nCharacter Encoding: encoded_character = offset + (plaintext_character - a) + A = %d + ( %c - a ) = %c", offset, plainChar, encoded);


	double mass1 = 0;
	double mass2 = 0;
	double distance = 0;

	printf("\n\nPlease enter the 1st mass the 2nd mass, and the distance (all floating-point values) for use in a force calculation: ");
	scanf("%lf", &mass1);
	scanf("%lf", &mass2);
	scanf("%lf", &distance);

	result = calculateForce(mass1, mass2, distance);

	printf("\nForce: Gravity * mass 1 * mass 2 / distance^2 = G * %lf * %lf / %lf^2 = %.15lf", mass1, mass2, distance, result);

	double fahrenheit = 0;

	printf("\n\nPlease enter the temperature in fahrenheit (floating-point value) for a conversion to celsius: ");
	scanf("%lf", &fahrenheit);

	double celcius = fahrenheitToCelsius(fahrenheit);

	printf("\n\nCelsius: fahrenheit - 32 / (9/5) = %lf - 32 / (9/5) = %.2lf", fahrenheit, celcius);


	double z = 0;
	double x = 0;
	double a = 0;

	printf("\n\nPlease enter the z, x, and z (all floating-point values) for use in the general equation: ");
	scanf("%lf", &z);
	scanf("%lf", &x);
	scanf("%lf", &a);

	result = calculateGeneralEq(z,x,a);

	//TODO: check why 0
	printf("\nGeneral Equation: y= (89/27) - z* x + a /(a modulo 2) = (89 /27) - %lf * %lf + %lf / (%lf % 2) = %.2lf", z, x, a, a, result);


	return 0;
}