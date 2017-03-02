#include <Rainbowduino.h>
#include <util/delay.h>

/**
* The international Morse code is a codification system created to transmit messages 
* using a series of on-off tones or ligths. The alphabet is composed by silences, 
* short-duration signals (dots) and long-duration signals (dashes).
*
* Every letter in the Latin alphabet can be codified with a pre-defined combination of
* dots and dashes, hence the receiver can decode the signals to understand the message.
*
* Create a function to transmit a letter S, another to transmit a letter O and a 
* function to set the whole Cube to a desired colour. Finally, use the functions to 
* send an infinite red-coloured Morse SOS message using the Cube.
*
* Knowing that:
* - The S letter is represented with three dots (. . .)
* - The O letter is represented with three dashes (- - -)
* - Dash's duration is 3 seconds
* - Dot's duration is 1 second
* - The duration of the silence between dashes and dots is 1 second
* - The duration of the silence between letters is 2 seconds and between words 4 seconds
*
* Additionally, in order to create an efficient sketch, create a function that sets the
* complete Cube to a given colour.
*
*			setCompleteCube(colour);
*/

long red = 0xFF0000;

void setup()
{
	Rb.init(); // Initialize the Rainbowduino driver
}

void loop()
{
	transmitS();
	_delay_ms(2000); // Silence between letters
	
	transmitO();
	_delay_ms(2000); // Silence between letters
	
	transmitS();
	_delay_ms(4000); // Silence between words
}

/*
* Function to switch on all the LEDs in the Cube on, with a given colour
*/
void setCompleteCube(long colour)
{
	int z,x,y;
	
	for(z=0; z<4; z++)
	{ 
		for(x=0; x<4; x++)
		{
			for(y=0; y<4; y++)
			{
				Rb.setPixelZXY(z, x, y, colour); // Set the LED to the given colour
			}
		}
	}
}

/*
* Function to generate the letter S in Morse Code
*/
void transmitS()
{
	setCompleteCube(red);
	_delay_ms(1000); // Dot
	Rb.blankDisplay();
	_delay_ms(1000); // Silence between symbols
	
	setCompleteCube(red);
	_delay_ms(1000); // Dot
	Rb.blankDisplay();
	_delay_ms(1000); // Silence between symbols
	
	setCompleteCube(red);
	_delay_ms(1000); // Dot
	Rb.blankDisplay();
}

/*
* Function to generate the letter O in Morse Code
*/
void transmitO()
{
	setCompleteCube(red);
	_delay_ms(3000); // Dash
	Rb.blankDisplay();
	_delay_ms(1000); // Silence between symbols
	
	setCompleteCube(red);
	_delay_ms(3000); // Dash
	Rb.blankDisplay();
	_delay_ms(1000); // Silence between symbols
	
	setCompleteCube(red);
	_delay_ms(3000); // Dash
	Rb.blankDisplay();
}