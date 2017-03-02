#include <Rainbowduino.h>
#include <util/delay.h>

/**
* Rainbowduino implements a second function to set a pixel in a given (Z,X,Y) 
* position with a desired colour. The difference with the function exposed
* in the last exercise lies on the way the colour is introduced in the 
* function. This time, the colour is defined as a single 24-bit number where
* the first 8 bits represent the level of R, the second 8 bits represent the
* level of G and the last 8 bits the level of B. 
*
*		Rb.setPixelZXY(z, x, y, RGB);
*
* Develop a sketch to set 3 LEDs in the Cube every 2 seconds, in 3 random 
* positions and 3 different random colours using the function described 
* above.
*/

void setup()
{
	Rb.init(); // Initialize the Rainbowduino driver
}

int z1,x1,y1;
int z2,x2,y2;
int z3,x3,y3;
	
long rgb1;
long rgb2;
long rgb3;

void loop()
{
	// Random position 1
	z1 = random(0,4);
	x1 = random(0,4);
	y1 = random(0,4);
	
	// Random position 2
	z2 = random(0,4);
	x2 = random(0,4);
	y2 = random(0,4);
	
	// Random position 3
	z3 = random(0,4);
	x3 = random(0,4);
	y3 = random(0,4);

	// Random colours
	rgb1 = random(0,0xFFFFFF);
	rgb2 = random(0,0xFFFFFF);
	rgb3 = random(0,0xFFFFFF);

	Rb.setPixelZXY(z1, x1, y1, rgb1); // Set the random LED1 
	Rb.setPixelZXY(z2, x2, y2, rgb2); // Set the random LED2 
	Rb.setPixelZXY(z3, x3, y3, rgb3); // Set the random LED3 
	_delay_ms(2000); 	// Introduce a delay of 2 seconds
	Rb.blankDisplay(); 	// Switch off the LEDs
}