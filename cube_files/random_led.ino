#include <Rainbowduino.h>
#include <util/delay.h>

/**
* Rainbowduino implements a function to set a pixel in a given (Z,X,Y) position
* with a desired colour as a combination of three 8-bit numbers which represent
* the levels of Red, Green and Blue, respectively. 
*
*		Rb.setPixelZXY(z, x, y, R, G, B);
*
* Moreover, the API of Rainbowduino contains a function to switch off all the 
* LEDs in the cube, hence every time this function is called, the LEDs that 
* were set previously will be shut off.
*
*		Rb.blankDisplay();
* 
* Using both functions described above, develop a sketch to set a LED in the 
* Cube every 2 seconds, in random position and a random colour.
*
* Note: Use the Arduino function random(min, max)
*/

void setup()
{
	Rb.init(); // Initialize the Rainbowduino driver
}

int z,x,y;	
long r,g,b;

void loop()
{
	// Random position
	z = random(0,4);
	x = random(0,4);
	y = random(0,4);

	// Random colour
	r = random(0,256);
	g = random(0,256);
	b = random(0,256);

	Rb.setPixelZXY(z, x, y, r, g, b); // Set the random LED 
	_delay_ms(2000); 	// Introduce a delay of 2 seconds
	Rb.blankDisplay(); 	// Switch off the LEDs
}