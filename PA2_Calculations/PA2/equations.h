/*******************************************************************************
* Programmer: Arantxa Sierra                                               *
* Class: CptS 121; Lab Section 07                                          *
* Programming Assignment: Programming Assignment 2                                      *
* Date:  09/13/24                                                                    *
*                                                                             *
* Description: This header file defines the function prototypes that the compiler    *
*              uses to recognize function calls. Also includes libraries, gaurd code, and defines constants.                              *
******************************************************************************/

// guard code
#ifndef EQUATIONS_H
#define EQUATIONS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h> 

#define GRAVITY 6.67e-11
#define PI 3.141592

/*************************************************************
* Function: calculateNewtons2ndLaw()                   
* Date Created: 9/12/24                                    
* Date Last Modified:  9/13/24                          
* Description: This function takes two double values representing 
* mass and acceleration. The function then uses these values to compute
* Newton's 2nd law.
* Input parameters: double mass and acceleration.         
* Returns: The double representing the result.             
* Preconditions: The values should not be null, and should be numeric.               *
* Postconditions: The result of Newtons's 2nd Law is returned as a double.                        
*************************************************************/
double calculateNewtons2ndLaw(double mass, double acceleration);



/*************************************************************
* Function: calculateVolumeCylinder()
* Date Created: 9/12/24
* Date Last Modified:   9/13/24
* Description: This function takes two double values representing
* cylinder radius and height. The function then uses these values to 
* compute the volume
* Input parameters: double radius and height.
* Returns: The double representing the volume.
* Preconditions: The values should not be null, and should be numeric.               *
* Postconditions: The result of the volume cylinder calculation  is returned as a double.
*************************************************************/
double calculateVolumeCylinder(double radius, double height);

/*************************************************************
* Function: performCharacterEncoding();
* Date Created: 9/12/24
* Date Last Modified:9/13/24
* Description: This function takes a char input representing the original char
* and a integer offest value which is how far in the ASCII table the char will added to
* Input parameters: dhar plaintext_character and int offset
* Returns: The double representing the volume.
* Preconditions: The values should not be null, and should be a char and an integer  
* Postconditions: The result of the character encoding is returned as a char.
*************************************************************/
char performCharacterEncoding(char plaintext_character, int offset);

/*************************************************************
* Function: calculateForce();
* Date Created: 9/12/24
* Date Last Modified:   9/13/24
* Description: This function takes two double values representing
* the first mass, second mass, and distance traveled. The function then uses these values to
* compute the force.
* Input parameters: double mass1, mass2, and distance.
* Returns: The double representing the volume.
* Preconditions: The values should not be null, and should be numeric.               *
* Postconditions: The result of the force calculation is returned as a double.
*************************************************************/
double calculateForce(double mass1, double mass2, double distance);

/*************************************************************
* Function:  fahrenheitToCelsius();
* Date Created: 9/12/24
* Date Last Modified:   9/13/24
* Description: This function takes one double value represtning the temperature in fahrenheit
* The function then uses these values to convert the temperature to celsius.
* Input parameters: double fahrenheit
* Returns: The double representing the temperature in celsius
* Preconditions: The value should not be null, and should be numeric.               *
* Postconditions: The result of the celsius conversion is returned as a double
*************************************************************/
double fahrenheitToCelsius(double fahrenheit);

/*************************************************************
* Function: calculateDistance();
* Date Created: 9/12/24
* Date Last Modified:   9/13/24
* Description: This function takes four double values representing
* two c0ordinate points (x1, y1) and (x2, y2). The function then uses these values to
* compute the distance between the points.
* Input parameters: int x1, x2, y1, y2.
* Returns: The double representing the volume.
* Preconditions: The values should not be null, and should be integers      *
* Postconditions: The result of the distance calculation is returned as an int.
*************************************************************/
int calculateDistance(int x1, int x2, int y1, int y2);


/*************************************************************
* Function: calculateGeneralEq();
* Date Created: 9/12/24
* Date Last Modified:   9/13/24
* Description: This function takes three double values representing z, x, and a.
* The function then uses these values to insert them into the general equation and 
* compute the result.
* Input parameters: int z, x, and a.
* Returns: The double representing the result.
* Preconditions: The values should not be null, and should be integers.     *
* Postconditions: The result of the general equation is returned as a double.
*************************************************************/
double calculateGeneralEq(int z, int x, int a);


#endif // guard code end

#pragma once


