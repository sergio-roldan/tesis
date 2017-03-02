#include <Rainbowduino.h>
#include <util/delay.h>

/**
* A spiral is a curve which emanates from a central point, getting progressively 
* farther away as it revolves around the initial point.
*
* In this task, we are going to create a 3-dimensional inverted blue spiral that 
* emanates from a far point creating a curve to reach the central point.
* The spiral should be created from the point (0,0) representing the Z and Y 
* axis respectively filling the whole X axis. That means, when the
* spiral is born, a line in z=0, y=0 is created, setting all the LEDs in the
* X axis. Then the spiral is extended to z=1, y=0, setting again all the LEDs
* in the X axis at that point and so on, until the central point is reached and
* the whole Cube is set. Afterwars, a new spiral appears from the same initial
* point (0,0) shutting off the X axis at that point and repeating the same process
* until the whole Cube is switched off.
*
* To complete this task, create a function that sets the LEDs in the X axis with a
* given colour in a point (z,y).
*
*			setXLine(z,y,colour); 
*
* Introduce a delay of 2 seconds every time a LED is set.
*/


long blue = 0x0000FF;
long black = 0x000000;
int z[16] = {0,1,2,3,3,3,3,2,1,0,0,0,1,2,2,1};
int y[16] = {0,0,0,0,1,2,3,3,3,3,2,1,1,1,2,2};

void setup()
{
	Rb.init(); // Initialize the Rainbowduino driver
}

void loop()
{
	for (int i=0; i<16; i++)
	{
		setXLine(z[i], y[i], blue);
		_delay_ms(2000); // Introduce a delay of 2 seconds
	}	
	
	for (int i=0; i<16; i++)
	{
		setXLine(z[i], y[i], black);
		_delay_ms(2000); // Introduce a delay of 2 seconds
	}
}

/*
* Function to switch the LEDs in a line along the X axis, with a given colour
*/
void setXLine(int z, int y, int colour)
{
	for(int x=0; x<4; x++)
	{ 
		Rb.setPixelZXY(z, x, y, colour); // Set the LED 
	}
}