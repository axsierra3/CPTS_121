
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h> 


#define GRAVITY 6.67e-11
#define PI 3.141592

int main() {

	double mass = 0;
	double acceleration = 0;

	printf("Please enter the mass and acceleration (both floating-point values) for use in Newton's Second Law: ");
	scanf("%lf", &mass);
	scanf("%lf", &acceleration);

	double result = mass * acceleration;

	printf("Newton's Second Law: force = mass * acceleration = %lf * %lf = %.2lf", mass, acceleration, result);


	double rad = 0;
	double height = 0;

	printf("\n\nPlease enter the radius and height (both floating-point values) for use in volume of a cylinder equation: ");
	scanf("%lf", &rad);
	scanf("%lf", &height);

	result = PI * (rad * rad) * height;

	printf("\nVolume of a cylinder: PI * radius^2 = 3.141592 * %lf * %lf = %.2lf", rad, height, result);


	char plainChar = NULL;
	int offset = 0;

	printf("\n\nPlease enter the character and offset (char and int) for use in character encoding: ");
	scanf(" %c", &plainChar);
	scanf("%d", &offset);

	char encoded = offset + (plainChar - 'a') + 'A';

	printf("\nCharacter Encoding: encoded_character = offset + (plaintext_character - a) + A = %d + ( %c - a ) = %c", offset, plainChar, encoded);


	double mass1 = 0;
	double mass2 = 0;
	double distance = 0;

	printf("\n\nPlease enter the 1st mass the 2nd mass, and the distance (all floating-point values) for use in a force calculation: ");
	scanf("%lf", &mass1);
	scanf("%lf", &mass2);
	scanf("%lf", &distance);

	result = (GRAVITY * mass1 * mass2) / (distance * distance);

	printf("\nForce: Gravity * mass 1 * mass 2 / distance^2 = G * %lf * %lf / %lf^2 = %.15lf", mass1, mass2, distance, result);

	double fahrenheit = 0;

	printf("\n\nPlease enter the temperature in fahrenheit (floating-point value) for a conversion to celsius: ");
	scanf("%lf", &fahrenheit);

	double celcius = (fahrenheit - (double)32) / ((double)9 / 5);

	printf("\n\nCelsius: fahrenheit - 32 / (9/5) = %lf - 32 / (9/5) = %.2lf", fahrenheit, celcius);


	int z = 0;
	int x = 0;
	int a = 0;

	printf("\n\nPlease enter the z, x, and z (all floating-point values) for use in the general equation: ");
	scanf("%d", &z);
	scanf("%d", &x);
	scanf("%d", &a);

	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;

	printf("\n\nPlease enter x1, x2, y1, and y2 (all integers) for use in a distance calculation: ");
	scanf("%d", &x1);
	scanf("%d", &x2);
	scanf("%d", &y1);
	scanf("%d", &y2);

	result = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	printf("\nDistance = square root of (x1 - x2)^2 + (y2 - y1)^2 = (%d - %d)^2 + (%d - %d)^2 = %.2lf", x1, x1, y1, y1, result);


	return 0; 
}